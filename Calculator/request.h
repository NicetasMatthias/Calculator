#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>

enum op
{
    PLUS = 0,
    MINUS,
    DIVIDE,
    MULTIPLY,
};

class Request : public QObject
{
    Q_OBJECT
public:
    explicit Request(QObject *parent = nullptr);
    bool setup(QString);
    double get_operand_A();
    double get_operand_B();
    int get_operation();

private:
    double operand_A;
    double operand_B;
    short operation;

};

#endif // REQUEST_H
