# AUTOMATIC ATTENDANCE SYSTEM THROUGH FACE RECOGNITION
#  The only pre-requisites are we need the photos of the candidates/students in
# <student_name>.<extension> format

# ENJOY THE PROJECT 😊😊😊





# importing libraries
import cv2
import numpy as np
import face_recognition
import os
from datetime import datetime
# taking the path
path = "images"
images = []
classnames = []

# make the list of the images
mylist = os.listdir(path)

# printing the list
print(mylist)

for i in mylist:
    # will read all the images one by one
    curimg = cv2.imread("{}/{}".format(path, i))

    # will append to the list
    images.append(curimg)

    # slice the path text and take the only name without extension
    classnames.append(os.path.splitext(i)[0])

print(classnames)

# function to do the encoding
def find_encoding(images):
    encodelist = []
    for img in images:
       pic = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
       encode = face_recognition.face_encodings(pic)[0]
       encodelist.append(encode)

    return encodelist

encode_similar = find_encoding(images)
print("encoding completed")

# function to mark the attendance
def markattendance(name):
    # to load the csv file
    with open("items/atten.csv", 'r+') as f:
        mydatalist = f.readlines()
        namelist = []
        for line in mydatalist:
            entry = line.split(",")
            namelist.append(entry[0])

        if name not in namelist:
            now = datetime.now()
            dtstr = now.strftime("%H:%M:%S")
            f.writelines(f"\n{name}, {dtstr}")

# to take the attendance
# markattendance('ritwik')
# to open the webcam and initiate our process
cap = cv2.VideoCapture(0)

while True:
    success, img = cap.read()
    # resize the image to its one fourth
    imgs = cv2.resize(img, (0, 0), None, 0.25, 0.25)
    # make the images as the rgb
    pic = cv2.cvtColor(imgs, cv2.COLOR_BGR2RGB)
    # take the face location because there can be multiple faces in one frame
    facesCurFrame = face_recognition.face_locations(pic)
    # encode all the faces in a single frame
    encodeCurframe = face_recognition.face_encodings(pic, facesCurFrame)

    # loop through to the faces

    # the loop will grab one by one the face location from facescurframe and each
    # encode face from encodecurframe
    for encodeface, faceloc in zip(encodeCurframe, facesCurFrame):
        matches = face_recognition.compare_faces(encode_similar, encodeface)
        faceDis = face_recognition.face_distance(encode_similar, encodeface)
        # the faceDis will return a list of distances from all the pics to the
        # webcam pic

        # the numpy argmin function will return the min distance value
        # of faceDis list
        match_index = np.argmin(faceDis)

        # to print the name of that person with the matched face
        if matches[match_index]:
            name = classnames[match_index].upper()
            print(name)
            y1, x2, y2, x1 = faceloc
            y1, x2, y2, x1 = y1*4, x2*4, y2*4, x1*4
            # fix the sizes according to requirements
            cv2.rectangle(img, (x1, y1), (x2, y2), color=(255, 200, 150), thickness=2)
            cv2.rectangle(img, (x1, y2-35), (x2, y2), color=(155, 200, 150))

            cv2.putText(img, name, (x1+6, y2-6), cv2.FONT_HERSHEY_DUPLEX, 1, (255, 85, 99), 2)

            # to add the attendance
            markattendance(name)


    # to show the total image
    cv2.imshow("Webcam", img)
    cv2.waitKey(1)











