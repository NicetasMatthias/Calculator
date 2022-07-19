#include "calculator.h"

Calculator::Calculator(QObject *parent) : QObject(parent)
{
    this->request_queue = nullptr;
    this->result_queue = nullptr;
    this->calculate_delay = 0;
    this->is_working = false;
    this->check_delay = 100;
}

void Calculator::setup(Queue<Request> *req_q, Queue<Result> *res_q)
{
    this->request_queue = req_q;
    this->result_queue = res_q;
}

void Calculator::set_calculate_delay(int delay)
{
    this->calculate_delay = delay;
}

void Calculator::processing()
{
    this->is_working = true;
    while(is_working)
    {
        bool request_queue_empty;
        Request *current_request = request_queue->pop(&request_queue_empty);
        if (request_queue_empty)
        {
            //очередь пуста
            QThread::msleep(check_delay);
        }
        else
        {
            emit(get_request());
            //взят элемент
            int err_c;
            double result = Calculate_dll::DoIt(current_request->get_operation(),
                                                current_request->get_operand_A(),
                                                current_request->get_operand_B(),
                                                &err_c);
            Result *res = new Result;
            res->setup(current_request,result,err_c);
            QThread::msleep(this->calculate_delay*1000);

            result_queue->push(res);
            emit(release_result());
        }
    }

}

void Calculator::stop()
{
    this->is_working = false;

}
