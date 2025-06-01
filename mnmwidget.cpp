#include "mnmwidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include"neldermead.h"
#include<iostream>
MNMWidget::MNMWidget(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(840,590);
    x_input->setPlaceholderText("Введите X");
    y_input->setPlaceholderText("Введите Y");
    count_iteration_input->setPlaceholderText("Введите кол-во итераций");
    iteration_for_visual->setPlaceholderText("Введите № итерации для отображения");
    QVBoxLayout* main_layout=new QVBoxLayout;
        QHBoxLayout* h_layout = new QHBoxLayout;
            h_layout->addWidget(visualizator);
            QVBoxLayout* v_layout=new QVBoxLayout;
                v_layout->addWidget(x_input);
                v_layout->addWidget(y_input);
                v_layout->addWidget(count_iteration_input);
                v_layout->addWidget(iteration_for_visual);
                v_layout->addWidget(multiple_button);
                v_layout->addWidget(min_x_output);
                v_layout->addWidget(min_y_output);
                v_layout->addWidget(min_func_value_output);
                v_layout->addWidget(result_count_iteration);
            h_layout->addLayout(v_layout);
        main_layout->addLayout(h_layout);
        main_layout->addWidget(start_btn);
        main_layout->addWidget(visualizate_btn);
    setLayout(main_layout);
    connect(start_btn,SIGNAL(clicked()),this,SLOT(startMNM()));
    connect(visualizate_btn,SIGNAL(clicked()),this,SLOT(visualBtnClick()));
}

void MNMWidget::startMNM(){
    visualizator->resetPoints();
    int count_iteration = count_iteration_input->text().toInt();
    start[0] = x_input->text().toDouble();
    start[1] = y_input->text().toDouble();
    NelderMead nm(accuracy, count_iteration);


    NMResult result = nm.optimize(rosenbrock, start,
                                  [this](const std::vector<std::vector<double>>& points){this->visualizator->setPoints(points);});
    min_x_output->setText("Значение Х в минимуме:"+QString::number(result.minimum[0]));
    min_y_output->setText("Значение Y в минимуме:"+QString::number(result.minimum[1]));
    min_func_value_output->setText("Минимум функции:"+QString::number(result.value));
    result_count_iteration->setText("Всего итераций:"+QString::number(result.iterations));
}
