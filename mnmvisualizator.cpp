#include "mnmvisualizator.h"
#include<thread>
#include<iostream>
#include<chrono>
MNMVisualizator::MNMVisualizator(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(500,500);
}

void MNMVisualizator::paintEvent(QPaintEvent* pe){
    QPainter painter(this);
    setQPainter(painter);
    painter.fillRect(0,0,width(),height(),Qt::white);
    for(int i = iteration_for_visual;i*3<points.size();++i){
        std::vector<QPointF> current_points = getCurrentSimplex(points,i);
        QPolygonF simplex = getScalesAndCentredSimplex(current_points);
        painter.drawPolygon(simplex);
        if(multiple_visual == false) break;
    }
}

void MNMVisualizator::setPoints(const std::vector<std::vector<double>>& _points){
    points.push_back(QPointF(_points[0][0],_points[0][1]));
    points.push_back(QPointF(_points[1][0],_points[1][1]));
    points.push_back(QPointF(_points[2][0],_points[2][1]));
}
void MNMVisualizator::setIterForVisual(unsigned int ifv){
    iteration_for_visual = ifv;
}

std::vector<QPointF> MNMVisualizator::getCurrentSimplex(const std::vector<QPointF>& all_points,int index_simplex){
    std::vector<QPointF> current_points;
    for(int i = index_simplex*3;i<index_simplex*3+3 && i<all_points.size();++i) current_points.push_back(all_points[i]);
    return current_points;
}
void MNMVisualizator::setQPainter(QPainter& painter){
    painter.setPen(QColor(255,20,147));
}
QPolygonF MNMVisualizator::getScalesAndCentredSimplex(std::vector<QPointF>& current_points){
    int scale = 6000;
    QPointF widget_center=QPointF(width()/2,height()/2);
    QPolygonF simplex;
    QPointF centroid(0,0);
    for(QPointF& point:current_points){//масштабируем симплекс и приводим к мат координатам + вычисляем центр масс
        point = QPointF(widget_center.x()+ point.x()*scale,
                        widget_center.y()-point.y()*scale);
        centroid+=point;
    }
    centroid/=3;
    QPointF perenos = centroid - widget_center;
    for(QPointF& point:current_points){//переносим симплекс в центр
        point-=perenos;
        simplex<<point;
    }
    return simplex;
}

