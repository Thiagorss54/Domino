#include "Game.h"


Game * game;
int main(){
    while(true){
    game = new Game();
    game->run();
    
    cout<< endl << endl;
    system("pause");
    }
    delete game;
    return 0;
}
// g++ -o a main.cpp game.cpp game.h domino.cpp domino.h player.cpp player.h bot.cpp bot.h