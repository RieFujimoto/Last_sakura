#pragma once

#include "ofMain.h"

#define NUM 100

class ofApp : public ofBaseApp{
    
public:
    ofVec2f location;
    ofVec2f move;
    ofVec2f mouse;
    float size;

    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y);
    void draw_sakura(int x, int y, int big);
    
//    ofEasyCam cam;
};

