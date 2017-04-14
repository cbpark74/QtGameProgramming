#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Bullet();

signals:

public slots:
    void move();
};

#endif // BULLET_H
