#pragma once
#include<vector>
#include <QWidget>
#include<QPainter>

class MNMVisualizator : public QWidget
{
public:
    explicit MNMVisualizator(QWidget *parent = nullptr);
    void setPoints(const std::vector<std::vector<double>>& _points);
    void setIterForVisual(unsigned int ifv);
    void resetPoints(){points.clear();}
    void setMultipleVisual(bool flag){ multiple_visual = flag;}
protected:
    void paintEvent(QPaintEvent* pe) override;
private:
    std::vector<QPointF> points;
    unsigned int iteration_for_visual = -1;
    std::vector<QPointF> getCurrentSimplex(const std::vector<QPointF>&,int);
    void setQPainter(QPainter& painter);
    QPolygonF getScalesAndCentredSimplex(std::vector<QPointF> &);
    bool multiple_visual = false;

};

