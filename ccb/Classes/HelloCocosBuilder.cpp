#include "HelloCocosBuilder.h"

using namespace cocos2d;

void HelloCocosBuilder::pressedButton(CCObject *pSender) {
    sprtIcon->stopAllActions();    
    sprtIcon->setRotation(0);
    sprtIcon->runAction(CCRotateBy::actionWithDuration(1.f, 360));
}

void HelloCocosBuilder::didLoadFromCCB() {
    sprtBurst->runAction(CCRepeatForever::actionWithAction(CCRotateBy::actionWithDuration(5.0f, 360)));
}

