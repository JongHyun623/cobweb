#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myvideocapture.h"
#include <time.h>
#include <iostream>
#include <softPwm.h>
#include <wiringPi.h>
#include <QPalette>
#include <QTextEdit>
#include <QFont>

int servoControl(int gpio, int value)
{
    // value : PWM value of servo motor
    wiringPiSetup();
    pinMode(gpio, OUTPUT);
    softPwmCreate(gpio, 0, 200); // Setting pwm range (0 to 100), initial value : 0
    softPwmWrite(gpio, value);
    delay(200);
    return 0;

}

int laserControl(int gpio, int  value)
{
    pinMode(gpio, OUTPUT);
    softPwmCreate(gpio, 0, 200);
    softPwmWrite(gpio, value);
    return 0;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mOpenCV_videoCapture = new MyVideoCapture(this);

    connect(mOpenCV_videoCapture, &MyVideoCapture::newPixmapCaptured, this, [&]()
    {
        ui->opencvFrame->setPixmap(mOpenCV_videoCapture->pixmap().scaled(560, 320));

    });

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(84, 84, 84, 255));
    setAutoFillBackground(true);
    setPalette(palette);

    ui->labelDate->setStyleSheet("QLabel { color : white; }");


    setAutoFillBackground(true);
    // init status
    ui->push_CCW->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushleft_off.png);");
    ui->push_CW->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushright_off.png)");
    ui->push_laser->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushlaser_off.png)");
    ui->push_cam->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushcam_off.png)");
    ui->opencvFrame->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/Right_layout.png)");
    setAutoFillBackground(true);
    QString init_str = "";
    ui->push_CW->setText(init_str);
    ui->push_CCW->setText(init_str);
    ui->push_laser->setText(init_str);
    ui->push_cam->setText(init_str);
    ui->labelDate->setText(init_str);
    // Set initial value
    if (count == 0) {
        videoBool.value = 0;
        pushbuttonStat.pushCW = 0;
        pushbuttonStat.pushCCW = 0;
        pushbuttonStat.pushCam = 0;
        pushbuttonStat.pushLaser = 0;
        pwmSave.value = 13;
        wiringPiSetup();
        pinMode(1, OUTPUT);
        softPwmCreate(1, 0, 200);
        softPwmWrite(1, 13);
        count++;
    }

    QFont font;
    font.setPointSize(25);
    font.setBold(true);
    ui->labelDate->setFont(font);



    // Set timer for showing current time
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    QLabel(QDateTime::currentDateTime().toString());

    timer->start(1000);
}

void MainWindow::update()
{
    QString timeStr;
    timeStr = QTime::currentTime().toString("hh:mm ap");

    ui->labelDate->setText(timeStr);

}

MainWindow::~MainWindow()
{
    delete ui;
    mOpenCV_videoCapture->terminate();
}


void MainWindow::on_push_CCW_clicked()
{
    int value = 3 ;
    pwmSave.value -= value;
    int servo_gpio = 1;

    if (pwmSave.value <= 5)
    {
        pwmSave.value = 5;
    } else if (pwmSave.value >=25){
        pwmSave.value = 25;
    } else {

    }

    servoControl(servo_gpio, pwmSave.value);
}

void MainWindow::on_push_CW_clicked()
{

    int value = 3;
    pwmSave.value += value;
    int servo_gpio = 1;

    if (pwmSave.value <= 5)
    {
        pwmSave.value = 5;
    } else if (pwmSave.value >= 25){
        pwmSave.value = 25;
    } else {

    }

    servoControl(servo_gpio, pwmSave.value);

}

void MainWindow::on_push_laser_clicked()
{
    int gpio = 4;
    int value1 = 200, value2 = 0;

    if (pushbuttonStat.pushLaser == 0) // False to True
    {
        laserControl(gpio, value1);
        pushbuttonStat.pushLaser = 1;
        ui->push_laser->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushlaser_on.png)");
        setAutoFillBackground(true);
    } else { // True to False
        laserControl(gpio, value2);
        softPwmStop(gpio);
        pushbuttonStat.pushLaser = 0;
        ui->push_laser->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushlaser_off.png)");
        setAutoFillBackground(true);
    }

}

void MainWindow::on_push_cam_clicked()
{


    if (videoBool.value == 0) // Turn off -> Turn On
    {
        connect(mOpenCV_videoCapture, &MyVideoCapture::newPixmapCaptured, this, [&]()
        {
            ui->opencvFrame->setPixmap(mOpenCV_videoCapture->pixmap().scaled(580, 480));

        });
        mOpenCV_videoCapture->start(QThread::HighestPriority);
        videoBool.value = 1;
        ui->push_cam->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushcam_on.png)");
        setAutoFillBackground(true);
    } else { // Turn on -> Turn off

        videoBool.value = 0;
        mOpenCV_videoCapture->disconnect();
        ui->push_cam->setStyleSheet("border-image:url(/home/pi/cam_ui_version_1_0/imgs/pushcam_on.png)");
        setAutoFillBackground(true);
    }
}
