//
//  CDZQRScanningViewController.h
//
//  Created by Chris Dzombak on 10/27/13.
//  Copyright (c) 2013 Chris Dzombak. All rights reserved.
//

#import <UIKit/UIKit.h>



@protocol CDZQRResult <NSObject>

@property (nonatomic, readonly) NSString *capturedString;
- (void)resumeScanning;

@end



typedef void (^CDZQRCompletionHandler)(id<CDZQRResult> result, NSError *error);

extern NSString * const CDZQRScanningErrorDomain;

typedef NS_ENUM(NSInteger, CDZQRScanningViewControllerErrorCode) {
    CDZQRScanningViewControllerErrorUnavailableMetadataObjectType = 1,
};

typedef NS_ENUM(NSInteger, CDZQRCameraDevice) {
    CDZQRCameraDeviceBackFacing,
    CDZQRCameraDeviceFrontFacing
};



@interface CDZQRScanningViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initCompletion:(CDZQRCompletionHandler)completionHandler;

- (instancetype)initWithDevice:(CDZQRCameraDevice)cameraDevice
                    completion:(CDZQRCompletionHandler)completionHandler;

- (instancetype)initWithMetadataObjectTypes:(NSArray *)metadataObjectTypes
                                     device:(CDZQRCameraDevice)cameraDevice
                                 completion:(CDZQRCompletionHandler)completionHandler NS_DESIGNATED_INITIALIZER;

@property (nonatomic, copy, readonly) CDZQRCompletionHandler completionHandler; // called on the main queue

/**
 *  An array of `AVMetadataMachineReadableCodeObject`s
 */
@property (nonatomic, readonly) NSArray *metadataObjectTypes;
@property (nonatomic, readonly) NSString *capturedString;

@end
