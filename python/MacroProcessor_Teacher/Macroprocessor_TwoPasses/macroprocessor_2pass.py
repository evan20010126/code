import sys
import expandedfile_2pass


def Pass1():
    # 讀含有巨集的source code
    macroflag = False
    for line in lines:

        if len(line) == 0 or line[0] == '.':  # 註解行 or 空行
            continue

        tokens = line.split()  # 把行切成token

        # 範例: RDBUFF	MACRO	&INDEV,&BUFADR,&RECLTH
        # 切成三個token
        # 此程式無法支援: RDBUFF MACRO &INDEV, &BUFADR, &RECLTH
        # 有空格會被拆成五個token

        if len(tokens) > 1 and tokens[1] == 'MACRO':  # 若是MACRO代表要開始定義了
            macroflag = True
            macrobody = []  # 為list，紀錄該巨集的定義
            name = tokens[0]  # name 為 RDBUFF(把巨集的名字取出來)
            parameters = tokens[2].split(",")
            # 把第三個token轉換成parameter
            # 處理過後為: ["&INDEV", "&BUFADR", "&RECLTH"]
        elif len(tokens) == 1 and tokens[0] == 'MEND':  # 遇到MEND會結束
            DEFTAB[name] = macrobody
            macroflag = False
        else:
            if macroflag == True:  # 若flag是true
                # 還要處理如果有參數要轉換，要做轉換(把parameter轉換成: ?1, ?2, ?3) 因為沒有存上面的參數&...，只有存下面的，並不會知道參數是第幾個，怎麼代入
                replaced = positionalNotation(line, parameters)
                # 要把指令加到macrobody內(逐行append)，之後MEND結束後再塞到DEFTAB
                macrobody.append(replaced)


def positionalNotation(line, parameters):
    replaced = line
    for i in range(1, len(parameters)+1):  # 因為是從 ?1 開始編號，都檢查
        replaced = replaced.replace(parameters[i-1], "?%s" % i)  # 若有出現的參數換成該編號
    return replaced


def Pass2():
    # 在乎主程式
    macroflag = False
    for line in lines:

        if len(line) == 0 or line[0] == '.':
            continue

        tokens = line.split()

        # 若是SIC or SIC/XE的指令，直接copy就好，而若發現說opcode在define table裡面，不能直接copy paste，要做展開的動作
        if len(tokens) > 1 and tokens[1] == 'MACRO':
            macroflag = True
        elif len(tokens) == 1 and tokens[0] == 'MEND':
            macroflag = False
        else:
            if macroflag == False:
                if tokens[0] in DEFTAB or (len(tokens) > 1 and tokens[1] in DEFTAB):
                    # 檢查token[0]或token[1]有沒有在define table裡面 (因為有可能此行有label，所以要檢查token[1])
                    # 做 len(token) > 1的判斷是怕出現out of index
                    if tokens[0] in DEFTAB:
                        macroname = tokens[0]
                        args = tokens[1]
                        # label = ""
                    else:
                        macroname = tokens[1]
                        args = tokens[2]
                        # label = tokens[0]
                    expand(macroname, args)  # expand(macroname, args, label)
                else:
                    outputfile.write(line)


def expand(macroname, args):  # expand(macroname, args, label)
    argtokens = args.split(",")
    # ["05", "BUFFER", "LENGTH"]
    macrobody = DEFTAB[macroname]

    # hasLabel = False
    # if (len(label) != 0):
    #    hasLabel = True

    for line in macrobody:

        # 例如處理: CLOOP RDBUFF F1,BUFFER,LENGTH
        # CLOOP 要加回去 (只有第一行會處理)
        # if (hasLabel):
        #     line = "%s%s" % (label, line)
        #     hasLabel = False

        # 參數的代換
        for i in range(1, len(argtokens)+1):
            line = line.replace("?%s" % i, argtokens[i-1])
            # 若是"?1"取代成argtokens[0]
        outputfile.write(line)


# main code
if len(sys.argv) != 2:
    print("Usage: python3 nacroprocessor.py <source file>")
    sys.exit()

inputfp = open(sys.argv[1], "r")
lines = inputfp.readlines()

DEFTAB = {}  # define table (放RDBUFF WRBUFF)
# key: 巨集名稱
# value: 字串(巨集的定義)
# INDEV 會被轉換成 ?1，BUFADR 會被轉換成 ?2，RECLTH 會被轉換成 ?3
#! ----------------------- !#
# RDBUFF	MACRO & INDEV, & BUFADR, & RECLTH
# CLEAR	X
# CLEAR	A
# CLEAR	S
# +LDT  # 4096
# TD = X'&INDEV'
# JEQ * -3
# RD = X'&INDEV'
# COMPR	A, S
# JEQ * +11
# STCH & BUFADR, X
# TIXR	T
# JLT * -19
# STX & RECLTH
# MEND
#! ----------------------- !#
# {'RDBUFF': ['\tCLEAR\tX\n', '\tCLEAR\tA\n', '\tCLEAR\tS\n', '\t+LDT\t#4096\n', "\tTD\t=X'?1'\n", '\tJEQ\t*-3\n', "\tRD\t=X'?1'\n", '\tCOMPR\tA,S\n', '\tJEQ\t*+11\n', '\tSTCH\t?2,X\n', '\tTIXR\tT\n', '\tJLT\t*-19\n', '\tSTX\t?3\n'],
# 'WRBUFF': ['\tCLEAR\tX\n', '\tLDT\t?3\n', '\tLDCH\t?2,X\n', "\tTD\t=X'?1'\n", '\tJEQ\t*-3\n', "\tWD\t=X'?1'\n", '\tTIXR\tT\n', '\tJLT\t*-14\n']}
#! ----------------------- !#

outputfile = expandedfile_2pass.openFile(sys.argv[1])

Pass1()

print(DEFTAB)

Pass2()  # 做展開的動作
