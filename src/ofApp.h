#pragma once

#include "ofMain.h"

#define NUM 100

class ofApp : public ofBaseApp{
    
public:
    ofVec3f location;
    ofVec3f velocity;
    ofVec3f acceleration;
    ofVec3f move;
    
    float maxspeed;
    float maxforce;
    
    float wingTheta;
    bool wingUp;
    float wingSpeed;
    float size;
    
    void setup();
    void seek(ofVec3f target);
    void applyForce(ofVec3f force);
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);
    
    ofEasyCam cam;
};

