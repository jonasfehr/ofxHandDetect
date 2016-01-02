#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Setup GUI
    imageSetup.setName("imageSetup");
    imageSetup.add(nearThreshold.set("nearThreshold", 22, 0, 255));
    imageSetup.add(farThreshold.set("farThreshold", 56, 0, 255));
    
    gui.setup(imageSetup);
    guiShow = true;

    device.setup(0, true);
    device.setDepthClipping(0, 255);
    cam.setup(&device);
    
    detectHands.setup(&cam.getDepthImage(), cam.getDepthImage().getWidth(), cam.getDepthImage().getHeight(), nearThreshold, farThreshold);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    detectHands.update();
    
    detectHands.setTresholds(nearThreshold, farThreshold);    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    
    ofBackgroundGradient(ofColor(100), ofColor(200));
    cam.getDepthImage().draw(0, 0);
    device.getIrImage().draw(512,0);
  //  cam.getColorImage().draw(0, cam.getDepthImage().getHeight(), 1920/3, 1080/3);
    device.getRegImage().draw(512, 424);
    
    detectHands.drawOverlay(0,0,512,424);
    detectHands.drawProcess(0,424, 512, 424, imgIndx);
    
    detectHands.drawOverlay(512,424,512,424);

    
    if (guiShow)    gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r') {
        cam.beginRecording();
    }
    if (key == 'R') {
        cam.endRecording();
    }
    if (key == ' ') {
        if (!ofGetKeyPressed(OF_KEY_SHIFT)) {
            cam.play();
        }
        else {
            cam.pause();
        }
    }
    if (key == 'l') {
        ofFileDialogResult result = ofSystemLoadDialog("Choose a folder of recorded data", true, ofToDataPath(""));
        if (result.getPath() != "") {
            cam.setPlaybackPath(result.getPath());
        }
    }
    if (key == 'L') {
        cam.setLive();
    }
    if(key == 'e') {
        detectHands.createMask();
        
    }
    if(key == 'w') {
        detectHands.resetMask();
        
    }
    if(key == 'g') {
        detectHands.createGenericMask();
        
    }
    
    if(key == '1') {
        imgIndx = 1;
    }
    if(key == '2') {
        imgIndx = 2;
    }
    if(key == '3') {
        imgIndx = 3;
    }
    if(key == '4') {
        imgIndx = 4;
    }
    if(key == '5') {
        imgIndx = 5;
    }
    if(key == '6') {
        imgIndx = 6;
    }
    if(key == '7') {
        imgIndx = 7;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
