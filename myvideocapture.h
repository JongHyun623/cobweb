#ifndef MYVIDEOCAPTURE_H
#define MYVIDEOCAPTURE_H

#include <QPixmap>
#include <opencv2/opencv.hpp>

#define ID_CAMERA 0

#include <QImage>
#include <QThread>
class MyVideoCapture : public QThread
{
    Q_OBJECT
public:
    MyVideoCapture(QObject *parent = nullptr);

    QPixmap pixmap() const
    {
        return mPixmap;
    }
signals :
    void newPixmapCaptured();
protected:
    void run() override;
public:
    QPixmap mPixmap; // Image -> QT
    cv::Mat mFrame; // Image -> OpenCV
    cv::VideoCapture mVideoCap; // Capture the video

    QImage cvMatToQImage(const cv::Mat &inMat);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);
};

#endif // MYVIDEOCAPTURE_H
