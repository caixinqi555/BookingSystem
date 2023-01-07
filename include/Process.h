#pragma once
#include "AutoState.h"
#include "DataSystem.h"
class Process :
    public AutoState
{
public:
    using AutoState::AutoState;
    static DataSystem* data;
    static long long getOpr(const string& info, long long min, long long max);
};
