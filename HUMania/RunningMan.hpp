#include<SDL.h>
#include "man.hpp"
#include "cactus.hpp"
#include "lives.hpp"
#include "coins_a.hpp"
#include "weapon.hpp"
#include "coins_b.hpp"
#include "animal.hpp"
#include<vector>
#include<list>
using namespace std;

class RunningMan{

    Man man1;
    coins_a app1;
    cactus cac;
    lives liv;
    coins_b cin;
    weapon knife;
    animal beast;
    vector<Man*> man;
    vector<weapon*> weapons;
    vector<coins_a*> coins_as;
    vector<cactus*> cactuses;
    vector<lives*> living;
    vector<animal*> beasts;
    vector<coins_b*> coins;

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