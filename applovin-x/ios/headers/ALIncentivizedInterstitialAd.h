//
//  ALIncentivizedInterstitialAd.h
//  sdk
//
//  Created by Matt Szaro on 10/1/13.
//
//

#import <Foundation/Foundation.h>
#import "ALInterstitialAd.h"
#import "ALAdVideoPlaybackDelegate.h"
#import "ALAdDisplayDelegate.h"
#import "ALAdLoadDelegate.h"

/*
 ALIncentivizedInterstitialAd is intended to help you provide incentivized videos to your user.
 
 This class will always return video interstitials, and will notify your ALAdVideoPlaybackDelegate
 about how much of the video the user viewed. Based on this information you are free to provide
 the user with virutal currency, game upgrades, or whatever else you choose.
 
 This does not apply to standard, non-incentivized placements; in those cases, you should
 use the standard ALInterstitialAd class, which is automatically pre-cached for you.
 */

@interface ALIncentivizedInterstitialAd : NSObject

/**
 * Get a reference to the shared instance of ALIncentivizedInterstitialAd.
 * This wraps the [ALSdk shared] call, and will only work if you hve set your SDK key in Info.plist.
*/
+(ALIncentivizedInterstitialAd*) shared;

/**
 * Pre-load an incentivized interstitial, and notify your provided Ad Load Delegate.
 * This method uses the shared instance, and will only work if you have set your SDK key in Info.plist.
 *
 * @param adLoadDelegate The delegate to notify that preloading was completed.
 */
+(void) preloadAndNotify: (id<ALAdLoadDelegate>) adLoadDelegate;

/**
 * Show an incentivized interstitial, using the most recently pre-loaded ad.
 * You must call preloadAndNotify before calling showOver.
 * This method uses the shared instance, and will only work if you have set your SDK key in Info.plist.
 *
 * @param adVideoPlaybackDelegate The video playback delegate to notify on video start and completion.
 *
 * Using the -(void) videoPlaybackEndedInAd.... callback provided in this protocol, you will be able to
 * reward your user for a completed view, or partial view, at your discretion. Please see the documentation
 * in ALAdVideoPlaybackDelegate.h for more information.
 */
+(void) showOver: (UIWindow*) window andNotify: (id<ALAdVideoPlaybackDelegate>) adVideoPlaybackDelegate;


/**
 * Initialize an incentivized interstitial with a specific custom SDK.
 * This is necessary if you use [ALSdk sharedWithKey: ...].
 *
 * @param An SDK instance to use.
 */
-(instancetype) initIncentivizedInterstitialWithSdk: (ALSdk*) anSdk;

/**
 * Pre-load an incentivized interstitial, and notify your provided Ad Load Delegate.
 *
 * @param adLoadDelegate The delegate to notify that preloading was completed.
 */
-(void) preloadAndNotify: (id<ALAdLoadDelegate>) adLoadDelegate;

/**
 * Show an incentivized interstitial, using the most recently pre-loaded ad.
 * You must call preloadAndNotify before calling showOver.
 *
 * @param adVideoPlaybackDelegate The video playback delegate to notify on video start and completion.
 *
 * Using the -(void) videoPlaybackEndedInAd.... callback provided in this protocol, you will be able to
 * reward your user for a completed view, or partial view, at your discretion. Please see the documentation
 * in ALAdVideoPlaybackDelegate.h for more information.
 */
-(void) showOver: (UIWindow*) window andNotify: (id<ALAdVideoPlaybackDelegate>) adVideoPlaybackDelegate;

/**
 * Dismiss an incentivized interstitial, before video playback has completed.
 */
-(void) dismiss;

/**
 * You may optionally set an Ad Display Delegate to be notified when the ad appears and disappears.
 */
@property (strong, nonatomic) id<ALAdDisplayDelegate> adDisplayDelegate;

@end
