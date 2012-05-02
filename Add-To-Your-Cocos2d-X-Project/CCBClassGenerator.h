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
    static cocos2d::SEL_MenuHandler createCustomSelectorWithName (const char * selectorNameCString);
    static cocos2d::CCLayer * createCustomCCLayerGradientClassWithName (const char * classNameCString);
    static cocos2d::CCLayer * createCustomCCLayerColorClassWithName (const char * classNameCString);
    static cocos2d::CCLayer * createCustomCCNodeClassWithName (const char * classNameCString);
    static bool respondsToSelectorDidLoadFromCCB (cocos2d::CCNode * node);
    static bool assignIvarToParent(cocos2d::CCNode * ivar, cocos2d::CCObject * parent, const char * assignmentNameCString);
};

#endif
