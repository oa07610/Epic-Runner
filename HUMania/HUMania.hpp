#include<SDL.h>
#include "bee.hpp"
#include "cactus.hpp"
#include "lives.hpp"
#include "coin.hpp"
#include "weapon.hpp"
#include "hh.hpp"
#include<vector>
#include<list>
using namespace std;

class HUMania{

    //Right now we're creating one pigeon, 
    Bee bee1;
    apple app1;
    cactus cac;
    lives liv;
    coin cin;
    weapon knife;
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Bee*> bee;       //vector for Pigeon
    vector<weapon*> weapons;
    vector<apple*> apples;
    vector<cactus*> cactuses;
    vector<lives*> living;
    vector<coin*> coins;

    public:
    bool coin_check = false;
    bool weapon_check = false;
    bool w_check = false;
    int tick = 0 ;
    bool life_check = false;
    bool checks = false ;
    bool left = false ;
    bool right = false ;
    void drawObjects();                    //prototype
    void createObject(int, int);          //prototype
    void createObj(); 
    
};