#pragma once
#include "Process.h"
class ShowAllBooking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

