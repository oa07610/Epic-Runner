#include <iostream>
#include "RunningMan.hpp"

using namespace std;

void RunningMan::drawObjects()                                 //Draws all the objects
{   
    int k,t = 0; 
    
    while (t < explosive.size()){                              //Iterating over the vector to make the object 
        if (explosive[t].value <20){                           //Checking counter/timer variable
        explosive[t].draw();                                   //Calling the draw function
        explosive[t].value++;}                                 //Incrementing the counter/timer
        else{explosive.erase(explosive.begin() + t);}          //Removing from the vector
        t++;
        }

    while (k < man.size()){                                     //Iterating over the vector to make the object 
        if (k==0){                                              //Initial Object Creation
        man[k]->draw();                                         //Calling the draw function
    if (left==true){                                            //User has pressed left button
            if ( (man[k] ->moverRect.x - 130) < 0 )             //Checks the corner of the screen
                {man[k] ->moverRect.x = 0;}                     //The man object moves left
            else {man[k] ->  moverRect.x -= 130;}               //The man object moves left
                left = false;}
        if (right==true){                                       //User has pressed right button
            if ( (man[k] ->moverRect.x + 130) > 980 )           //Checks the corner of the screen
                {man[k] ->moverRect.x = 980;}                   //The man object moves right
            else{man[k] ->  moverRect.x += 130;}                //The man object moves right
                right = false;}
        if (checks==true){                                      //User has pressed jump button
            man[k] -> check = true;                             //Flag Variable
            checks = false;}
        if (man[k] -> check ==true){
        man[k]->jump();}                                        //Calling the Jump function
        else{
        man[k]->moving();}  }                                   //Calling the Move function
        k++;}

    t = 0;
    while (t < living.size()){                                  //Iterating over the vector to make the object 
        living[t].draw();                                       //Drawing the lives
        if (life_check == true)                                 //Lost a life by collision
        {--living[t];                                           //OPERATOR OVERLOADING to decrease the lives
        life_check = false;}                            
        if (living[t].l_left < 1){ lost_check = true ;}         //All lives lost then game lost sorry
        t++;
        }

    t = 0; 
    while (t < coins.size()){                                   //Iterating over the vector to make the object 
        coins[t].draw();                                        //Drawing the top bar coins
        if (coin_check == true)                                 //Coin collected
        {++coins[t];                                            //OPERATOR OVERLOADING to increase the coins' count                       
        coin_check = false;}
        if (coins[t].counts > 10){ win_check = true ;}          //10 coins collected, game won yay
        t++;
        }

    t = 0;
    while (t < coining.size()){                                 //Iterating over the vector to make the object 
        coining[t]->draw();                                     //Draw the bottom running coins
        coining[t]->move();                                     //Moving them
        if (((abs(man[0]->moverRect.x-(coining[t]->moverRect.x))<12) && (abs(man[0]->moverRect.y-(coining[t]->moverRect.y))<12))){ //Collision condition by comparing x & y values
        coin_check = true;
        delete coining[t];                                      //Deleting the object
        coining.erase(coining.begin() + t);                     //Removing from the vector
        }
        t++;
    }

    for (Unit* x: objects){                                     //Iterationg over Unit* type list for the rest of the obstacles
        x->draw();                                              //Draw the rest of the obstacles
        x->move();                                              //Moving them
        if ((x->moverRect.x<0) || (x->moverRect.y>515)){        //End of the screen
            objects.remove(x);}                                 //Remove
        
        if (((abs(man[0]->moverRect.x-(x->moverRect.x))<20) && (abs(man[0]->moverRect.y-(x->moverRect.y))<20))){    //Collision condition by comparing x & y values
            cout<<"collision occured"<<endl;
            life_check = true;                                  //Life lost
            explosion ex(x->moverRect.x, x->moverRect.y);
            explosive.push_back(ex);
            objects.remove(x);}                                 //Removing from the vector
        }   
    } 

void RunningMan::createObject()                     //Creates and pushes all the objects to vectors
{
    if (counter == 0){
        if (man.size()<1){
        Man *man1 = new Man();                      //Creates one man object pointer
        man.push_back(man1);}

        if (living.size()<1){
        lives liv;                                  //Creates one lives object
        living.push_back(liv);}

        if (coins.size()<1){                    
        coins_b cin;                                //Creates the top bar coins object
        coins.push_back(cin);}

        counter++ ;
    }

    tick ++;                                        //Delay

    if (tick >25){                                  //Delay Counter
    cout << "created"<<endl;
    int number = (rand() % 10);                     //Random generator
     if (number == 0)
        {
            coins_a *app1 = new coins_a();          //Bottom coins object creation
            coining.push_back(app1);                //Push to the vector
        }
        else if (number ==  1 || number ==  4 )
        {
            cactus *cac = new cactus();             //Zombie object creation
            objects.push_back(cac);                 //Push to the vector
        }
        else if (number ==  2 || number ==  5)
        {
            animal *beast = new animal();           //Animal object creation
            objects.push_back(beast);               //Push to the vector
        }
        else if (number ==  3 || number ==  6)
        {
            ghost *boo = new ghost();               //Ghost object creation
            objects.push_back(boo);                 //Push to the vector
        }
        else if (number == 7 || number == 8 || number == 9){
            meteor *rock = new meteor();            //Meteor object creation
            objects.push_back(rock);                //Push to the vector
        }
    tick = 0;}
}

void RunningMan::emptying(){                        //Clears the vectors and deletes the pointers/everything
    for(auto&& i : objects){                        
	delete i;}                                      //Deletes the pointers in objects list from the memory
    objects.clear();                                //Removes them from the vector
    for(auto&& i : man){
	delete i;}                                      //Deletes the pointers in man vector from the memory
    man.clear();                                    //Removes them from the vector
    for(auto&& i : coining){
	delete i;}                                      //Deletes the pointers in coins vector from the memory
    coining.clear();                                //Removes them from the vector

    living.clear();                                 //Removes the lives object from the vector
    coins.clear();                                  //Removes the coins' objects from the vector
    explosive.clear();                              //Removes the explosives' objects from the vector
}

RunningMan :: ~RunningMan(){                        //Destructor to remove the object of this class
}
