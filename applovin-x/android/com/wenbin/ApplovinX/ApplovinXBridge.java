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

package com.wenbin.ApplovinX;

import java.lang.ref.WeakReference;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.applovin.adview.AppLovinInterstitialAd;
import com.applovin.adview.AppLovinInterstitialAdDialog;
import com.applovin.sdk.*;

import android.util.Log;

public class ApplovinXBridge {
    private static final String TAG = "ApplovinX";
    private static WeakReference<Cocos2dxActivity> s_activity;
    private static AppLovinSdk s_alSdk;
    private static AppLovinInterstitialAdDialog s_alAdDialog;

    private static native void didLoadAd(String lable);
    private static native void didFailToLoadAdWithError(int code);
    
    // the method must be called in main thread, before any other method
    public static void initApplovinXBridge(Cocos2dxActivity activity){
    	s_activity = new WeakReference<Cocos2dxActivity>(activity);
    	AppLovinSdk.initializeSdk(activity);
    	s_alSdk = AppLovinSdk.getInstance(activity);
    	s_alAdDialog = AppLovinInterstitialAd.create(s_alSdk, activity);
    }
    
    public static void showInterstitialAd() {        
        if (s_alSdk != null) {
        	s_alSdk.getAdService().loadNextAd(AppLovinAdSize.INTERSTITIAL, s_alAdLoadListener);
        } else {
            Log.w(TAG, "Abort! cannot get shared AppLovinSdk!");
        }
    }
    
    
    static private AppLovinAdLoadListener s_alAdLoadListener = new AppLovinAdLoadListener() {
        @Override
        public void adReceived(final AppLovinAd ad)
        {
        	s_activity.get().runOnUiThread(new Runnable() {
                public void run() {
                	s_alAdDialog.showAndRender(ad);
                }
            });

        	s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                	ApplovinXBridge.didLoadAd(ad.getSize().getLabel());
                }
            });
        }

        @Override
        public void failedToReceiveAd(final int errorCode)
        {
        	ApplovinXBridge.s_activity.get().runOnGLThread(new Runnable() {
                public void run() {
                	ApplovinXBridge.didFailToLoadAdWithError(errorCode);
                }
            });
        }
    };

}
