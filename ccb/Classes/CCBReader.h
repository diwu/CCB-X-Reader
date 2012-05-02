//
//  CCBReader.h
//  ccb
//
//  Created by diwwu on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef ccb_CCBReader_h
#define ccb_CCBReader_h

#include "cocos2d.h"

enum {
    kCCBMemberVarAssignmentTypeNone = 0,
    kCCBMemberVarAssignmentTypeDocumentRoot = 1,
    kCCBMemberVarAssignmentTypeOwner = 2,
};

class CCBReader {
    
public:
    static cocos2d::CCScene * sceneWithNodeGraphFromFile(const char * file);
    static cocos2d::CCScene * sceneWithNodeGraphFromFileOwner(const char * file, cocos2d::CCObject * owner);

    static cocos2d::CCNode * nodeGraphFromFile(const char * file);
    static cocos2d::CCNode * nodeGraphFromFileOwner(const char * file, cocos2d::CCObject * owner);

    static cocos2d::CCNode * nodeGraphFromDictionary(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict);
    static cocos2d::CCNode * nodeGraphFromDictionaryOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCObject * owner);
    static cocos2d::CCNode * nodeGraphFromDictionaryExtraPropsAssetsDirOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner);
    
    static cocos2d::CCNode * ccObjectFromDictionaryExtraPropsAssetsDirOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner);
    static cocos2d::CCNode * ccObjectFromDictionaryExtraPropsAssetsDirOwnerRoot(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner, cocos2d::CCNode * root);
    
    static void setPropsForNodePropsExtraProps (cocos2d::CCNode *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForParticleSystemPropsExtraProps (cocos2d::CCParticleSystem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForMenuItemPropsExtraProps(cocos2d::CCMenuItem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForMenuItemImagePropsExtraProps(cocos2d::CCMenuItemImage *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForLayerPropsExtraProps (cocos2d::CCLayer *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForMenuPropsExtraProps (cocos2d::CCMenu *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForLabelBMFontPropsExtraProps (cocos2d::CCLabelBMFont *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForSpritePropsExtraProps (cocos2d::CCSprite *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForLayerColorPropsExtraProps (cocos2d::CCLayerColor *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);
    static void setPropsForLayerGradientPropsExtraProps (cocos2d::CCLayerGradient *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps);

    static int intValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static float floatValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static bool boolValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static cocos2d::CCPoint pointValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static cocos2d::CCSize sizeValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static cocos2d::ccColor3B color3ValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static cocos2d::ccColor4F color4fValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
    static cocos2d::ccBlendFunc blendFuncValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key);
};

#endif
