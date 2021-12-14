#ifndef BOT_H_
#define BOT_H_

#include "Player.h"
#include <vector>
#include <string>

using namespace std;
class Bot:public Player{
    public:
        Bot(vector<vector<int>> mao_inicial,string n):Player(mao_inicial,n){}
        void Jogar() override;

};


#endif // !BOT_H_
