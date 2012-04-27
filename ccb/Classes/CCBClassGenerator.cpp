//
//  CCBClassGenerator.cpp
//  ccb
//
//  Created by diwwu on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "CCBClassGenerator.h"
#include "HelloCocosBuilder.h"

using namespace cocos2d;

cocos2d::CCLayer * CCBClassGenerator::createCustomCCLayerClassWithName (const char * classNameCString) {
    if (strcmp(classNameCString, "HelloCocosBuilder") == 0) {
        return dynamic_cast<CCLayer *>(new HelloCocosBuilder); 
    }
    
    return NULL;
}
