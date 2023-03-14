# Nama File         : negative_img.py
# Deskripsi         : Mengaplikasikan fungsi transformasi negatif 
#                     pada gambar
# Pembuat           : Aprilyanto Setiyawan Siburian
# NIM               : 24060121120022
# Tanggal Pembuatan : Kamis, 28 April 2022

# import Pillow modules
from PIL import Image

# Read pixels and apply negative transformation function
def Negativemaker(arrgambar):
    for i in range(0, arrgambar.size[0]-1):
        for j in range(0,arrgambar.size[1]-1):
            pixelColorVals = arrgambar.getpixel((i, j));
            # Invert color
            redPixel = 255 - pixelColorVals[0];  # Negate red pixel
            greenPixel = 255 - pixelColorVals[1];  # Negate green pixel
            bluePixel = 255 - pixelColorVals[2];  # Negate blue pixel
            arrgambar.putpixel((i, j), (redPixel, greenPixel, bluePixel));
    return arrgambar

# Load the  first image
img1 = Image.open(r"C:\Users\XP\Documents\UNDIP\MATA KULIAH\SMT 2\Grafika dan Komputasi Visual (GKV)\PART 2\Negative Image\1.png")
# Display the first image
img1.show();
# Apply function to make a negative image for first image
neg1 = Negativemaker(img1)
# Showing first negative image
neg1.show()

#Load the second image
img2 = Image.open(r"C:\Users\XP\Documents\UNDIP\MATA KULIAH\SMT 2\Grafika dan Komputasi Visual (GKV)\PART 2\Negative Image\2.jpg") 
# Display the second image
img2.show();
# Apply function to make a negative image second image
neg2 = Negativemaker(img2)
# Showing second negative image
neg2.show()

#Load the third image
img3 = Image.open(r"C:\Users\XP\Documents\UNDIP\MATA KULIAH\SMT 2\Grafika dan Komputasi Visual (GKV)\PART 2\Negative Image\3.png") 
# Display the third image
img3.show();
# Apply function to make a negative image for third image
neg3 = Negativemaker(img3)
# Showing third negative image
neg3.show()

#Load the fourth image
img4 = Image.open(r"C:\Users\XP\Documents\UNDIP\MATA KULIAH\SMT 2\Grafika dan Komputasi Visual (GKV)\PART 2\Negative Image\4.jpg") 
# Display the fourth image
img4.show();
# Apply function to make a negative image for fourth image
neg4 = Negativemaker(img4)
# Showing fourth negative image
neg4.show()

#Load the fifth image
img5 = Image.open(r"C:\Users\XP\Documents\UNDIP\MATA KULIAH\SMT 2\Grafika dan Komputasi Visual (GKV)\PART 2\Negative Image\5.png")
# Display the fifth image
img5.show();
# Apply function to make a negative image for fifth image
neg5 = Negativemaker(img5)
# Showing fifth negative image
neg5.show()