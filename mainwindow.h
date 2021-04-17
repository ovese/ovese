#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include <QtCore>
#include <QtGui>
#include <QtOpenGL/QtOpenGL>


#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QComboBox>
#include <QScrollArea>
#include <QTextEdit>

#include <QDialog>
//#include <qtimgui>

#include <cstdint>
#include <cstdlib>

using namespace std;

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onComboboxCurrentIndexChanged();
    void onComboboxCurrentIndexChanged(const QString &text);
    void onComboboxCurrentTextChanged(const QString &text);
    void OpenShapeFile(QChar *filename);
    void draw();
    void paintGL();


private:
    QLabel *imageLabel;
    QComboBox *qcb;
    QScrollArea *scrollArea;
    QChar *ptr_shp1;
};
#endif // MAINWINDOW_H
