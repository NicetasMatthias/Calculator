#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>
#include <QThread>

#include "result.h"
#include "request.h"
#include "queue.h"
#include "include/calculate_dll.h"

class Calculator : public QObject
{
    Q_OBJECT

private:
    Queue<Request>* request_queue;
    Queue<Result>* result_queue;
    int calculate_delay; //задержка вычислений (в секундах)
    int check_delay; //задержка проверки очереди (в миллисекундах)
    bool is_working;
public:
    explicit Calculator(QObject *parent = nullptr);
    void setup(Queue<Request>* req_q, Queue <Result>* res_q);
    void set_calculate_delay(int delay);
    void stop();


public slots:
    void processing();


signals:
    void release_result();
    void get_request();

};

#endif // CALCULATOR_H
