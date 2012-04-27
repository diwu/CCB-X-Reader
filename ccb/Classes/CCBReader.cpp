//
//  CCBReader.cpp
//  ccb
//
//  Created by diwwu on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "CCBReader.h"
#include "CCBClassGenerator.h"

using namespace cocos2d;

void CCBReader::setPropsForNodePropsExtraProps (cocos2d::CCNode *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setPosition(CCBReader::pointValFromDictForKey(props, "position"));
    
}
void CCBReader::setPropsForParticleSystemPropsExtraProps (cocos2d::CCParticleSystem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
}
void CCBReader::setPropsForMenuItemPropsExtraProps(cocos2d::CCMenuItem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
}
void CCBReader::setPropsForMenuItemImagePropsExtraProps(cocos2d::CCMenuItemImage *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
}

cocos2d::CCScene * CCBReader::sceneWithNodeGraphFromFile(const char * file) {
    return CCBReader::sceneWithNodeGraphFromFileOwner(file, NULL);
}
cocos2d::CCScene * CCBReader::sceneWithNodeGraphFromFileOwner(const char * file, cocos2d::CCObject * owner) {
    CCNode *node = CCBReader::nodeGraphFromFileOwner(file, owner);
    CCScene *scene = CCScene::node();
    
    scene->addChild(node);
    return scene;
}

cocos2d::CCNode * CCBReader::nodeGraphFromFile(const char * file) {
    return CCBReader::nodeGraphFromFileOwner(file, NULL);
}
cocos2d::CCNode * CCBReader::nodeGraphFromFileOwner(const char * file, cocos2d::CCObject * owner) {
    
    const char *path = CCFileUtils::fullPathFromRelativePath(file);
    CCDictionary<std::string, CCObject*> *plistDictionary = CCFileUtils::dictionaryWithContentsOfFile(path);
    
    return CCBReader::nodeGraphFromDictionaryOwner(plistDictionary, owner);
}

cocos2d::CCNode * CCBReader::nodeGraphFromDictionary(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict) {
    return CCBReader::nodeGraphFromDictionaryOwner(dict, NULL);
}
cocos2d::CCNode * CCBReader::nodeGraphFromDictionaryOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCObject * owner) {
    return CCBReader::nodeGraphFromDictionaryExtraPropsAssetsDirOwner(dict, NULL, "", owner);
}

cocos2d::CCNode * CCBReader::nodeGraphFromDictionaryExtraPropsAssetsDirOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner) {
    if ( ! dict) {
        CCLog("WARNING! Trying to load invalid file type");
        return NULL;
    }
    
    const char * fileType = (((CCString*) (dict->objectForKey("fileType"))) -> toStdString()).c_str();
    const char * fileVersionCString = (((CCString*) (dict->objectForKey("fileVersion"))) -> toStdString()).c_str();
    int fileVersionInt = atoi(fileVersionCString);
    
    if ( ! fileType) {
        CCLog("WARNING! Trying to load invalid file type");
        return NULL;
    }
    
    if (strcmp(fileType, "CocosBuilder") != 0) {
        CCLog("WARNING! Trying to load invalid file type");
        return NULL;
    }
    
    if (fileVersionInt > 2) {
        CCLog("WARNING! Trying to load file made with a newer version of CocosBuilder, please update the CCBReader class");
        return NULL;
    }
    
    CCDictionary<std::string, CCObject*> *nodeGraph = (CCDictionary<std::string, CCObject*> *)dict->objectForKey("nodeGraph");
    return CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwner(nodeGraph, extraProps, path, owner);
}

cocos2d::CCNode * CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwner(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner) {
    return CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwnerRoot(dict, extraProps, path, owner, NULL);
}

cocos2d::CCNode * CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwnerRoot(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps, std::string path, cocos2d::CCObject * owner, cocos2d::CCNode * root) {
    
    const char * classCString = (((CCString*) (dict->objectForKey("class"))) -> toStdString()).c_str();
    cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props = (CCDictionary<std::string, CCObject*> *)dict->objectForKey("properties");
    cocos2d::CCMutableArray<CCObject *> * children = (cocos2d::CCMutableArray<CCObject *> *)dict->objectForKey("children");
    const char *customClass = (((CCString*) (props->objectForKey("customClass"))) -> toStdString()).c_str();

    if (extraProps) { 
        customClass = NULL;
    }
    
    CCNode * node;
    
    if (strcmp(classCString, "CCParticleSystem") == 0) {
        
        CCLog("is processing CCParticleSystem...");
        
        const char *spriteFileNameCString = (((CCString*) (props->objectForKey("spriteFile"))) -> toStdString()).c_str();

        string spriteFile = path + spriteFileNameCString;
        
        CCParticleSystem * sys = new ARCH_OPTIMAL_PARTICLE_SYSTEM;
        
        sys->initWithTotalParticles(2048);
        sys->autorelease();
        
        sys->setTexture(CCTextureCache::sharedTextureCache()->addImage(spriteFile.c_str()));
        
        node = sys;
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForParticleSystemPropsExtraProps((CCParticleSystem *)node, props, extraProps);
        
    }
    else if (strcmp(classCString, "CCMenuItemImage") == 0) {
    {
        string spriteFileNormal = path + (((CCString*) (props->objectForKey("spriteFileNormal"))) -> toStdString()).c_str();
        //NSString* spriteFileNormal = [NSString stringWithFormat:@"%@%@", path, [props objectForKey:@"spriteFileNormal"]];
        string spriteFileSelected = path + (((CCString*) (props->objectForKey("spriteFileSelected"))) -> toStdString()).c_str();
        //NSString* spriteFileSelected = [NSString stringWithFormat:@"%@%@", path, [props objectForKey:@"spriteFileSelected"]];
        string spriteFileDisabled = path + (((CCString*) (props->objectForKey("spriteFileDisabled"))) -> toStdString()).c_str();
        //NSString* spriteFileDisabled = [NSString stringWithFormat:@"%@%@", path, [props objectForKey:@"spriteFileDisabled"]];
        
        CCSprite* spriteNormal;
        CCSprite* spriteSelected;
        CCSprite* spriteDisabled;
        
        string spriteSheetFile = ((CCString*) (props->objectForKey("spriteFramesFile"))) -> toStdString();
        //NSString* spriteSheetFile = [props objectForKey:@"spriteFramesFile"];
        
        if ( spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0) {
        //if (spriteSheetFile  && ![spriteSheetFile isEqualToString:@""]) {
            spriteSheetFile = path + spriteSheetFile;
            //spriteSheetFile = [NSString stringWithFormat:@"%@%@", path, spriteSheetFile];
        }
        
        if ( spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0) {
        //if (spriteSheetFile && ![spriteSheetFile isEqualToString:@""]) {
            
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(spriteSheetFile.c_str());
            //[[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:spriteSheetFile];

            //try {
            //@try {
                spriteNormal = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileNormal"))) -> toStdString().c_str());
                //spriteNormal = [CCSprite spriteWithSpriteFrameName:[props objectForKey:@"spriteFileNormal"]];
                
                spriteSelected = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileSelected"))) -> toStdString().c_str());
                //spriteSelected = [CCSprite spriteWithSpriteFrameName:[props objectForKey:@"spriteFileSelected"]];
                spriteDisabled = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileDisabled"))) -> toStdString().c_str());
                //spriteDisabled = [CCSprite spriteWithSpriteFrameName:[props objectForKey:@"spriteFileDisabled"]];
            //}
            //catch (NSException *exception)
            //@catch (NSException *exception)
            //{
                //spriteNormal = NULL;
                //spriteSelected = NULL;
                //spriteDisabled = NULL;
            //}
        }
        else
        {
            spriteNormal = CCSprite::spriteWithFile(spriteFileNormal.c_str());
            //spriteNormal = [CCSprite spriteWithFile:spriteFileNormal];
            spriteSelected = CCSprite::spriteWithFile(spriteFileSelected.c_str());
            //spriteSelected = [CCSprite spriteWithFile:spriteFileSelected];
            spriteDisabled = CCSprite::spriteWithFile(spriteFileDisabled.c_str());
            //spriteDisabled = [CCSprite spriteWithFile:spriteFileDisabled];
        }
        
        if (!spriteNormal) spriteNormal = CCSprite::spriteWithFile("missing-texture.png");
        //if (!spriteNormal) spriteNormal = [CCSprite spriteWithFile:@"missing-texture.png"];
        if (!spriteSelected) spriteSelected = CCSprite::spriteWithFile("missing-texture.png");
        //if (!spriteSelected) spriteSelected = [CCSprite spriteWithFile:@"missing-texture.png"];
        if (!spriteDisabled) spriteDisabled = CCSprite::spriteWithFile("missing-texture.png");
        //if (!spriteDisabled) spriteDisabled = [CCSprite spriteWithFile:@"missing-texture.png"];

        /*
        NSObject* target = NULL;
        SEL selector = NULL;
        if (!extraProps)
        {
            int targetType = [[props objectForKey:@"target"] intValue];
            if (targetType == kCCBMemberVarAssignmentTypeDocumentRoot) target = root;
            else if (targetType == kCCBMemberVarAssignmentTypeOwner) target = owner;
            
            NSString* selectorName = [props objectForKey:@"selector"];
            if (selectorName && ![selectorName isEqualToString:@""] && target)
            {
                selector = NSSelectorFromString(selectorName);
            }
            if (!selector) target = NULL;
            
            if (target && selector)
            {
                if (![target respondsToSelector:selector])
                {
                    NSLog(@"WARNING! CCMenuItemImage target doesn't respond to selector %@",selectorName);
                    target = NULL;
                    selector = NULL;
                }
            }
        }
         */
        
        /*
        node = [CCMenuItemImage itemFromNormalSprite:spriteNormal selectedSprite:spriteSelected disabledSprite:spriteDisabled target:target selector:selector];
         */
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        //[CCBReader setPropsForNode:node props:props extraProps:extraProps];
        CCBReader::setPropsForMenuItemPropsExtraProps((CCMenuItem *)node, props, extraProps);
        //[CCBReader setPropsForMenuItem:(CCMenuItem*)node props:props extraProps:extraProps];
        CCBReader::setPropsForMenuItemImagePropsExtraProps((CCMenuItemImage *)node, props, extraProps);
        //[CCBReader setPropsForMenuItemImage:(CCMenuItemImage*)node props:props extraProps:extraProps];
    }
    else if (strcmp(classCString, "CCLayer") == 0)
    {
        CCLog("is processing CCLayer...");

        CCLayer *tempLayer = CCBClassGenerator::createCustomCCLayerClassWithName(customClass);
        tempLayer->init();
        tempLayer->autorelease();
        
        node = dynamic_cast<CCNode *>(tempLayer);
                
        if (!node) {
            node = CCLayer::node();
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        
        /*
        [CCBReader setPropsForNode:node props:props extraProps:extraProps];
        [CCBReader setPropsForLayer:(CCLayer*)node props:props extraProps:extraProps];
         */
    }
    
    //=========================================================
    if (!root) {
        root = node;
    }
    
    // Add children
    for (int i = 0; i < children->count(); i++)
    {
        CCLog("adding child %d - total = %d", i, children->count());
        cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * childDict = (cocos2d::CCDictionary<std::string, cocos2d::CCObject*> *) children->getObjectAtIndex(i);
        CCNode *child = CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwnerRoot(childDict, extraProps, path, owner, root);

        int zOrder = atoi((((CCString *)(((cocos2d::CCDictionary<std::string, cocos2d::CCObject*> *)childDict->objectForKey("properties"))->objectForKey("zOrder")))->toStdString()).c_str());

        if (child && node)
        {

            //node->addChild(child, zOrder);
        }
        else
        {

            CCLog("WARNING! Failed to add child=%s to node=%s",child,node);
        }
        
    }
    
    return node;
}

//=============================================
cocos2d::CCPoint CCBReader::pointValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * x_ccString = arr->getObjectAtIndex(0);
    CCString * y_ccString = arr->getObjectAtIndex(1);

    float x = atof(x_ccString->toStdString().c_str());
    float y = atof(y_ccString->toStdString().c_str());
    
    CCLog("point value = %f, %f", x, y);
    
    return ccp(x, y);
}

