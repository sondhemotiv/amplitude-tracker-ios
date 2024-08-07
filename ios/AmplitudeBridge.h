#ifndef AMPLITUDE_BRIDGE_H
#define AMPLITUDE_BRIDGE_H

#ifdef __cplusplus
extern "C" {
#endif

void initAmplitude(const char* apiKey);
void logEvent(const char* eventName);

#ifdef __cplusplus
}
#endif

#endif // AMPLITUDE_BRIDGE_H
