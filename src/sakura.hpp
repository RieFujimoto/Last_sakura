//
//  sakura.hpp
//  Last_sakura
//
//  Created by 藤本理英 on 2019/05/19.
//

#ifndef sakura_hpp
#define sakura_hpp

#include <stdio.h>
#include "ofMain.h"

class sakura{
public:
    sakura();
    
    void setup();
    void applyForce(ofVec3f force);
    void update();
    void draw();
    
    
};
#endif /* sakura_hpp */
