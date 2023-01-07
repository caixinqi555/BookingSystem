#pragma once
#include "Process.h"
class AddAccount :
    public Process
{
public:
    using Process::Process;
    void loop();
};

