#pragma once
#include "Process.h"
class AddModule :
    public Process
{
public:
    using Process::Process;
    void loop();
};

