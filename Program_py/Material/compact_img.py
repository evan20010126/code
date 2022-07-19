from PIL import ImageGrab
from PIL import Image

file_name = "transformer_model_01.png"

img = Image.open(file_name)

img = img.resize((678, 2753), Image.BILINEAR)

img.save("modify"+file_name)
