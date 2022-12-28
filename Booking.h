#pragma once
#include "Process.h"
class Booking :
    public Process
{
public:
    using Process::Process;
    void loop();
};

