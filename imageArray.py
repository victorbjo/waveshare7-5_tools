from ctypes import sizeof
import cv2
def createImageArray(src, image):
    list = []
    img = cv2.imread(src)
    for row in img:
        tempList = []
        for cols in row:
            if cols[2] > (int(cols[1]) + int(cols[0]))*1.05:
                tempList.append(2)
            elif int(cols[0]) + int(cols[1]) + int(cols[2]) < 350:
                tempList.append(1)
            else:
                tempList.append(0)
        list.append(tempList)
    lenX = (len(list))
    lenY = (len(list[0]))
    list = str(list)
    list = list.replace("[","{")
    list = list.replace("]","}")
    print(list)
    f = open(image+".h", "a")
    f.write("#ifndef "+image+"_h\n")
    f.write("#define "+image+"_h\n")
    f.write('#include <pgmspace.h> \n#include "Arduino.h"\n')
    f.write("const unsigned int "+image+"["+str(lenX)+"]["+str(lenY)+"] PROGMEM ="+list+";")
    f.write("\n#endif")
createImageArray("C:/Users/Victor/Desktop/testimgsmall.jpg", "battery")