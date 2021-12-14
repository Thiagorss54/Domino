#include "Game.h"
#include <windows.h>

#define DIFICULDADE_ 10000

const int tempo_=4000;
Game::Game(){

    
    gameover =0;
    domino = new Domino();
    player = new Player(domino->getPecas(0),"Voce");
    bot1 = new Bot(domino->getPecas(1),"Bot1");
    bot2 = new Bot(domino->getPecas(2),"Bot2");
    bot3 = new Bot(domino->getPecas(3),"Bot3");

}
void Game::run(){
    jog = 0;
    vez = domino->quemComeca();
    int dif;
    // cout << "Dificuldade: ";
    // cin >> dif;

    setDificudade(DIFICULDADE_);
    
    while(!gameover){
        
        draw();

         if(vez==0){player->Jogar();}
         else if(vez ==1){bot1->Jogar();Sleep(tempo_);}
         else if(vez ==2){bot2->Jogar();Sleep(tempo_);}
         else if(vez ==3){bot3->Jogar(); vez=-1;Sleep(tempo_);}

      
       
        //atualizar as pontas
        if(!mesa.empty()){
            atualizarPontas();
            //testar se o jogo acabou
            isTheGameOver();
        }
         vez++;
         jog++;
        
    }
       
}

//player 0 bot1 1 bot2 2 bot33

 void Game::addMesa(vector<int> p,int ed){
     if(ed==0){
         mesa.push_front(p);
     }else if(ed==1){
         mesa.push_back(p);
     }
 }
 void Game::isTheGameOver(){
     draw();
     //acabou as pecas
     if(player->getMao().empty()){cout<< "          YOU WIN!";gameover=1;}
     else if(bot1->getMao().empty()){cout<< "           BOT1 WIN!!!";gameover=1;}
     else if(bot2->getMao().empty()){cout<< "           BOT2 WIN!!!";gameover=1;}
     else if(bot3->getMao().empty()){cout<< "           BOT3 WIN!!!";gameover=1;}

    // fechou o jogo
    else if(fechouOjogo()){

        gameover=1;
    }
 }
 bool Game::fechouOjogo(){
    vector<vector<int>> pecas_nao_jogadas;

    for(int i = 0; i< player->getMao().size();++i){
        pecas_nao_jogadas.push_back( player->getMao()[i]);
    }
    for(int i = 0; i< bot1->getMao().size();++i){
        pecas_nao_jogadas.push_back( bot1->getMao()[i]);
    }
    for(int i = 0; i< bot2->getMao().size();++i){
        pecas_nao_jogadas.push_back( bot2->getMao()[i]);
    }
    for(int i = 0; i< bot3->getMao().size();++i){
        pecas_nao_jogadas.push_back( bot3->getMao()[i]);
    }
    //testar se nenhuma peca cabe mais 
    for(int t =0; t<pecas_nao_jogadas.size();++t){
        if(pecas_nao_jogadas[t][0]==pontasED[0]||pecas_nao_jogadas[t][1]==pontasED[0])   
                return 0;
        else if(pecas_nao_jogadas[t][0]==pontasED[1]||pecas_nao_jogadas[t][1]==pontasED[1])
                return 0;

    }
    addTexto("GAME: ","ALGUM CORNO FECHOU O JOGO!");
     if(vez == 0){
         if(somarPontos(player->getMao()) < somarPontos(bot1->getMao()) ){
                 winer("PLAYER");
         }else if(somarPontos(player->getMao()) > somarPontos(bot1->getMao())){
                 winer("BOT1");
        }else{
            addTexto("GAME: ","EMPATE");
        }
    }else if(vez==1){
        if(somarPontos(bot1->getMao()) < somarPontos(bot2->getMao()) ){
                 winer("BOT1");
        }else if(somarPontos(bot1->getMao()) > somarPontos(bot2->getMao()) ){
                 winer("BOT2");
        }else{
            addTexto("GAME: ","EMPATE");
        }

    }else if(vez == 2){
        if(somarPontos(bot2->getMao()) < somarPontos(bot3->getMao()) ){
                winer("BOT2");
        }else if(somarPontos(bot2->getMao()) > somarPontos(bot3->getMao()) ){
                winer("BOT3");
        }else{
            addTexto("GAME: ","EMPATE");
        }

    }else if(vez == -1){
        if(somarPontos(bot3->getMao())< somarPontos(player->getMao()) ){
            winer("BOT3");
        }else if(somarPontos(bot3->getMao()) > somarPontos(player->getMao()) ){
            winer("PLAYER");
        }else{
            addTexto("GAME: ","EMPATE");
        }

    }
    return 1;

 }
 void Game::winer(string vencedor){
     cout <<"\t\t\t\t\t\t"<< vencedor << " FOI O VENCEDOR!!";
 }
 void Game::atualizarPontas(){
    if(!pontasED.empty())
        pontasED.clear();
    
    auto esquerda = mesa.begin();
    auto direita = --mesa.end();
   
    pontasED.push_back((*esquerda)[0]);
    
    pontasED.push_back((*direita)[1]);
    
 }
void Game::draw(){
    system("cls");
    // quantidade de pecas
    cout<< "Bot1: " << bot1->getMao().size() <<"            Bot2: " <<bot2->getMao().size() << "            Bot3: " <<bot3->getMao().size();
    cout<< endl << endl << endl;
    //mesa
    if(!mesa.empty()){
        int posi=0;
        for(auto tab = mesa.begin();tab!=mesa.end();++tab){
            if(*tab == vector<int>(2,6)){
                    for(int e = 0; e<11-posi;++e)
                        cout<< "      ";
                break;
            }
            ++posi;
        }

        for(auto u = mesa.begin();u!=mesa.end();++u){
            cout << "["<<(*u)[0] << "|" << (*u)[1] <<"] " ;
        }
    }
    cout<< endl << endl << endl << endl << endl << endl;

    for(auto it=texto.begin();it!=texto.end();++it){
        cout<<*it<< endl ;
    }
    if( jog < DIFICUDADE)
            player->MostrarMao();
    cout<< endl << endl ;
    

}
void Game::addTexto(string n,string txt){
    string aux;
    aux = n + ": " + txt;
    texto.push_back(aux);
}
int Game::somarPontos(vector<vector<int>> m){
    int soma=0;
    for(int i = 0;i<m.size();++i){
        soma+= m[i][0] + m[i][1];
    }
    return soma;

}
Game::~Game(){
    delete domino;
    delete player;
    delete bot1;
    delete bot2;
    delete bot3;
   
}