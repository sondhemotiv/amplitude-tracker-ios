// AmplitudeBridge.mm

#include "AmplitudeBridge.h"
#include "AmplitudeSwift/AmplitudeSwift-Swift.h"

void initAmplitude(const char* apiKey) {
    NSString *apiKeyString = [NSString stringWithUTF8String:apiKey];
    AMPConfiguration* configuration = [AMPConfiguration initWithApiKey:apiKeyString];
    configuration.logLevel = AMPLogLevelLOG;
    configuration.serverZone = AMPServerZoneUS;
    configuration.defaultTracking = AMPDefaultTrackingOptions.ALL;
    configuration.loggerProvider = ^(NSInteger logLevel, NSString* _Nonnull message) {
        NSLog(@"%@", message);
    };
    Amplitude* amplitude = [Amplitude initWithConfiguration:configuration];
}

void logEvent(const char* eventName) {

}
