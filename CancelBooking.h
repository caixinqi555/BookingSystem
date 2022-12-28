#pragma once
#include "Process.h"
class CancelBooking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

