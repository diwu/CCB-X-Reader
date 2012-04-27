//
//  CCBClassGenerator.h
//  ccb
//
//  Created by diwwu on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ccb_CCBClassGenerator_h
#define ccb_CCBClassGenerator_h

#include "cocos2d.h"

class CCBClassGenerator {
    
public:
    static cocos2d::CCLayer * createCustomCCLayerClassWithName (const char * classNameCString);
};

#endif
