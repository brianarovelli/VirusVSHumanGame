/***************************************************************************
* Name: Briana Rovelli and Maleesia Ragins
*
* Completed December 12, 2019 9:30 PM
*
* Function: Implemented the framework of the game in Main
*
* Input:  Inputs listed and specified below each function.
*
* Output:   Outputs listed and specified below each function
*
* Additional Comments:
*
*
***************************************************************************/
#include <cstdio>
#include <iostream>
#include <string>
#include "Earth.h"

using namespace std;

int main()
{
    Earth ea;
    string cont;
    
    bool boardFull = false;
    while(!boardFull && ea.getYear() < 100) //100 years
    {
        cout << "Year " << ea.getYear() << endl;
        ea.PrintGrid(); //print current grid
        ea.increaseYear(); //+1 day
        
        if(ea.lastHuman() == true)
            break;
        
        ea.UpdateGrid(); //apply rules
        
        cout << "Type 'EXIT' to exit or type 'c' to continue" << endl;
        //will continue with any letter, but c looks nice
        cin >> cont;
        if(cont == "EXIT") //end session
            break;
        boardFull = ea.checkBoard();
    }
    ea.PrintGrid(); //print current grid
    
    if(ea.numHuman() > ea.numInfect())
        cout << "More humans on the board! Humans win!" << endl;
    else if (ea.numHuman() < ea.numInfect())
        cout << "More viruses on the board! Viruses win" << endl;
    else
        cout << "It's a draw!" << endl;
    
    cout << "Thank you for playing! " << endl;
    return 0;
}
