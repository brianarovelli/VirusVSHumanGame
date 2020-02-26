/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12, 2019, 9:30pm
 *
 * Function: Implemented the Earth class headers
 *
 * Input:  Inputs listed and specified below each function in the executable.
 *
 * Output:   Outputs listed and specified below each function in the executable.
 *
 * Additional Comments:
 *
 *
 ***************************************************************************/
#ifndef Earth_h
#define Earth_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "World.h"
#include "Human.h"
#include "VirusA.h"
#include "VirusZ.h"
using namespace std;

class Earth : public World
{
	public:
		//constructors
		Earth();

        //variables
        int infectNum; //number of viruses
        int humanCount; //number of humans
    
		//methods
		void PrintGrid(); //prints grid
		void UpdateGrid(); //applies rules to grid
    
        int getYear(); //changing day to year, but can't change world.h
        void increaseYear(); //day to year, year++
    
        bool checkBoard(); //checks if board is full
    
        bool lastHuman(); //checks if one human is left
    
        int numInfect(); //return infectNum
        int numHuman(); //return humanCount

	protected:
        vector<Human> vect; //all humans on grid
        vector<VirusA> infectA; // all viruses A on grid
        vector<VirusZ> infectZ; // all viruses Z on grid
    
        void initGrid(); //set up grid
        void moveGrid(); //rule 1: move grid
    
        bool checkBounds(int, int); //check if out of bounds EDIT THIS
        bool checkEmpty(int, int); //true if empty, false if not
        void chooseDirection(int&, int&); //direction to move
        void changeMapLoc(int, int, int, int); //change location on map
    
        Human& findatPointHU(int, int); //find Human object at point
        void humanInfected(int, int); //delete human
        void printHumans();
        
        void spawnChild(); //rule 2: humans meet, have child
        void spawnDoctor(); //rule 9: spawn doctor
        void spawnVirusA(); //spawn new virus A
        void spawnVirusZ(); //spawn new virus Z
};

#endif /* Earth_h */
