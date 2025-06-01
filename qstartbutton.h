#ifndef QSTARTBUTTON_H
#define QSTARTBUTTON_H
#include<QPushButton>
#include"neldermead.h"
#include"mnmvisualizator.h"
#include<iostream>
#include<vector>
/
class QStartButton:public QPushButton
{
    Q_OBJECT
public:
    QStartButton(QWidget* parent = nullptr):QPushButton(parent){
        connect(this,SIGNAL(clicked()),this,SLOT(startMNM()));
        visualizator.show();
    }
private slots:

private:

};

#endif // QSTARTBUTTON_H
