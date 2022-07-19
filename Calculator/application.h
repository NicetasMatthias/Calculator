#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QObject>
#include <QThread>
#include <QSettings>

#include "mainwindow.h"
#include "calculator.h"

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);
    ~Application();
private:
    MainWindow *mw;
    Calculator *calc;
    QThread *calc_thread;
    Queue <Request> *queue_requests;
    Queue <Result>  *queue_results;
    QSettings *config;

signals:
    void drop_console_message(int message_type, QString message_text);
    void send_requests_queue_size(int);
    void send_results_queue_size(int);

private slots:
    void get_expression_from_interface(QString expression);
    void get_delay_from_interface(int);
    void get_new_result();
    void calculator_get_request();
};

#endif // APPLICATION_H
