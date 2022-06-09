import sys
import expandedfile


def GETLINE():
    # 有兩種情況，一種是從define table讀，一種是從source code讀(取決於expanding變數)
    if len(expandedMacro) > 0:
        # 若正在做展開的動作，從deftab讀取一行
        global expandedLineIndex
        expandedLineIndex += 1
        return DEFTAB[expandedMacro][expandedLineIndex-1]
    else:
        # 讀取 SIC .asm檔的一行(從asm檔的第一行開始一行一行讀)
        line = inputfp.readline()
        return line


def PROCESSLINE(line):
    # 忽略註解行
    if len(line) == 0 or line[0] == '.':
        tokens = []
    else:
        tokens = line.split()

    # 忽略空行
    if len(tokens) == 0:
        return

    # Case1: 巨集的呼叫(i.e 展開)
    if tokens[0] in DEFTAB or (len(tokens) > 1 and tokens[1] in DEFTAB):
        # ? Ex. 讀取到 main 的 MACROX，發現MACROX已經定義好了，之後要Expand MACROX
        if tokens[0] in DEFTAB:
            macroname = tokens[0]
            if len(tokens) > 1:
                args = tokens[1]
            else:
                args = ""
        else:
            macroname = tokens[1]
            label = tokens[0]
            if len(tokens) > 2:
                args = tokens[2]
            else:
                args = ""
        global expandedMacro
        # 課本是把EXPANDING改成true，這裡是把expandedMacro改成macroname (MACORX)
        expandedMacro = macroname  # 為MACORX
        EXPAND(macroname, args, label)  # 呼叫EXPAND
    # Case2: 巨集的定義
    elif len(tokens) > 1 and tokens[1] == "MACRO":
        # ? 遇到MACROX	MACRO，開始定義MACROX
        DEFINE(line)
    # Case3 寫進output檔
    else:
        # ? Ex. 遇到MM	START	0 直接copy paste輸出
        outputfile.write(line)


def DEFINE(macrodefline):
    # ? 遇到MACROX	MACRO，開始定義MACROX
    macrobody = []
    tokens = macrodefline.split()
    name = tokens[0]
    if len(tokens) > 2:
        parameters = tokens[2].split(",")
    else:
        parameters = []

    level = 1
    # 可以處理巨集裡面有巨集
    # 第一層的巨集，若巨集裡面遇到巨集(還沒有遇到自己的MEND，但又遇到一個MACRO)，會變第二層的巨集(level = 2)
    # level == 0 代表找到對應的macro end了

    while level > 0:
        line = GETLINE()  # 繼續讀下一行
        # ? Ex. RDBUFF MACRO &ADDR

        tokens = line.split()

        replaced = positionalNotation(line, parameters)
        # 若有parameter(ex. ?1, ?2, ?3)，要取代

        macrobody.append(replaced)
        # 放到macrobody內

        if len(tokens) > 1 and tokens[1] == 'MACRO':
            level += 1
        elif len(tokens) == 1 and tokens[0] == 'MEND':
            level -= 1

    # 跑完後，DEFTAB內有:
    # 'MACROX': ['RDBUFF\tMACRO\t&ADDR', '\tLDT\t&ADDR', 'MEND', 'MEND']
    del macrobody[len(macrobody)-1]  # 為了刪除 MEND那行
    # 'MACROX': ['RDBUFF\tMACRO\t&ADDR', '\tLDT\t&ADDR', 'MEND']

    DEFTAB[name] = macrobody

    return


def EXPAND(macroname, args, label):

    # Stack.push("MACROX")

    argtokens = args.split(",")  # MACROX時沒有args
    macrobody = DEFTAB[macroname]  # MACROX定義好了有在define table

    # MACROX macrobody長這樣: ['RDBUFF\tMACRO\t&ADDR\n', '\tLDT\t&ADDR\n', '\tMEND\n']

    global expandedLineIndex

    while expandedLineIndex < len(macrobody):
        line = GETLINE()
        # 因為expandedMacro現在為MACROX不為空字串，所以會跑expand巨集的那個if，取得下一行

        # 如果是第一行就要加上label
        if expandedLineIndex == 1 and len(label) > 0:
            line = "%s%s" % (label, line)

        # 取代parameter
        for i in range(1, len(argtokens)+1):
            line = line.replace("?%s" % i, argtokens[i-1])

        PROCESSLINE(line)
        # 第一次取是長這樣'RDBUFF\tMACRO\t&ADDR\n'
        # 因為遇到MACRO，Expanding中又去define RDBUFF
        # define RDBUFF: ['\tLDT\t?1\n']
        # define完RDBUFF後，MACROX就算做完了

    global expandedMacro
    expandedMacro = ""  # pop MACROX
    expandedLineIndex = 0


def positionalNotation(line, parameters):
    replaced = line
    for i in range(1, len(parameters)+1):
        replaced = replaced.replace(parameters[i-1], "?%s" % i)
    return replaced


def isEND(line):
    # 看opcode是否讀到END，是END則迴圈停止
    tokens = line.split()
    if len(tokens) == 1 and tokens[0] == 'END':
        return True
    elif len(tokens) > 1 and (tokens[0] == 'END' or tokens[1] == 'END'):
        return True
    return False


# Main
if len(sys.argv) != 2:
    print("Usage: python3 nacroprocessor.py <source file>")
    sys.exit()

inputfp = open(sys.argv[1], "r")

DEFTAB = {}

# output展開的code
outputfile = expandedfile.openFile(sys.argv[1])

# 此三行對應課本的expanding變數 (Why用三行?)
expandedMacro = ""  # 是正在展開的巨集巨集的名稱，若是空字串，代表expanding是false
expandedLineIndex = 0
processline = ""

while isEND(processline) == False:
    processline = GETLINE()
    PROCESSLINE(processline)
