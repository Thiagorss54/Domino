#include "Player.h"
#include "Game.h"
#include <vector>
#include <iostream>
#include <list>
#include <windows.h>


using namespace std;

extern Game * game;
Player::Player(vector<vector<int>> mao_inicial,string n):mao(mao_inicial),nome(n){}

void Player::Jogar(){
    vector<int> jogada;
    int buff;
    cin >> buff;
    jogada.push_back(buff);
    cin >> buff;
    jogada.push_back(buff);
                               ///////////////
    if(buff==7){
        game->addTexto(nome,"Passei :(");
        //game->setJog(game->getDificuldade()-1);
    }
    else if(validarJogada(jogada)){ 
       game->addTexto(nome,"Ja joguei");
    }else{
        Jogar();
    }
    
    
}
void Player::MostrarMao(){
     for(int i =0; i< mao.size();++i){
        cout << "[ "<<mao[i][0] << " | " << mao[i][1] <<" ]" << endl;
    }
}
bool Player::validarJogada(vector<int> jogada){
    for(int i =0; i<mao.size();++i){
     
       
         if(jogada==mao[i]||pecaInvertida(jogada)==mao[i]){// se eu tenho a peca
            if(game->getMesa().empty()){          
                game->addMesa(jogada,1);
                removerPeca(jogada);
                return 1;
            }else if(jogada[0]==game->getPontasED()[0]){          //se cabe do lado esquerdo
                game->addMesa(pecaInvertida(jogada),0);
                removerPeca(jogada);
                return 1;
            }else if(jogada[0]==game->getPontasED()[1]){    // se cabe do lado direito
                game->addMesa(jogada,1);
                removerPeca(jogada);
                return 1;
            }
        }
    }
    return 0;
}
vector<int> Player::pecaInvertida(vector<int> jogada){
    vector<int> aux;
    aux.push_back(jogada[1]);
    aux.push_back(jogada[0]);

    return aux;
}
void Player::removerPeca(vector<int> jogada){
    auto u = mao.begin();
    for(int i =0; i<mao.size();++i){
        if(jogada==mao[i]||pecaInvertida(jogada)==mao[i]){ //posso nao precisar desse ou quando for colocar em validar jogada (la ja tem a condicap)
            mao.erase(u);
        }
    ++u;
    }
}
