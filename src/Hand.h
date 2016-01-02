//
//  Hand.h
//
//  Created by Jonas Fehr on 02/01/16.
//
//

#include "ofMain.h"
#include "ofxCV.h"
//#include "ofxCvMin.h"

class Hand
{
public:
    ofVec2f armBase; // Base of the arm (where the arm intersects the edge of the table)
    int indxBaseStart;
    int indxBaseEnd;
    
    ofPolyline boundaryPoly;
    
    vector<ofPoint> boundary;
    
    ofVec2f palmCenter;
    ofVec2f centroid;
    
    
    cv::Mat armBlob = cv::Mat::zeros( cvSize(512, 424), CV_8UC1 );
    cv::Mat armBlob2 = cv::Mat::zeros( cvSize(512, 424), CV_8UC1 );
    
    
    void draw(){
            ofSetColor(255, 0, 0);
            ofNoFill();
            ofDrawCircle(palmCenter, 20);
            // ofDrawCircle(centroid, 10);
            ofDrawLine(palmCenter, armBase);
        
            ofSetColor(0, 0, 255);
            boundaryPoly.draw();
    };
    
    
    
};
