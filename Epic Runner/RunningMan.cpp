#include <iostream>
#include "RunningMan.hpp"

using namespace std;

void RunningMan::drawObjects()
{   
    int k = 0; 
    while (k < man.size()){        //iterating over the vector to make the object 
        if (k==1){
        screen = true;
        man[k]->draw();             // calling the draw function
        if (left==true){
            if ( (man[k] ->moverRect.x - 130) < 0 )
                {man[k] ->moverRect.x = 0;}
            else {man[k] ->  moverRect.x -= 130;}           
                left = false;}
        if (right==true){
            if ( (man[k] ->moverRect.x + 130) > 980 )
                {man[k] ->moverRect.x = 980;}
            else{man[k] ->  moverRect.x += 130;}  
                right = false;}
        if (checks==true){
            man[k] -> check = true;
            checks = false;}
        if (man[k] -> check ==true){
        man[k]->jump();}
        else{
        man[k]->fly();}  }       // calling the fly function
        k++;}

    int w = 0;   //coin coin coin 
    while (w < coins_as.size()){        //iterating over the vector to make the object 
        int x_values = (man[1]->moverRect.x - coins_as[w]-> moverRect.x);
        int y_values = (man[1]->moverRect.y - coins_as[w]-> moverRect.y);
        if (w>0){
        coins_as[w]->draw();
        coins_as[w]->move();
        }
        if ((coins_as[w]->count == 3) || ((x_values < 20 && x_values > -20) && (y_values < 10 && y_values > -10))){
        coins_as.erase(coins_as.begin()+w);
        coin_check = true;}
        w++;
        }

    int t = 0;

    while (t < cactuses.size()){        //iterating over the vector to make the object 
        int x_values = (man[1]->moverRect.x - cactuses[t]-> moverRect.x);
        int y_values = (man[1]->moverRect.y - cactuses[t]-> moverRect.y);
        if (t>0){
        cactuses[t]->draw();
        cactuses[t]->move();
        }
        if ( (cactuses[t]->count == 3) || ( (x_values < 10 && x_values > -10) && (y_values < 10 && y_values > -10) )){
        cactuses.erase(cactuses.begin()+t);
        life_check = true;}
        t++;
        }
    t = 0;

    while (t < beasts.size()){        //iterating over the vector to make the object 
        int x_values = (man[1]->moverRect.x - beasts[t]-> moverRect.x);
        int y_values = (man[1]->moverRect.y - beasts[t]-> moverRect.y);
        if (t>0){
        beasts[t]->draw();
        beasts[t]->move();
        }
        if ( (beasts[t]->count == 3) || ( (x_values < 10 && x_values > -10) && (y_values < 10 && y_values > -10) )){
        beasts.erase(beasts.begin()+t);
        life_check = true;}
        t++;
        }

    t = 0; 
    while (t < living.size()){        //iterating over the vector to make the object 
        living[t]->draw();
        if (life_check == true)
        {living[t] -> l_left-- ;
        life_check = false;}
        t++;
        }

    t = 0; 
    while (t < coins.size()){        //iterating over the vector to make the object 
        coins[t]->draw();
        if (coin_check == true)
        {coins[t] -> counts++ ;
        coin_check = false;}
        t++;
        }

}

void RunningMan::createObject(int x, int y)
{
    // TODO: create an object randomly, and push it into corresponding vector
    if (man.size()<2){
    Man *man1 = new Man(x,y);
    man.push_back(man1);}

    if (living.size()<1){
    lives *liv = new lives();
    living.push_back(liv);}

    if (coins.size()<1){
    coins_b *cin = new coins_b();
    coins.push_back(cin);}
}

void RunningMan::createObj()
{
    tick ++;
    if (tick >25){
    cout << "created"<<endl;
    int number = (rand() % 3); 
     if (number == 0)
        {
            coins_a *app1 = new coins_a(30,500);
            coins_as.push_back(app1); 
        }
        else if (number ==  1)
        {
            cactus *cac = new cactus(30,500);
            cactuses.push_back(cac);
        }
        else if (number ==  2)
        {
            animal *beast = new animal(30,500);
            beasts.push_back(beast);
        }
    tick = 0;}

}