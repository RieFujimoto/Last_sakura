//
//  sakura.cpp
//  Last_sakura
//
//  Created by 藤本理英 on 2019/05/19.
//

#include "sakura.hpp"

//--------------------------------------------------------------
void sakura::setup(){
    ofSetBackgroundColor(0);
    //    ofSetFrameRate();
    move = ofVec3f(0, 0, 0);
    //    cout << ofGetHeight() << ", " << ofGetWidth() << endl;
}

//--------------------------------------------------------------
void sakura::applyForce(ofVec3f force){
    acceleration += force;
}

//--------------------------------------------------------------
void sakura::update(){
    
    velocity += acceleration;
    velocity.limit(maxspeed);
    location += velocity;
    
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
    
    //    move.x  = move.x + ofRandom(-5, 5);
    //    move.y  = move.y + ofRandom(-5, 5);
    //    move.z  = move.z + ofRandom(-5, 5);
}

//--------------------------------------------------------------
void sakura::draw(){
    location = ofVec3f(move.x, move.y, move.z);
   
    maxspeed = ofRandom(10) + 2;
    maxforce = ofRandom(0.002) + 0.001;
    
    wingSpeed = ofRandom(1) + 1;
    wingTheta = 30;
    wingUp = true;
    
    size = ofRandom(0) + 15.0;
    
    cam.begin();
    
    ofPushMatrix();
    ofTranslate(location);
    
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
