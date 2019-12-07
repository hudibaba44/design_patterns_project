#include <QApplication>
#include "Game.h"
#include <QTest>
//#include "Player.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game *game = new Game();
    game->show();

    for(int i=0;i<100;i++){
        QTest::qWait(100);
        game->timeComponent->update(game->player);
    }

    return a.exec();
}
