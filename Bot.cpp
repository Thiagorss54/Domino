#include "Bot.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include <list>


using namespace std;
extern Game * game;
void Bot::Jogar(){
    if(game->getMesa().empty()){
        for(int i =0;i<getMao().size();++i){
            if(getMao()[i]==vector<int>(2,6)){
                if(validarJogada(getMao()[i])){
                    game->addTexto(getNome(),"Simbora");
                    return;
                }            
            }
        }
    }
    for(int i =0;i<getMao().size();++i){
        
        if(validarJogada(getMao()[i])){
            game->addTexto(getNome(),"Eu mesmo ja joguei ");
            return;
        }else if(validarJogada(pecaInvertida(getMao()[i]))){
            game->addTexto(getNome(),"Eu mesmo ja joguei ");
            return;
        }

    }
    game->addTexto(getNome(),"Passei ze ruela");

}