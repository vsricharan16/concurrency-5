#include <QApplication>
#include "Game.h"
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include<QElapsedTimer>
#include<QMediaPlayer>
#include "Button.h"

Game * game;
QMediaPlayer *bulletsound;
void sound_func()   //the function to run the sound of bulle shot concurrently
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/resources/sound/bullet.wav"));
    if(bulletsound->state()==QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else
       {
        bulletsound->setMedia(QUrl("qrc:/sound/resources/sound/bullet.wav"));
        bulletsound->play();
       }
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
	QMovie *movie = new QMovie(":/images/resources/images/loading.gif");
	
    if(!movie->isValid())
        {
            qDebug() << "ERROR(main.cpp) -> Failed To Load : resources/images/loading.gif";
            std::exit(EXIT_FAILURE);
        }
    QLabel *label = new QLabel;


    label->setMovie(movie);

    movie->start();
    label->show();
        QElapsedTimer timer;
         timer.start();

	QTimer::singleShot(3000,label,SLOT(close()));
       QTimer::singleShot(3000,game,SLOT(show()));
       game->displayMainMenu();

    return a.exec();
}
