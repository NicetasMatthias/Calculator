#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_console->setStyleSheet("background-color: #FF000000;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup(int delay, QRect rect)
{
    ui->spinBox_calculate_time->setValue(delay);
    this->setGeometry(rect);
}

void MainWindow::get_setup(int *delay, QRect *rect)
{
    *delay = ui->spinBox_calculate_time->value();
    *rect = this->geometry();
}

void MainWindow::drop_message(int message_type, QString message_text) //Слот-функция вывода сообщения в консоль
{
    QColor color;
    QString promt = QTime::currentTime().toString()+": ";

    switch (message_type)
    {
    case DEFAULT:
        color.setRgb(255,255,255);
        promt += "Message > ";
        break;
    case REQUEST:
        color.setRgb(0,200,0);
        promt += "Request > ";
        break;
    case RESULT:
        color.setRgb(98,98,255);
        promt += "Result > ";
        break;
    case ERROR:
        color.setRgb(255,0,0);
        promt += "Error > ";
        break;
    default:
        color.setRgb(0,0,0);
        promt += "Undefined > ";
    }
    ui->textEdit_console->setTextColor(color);
    ui->textEdit_console->textCursor().insertText(promt+message_text+"\n");
    ui->textEdit_console->moveCursor(QTextCursor::End);

}

//слоты-функции изменения длинны очереди в интерфейсе
void MainWindow::set_results_queue_size(int size)
{
    ui->lineEdit_results_queue_size->setText(QString::number(size));
}

void MainWindow::set_requests_queue_size(int size)
{
    ui->lineEdit_requests_queue_size->setText(QString::number(size));
}

//блок слотов обработки кнопок
void MainWindow::on_pushButton_0_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"0");
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"1");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"2");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"4");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"5");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"6");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"7");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"8");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"9");
}

void MainWindow::on_pushButton_divide_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"/");
}

void MainWindow::on_pushButton_minus_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"-");
}

void MainWindow::on_pushButton_multiply_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"*");
}

void MainWindow::on_pushButton_plus_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+"+");
}

void MainWindow::on_pushButton_point_clicked()
{
    ui->lineEdit_expression->setText(ui->lineEdit_expression->text()+".");
}

//конец блока обработки кнопок

void MainWindow::on_pushButton_equal_clicked()
{
    emit(send_expression_to_application(ui->lineEdit_expression->text()));
    ui->lineEdit_expression->setText("");
}

void MainWindow::on_spinBox_calculate_time_valueChanged(int arg1)
{
    emit(interface_calculate_delay_changed(arg1));
}
