#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    move = ofVec2f(0, 0);
    //    cout << ofGetHeight() << ", " << ofGetWidth() << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    move.x = ofGetFrameNum()*0.1;
    move.y = ofGetFrameNum()*0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofPushStyle();
//    ofRotateDeg(ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1);
//    draw_sakura(50, 50, 100);
//    ofPopStyle();
//
//    ofPushStyle();
//    ofRotateDeg(-ofGetFrameNum()*0.2, ofGetFrameNum()*0.3, ofGetFrameNum()*0.1, ofGetFrameNum()*0.2);
//    draw_sakura(100, 100, 200);
//    ofPopStyle();
    
    draw_sakura(50, 50, 100);
}

//--------------------------------------------------------------
void ofApp::draw_sakura(int x, int y, int big){
    location = ofVec2f(x + move.x, y + move.y);
//    location = ofVec2f(x , y);
    
    size = ofRandom(0) + big;
    
    ofPushMatrix();
    ofTranslate(location);
    
    ofSetColor(250, 190, 230, 200);

    ofRotateDeg(ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1);
    
    ofPushMatrix();
    
    ofBeginShape();
    ofVertex(size*0.4, 0, 0);
    ofVertex(size*0.37, size*0.25, 0);
    ofVertex(size*0.3, size*0.38, 0);
    ofVertex(size*0.2, size*0.5, 0);
    ofVertex(0, size*0.3, 0);
    ofVertex(-size*0.2, size*0.5, 0);
    ofVertex(-size*0.3, size*0.38, 0);
    ofVertex(-size*0.37, size*0.25, 0);
    ofVertex(-size*0.4, 0, 0);
    ofVertex(-size*0.37, -size*0.2, 0);
    ofVertex(-size*0.23, -size*0.4, 0);
    ofVertex(0, -size*0.6, 0);
    ofVertex(size*0.23, -size*0.4, 0);
    ofVertex(size*0.37, -size*0.2, 0);
    ofEndShape();
    
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouse.x = x;
    mouse.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
//    mouseX = x;
//    mouseY = y;
}

