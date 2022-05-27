import sys
import expandedfile

def GETLINE():
    if len(expandedMacro) > 0:
        global expandedLineIndex
        expandedLineIndex += 1
        return DEFTAB[expandedMacro][expandedLineIndex-1]
    else:
        line = inputfp.readline()
        return line
        
def PROCESSLINE(line):
    if len(line) == 0 or line[0] == '.':
        tokens = []
    else:
        tokens = line.split()

    if len(tokens) == 0:
        return
    
    if tokens[0] in DEFTAB or (len(tokens) > 1 and tokens[1] in DEFTAB):
        if tokens[0] in DEFTAB:
            macroname = tokens[0]
            if len(tokens) > 1:
                args = tokens[1]
            else:
                args = ""
        else:
            macroname = tokens[1]
            if len(tokens) > 2:
                args = tokens[2]
            else:
                args = ""
        global expandedMacro
        expandedMacro = macroname
        EXPAND(macroname, args)
    elif len(tokens) > 1 and tokens[1] == "MACRO":
        DEFINE(line)
    else:
        outputfile.write(line)

def DEFINE(macrodefline):

    macrobody = []
    tokens = macrodefline.split()
    name = tokens[0]
    if len(tokens) > 2:
        parameters = tokens[2].split(",")
    else:
        parameters = []
    level = 1
        
    while level > 0:
        line = GETLINE()
        tokens = line.split()
        replaced = positionalNotation(line, parameters)
        macrobody.append(replaced)
        if len(tokens) > 1 and tokens[1] == 'MACRO':
            level += 1
        elif len(tokens) == 1 and tokens[0] == 'MEND':
            level -= 1
    del macrobody[len(macrobody)-1]
    DEFTAB[name] = macrobody    
    return

def EXPAND(macroname, args):
    argtokens = args.split(",")
    macrobody = DEFTAB[macroname]

    global expandedLineIndex
    
    while expandedLineIndex < len(macrobody):
        line = GETLINE()
        for i in range(1, len(argtokens)+1):
            line = line.replace("?%s" % i, argtokens[i-1])
        PROCESSLINE(line)
    
    global expandedMacro
    expandedMacro = ""
    expandedLineIndex = 0

def positionalNotation(line, parameters):
    replaced = line
    for i in range(1, len(parameters)+1):
        replaced = replaced.replace(parameters[i-1], "?%s" % i)
    return replaced
    
def isEND(line):
    tokens = line.split()
    if len(tokens) == 1 and tokens[0] == 'END':
        return True
    elif len(tokens) > 1 and (tokens[0] == 'END' or tokens[1] == 'END'):
        return True
    return False

if len(sys.argv) != 2:
    print("Usage: python3 nacroprocessor.py <source file>")
    sys.exit()
    
inputfp = open(sys.argv[1], "r")

DEFTAB = {}

outputfile = expandedfile.openFile(sys.argv[1])

expandedMacro = ""
expandedLineIndex = 0
processline = ""

while isEND(processline) == False:
    processline = GETLINE()
    PROCESSLINE(processline)
        

    
        
    

    

    
    

