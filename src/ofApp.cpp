#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    //    ofSetFrameRate();
    move = ofVec3f(0, 0, 0);
    //    cout << ofGetHeight() << ", " << ofGetWidth() << endl;
}

//--------------------------------------------------------------
void ofApp::seek(ofVec3f target){
    ofVec3f desired = target - location;
    desired.normalize();
    desired *= maxspeed;
    
    ofVec3f steer = desired - velocity;
    steer.limit(maxforce);
    
    applyForce(steer);
}

//--------------------------------------------------------------
void ofApp::applyForce(ofVec3f force){
    acceleration += force;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    acceleration *= 0;
    
    if (wingTheta < -60) {
        wingUp = true;
    }
    if (wingTheta > 60) {
        wingUp = false;
    }
    if (wingUp) {
        wingTheta += wingSpeed;
    } else {
        wingTheta -= wingSpeed;
    }
    
    move.x  = -ofGetWidth()/2 +ofGetFrameNum()*0.1;
    move.y  = ofGetHeight()/2 - ofGetFrameNum()*0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    location = ofVec3f(move.x, move.y, move.z);
    
    //    maxspeed = ofRandom(10) + 2;
    //    maxforce = ofRandom(0.002) + 0.001;
    //    wingSpeed = ofRandom(1) + 1;
    //    wingSpeed = 1;
    wingTheta = 30;
    wingUp = true;
    
    size = ofRandom(0) + 50.0;
    
    cam.begin();
    
    ofPushMatrix();
    ofTranslate(location);
    
    ofRotateDeg(ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1, ofGetFrameNum()*0.1);
    ofSetColor(200, 160, 200, 200);
    
    // left wing
    ofPushMatrix();
    
    ofBeginShape();
    ofVertex(0, 0, 0);
    ofVertex(size*0.4, 0, 0);
    ofVertex(size*0.37, size*0.25, 0);
    ofVertex(size*0.2, size*0.5, 0);
    ofVertex(0, size*0.3, 0);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(0, 0, 0);
    ofVertex(size*0.4, 0, 0);
    ofVertex(size*0.37, -size*0.2, 0);
    ofVertex(size*0.2, -size*0.4, 0);
    ofVertex(0, -size*0.6, 0);
    ofEndShape();
    
    ofPopMatrix();
    
    // rigtht wing
    ofPushMatrix();
    ofRotateYDeg(-wingTheta);
    
    ofBeginShape();
    ofVertex(0, 0, 0);
    ofVertex(-size*0.4, 0, 0);
    ofVertex(-size*0.37, size*0.25, 0);
    ofVertex(-size*0.2, size*0.5, 0);
    ofVertex(0, size*0.3, 0);
    ofEndShape();
    
    ofBeginShape();
    ofVertex(0, 0, 0);
    ofVertex(-size*0.4, 0, 0);
    ofVertex(-size*0.37, -size*0.2, 0);
    ofVertex(-size*0.2, -size*0.4, 0);
    ofVertex(0, -size*0.6, 0);
    ofEndShape();
    
    ofPopMatrix();
    
    ofPopMatrix();
    
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
//    move.x = x;
//    move.y = y;
}

