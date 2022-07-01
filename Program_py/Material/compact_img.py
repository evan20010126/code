from PIL import ImageGrab
from PIL import Image

file_name = "store_hat.jpg"

img = Image.open(file_name)

img = img.resize((613, 535), Image.BILINEAR)

img.save("modify"+file_name)
