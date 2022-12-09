#include<SDL.h>
#include "man.hpp"
#include "cactus.hpp"
#include "lives.hpp"
#include "coins_a.hpp"
#include "coins_b.hpp"
#include "animal.hpp"
#include "Unit.hpp"
#include "ghost.hpp"
#include "meteor.hpp"
#include "explosion.hpp"
#include<vector>
#include<list>
using namespace std;

class RunningMan{
    vector<Man*> man;                       //Vector to store the man object
    vector<lives> living;                   //Vector to store the lives
    vector<explosion> explosive;            //Vector to store the explosives' objects
    vector<coins_b> coins;                  //Vector to store the top coins
    vector<coins_a*> coining;               //Vector to store the bottom/moving coins
    list <Unit*> objects;                   //List to store the rest of the polymorphised objects' pointers such as animal, ghosts etc

    public:
    bool coin_check = false;                //Checks if man has collected a coin
    bool lost_check = false;                //Checks if the game has been lost
    bool win_check = false;                 //Checks if the game has been won
    int tick = 0 ;                          //Counter to introduce delay
    bool life_check = false;                //Checks if a life is lost by collision with enemies
    bool checks = false ;                   //Checks if the user has pressed jump for the man
    bool left = false ;                     //Checks if the user has pressed left dash for the man
    bool right = false ;                    //Checks if the user has pressed right dash for the man
    int counter=0;                          //Checks how many man/lives object has been created
    void drawObjects();                     //Draws all the objects
    void createObject();                    //Creates and pushes all the objects to vectors
    void emptying();                        //Clears the vectors and deletes the pointers/everything

    ~RunningMan();                          //Destructor
};