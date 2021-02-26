import cv2
import imutils

haar_upper_body_cascade = cv2.CascadeClassifier(cv2.data.haarcascades +"haarcascade_eye.xml")

# Uncomment this for real-time webcam detection
# If you have more than one webcam & your 1st/original webcam is occupied,
# you may increase the parameter to 1 or respectively to detect with other webcams, depending on which one you wanna use.

# video_capture = cv2.VideoCapture(0)

# For real-time sample video detection
video_capture = cv2.VideoCapture(0)
maxX = 0
minX = 150

while True:
    ret, frame = video_capture.read()

    frame = imutils.resize(frame, width=500) # resize original video for better viewing performance
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) # conert video to grayscale


    upper_body = haar_upper_body_cascade.detectMultiScale(
        gray,
        scaleFactor = 1.1,
        minNeighbors = 5,
        minSize = (20,20), # Min size for valid detection, changes according to video size or body size in the video.
        flags = cv2.CASCADE_SCALE_IMAGE

    )

    # Draw a rectangle around the upper bodies
    for (x, y, w, h) in upper_body:
        minX = min(x,minX)
        maxX = max(x+w,maxX)
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2) # creates green color rectangle with a thickness size of 1
        cv2.putText(frame, "Upper Body Detected", (x + 5, y + 15), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2) # creates green color text with text size of 0.5 & thickness size of 2
        print("we see someone at x1="+str(x)+" and x2= "+str(x+w))
    cv2.imshow('Video', frame) # Display video

    # stop script when "q" key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release capture
print("Max X = "+str(maxX))
print("Min X = "+str(minX))
video_capture.release()
cv2.destroyAllWindows()
