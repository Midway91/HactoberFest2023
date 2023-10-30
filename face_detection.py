import cv2
import os

# Load the pre-trained Haar Cascade classifier for face detection
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Load the image
image_path = 'WhatsApp Image 2023-09-02 at 21.38.44.jpeg'  # Replace with the path to your image

# Check if the image path is valid
if not os.path.isfile(image_path):
    print(f"Invalid image path: {image_path}")
    exit()

image = cv2.imread(image_path)

# Check if the image is loaded successfull
if image is None:
    print("Failed to load image")
    exit()

# Convert the image to grayscale (Haar Cascade works on grayscale images)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Perform face detection
faces = face_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

# Draw rectangles around the detected faces
for (x, y, w, h) in faces:
    cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 3)

# Display the image with detected faces
cv2.imshow('Face Detection', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
