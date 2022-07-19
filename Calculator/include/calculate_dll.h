#pragma once

#ifndef CALCULATE_DLL_H
#define CALCULATE_DLL_H

#include "Calculate_dll_global.h"

class CALCULATE_DLL_EXPORT Calculate_dll
{
public:
    static double DoIt (int TypeWork, double OperandA, double OperandB, int* ErrorCode);
};

#endif // CALCULATE_DLL_H
