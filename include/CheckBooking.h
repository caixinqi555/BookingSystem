#pragma once
#include "Process.h"
class CheckBooking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

