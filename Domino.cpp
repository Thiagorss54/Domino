#include "Domino.h"
#include "Game.h"
#include <cmath>
#define NUM_PECAS 28
using namespace std;

extern Game * game;
void Show( vector<vector<int>> const x){
    for(int i =0; i< x.size();++i){
        cout << "[ "<<x[i][0] << " | " << x[i][1] <<" ]" << endl;
    }
}

Domino::Domino(){
    int p[][2]={
        {6,6},{6,5},{6,4},{6,3},{6,2},{6,1},{6,0},
        {5,5},{5,4},{5,3},{5,2},{5,1},{5,0},
        {4,4},{4,3},{4,2},{4,1},{4,0},
        {3,3},{3,2},{3,1},{3,0},
        {2,2},{2,1},{2,0},
        {1,1},{1,0},
        {0,0}
        };
    for(int i = 0; i<NUM_PECAS;++i){
        vector<int> buffer;
        for(int j = 0; j<2;++j){
            buffer.push_back(p[i][j]);
        }
        pecas.push_back(buffer);
    }
 
    Shuffle();


    

}

void Domino::Shuffle(){ 
    vector<vector<int>> pecas_copia;
    vector<int> buffer;
    pecas_copia = pecas;
    pecas.clear();
    int r;
    srand(time(0));
    for( int i =0; i< NUM_PECAS ; ++i){
         r =  rand() % pecas_copia.size();
         auto u = pecas_copia.begin();
         for(int a = 0; a < r;++a){
             ++u;
         }
         buffer = *u;
         pecas.push_back(buffer);
         pecas_copia.erase(u);
         
    }

    //Show(pecas);


}
vector<vector<int>> Domino::getPecas(int n){
    vector<vector<int>> setepecas;
    int pos=n*7;
    for(int i = 0;i<7;++i){
        setepecas.push_back(pecas[i+pos]);
    }
    return setepecas;
}
int Domino::quemComeca(){
    double aux;
    int resposta;
    for(double i=0;i<NUM_PECAS;++i){
        if(pecas[i]==vector<int>(2,6)){
           aux =i/7;
           resposta = (int) aux;
           break;
        }
       
    }
    return resposta;

}