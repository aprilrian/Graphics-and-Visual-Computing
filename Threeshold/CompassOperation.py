# Nama program: CompassOperation.py
# Nama        : Aprilyanto Setiyawan Siburian
# NIM         : 24060121120022
# Kelas       : GKV D
# Deskripsi   : Membuat program edge detection menggunakan operasi kompas

import cv2
import numpy as np

kernels = {
    'n' : np.array([[1, 1, 1], [1, -2 , 1], [-1, -1 ,-1]]), 
    'ne': np.array([[1, 1, 1], [-1, -2, 1], [-1, -1, 1]]), 
    'e' : np.array([[-1, 1, 1], [-1, -2 ,1], [-1, 1, 1]]), 
    'se': np.array([[-1, -1, 1], [-1, -2, 1], [1, 1, 1]]), 
    's' : np.array([[-1, -1, -1], [1, -2, 1], [1, 1, 1]]), 
    'sw': np.array([[1, -1, -1], [1, -2, -1], [1, 1, 1]]), 
    'w' : np.array([[1, 1, -1], [1, -2, -1], [1, 1, -1]]), 
    'nw': np.array([[1, 1, 1], [1, -2, -1], [1, -1, -1]]),}

conv_result = []
fileName = "foto.png"
im = cv2.imread(fileName, cv2.IMREAD_GRAYSCALE)
threshold = 125

cv2.imwrite(f"orig.png", im)
width,height = im.shape
for dir in kernels:
    temp_im = cv2.filter2D(im, -1, kernels[dir])
    cv2.imwrite(f"{dir}.png", temp_im)
    conv_result.append(temp_im)

final_result = np.copy(im)
for i in range(1, width-1):
        for j in range(1, height-1):
            conv_res = np.array([elmt[i,j] for elmt in conv_result])
            final_result[i,j] = np.amax(conv_res)
cv2.imwrite(f"final.png", final_result)

final_threshold = np.copy(im)
for i in range(1, width-1):
        for j in range(1, height-1):
            conv_res = np.array([elmt[i,j] for elmt in conv_result])
            final_result[i,j] = 0 if threshold < np.amax(conv_res) else 255
cv2.imwrite(f"final_threshold.png", final_threshold)
