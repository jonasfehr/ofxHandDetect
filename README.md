# ofxHandDetect
Hand/palm detection using a depthCamera.

Introduction
------------
The code was initially written to detect the palms which were moving above a kine of trunk (an open box in the size of a small table) The tracking is inspired and based on the work of KinectArms (http://hci.usask.ca/publications/view.php?id=286) and the work of Wei-chao Chen (陳威詔)’s master thesis “Real-Time Palm Tracking and Hand Gesture Estimation Based on Fore-Arm Contour” (http://pc01.lib.ntust.edu.tw/ETD-db/ETD-search/view_etd?URN=etd-0718111-154755)

The addon was used to create the installation "LichtGestalt #1" (http://www.jonasfehr.ch/?portfolio=lichtgestalt)

Dependencies
------------
needed addon:
- ofxCv (https://github.com/kylemcdonald/ofxCv.git)

the example was made using the new Kinect addon ofxDepthCamera and should be compatible to various depth Cameras. However, the example was built on OSX 10.11 using a Kinect V2. 
example needs additional addons:
- ofxDepthCamera (https://github.com/mattfelsen/ofxDepthCamera.git)

to runn the Kinect V2
- ofxMultiKinectV2
- ofxTurboJpeg
- ofxFastFboReader

interface (near and far clipping)
- ofxGui

Compatibility
------------
- supports current oF 0.9.0
- tested on MAC osx 10.11 using a Kinect V2

Known issues
------------
none

Usage
------------
if requestet I will write some additional infos for the usage.
please send me a mail: mail (at) jonasfehr.ch

Licence
-------
The code in this repository is available under the MIT License.