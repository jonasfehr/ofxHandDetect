//
//  ofxHand.cpp
//
//  Created by Jonas Fehr on 02/01/16.
//
//

#include "Hand.h"


void ofxHand::draw()
{
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofDrawCircle(palmCenter, 20);
    
    // ofCircle(centroid, 10);
    
    ofDrawLine(palmCenter, armBase);
    
    // cout << ofToString(armBase.x)<<" : "<<ofToString(armBase.y) << "\n";
    
    
    ofSetColor(0, 0, 255);
    //
    boundaryPoly.draw();
    
}