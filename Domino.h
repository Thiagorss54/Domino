#ifndef DOMINO_H_
#define DOMINO_H_

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
using namespace std;


class Domino{
    public:
        Domino();
        void Shuffle();
        vector<vector<int>> getPecas(int);
        int quemComeca();
    private:
        vector<vector<int>> pecas;
        

    
};

#endif // !DOMINO_H_
