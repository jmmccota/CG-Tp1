#pragma once
// No-op FMOD stub for non-Windows builds
#include <cstddef>

typedef int          FMOD_RESULT;
typedef unsigned int FMOD_MODE;

#define FMOD_OK            0
#define FMOD_DEFAULT       0u
#define FMOD_LOOP_NORMAL   0u
#define FMOD_LOOP_OFF      0u
#define FMOD_CREATESTREAM  0u
#define FMOD_HARDWARE      0u
#define FMOD_INIT_NORMAL   0u
#define FMOD_CHANNEL_FREE  -1
#define FMOD_CHANNEL_REUSE -2
#define FMOD_VERSION       0x00044400u

namespace FMOD {
    struct Sound {
        FMOD_RESULT setMode(unsigned int) { return FMOD_OK; }
        FMOD_RESULT release() { return FMOD_OK; }
        FMOD_RESULT getLength(unsigned int*, int) { return FMOD_OK; }
    };
    struct Channel {
        FMOD_RESULT stop() { return FMOD_OK; }
        FMOD_RESULT setVolume(float) { return FMOD_OK; }
        FMOD_RESULT isPlaying(bool* p) { if(p) *p = false; return FMOD_OK; }
        FMOD_RESULT getPaused(bool* p) { if(p) *p = false; return FMOD_OK; }
        FMOD_RESULT setPaused(bool) { return FMOD_OK; }
    };
    struct System {
        FMOD_RESULT init(int, unsigned int, void*) { return FMOD_OK; }
        FMOD_RESULT createSound(const char*, unsigned int, void*, Sound**) { return FMOD_OK; }
        FMOD_RESULT createStream(const char*, unsigned int, void*, Sound**) { return FMOD_OK; }
        FMOD_RESULT playSound(int, Sound*, bool, Channel**) { return FMOD_OK; }
        FMOD_RESULT getVersion(unsigned int* v) { if(v) *v = FMOD_VERSION; return FMOD_OK; }
        FMOD_RESULT update() { return FMOD_OK; }
        FMOD_RESULT release() { return FMOD_OK; }
    };
    inline FMOD_RESULT System_Create(System** s) { *s = new System(); return FMOD_OK; }
}

inline const char* FMOD_ErrorString(FMOD_RESULT) { return ""; }
