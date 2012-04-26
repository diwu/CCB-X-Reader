//
//  CCBReader.cpp
//  ccb
//
//  Created by diwwu on 4/26/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "CCBReader.h"

using namespace cocos2d;

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
    
    CCMessageBox(classCString, "class");
    
    return NULL;
}

