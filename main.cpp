#include "pichistogrammanager.h"
#include "singlehistogram.h"
#include "histowitheditboxes.h"
#include "Shared/openglpicviewer.h"

#include <QApplication>
#include <QtWidgets>
#include <opencv2/opencv.hpp>


int openCVbasicDemo(QApplication *app);
int graphicSceneDemo(QApplication *app);

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    PicHistogramManager histmgr;
    SingleHistogram hist;
    HistoWithEditboxes histBoxed;
    OpenGLPicViewer * openGLPic;
    OpenGLPicViewer * openGLPicIgnoreAR;
    OpenGLPicViewer * openGLPicKeepAR;
    OpenGLPicViewer * openGLPicKeepARExpand;

    int demoSelect = 5;

    switch (demoSelect)
    {
    case 0:
        // All histogram widgets
        histmgr.show();
        hist.show();
        histBoxed.show();
        return app.exec();
        break;

    case 1:
        // Histogram manager only
        histmgr.show();
        return app.exec();
        break;

    case 2:
        // OpenCV basic demo
        return openCVbasicDemo(&app);
        break;

    case 3:
        // Basic QGraphicScene demo
        return graphicSceneDemo(&app);
        break;

    case 4:
        // Basic QOpenGLWidget demo
        openGLPic = new OpenGLPicViewer();
        openGLPic->show();
        return app.exec();
        break;

    case 5:
        // 3 QOpenGLWidgets with 3 aspect ratios
        openGLPicIgnoreAR = new OpenGLPicViewer();
        openGLPicKeepAR = new OpenGLPicViewer();
        openGLPicKeepARExpand = new OpenGLPicViewer();

        openGLPicIgnoreAR->setAspectRatioMode(Qt::IgnoreAspectRatio);
        openGLPicKeepAR->setAspectRatioMode(Qt::KeepAspectRatio);
        openGLPicKeepARExpand->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);

        openGLPicIgnoreAR->show();
        openGLPicKeepAR->show();
        openGLPicKeepARExpand->show();

        return app.exec();
        break;
    }
}

