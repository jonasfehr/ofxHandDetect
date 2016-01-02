#pragma once

#include "ofMain.h"

#include "ofxDepthCameraMultiKinectV2.h"
#include "ofxDepthCameraProvider.h"
#include "ofxGui.h"

#include "ofxHandDetect.h"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxDepthCameraMultiKinectV2 device;
    ofxDepthCameraProvider cam;
    
    ofxHandDetect   detectHands;
    int imgIndx = 1;
    
    // GUI / Controlpanel
    bool guiShow;
    ofxPanel gui;
    ofParameterGroup imageSetup;
    
    ofParameter<int>   nearThreshold;
    ofParameter<int>   farThreshold;
    
};
