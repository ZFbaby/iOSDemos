
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <AVFoundation/AVFoundation.h>


typedef NS_ENUM(NSInteger, TransitionType)
{
    kTransitionTypeNone = 0,
    kTransitionTypePushHorizontalSpinFromRight = 1,
    kTransitionTypePushHorizontalFromRight,
    kTransitionTypePushHorizontalFromLeft,
    kTransitionTypePushVerticalFromBottom,
    kTransitionTypePushVerticalFromTop,
    kTransitionTypeCrossFade,
    kTransitionTypeFadeInAndFadeOut,//淡入淡出
};


@interface ZJSimpleEditor : NSObject

// Set these properties before building the composition objects.
@property (nonatomic, copy) NSArray *clips; // array of AVURLAssets
@property (nonatomic, copy) NSArray *clipTimeRanges; // array of CMTimeRanges stored in NSValues.
@property(nonatomic, strong) NSMutableArray * transitionTypes;
@property (nonatomic) CMTime transitionDuration;

@property (nonatomic, readonly, retain) AVMutableComposition *composition;
@property (nonatomic, readonly, retain) AVMutableVideoComposition *videoComposition;
@property (nonatomic, readonly, retain) AVMutableAudioMix *audioMix;

// Builds the composition and videoComposition
- (void)buildCompositionObjectsForPlayback;

- (AVPlayerItem *)playerItem;

@end
