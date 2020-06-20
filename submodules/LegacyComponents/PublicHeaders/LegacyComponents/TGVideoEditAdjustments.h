#import <AVFoundation/AVFoundation.h>
#import <LegacyComponents/TGMediaEditingContext.h>

@class PGPhotoEditorValues;

typedef enum
{
    TGMediaVideoConversionPresetCompressedDefault,
    TGMediaVideoConversionPresetCompressedVeryLow,
    TGMediaVideoConversionPresetCompressedLow,
    TGMediaVideoConversionPresetCompressedMedium,
    TGMediaVideoConversionPresetCompressedHigh,
    TGMediaVideoConversionPresetCompressedVeryHigh,
    TGMediaVideoConversionPresetAnimation,
    TGMediaVideoConversionPresetVideoMessage,
    TGMediaVideoConversionPresetProfile
} TGMediaVideoConversionPreset;

@interface TGVideoEditAdjustments : NSObject <TGMediaEditAdjustments>

@property (nonatomic, readonly) NSTimeInterval videoStartValue;
@property (nonatomic, readonly) NSTimeInterval trimStartValue;
@property (nonatomic, readonly) NSTimeInterval trimEndValue;
@property (nonatomic, readonly) TGMediaVideoConversionPreset preset;

- (CMTimeRange)trimTimeRange;

- (bool)trimApplied;

- (bool)isCropAndRotationEqualWith:(id<TGMediaEditAdjustments>)adjustments;

- (NSDictionary *)dictionary;

- (instancetype)editAdjustmentsWithPreset:(TGMediaVideoConversionPreset)preset maxDuration:(NSTimeInterval)maxDuration videoStartValue:(NSTimeInterval)videoStartValue;
+ (instancetype)editAdjustmentsWithOriginalSize:(CGSize)originalSize preset:(TGMediaVideoConversionPreset)preset;
+ (instancetype)editAdjustmentsWithPhotoEditorValues:(PGPhotoEditorValues *)values;
+ (instancetype)editAdjustmentsWithDictionary:(NSDictionary *)dictionary;

+ (instancetype)editAdjustmentsWithOriginalSize:(CGSize)originalSize
                                       cropRect:(CGRect)cropRect
                                cropOrientation:(UIImageOrientation)cropOrientation
                                   cropRotation:(CGFloat)cropRotation
                          cropLockedAspectRatio:(CGFloat)cropLockedAspectRatio
                                   cropMirrored:(bool)cropMirrored
                                 trimStartValue:(NSTimeInterval)trimStartValue
                                   trimEndValue:(NSTimeInterval)trimEndValue
                                     toolValues:(NSDictionary *)toolValues
                                   paintingData:(TGPaintingData *)paintingData
                                      sendAsGif:(bool)sendAsGif
                                         preset:(TGMediaVideoConversionPreset)preset;

@end

typedef TGVideoEditAdjustments TGMediaVideoEditAdjustments;

extern const NSTimeInterval TGVideoEditMinimumTrimmableDuration;
extern const NSTimeInterval TGVideoEditMaximumGifDuration;
