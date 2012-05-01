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

cocos2d::SEL_MenuHandler CCBClassGenerator::createCustomSelectorWithName (const char * selectorNameCString) {
    if (strcmp(selectorNameCString, "pressedButton:") == 0) {
        CCLog(" is creating a *pressedButton:* method...");
        return menu_selector(HelloCocosBuilder::pressedButton);
    }
    
    return NULL;
}

cocos2d::CCLayer * CCBClassGenerator::createCustomCCLayerGradientClassWithName (const char * classNameCString) {
    return NULL;
}

cocos2d::CCLayer * CCBClassGenerator::createCustomCCLayerColorClassWithName (const char * classNameCString) {
    return NULL;
}

cocos2d::CCLayer * CCBClassGenerator::createCustomCCNodeClassWithName (const char * classNameCString) {
    return NULL;
}

bool CCBClassGenerator::respondsToSelectorDidLoadFromCCB (cocos2d::CCNode * node) {
    if (dynamic_cast<HelloCocosBuilder *>(node) != NULL) {
        
        HelloCocosBuilder *temp = dynamic_cast<HelloCocosBuilder *>(node);
        temp->didLoadFromCCB();

        return true;
    } else {
        return false;
    }
}

bool CCBClassGenerator::assignIvarToParent(cocos2d::CCNode * ivar, cocos2d::CCObject * parent, const char * assignmentNameCString) {
    if (dynamic_cast<HelloCocosBuilder *>(parent) != NULL) {
        if (strcmp(assignmentNameCString, "sprtBurst") == 0) {
            CCLog(" assign: sprtBurst");
            ((HelloCocosBuilder *)parent)->setSprtBurst(dynamic_cast<CCSprite *>(ivar));
            //((HelloCocosBuilder *)parent)->setSprtIcon(dynamic_cast<CCSprite *>(ivar));
            return true;
        } else if (strcmp(assignmentNameCString, "sprtIcon") == 0) {
            CCLog(" assign: sprtIcon");

            ((HelloCocosBuilder *)parent)->setSprtIcon(dynamic_cast<CCSprite *>(ivar));
            //((HelloCocosBuilder *)parent)->setSprtBurst(dynamic_cast<CCSprite *>(ivar));

            return true;
        }
    }
    
    return false;
}

