#ifndef __HELLOCOCOSBUILDER_H_
#define __HELLOCOCOSBUILDER_H_

#include "cocos2d.h"

class HelloCocosBuilder : public cocos2d::CCLayer {
        
public:
    void pressedButton(CCObject *pSender);
    void didLoadFromCCB();
        
    CC_SYNTHESIZE(cocos2d::CCSprite *, sprtBurst, SprtBurst);
    CC_SYNTHESIZE(cocos2d::CCSprite *, sprtIcon, SprtIcon);
};

#endif
