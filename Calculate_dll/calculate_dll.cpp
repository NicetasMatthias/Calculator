#include "calculate_dll.h"


double Calculate_dll::DoIt(int TypeWork, double OperandA, double OperandB, int *ErrorCode)
{
    /*
     * Typework:
     * 0 - сложение
     * 1 - вычитание
     * 2 - деление
     * 3 - умножение
    */

    /*
     * ErrorCode:
     * 0 - Все ОК
     * 1 - Деление на 0
     * 2 - Неизвестный код операции
    */
    double result;
    switch (TypeWork)
    {
    case 0:
        result = OperandA + OperandB;
        *ErrorCode = 0;
        break;
    case 1:
        result = OperandA - OperandB;
        *ErrorCode = 0;
        break;
    case 2:
        if (OperandB==0)
        {
            *ErrorCode = 1;
            result = 0;
        }
        else
        {
            result = OperandA / OperandB;
            *ErrorCode = 0;
        }
        break;
    case 3:
        result = OperandA * OperandB;
        *ErrorCode = 0;
        break;
    default:
        *ErrorCode = 2;
        result = 0;
    }
    return result;
}
