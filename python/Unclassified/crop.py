import cv2
# 230x420
name = "modify_shoes04.png"
try:
    img = cv2.imread(name)
except:
    print("no")
    exit()

# 裁切區域的 x 與 y 座標（左上角）
x = 180
y = 0

# 裁切區域的長度與寬度
w = 230
h = 420

# 裁切圖片
crop_img = list()
crop_img = img[y:y+h, x:x+w]

cv2.imwrite("0" + name, crop_img)
