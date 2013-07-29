//
//  Copyright 2012 Christoph Jerolimov
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License
//

#import <Foundation/Foundation.h>

typedef void (^EventEmitterNotifyCallback)();
typedef void (^EventEmitterDefaultCallback)(id arg0);
typedef void (^EventEmitterArrayCallback)(NSArray* data);

#pragma mark - NSObject+EventEmitterListenerHandling

@interface NSObject(EventEmitterListenerHandling)

// connect to self
- (void)on:(NSString*)event notify:(EventEmitterNotifyCallback)callback;
- (void)on:(NSString*)event callback:(EventEmitterDefaultCallback)callback;
- (void)on:(NSString*)event array:(EventEmitterArrayCallback)callback;
- (void)once:(NSString*)event notify:(EventEmitterNotifyCallback)callback;
- (void)once:(NSString*)event callback:(EventEmitterDefaultCallback)callback;
- (void)once:(NSString*)event array:(EventEmitterArrayCallback)callback;

// connect to sender
- (void)on:(NSString*)event sender:(id)sender notify:(EventEmitterNotifyCallback)callback;
- (void)on:(NSString*)event sender:(id)sender callback:(EventEmitterDefaultCallback)callback;
- (void)on:(NSString*)event sender:(id)sender array:(EventEmitterArrayCallback)callback;
- (void)once:(NSString*)event sender:(id)sender notify:(EventEmitterNotifyCallback)callback;
- (void)once:(NSString*)event sender:(id)sender callback:(EventEmitterDefaultCallback)callback;
- (void)once:(NSString*)event sender:(id)sender array:(EventEmitterArrayCallback)callback;

// listener management
- (void)removeCallback:(id)callback;
- (void)removeListener:(NSString*)event callback:(id)callback;
- (void)removeAllListener:(NSString*)event;
- (void)removeAllListener;
- (NSArray*)listeners;
- (NSArray*)listeners:(NSString*)event;

@end

#pragma mark - NSObject+EventEmitterDistributionHandling

@interface NSObject(EventEmitterDistributionHandling)

- (void)emit:(NSString*)event;
- (void)emit:(NSString*)event data:(id)arg0;
- (void)emit:(NSString*)event arguments:(id)arg0, ...;
- (void)emit:(NSString*)event array:(NSArray*)array;

@end
