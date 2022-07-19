#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

enum MESSAGE_TYPES
{
    DEFAULT = 0,
    REQUEST,
    RESULT,
    ERROR
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setup(int delay, QRect rect);
    void get_setup(int *delay, QRect *rect);

private slots:
    void drop_message(int message_type, QString message_text);
    void set_results_queue_size(int);
    void set_requests_queue_size(int);

    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_point_clicked();

    void on_spinBox_calculate_time_valueChanged(int arg1);

signals:
    void send_expression_to_application(QString expression);
    void interface_calculate_delay_changed(int);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
