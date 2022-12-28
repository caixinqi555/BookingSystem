#pragma once
#include "Process.h"
class Login :
    public Process
{
public:
    Login(const string& label, int type);
    void loop();
    int m_type;
};

