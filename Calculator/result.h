#ifndef RESULT_H
#define RESULT_H

#include <QObject>

#include "request.h"

class Result : public QObject
{
    Q_OBJECT
public:
    explicit Result(QObject *parent = nullptr);

    void setup(Request*req, double ans, int err_c);
    QString get_result(int *err_c);

private:
    Request *request;
    double answer;
    int error_code;
};

#endif // RESULT_H
