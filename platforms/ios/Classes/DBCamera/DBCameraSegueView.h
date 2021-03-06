//
//  DBCameraSegueView.h
//  DBCamera
//
//  Created by iBo on 17/02/14.
//  Copyright (c) 2014 PSSD - Daniele Bogo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DBCameraImageView.h"
#import "DBEventlessView.h"

@protocol DBCameraSegueViewDelegate;

@interface DBCameraSegueView : UIView
@property (nonatomic, weak) id <DBCameraSegueViewDelegate> delegate;
@property (nonatomic, strong) DBCameraImageView *imageView;
@property (nonatomic, strong) DBEventlessView *filterView;
@property (nonatomic, strong) DBEventlessView *tempFilterView;
@property (nonatomic, strong) UIView *stripeView;
@property (nonatomic, strong) UIButton *retakeButton, *useButton, *cropButton;
@property (nonatomic, strong) UIImage *_thumb;

@property (nonatomic, strong) NSArray *filter;

@property (nonatomic, strong) NSDictionary *capturedImageMetadata;

@property (nonatomic, assign, getter = isCropModeOn) BOOL cropMode;
@property (nonatomic,strong) UIImage *cropedImage;
@property (nonatomic,assign, getter = getFilter, setter = setFilter:) int filterNumber;

- (void) buildButtonInterface;

@end

@protocol DBCameraSegueViewDelegate <NSObject>
@optional
- (void) retakeImageFromCameraView:(DBCameraSegueView *)cameraView;
- (void) useImageFromCameraView:(DBCameraSegueView *)cameraView;
- (void) cameraView:(DBCameraSegueView *)cameraView cropQuadImageForState:(BOOL)state;
- (void) useFilter:(int) i;
@end