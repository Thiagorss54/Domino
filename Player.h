#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <string>
using namespace std;

class Player{
    public:
    Player(vector<vector<int>>  mao_inicial,string);
    virtual void Jogar();
    bool validarJogada(vector<int>);
    void MostrarMao();
    vector<int> pecaInvertida(vector<int>);
    void removerPeca(vector<int>);
    vector<vector<int>> getMao(){return mao;}
    string getNome(){return nome;}
    


    private:
    vector<vector<int>> mao;
    string nome;

};

#endif // !PLAYER_H_