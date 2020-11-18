# final-project-sentinals
final-project-sentinals created by GitHub Classroom

https://github.com/djmv/MobilNet_SSD_opencv , The training and model files are from this github. We used the training model from this github (we can customize the training model).
https://www.pyimagesearch.com/2017/09/18/real-time-object-detection-with-deep-learning-and-opencv/ 
The detection for object and face are from the python implementation from this website. This python implementation is specfically designed for object detection for cameras.
For the caffe Training model this is how we set it up https://docs.opencv.org/3.4/d5/de7/tutorial_dnn_googlenet.html
For the object detection to run, type this command in a virtual environment, 
python3 real_time_object_detection.py --prototxt=MobileNetSDD_Deploy.prototxt --model MobileNetSSD_deploy.caffemodel
