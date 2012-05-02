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
    
    CCSprite *tempSprite = dynamic_cast<CCSprite *>(node);
    CCMenuItemImage *tempMenuItemImage = dynamic_cast<CCMenuItemImage *>(node);
    CCLabelBMFont *tempLabelBMFont = dynamic_cast<CCLabelBMFont *>(node);
    
    if ( !tempSprite && !tempMenuItemImage && !tempLabelBMFont) {
        node->setContentSize(CCBReader::sizeValFromDictForKey(props, "contentSize"));
    }
    
    node->setScaleX(CCBReader::floatValFromDictForKey(props, "scaleX"));
    node->setScaleY(CCBReader::floatValFromDictForKey(props, "scaleY"));
    node->setAnchorPoint(CCBReader::pointValFromDictForKey(props, "anchorPoint"));
    node->setRotation(CCBReader::floatValFromDictForKey(props, "rotation"));
    node->setIsRelativeAnchorPoint(CCBReader::boolValFromDictForKey(props, "isRelativeAnchorPoint"));
    node->setIsVisible(CCBReader::boolValFromDictForKey(props, "visible"));
    
    if (extraProps) {
        // To be implemented soon...
    } else {
        node->setTag(CCBReader::intValFromDictForKey(props, "tag"));
    }
}

void CCBReader::setPropsForParticleSystemPropsExtraProps (cocos2d::CCParticleSystem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setEmitterMode(CCBReader::intValFromDictForKey(props, "emitterMode"));
    node->setEmissionRate(CCBReader::floatValFromDictForKey(props, "emissionRate"));
    node->setDuration(CCBReader::floatValFromDictForKey(props, "duration"));
    node->setPosVar(CCBReader::pointValFromDictForKey(props, "posVar"));
    node->setTotalParticles(CCBReader::intValFromDictForKey(props, "totalParticles"));
    node->setLife(CCBReader::floatValFromDictForKey(props, "life"));
    node->setLifeVar(CCBReader::floatValFromDictForKey(props, "lifeVar"));
    node->setStartSize(CCBReader::intValFromDictForKey(props, "startSize"));
    node->setStartSizeVar(CCBReader::intValFromDictForKey(props, "startSizeVar"));
    node->setEndSize(CCBReader::intValFromDictForKey(props, "endSize"));
    node->setEndSpinVar(CCBReader::intValFromDictForKey(props, "endSizeVar"));
    
    if (dynamic_cast<CCParticleSystemQuad *>(node) != NULL) {
        node->setStartSpin(intValFromDictForKey(props, "startSpin"));
        node->setStartSpinVar(intValFromDictForKey(props, "startSpinVar"));
        node->setEndSpin(intValFromDictForKey(props, "endSpin"));
        node->setEndSpinVar(intValFromDictForKey(props, "endSpinVar"));
    }
    
    node->setStartColor(CCBReader::color4fValFromDictForKey(props, "startColor"));
    node->setStartColorVar(CCBReader::color4fValFromDictForKey(props, "startColorVar"));
    node->setEndColor(CCBReader::color4fValFromDictForKey(props, "endColor"));
    node->setEndColorVar(CCBReader::color4fValFromDictForKey(props, "endColorVar"));
    node->setBlendFunc(CCBReader::blendFuncValFromDictForKey(props, "blendFunc"));
    
    if (node->getEmitterMode() == kCCParticleModeGravity) {
        node->setGravity(CCBReader::pointValFromDictForKey(props, "gravity"));
        node->setAngle(CCBReader::intValFromDictForKey(props, "angle"));
        node->setAngleVar(CCBReader::intValFromDictForKey(props, "angleVar"));
        node->setSpeed(CCBReader::intValFromDictForKey(props, "speed"));
        node->setSpeedVar(CCBReader::intValFromDictForKey(props, "speedVar"));
        node->setTangentialAccel(CCBReader::intValFromDictForKey(props, "tangentialAccel"));
        node->setTangentialAccelVar(CCBReader::intValFromDictForKey(props, "tangentialAccelVar"));
        node->setRadialAccel(CCBReader::intValFromDictForKey(props, "radialAccel"));
        node->setRadialAccelVar(CCBReader::intValFromDictForKey(props, "radialAccelVar"));
    } else {
        node->setStartRadius(intValFromDictForKey(props, "startRadius"));
        node->setStartRadiusVar(intValFromDictForKey(props, "startRadiusVar"));
        node->setEndRadius(intValFromDictForKey(props, "endRadius"));
        node->setEndRadiusVar(intValFromDictForKey(props, "endRadiusVar"));
        node->setRotatePerSecond(intValFromDictForKey(props, "rotatePerSecond"));
        node->setRotatePerSecondVar(intValFromDictForKey(props, "rotatePerSecondVar"));
    }
    
    if (extraProps) {
        // To be implemented soon...
    }
    
    node->setPositionType(kCCPositionTypeGrouped);
}
void CCBReader::setPropsForMenuItemPropsExtraProps(cocos2d::CCMenuItem *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setIsEnabled(CCBReader::boolValFromDictForKey(props, "isEnabled"));
    
    if (extraProps) {
        // To be implemented soon...
    }
}
void CCBReader::setPropsForMenuItemImagePropsExtraProps(cocos2d::CCMenuItemImage *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    if (extraProps) {
        // To be implemented soon...
    }
}
void CCBReader::setPropsForLayerPropsExtraProps (cocos2d::CCLayer *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    if (extraProps) {
        // To be implemented soon...
    } else {
        node->setIsTouchEnabled(CCBReader::boolValFromDictForKey(props, "touchEnabled"));
        node->setIsAccelerometerEnabled(CCBReader::boolValFromDictForKey(props, "accelerometerEnabled"));
    }
}
void CCBReader::setPropsForMenuPropsExtraProps (cocos2d::CCMenu *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    if (extraProps) {
        // To be implemented soon...
    }
}
void CCBReader::setPropsForLabelBMFontPropsExtraProps (cocos2d::CCLabelBMFont *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setOpacity(CCBReader::intValFromDictForKey(props, "opacity"));
    node->setColor(CCBReader::color3ValFromDictForKey(props, "color"));
    
    if (extraProps) {
        // To be implemented soon...
    }
}
void CCBReader::setPropsForSpritePropsExtraProps (cocos2d::CCSprite *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setOpacity(CCBReader::intValFromDictForKey(props, "opacity"));
    node->setColor(CCBReader::color3ValFromDictForKey(props, "color"));
    node->setFlipX(CCBReader::boolValFromDictForKey(props, "flipX"));
    node->setFlipY(CCBReader::boolValFromDictForKey(props, "flipY"));
    
    node->setBlendFunc(CCBReader::blendFuncValFromDictForKey(props, "blendFunc"));
    
    if (extraProps) {
        // To be implemented soon...
    }
}
void CCBReader::setPropsForLayerColorPropsExtraProps (cocos2d::CCLayerColor *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    
    node->setColor(CCBReader::color3ValFromDictForKey(props, "color"));
    node->setOpacity(CCBReader::intValFromDictForKey(props, "opacity"));
    node->setBlendFunc(CCBReader::blendFuncValFromDictForKey(props, "blendFunc"));
}
void CCBReader::setPropsForLayerGradientPropsExtraProps (cocos2d::CCLayerGradient *node, cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * props, cocos2d::CCMutableDictionary<std::string, cocos2d::CCObject*> * extraProps) {
    node->setStartColor(CCBReader::color3ValFromDictForKey(props, "color"));
    node->setStartOpacity(CCBReader::intValFromDictForKey(props, "opacity"));
    node->setEndColor(CCBReader::color3ValFromDictForKey(props, "endColor"));
    node->setEndOpacity(CCBReader::intValFromDictForKey(props, "endOpacity"));
    node->setVector(CCBReader::pointValFromDictForKey(props, "vector"));
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

    const char *customClass;
    
    if (props->objectForKey("customClass") == NULL) {
        customClass = "";
    } else {
        customClass = (((CCString*) (props->objectForKey("customClass"))) -> toStdString()).c_str();
    }
    
    if (extraProps) { 
        customClass = NULL;
    }
    
    CCNode * node;
    
    if (strcmp(classCString, "CCParticleSystem") == 0) {
                
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
    else if (strcmp(classCString, "CCMenuItemImage") == 0)
    {
        string spriteFileNormal = path + (((CCString*) (props->objectForKey("spriteFileNormal"))) -> toStdString()).c_str();
        string spriteFileSelected = path + (((CCString*) (props->objectForKey("spriteFileSelected"))) -> toStdString()).c_str();
        string spriteFileDisabled = path + (((CCString*) (props->objectForKey("spriteFileDisabled"))) -> toStdString()).c_str();
        
        CCSprite* spriteNormal;
        CCSprite* spriteSelected;
        CCSprite* spriteDisabled;
        
        string spriteSheetFile;
        if (props->objectForKey("spriteFramesFile") != NULL) {
            spriteSheetFile = ((CCString*) (props->objectForKey("spriteFramesFile"))) -> toStdString();
        }
        
        if ( ! spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0) {
            spriteSheetFile = path + spriteSheetFile;
        }
        
        if ( ! spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0) {
            
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(spriteSheetFile.c_str());

            //Since Cocos2d-X didn't implemented the Exception thing, we abandoned the try/catch code here
            spriteNormal = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileNormal"))) -> toStdString().c_str());                
            spriteSelected = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileSelected"))) -> toStdString().c_str());
            spriteDisabled = CCSprite::spriteWithSpriteFrameName(((CCString*) (props->objectForKey("spriteFileDisabled"))) -> toStdString().c_str());
        }
        else
        {
            spriteNormal = CCSprite::spriteWithFile(spriteFileNormal.c_str());
            spriteSelected = CCSprite::spriteWithFile(spriteFileSelected.c_str());
            spriteDisabled = CCSprite::spriteWithFile(spriteFileDisabled.c_str());
        }
        
        if (!spriteNormal) {
            spriteNormal = CCSprite::spriteWithFile("missing-texture.png");
        }
        if (!spriteSelected) {
            spriteSelected = CCSprite::spriteWithFile("missing-texture.png"); 
        }
        if (!spriteDisabled) {
            spriteDisabled = CCSprite::spriteWithFile("missing-texture.png");
        }

        CCObject* target = NULL;
        SEL_MenuHandler selector = NULL;

        if (!extraProps)
        {
            int targetType = atoi((((CCString*) (props->objectForKey("target"))) -> toStdString()).c_str());
            
            if (targetType == kCCBMemberVarAssignmentTypeDocumentRoot) target = root;
            else if (targetType == kCCBMemberVarAssignmentTypeOwner) target = owner;

            const char * selectorName = (((CCString*) (props->objectForKey("selector"))) -> toStdString()).c_str();
            if (selectorName && strcmp(selectorName, "") != 0 && target)
            {
                selector = CCBClassGenerator::createCustomSelectorWithName(selectorName);
            }
            if (!selector) target = NULL;
        }

        node = (CCNode *)CCMenuItemImage::itemFromNormalImage(spriteFileNormal.c_str(), spriteFileSelected.c_str(), spriteFileDisabled.c_str(), target, selector);
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForMenuItemPropsExtraProps((CCMenuItem *)node, props, extraProps);
        CCBReader::setPropsForMenuItemImagePropsExtraProps((CCMenuItemImage *)node, props, extraProps);
    }
    else if (strcmp(classCString, "CCMenu") == 0)    
    {
        node = CCMenu::menuWithItems(NULL);
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForLayerPropsExtraProps((cocos2d::CCLayer *)node, props, extraProps);
        CCBReader::setPropsForMenuPropsExtraProps((cocos2d::CCMenu *)node, props, extraProps);
    }
    else if (strcmp(classCString, "CCLabelBMFont") == 0)
    {

        string fontFile = path + (((CCString*) (props->objectForKey("fontFile"))) -> toStdString()).c_str();
        string stringFile = path + (((CCString*) (props->objectForKey("string"))) -> toStdString()).c_str();
        node = CCLabelBMFont::labelWithString(stringFile.c_str(), fontFile.c_str());

        //Since Cocos2d-X didn't implemented the Exception thing, we abandoned the try/catch code here        
        if ( ! node) {
            node = CCLabelBMFont::labelWithString(stringFile.c_str(), "missing-font.fnt");
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForLabelBMFontPropsExtraProps((CCLabelBMFont *)node, props, extraProps);
    }
    else if (strcmp(classCString, "CCSprite") == 0)
    {
        string spriteFile = path + (((CCString*) (props->objectForKey("spriteFile"))) -> toStdString()).c_str();        
        string spriteSheetFile;
        if (props->objectForKey("spriteFramesFile") == NULL) {
            spriteSheetFile = "";
        } else {
            spriteSheetFile = path + (((CCString*) (props->objectForKey("spriteFramesFile"))) -> toStdString()).c_str();
        }
        if ( !spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0) {
            spriteSheetFile = path + (((CCString*) (props->objectForKey("spriteFramesFile"))) -> toStdString()).c_str();
        }
        
        if ( !spriteSheetFile.empty() && strcmp(spriteSheetFile.c_str(), "") != 0 )
        {
            //Since Cocos2d-X didn't implemented the Exception thing, we abandoned the try/catch code here        
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(spriteSheetFile.c_str());
            node = CCSprite::spriteWithSpriteFrameName((((CCString*) (props->objectForKey("spriteFile"))) -> toStdString()).c_str());
        }
        else
        {
            node = CCSprite::spriteWithFile(spriteFile.c_str());
        }
        
        if ( ! node) {
            node = CCSprite::spriteWithFile("missing-texture.png");
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForSpritePropsExtraProps((cocos2d::CCSprite *)node, props, extraProps);                
    }
    else if (strcmp(classCString, "CCLayerGradient") == 0) 
    {
        if (customClass != NULL && strcmp(customClass, "") != 0) {
            node = CCBClassGenerator::createCustomCCLayerGradientClassWithName(customClass);
        } else {
            node = NULL;
        }
        
        if (node != NULL) {
            CCLayerGradient * temp = dynamic_cast<CCLayerGradient *>(node);
            if (temp != NULL) {
                temp->init();
                temp->autorelease();
            }
        } else {
            node = CCLayerGradient::node();
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForLayerPropsExtraProps((CCLayer *) node, props, extraProps);
        CCBReader::setPropsForLayerColorPropsExtraProps((CCLayerColor *)node, props, extraProps);
        CCBReader::setPropsForLayerGradientPropsExtraProps((CCLayerGradient *) node, props, extraProps);
    }
    else if (strcmp(classCString, "CCLayerColor") == 0)
    //else if ([class isEqualToString:@"CCLayerColor"])
    {
        if (customClass != NULL && strcmp(customClass, "") != 0) {
            node = CCBClassGenerator::createCustomCCLayerColorClassWithName(customClass);
        } else {
            node = NULL;
        }
        
        if (node != NULL) {
            CCLayerColor * temp = dynamic_cast<CCLayerColor *>(node);
            if (temp != NULL) {
                temp->init();
                temp->autorelease();
            }
        } else {
            node = CCLayerColor::node();
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForLayerPropsExtraProps((CCLayer *) node, props, extraProps);
        CCBReader::setPropsForLayerColorPropsExtraProps((CCLayerColor *)node, props, extraProps);
    }
    else if (strcmp(classCString, "CCLayer") == 0)
    {
        CCLayer *tempLayer = CCBClassGenerator::createCustomCCLayerClassWithName(customClass);
        tempLayer->init();
        tempLayer->autorelease();
        
        node = dynamic_cast<CCNode *>(tempLayer);
        
        if (!node) {
            node = CCLayer::node();
        } else {
            CCLog(" HelloWorldBuilder cclayer created ok...");
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
        CCBReader::setPropsForLayerPropsExtraProps((cocos2d::CCLayer *)node, props, extraProps);
    }
    else if (strcmp(classCString, "CCNode") == 0)
    {
        if (customClass != NULL && strcmp(customClass, "") != 0) {
            node = CCBClassGenerator::createCustomCCNodeClassWithName(customClass);
        } else {
            node = NULL;
        }
        
        if (node != NULL) {
            CCNode * temp = dynamic_cast<CCNode *>(node);
            if (temp != NULL) {
                temp->autorelease();
            }
        } else {
            node = CCNode::node();
        }
        
        CCBReader::setPropsForNodePropsExtraProps(node, props, extraProps);
    }
    if (!root) {
        root = node;
    }
    
    // Add children
    for (int i = 0; i < children->count(); i++)
    {
        cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * childDict = (cocos2d::CCDictionary<std::string, cocos2d::CCObject*> *) children->getObjectAtIndex(i);
        CCNode *child = CCBReader::ccObjectFromDictionaryExtraPropsAssetsDirOwnerRoot(childDict, extraProps, path, owner, root);

        int zOrder = atoi((((CCString *)(((cocos2d::CCDictionary<std::string, cocos2d::CCObject*> *)childDict->objectForKey("properties"))->objectForKey("zOrder")))->toStdString()).c_str());

        if (child && node)
        {
            node->addChild(child, zOrder);
        }
        else
        {
            CCLog("WARNING! Failed to add child=%s to node=%s",child,node);
        }
        
    }
    
    if ( ! extraProps) {

        string assignmentName;
        if (props->objectForKey("memberVarAssignmentName") != NULL) {
            assignmentName= ((CCString*) (props->objectForKey("memberVarAssignmentName"))) -> toStdString();
        } else {
            assignmentName = "";
        }

        int assignmentType = ((CCString*) (props->objectForKey("memberVarAssignmentType"))) -> toInt();
        
        if ( !assignmentName.empty() && strcmp(assignmentName.c_str(), "") != 0 && assignmentType) {
            CCObject * assignTo = NULL;
            
            if (assignmentType == kCCBMemberVarAssignmentTypeOwner) {
                assignTo = owner;
            } else {
                assignTo = root;
            }
            
            if (assignTo != NULL) {
                CCBClassGenerator::assignIvarToParent(node, assignTo, assignmentName.c_str());
            }
        }
        
        CCBClassGenerator::respondsToSelectorDidLoadFromCCB(node);

    }
    
    
    return node;
}

cocos2d::CCPoint CCBReader::pointValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * x_ccString = arr->getObjectAtIndex(0);
    CCString * y_ccString = arr->getObjectAtIndex(1);

    float x = atof(x_ccString->toStdString().c_str());
    float y = atof(y_ccString->toStdString().c_str());
        
    return ccp(x, y);
}

cocos2d::CCSize CCBReader::sizeValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * w_ccString = arr->getObjectAtIndex(0);
    CCString * h_ccString = arr->getObjectAtIndex(1);
    
    float w = atof(w_ccString->toStdString().c_str());
    float h = atof(h_ccString->toStdString().c_str());
        
    return CCSizeMake(w, h);
}

float CCBReader::floatValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    return atof(((CCString *)dict->objectForKey(key))->toStdString().c_str());
}

bool CCBReader::boolValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    return atoi(((CCString *)dict->objectForKey(key))->toStdString().c_str());
}
int CCBReader::intValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    return atoi(((CCString *)dict->objectForKey(key))->toStdString().c_str());    
}
cocos2d::ccColor4F CCBReader::color4fValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * r_ccString = arr->getObjectAtIndex(0);
    CCString * g_ccString = arr->getObjectAtIndex(1);
    CCString * b_ccString = arr->getObjectAtIndex(2);
    CCString * a_ccString = arr->getObjectAtIndex(3);
    
    float r = r_ccString->toFloat();
    float g = g_ccString->toFloat();
    float b = b_ccString->toFloat();
    float a = a_ccString->toFloat();
    
    ccColor4F color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
        
    return color;

}
cocos2d::ccBlendFunc CCBReader::blendFuncValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * src_string = arr->getObjectAtIndex(0);
    CCString * dst_string = arr->getObjectAtIndex(1);
    int src = src_string->toInt();
    int dst = dst_string->toInt();
    ccBlendFunc blendFunc;
    blendFunc.src = src;
    blendFunc.dst = dst;
    
    return blendFunc;
}

cocos2d::ccColor3B CCBReader::color3ValFromDictForKey(cocos2d::CCDictionary<std::string, cocos2d::CCObject*> * dict, std::string key) {
    
    CCMutableArray<CCString *> * arr = (CCMutableArray<CCString *> *)dict->objectForKey(key);
    CCString * r_ccString = arr->getObjectAtIndex(0);
    CCString * g_ccString = arr->getObjectAtIndex(1);
    CCString * b_ccString = arr->getObjectAtIndex(2);
    
    int r = r_ccString->toInt();
    int g = g_ccString->toInt();
    int b = b_ccString->toInt();
        
    return ccc3(r, g, b);
}
