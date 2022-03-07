# RaspberryPI Projects 
  
<br/>

## Install OpenCV on RaspberryPI 
* Followed intructions from pyimagesearch [1] and learnopencv [2]. 
* Here are the installation steps: <br/>
<p align="center">
  <img src="https://user-images.githubusercontent.com/86133411/156970122-e0c0ac51-babd-44e6-8fe0-6bede44ba0b7.png" width="238" height="461">
</p>

## Notes
#### [CameraMotionDetect](/CameraMotionDetect)
* In this project I build a surveillance camera for my home. The camera detects and records moving object. 
* Features: 
  * When detect moving objects the camera starts to record for a period of time and then stop. <br/>
  * The algorithm for moving object detection is based on image subtraction [3]. <br/>
  * Checks hardward free space before recording to avoid running out of space. <br/>

* The RaspberryPI and camera setup 
<pre><p align="center">
<img src="https://user-images.githubusercontent.com/86133411/153816022-855bdc5d-ab93-4e00-a055-9b8bd01e90b8.png" width="283" height="258">            <img src="https://user-images.githubusercontent.com/86133411/153816013-82f2b5ec-0f48-4bc2-b36b-17212a190a31.png">
</p></pre>

* Me walking in front of the house to test the motion detection camera 
<pre><p align="center">
<img src="https://user-images.githubusercontent.com/86133411/153915136-0634f358-da64-494b-a0a8-3379ca0aaa0d.png" width="283" height="258">            <img src="https://user-images.githubusercontent.com/86133411/153915151-2d1e5e6d-fa98-4253-ac94-987447ec40a2.png">
</p></pre>

<br/><br/>

# References 
[1] Vishwesh Shrimali, https://learnopencv.com/install-opencv-4-on-raspberry-pi/. <br/>
[2] Adrian Rosebrock, https://www.pyimagesearch.com/2019/09/16/install-opencv-4-on-raspberry-pi-4-and-raspbian-buster/. <br/>
[3] Chris Dahms, https://www.youtube.com/watch?v=7SM5OD2pZKY&t=0s. <br/>
