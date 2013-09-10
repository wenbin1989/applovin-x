/****************************************************************************
 Copyright (c) 2012      Wenbin Wang
 
 http://geeksavetheworld.com
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "ApplovinXJni.h"
#include "ApplovinX.h"

#define  CLASS_NAME "com/wenbin/ApplovinX/ApplovinXBridge"

using namespace cocos2d;

extern "C"
{
    
    void showInterstitialAdJNI()
    {
        JniMethodInfo methodInfo;
        
        if (!  JniHelper::getStaticMethodInfo(methodInfo, CLASS_NAME, "showInterstitialAd", "()V"))
        {
            return;
        }
        methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
    
      
    void Java_com_wenbin_ApplovinX_ApplovinXBridge_didLoadAd(JNIEnv*  env, jobject thiz, jstring location)
    {
        if (ALXAdLoadDelegate * delegate = ALX::sharedALX()->getAdLoadDelegate()) {
            delegate->didLoadAd(JniHelper::jstring2string(location).c_str());
        }
    }
    
    void Java_com_wenbin_ApplovinX_ApplovinXBridge_didFailToLoadAdWithError(JNIEnv*  env, jobject thiz, jint code)
    {
        if (ALXAdLoadDelegate * delegate = ALX::sharedALX()->getAdLoadDelegate()) {
            delegate->didFailToLoadAdWithError(code);
        }
    }
    
}
