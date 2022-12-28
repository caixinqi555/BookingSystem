#pragma once
#include "Process.h"
class ShowMyBooking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

