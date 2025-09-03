#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <functional>
#include <memory>
#include <vector>
#include <thread>
#include <atomic>
using CursorChangedCallback = std::function<void(int, int, const std::vector<uint8_t>&)>;
using CursorPositionCallback = std::function<void(int, int, double, double)>;

// Adding CPP_ prefix to avoid conflicts with Windows system macros
#define CPP_CURSOR_INVISIBLE 1
#define CPP_CURSOR_VISIBLE 2
#define CPP_CURSOR_UPDATED_DEFAULT 3
#define CPP_CURSOR_UPDATED_IMAGE 4
#define CPP_CURSOR_UPDATED_CACHED 5
#define CPP_CURSOR_POSITION_CHANGED 6

class CursorMonitor {
public:
    static HWINEVENTHOOK Global_HOOK;
    static void startHook(CursorChangedCallback callback, long long callback_id, bool hookAll);
    static void endHook(long long callback_id);
    
    // Position monitoring functions
    static void startPositionHook(CursorPositionCallback callback, long long callback_id);
    static void endPositionHook(long long callback_id);
    
private:
    // Hook thread management
    static void hookThreadFunction();
    static void startHookThread();
    static void stopHookThread();
    
    // Thread-related static variables
    static std::unique_ptr<std::thread> hookThread;
    static std::atomic<bool> shouldStopHookThread;
    static std::atomic<bool> hookThreadRunning;
};