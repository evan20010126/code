import os

dirPath_Q = r"../Question/"
allFileList_Q = os.listdir(dirPath_Q)  # allFileList: 為所有input影片檔案名稱


dirPath_P = r"../Program/"
allFileList_P = os.listdir(dirPath_P)  # allFileList: 為所有input影片檔案名稱

for i in allFileList_Q:
    if ((i[:-4] + '.cpp') not in allFileList_P):
        file = open('../Program/' + i[:-4] + '.cpp', 'w')
        file.close()
