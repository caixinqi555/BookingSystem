#pragma once
#include "Process.h"
class CheckAccount :
    public Process
{
public:
    using Process::Process;
    void loop();
};

