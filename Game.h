#ifndef GAME_H_
#define GAME_H_

#include "Domino.h"
#include "Player.h"
#include "Bot.h"
#include <list>

class Game{
    public:
        Game();
        void run();
        void draw();
        void atualizarPontas();
        list<vector<int>> getMesa(){return mesa;}
        vector<int> getPontasED(){return pontasED;}
        void addMesa(vector<int>,int); //vai receber a peca a ser adicionada e 0 para adicionar na esquerda ou 1 pra adicionar na direita do list
        void isTheGameOver();
        bool fechouOjogo();
        ~Game();
        void addTexto(string,string);
        int somarPontos(vector<vector<int>>);
        void winer(string);
        void setDificudade(int a){DIFICUDADE = a;};
        int getDificuldade(){return DIFICUDADE;}
        void setJog(int a){jog =a;}
        int getJog(){return jog;}
    private:
        list<vector<int>> mesa;
        vector<int> pontasED;
        Domino * domino;
        Player * player;
        Bot * bot1;
        Bot * bot2;
        Bot * bot3;
        bool gameover;
        int vez;
        vector<string> texto;
        int DIFICUDADE;
        int jog;
};

#endif // !GAME_H_
