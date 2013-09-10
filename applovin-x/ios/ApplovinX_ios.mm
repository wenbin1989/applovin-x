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

#include "ApplovinX.h"

#import "ALSdk.h"
#include "ALAdLoadDelegate.h"
#import "ALInterstitialAd.h"

// ALAdLoadDelegateBridge
@interface ALAdLoadDelegateBridge : NSObject<ALAdLoadDelegate>
@end
static ALAdLoadDelegateBridge* s_pDelegateBridge = nil;

static ALX* s_pALX = NULL;

ALX* ALX::sharedALX()
{
    if (s_pALX == NULL)
    {
        s_pALX = new ALX();
        s_pDelegateBridge = [[ALAdLoadDelegateBridge alloc] init];
        
        [ALInterstitialAd shared].adLoadDelegate = s_pDelegateBridge;
    }
    return s_pALX;
}

void ALX::purgeALX()
{
    CC_SAFE_DELETE(s_pALX);
    [s_pDelegateBridge dealloc];
}


void ALX::showInterstitialAd()
{
    [ALInterstitialAd showOver:[[UIApplication sharedApplication] keyWindow]];
}

/*
 * ALAdLoadDelegateBridge Methods
 *
 */
@implementation ALAdLoadDelegateBridge

-(void)adService:(ALAdService *)adService didLoadAd:(ALAd *)ad {
    if (ALXAdLoadDelegate * delegate = ALX::sharedALX()->getAdLoadDelegate()) {
        delegate->didLoadAd([[ad.size label] UTF8String]);
    }
}

-(void)adService:(ALAdService *)adService didFailToLoadAdWithError:(int)code {
    if (ALXAdLoadDelegate * delegate = ALX::sharedALX()->getAdLoadDelegate()) {
        delegate->didFailToLoadAdWithError(code);
    }
}

@end


