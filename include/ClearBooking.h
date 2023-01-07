#pragma once
#include "Process.h"
class ClearBooking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

