#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <QList>

#include <QDebug>

Enemy::Enemy()
{

    int random_number = rand() % 700;
    setPos(random_number, 0);

    setRect(0,0,100,100);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);// msec
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y() + 5);

    if (y() + rect().height() > scene()->height()) {
        scene()->removeItem(this);

        delete this;


        qDebug() << "Enemy deleted.";
    }
}
