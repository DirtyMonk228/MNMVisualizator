#ifndef MNMWIDGET_H
#define MNMWIDGET_H
#include"mnmvisualizator.h"
#include <QWidget>
#include<QCheckBox>
#include<QLineEdit>
#include<QPushButton>
#include<QLabel>
#include"rosenbrock_func.h"
class MNMWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MNMWidget(QWidget *parent = nullptr);

public slots:
    void startMNM();
private slots:
    void visualBtnClick(){
        visualizator->setIterForVisual(iteration_for_visual->text().toUInt());
        visualizator->setMultipleVisual(multiple_button->isChecked());
        visualizator->update();
    }

private:
    MNMVisualizator* visualizator = new MNMVisualizator;
    QPushButton* start_btn = new QPushButton("Старт");
    QPushButton* visualizate_btn = new QPushButton("Отобразить");
    QLineEdit* x_input = new QLineEdit;
    QLineEdit* y_input = new QLineEdit;
    QLineEdit* count_iteration_input = new QLineEdit;
    QLabel* min_x_output = new QLabel;
    QLabel* min_y_output = new QLabel;
    QLabel* min_func_value_output = new QLabel;
    QLabel* result_count_iteration = new QLabel;
    QLineEdit* iteration_for_visual = new QLineEdit;
    QCheckBox* multiple_button = new QCheckBox("Мульти режим");


    std::vector<double> start = std::vector<double>(2);//стартовая точка для алгоритма
    double accuracy = 0.0000001;//точность


};

#endif // MNMWIDGET_H
