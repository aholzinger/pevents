/*
 * WIN32 Events for POSIX
 * Author: Mahmoud Al-Qudsi <mqudsi@neosmart.net>
 * Copyright (C) 2011 - 2022 by NeoSmart Technologies
 * SPDX-License-Identifier: MIT
 */

#pragma once

extern "C" {
    #include "pevents.h"
}

namespace neosmart {
    // Constant declarations
    const uint64_t WAIT_INFINITE = NSPE_WAIT_INFINITE;

    // Function declarations
    inline neosmart_event_t CreateEvent(bool manualReset = false, bool initialState = false) {
        return NspeCreateEvent(manualReset, initialState);
    }
    inline int DestroyEvent(neosmart_event_t event) {
        return NspeDestroyEvent(event);
    }
    inline int WaitForEvent(neosmart_event_t event, uint64_t milliseconds = WAIT_INFINITE) {
        return NspeWaitForEvent(event, milliseconds);
    }
    inline int SetEvent(neosmart_event_t event) {
        return NspeSetEvent(event);
    }
    inline int ResetEvent(neosmart_event_t event) {
        return NspeResetEvent(event);
    }
#ifdef WFMO
    inline int WaitForMultipleEvents(neosmart_event_t *events, int count, bool waitAll, uint64_t milliseconds) {
        return NspeWaitForMultipleEvents(events, count, waitAll, milliseconds);
    }
    inline int WaitForMultipleEvents(neosmart_event_t* events, int count, bool waitAll, uint64_t milliseconds, int &index) {
        return  NspeWaitForMultipleEventsWithIndex(events, count, waitAll, milliseconds, &index);
    }
#endif
#ifdef PULSE
    inline int PulseEvent(neosmart_event_t event) {
        return NspePulseEvent(event);
    }
#endif
} // namespace neosmart
