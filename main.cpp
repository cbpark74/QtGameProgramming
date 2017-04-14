//#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QtWidgets>

#include "MyRect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create a brush
    QBrush brush;
    brush.setColor(Qt::GlobalColor::red);
    brush.setStyle(Qt::BrushStyle::SolidPattern);

    // create an item to put into the scene
    MyRect * player = new MyRect();
    player->setBrush(brush);
    player->setRect(0, 0, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the item to the scene
    scene->addItem(player);

    // create a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(800, 600);

    scene->setSceneRect(0,0,800, 600);
    player->setPos(view->width()/2, view->height() - player->rect().height() );

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);
    return a.exec();
}
