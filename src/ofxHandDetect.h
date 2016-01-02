//
//  ofxHandDetect.h
//
//  Created by Jonas Fehr on 15/11/15.
// based on https://www.youtube.com/watch?v=th8hUD7Ajg4
// by catsass19
//

#pragma once

#include "ofMain.h"
//#include "ofxOpenCv.h"
#include "ofxCv.h"

#include "Hand.h"


class ofxHandDetect
{
public:
    ofxHandDetect();
    
    void setup(ofImage* _input, int _w, int _h, int _nearThreshold, int _farThreshold);
    void update();
    
    // DRAW
   // void drawOverlay(int x = 0, int y =0);
    void drawOverlay(int x, int y, int w, int h);
    //void drawProcess(int x = 0, int y =0, int index = 1);
    void drawProcess(int x, int y, int w, int h, int index = 1);
    void createMask();
    void resetMask();
    void createGenericMask();

    // GET DATA
    vector<Hand> getHands();
    vector<ofVec2f> getHandPos();
    vector<ofPolyline> getContours();
    
    void setTresholds(int near, int far){
        nearThreshold = near;
        farThreshold = far;
    }
    
    //ofxCvGrayscaleImage output;

    
private:
    
    void getHandBoundries(cv::Mat _armBlobs);
    ofVec2f findArmBase(cv::Mat tableEdges, Hand &_hand);
    ofVec2f findPalmCenter(Hand _hand);
    
    int farThreshold;
    int nearThreshold;
    
    //CvCapture *capture;
    ofFbo outputImage;

    
    cv::Mat *frame;
    //IplImage* mask = cvCreateImage(cvSize(640,480),IPL_DEPTH_8U,1);
    cv::Mat depthImage;
    cv::Mat inputImage;
    cv::Mat output;
    
    int outputImageIndex = 1;


    cv::Mat activeAreaMask;

    ofVec2f handPosition;
    vector<Hand> hands;

    
    int width, height;
    ofImage* input;
    
    vector<vector<cv::Point> > contoursLocal;

};
