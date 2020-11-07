#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wiringPi.h>
#include <QTimer>
#include <QDateTime>
#include <QDialog>
#include <QHBoxLayout>
#include <myvideocapture.h>
#include <QLabel>

class QHBoxlayout;
class QLabel;


namespace Ui
{
class MainWindow;
}

class MyVideoCapture;
class pwmClass
{
public :
    int value;
};

class videobool
{
public :
    int value;
};
class pushbutton_stat
{
public :
    int pushCW;
    int pushCCW;
    int pushLaser;
    int pushCam;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int count = 0;
    ~MainWindow();

private slots:

    void on_push_CCW_clicked();

    void on_push_CW_clicked();

    void on_push_laser_clicked();

    void on_push_cam_clicked();

    void update();

private:
    Ui::MainWindow *ui;
    MyVideoCapture *mOpenCV_videoCapture;
    pwmClass pwmSave;
    videobool videoBool;
    QTimer *timer;
    QLabel *labelDate;
    QHBoxlayout *layout;
    pushbutton_stat pushbuttonStat;
};

#endif // MAINWINDOW_H
