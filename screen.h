#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>

class screen : public QWidget
{
    Q_OBJECT

public:
    screen(QWidget *parent = nullptr);
    ~screen();
};
#endif // SCREEN_H
