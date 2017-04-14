#include "MyRect.h"
#include <QDebug>
#include <QtWidgets>
#include "Bullet.h"
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (x() > 0) {
            setPos(x() - 10, y());
        }
    }
    else if (event->key() == Qt::Key_Right) {
        if (x() + rect().width() < scene()->width()) {
            setPos(x() + 10, y());
        }
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet * bullet = new Bullet();

        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }


}

void MyRect::spawn()
{
    // Create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

    qDebug() << "Enemy added";
}
