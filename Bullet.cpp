#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>

#include "Enemy.h"

Bullet::Bullet()
{
    setRect(0,0,10,50);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);// msec
}

void Bullet::move()
{

    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    int n = colliding_items.size();
    qDebug() << "number of collisions = " << n;

    for (int i =0; i < n; i++)
    {

        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // remove both

            qDebug() << "collision detected" << endl;
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
    }


    // move bullet up
    setPos(x(), y() - 10);

    if (y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet deleted.";
    }
}
