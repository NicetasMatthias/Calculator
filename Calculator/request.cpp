#include "request.h"

Request::Request(QObject *parent) : QObject(parent)
{

}

bool Request::setup(QString expression)
{
    if (expression.isEmpty()) return true; //выбрасываем ошибку если строка пустая
    QChar op;
    short count = 0;
    if (expression.contains("+"))
    {
        count++;
        op = '+';
        this->operation = PLUS;
    }
    if (expression.contains("-"))
    {
        count++;
        op = '-';
        this->operation = MINUS;
    }
    if (expression.contains("/"))
    {
        count++;
        op = '/';
        this->operation = DIVIDE;
    }
    if (expression.contains("*"))
    {
        count++;
        op = '*';
        this->operation = MULTIPLY;
    }

    if (count!=1) return true; //выбрасываем ошибку если встретили больше одного оператора или ни одного

    QStringList operands = expression.split(op);

    if (operands.size()!=2) return true; //выбрасываем ошибку если количество операндов не равно двум

    bool flag_1,flag_2;
    this->operand_A = operands[0].toDouble(&flag_1);
    this->operand_B = operands[1].toDouble(&flag_2);

    if( !(flag_1 && flag_2) ) return true; //выбрасываем ошибку если не получилось преобразовать один из операндов в число
    else return false;
}


double Request::get_operand_A()
{
    return this->operand_A;
}
double Request::get_operand_B()
{
    return this->operand_B;
}
int Request::get_operation()
{
    return this->operation;
}
