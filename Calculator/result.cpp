#include "result.h"

Result::Result(QObject *parent) : QObject(parent)
{
    this->error_code = -1;
}

void Result::setup(Request *req, double ans, int err_c)
{
    this->request = req;
    this->answer = ans;
    this->error_code = err_c;

}

QString Result::get_result(int *err_c)
{
    *err_c = this->error_code;
    if (error_code == -1) return QString("Класс результата не инициализирован");
    QString result;
    result += QString::number(this->request->get_operand_A());
    switch (this->request->get_operation())
    {
    case PLUS:
        result += " + ";
        break;
    case MINUS:
        result += " - ";
        break;
    case DIVIDE:
        result += " / ";
        break;
    case MULTIPLY:
        result += " * ";
        break;
    default:
        break;
    }
    result += QString::number(this->request->get_operand_B());


    switch (this->error_code)
    {
    case 0:
        result += " = " + QString::number(this->answer);
        break;
    case 1:
        result += " : Деление на 0 ERROR#" + QString::number(error_code);
        break;
    case 2:
        result += " : Неизвестный код операции ERROR#" + QString::number(error_code);
        break;
    default:
        result += " : Неизвестный код ошибки ERROR#" + QString::number(error_code);
    }
    return result;
}
