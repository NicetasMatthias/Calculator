#include "application.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc,argv)
{
    QCoreApplication::setOrganizationName("Matveev Inc.");
    QCoreApplication::setApplicationName("Calculator");
    config = new QSettings;

    queue_requests = new Queue <Request>;
    queue_results = new Queue <Result>;



    mw = new MainWindow;
    calc = new Calculator;
    calc_thread = new QThread;
    calc->moveToThread(calc_thread);
    calc->setup(queue_requests,queue_results);

    connect(calc_thread, SIGNAL(started()),
            calc, SLOT(processing()));
    connect(calc,SIGNAL(release_result()),
            this,SLOT(get_new_result()));
    connect(calc, SIGNAL(get_request()),
            this, SLOT(calculator_get_request()));

    connect(this,SIGNAL(drop_console_message(int,QString)),
            mw,SLOT(drop_message(int, QString)));
    connect(mw,SIGNAL(send_expression_to_application(QString)),
            this,SLOT(get_expression_from_interface(QString)));

    connect(mw,SIGNAL(interface_calculate_delay_changed(int)),
            this,SLOT(get_delay_from_interface(int)));

    connect(this,SIGNAL(send_results_queue_size(int)),
            mw,SLOT(set_results_queue_size(int)));
    connect(this,SIGNAL(send_requests_queue_size(int)),
            mw,SLOT(set_requests_queue_size(int)));


    calc_thread->start();

    mw->show();

    int calc_delay,ax,ay,aw,ah;
    calc_delay = config->value("delay",-1).toInt();
    ax = config->value("position/x",-1).toInt();
    ay = config->value("position/y",-1).toInt();
    aw = config->value("size/w",-1).toInt();
    ah = config->value("size/h",-1).toInt();
    if(calc_delay!=-1 && ax!=-1 && ay!=-1 && aw!=-1 && ah!=-1)
    {
        mw->setup(calc_delay,QRect(QPoint(ax,ay),QSize(aw,ah)));
    }

}

Application::~Application()
{
    //тут сохраняем размер, положение окна и время вычислений
    QRect win_rect;
    int calc_delay,ax,ay,aw,ah;
    mw->get_setup(&calc_delay, &win_rect);
    win_rect.getRect(&ax,&ay,&aw,&ah);
    config->setValue("delay",calc_delay);
    config->setValue("position/x",ax);
    config->setValue("position/y",ay);
    config->setValue("size/w",aw);
    config->setValue("size/h",ah);


    calc->stop();
    calc_thread->quit();
    calc_thread->wait();

    delete config;
    delete calc;
    delete calc_thread;
    delete mw;
    delete queue_requests;
    delete queue_results;
}

void Application::get_expression_from_interface(QString expression)
{
    Request *request = new Request;
    if (request->setup(expression))
    {
        //ошибка создания запроса
        emit(drop_console_message(ERROR,"Ошибка при создании запроса: \""+expression+"\""));
        delete request;
    }
    else
    {
        //запрос успешно создан
        queue_requests->push(request);
        emit(drop_console_message(REQUEST,"Создан запрос: \""+expression+"\""));
        emit(send_requests_queue_size(queue_requests->size()));
    }
}

void Application::get_delay_from_interface(int delay)
{
    calc->set_calculate_delay(delay);
}

void Application::get_new_result()
{
    emit(send_results_queue_size(queue_results->size()));
    while(1)
    {
        bool results_empty;
        Result *current_result = queue_results->pop(&results_empty);
        if (results_empty)
        {
            break;
        }
        else
        {
            int error;
            QString result = current_result->get_result(&error);
            if(error)
            {
                emit(drop_console_message(ERROR,result));
            }
            else
            {
                emit(drop_console_message(RESULT,result));
            }
            emit(send_results_queue_size(queue_results->size()));
        }
    }
}

void Application::calculator_get_request()
{
    emit(send_requests_queue_size(queue_requests->size()));
}

