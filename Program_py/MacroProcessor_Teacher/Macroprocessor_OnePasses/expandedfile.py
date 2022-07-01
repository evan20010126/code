def openFile(filename):
    expandedfilename = getMainFileName(filename)
    expandedfilename = expandedfilename + "_expanded.asm"
    expandedfile = open(expandedfilename, "w")
    return expandedfile

def getMainFileName(filename):
    i = 0
    mainname = ""
    while True:
        if filename[i] == '.':
            break
        mainname += filename[i]
        i += 1
    return mainname
    
    
