#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ApplovinX.h"

class HelloWorld : public cocos2d::CCLayer, public ALXAdLoadDelegate
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();
    
    // selector callback
    void menuCloseCallback(CCObject* pSender);
    void menuShowCallback(CCObject* pSender);
    
    // ALXAdLoadDelegate method
    void didLoadAd(const char* lable);
    void didFailToLoadAdWithError(int code);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

};

#endif // __HELLOWORLD_SCENE_H__
