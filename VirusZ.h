/***************************************************************************
* Name: Briana Rovelli and Maleesia Ragins
*
* Completed December 12, 2019 9:30 PM
*
* Function: Implemented the VirusZ class prototypes.
*
* Input:  Inputs listed and specified below each function.
*
* Output:   Outputs listed and specified below each function
*
* Additional Comments:
*
*
***************************************************************************/

#ifndef VirusZ_h
#define VirusZ_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Virus.h"

using namespace std;

class VirusZ: public Virus
{
        public:
        //constructors
        VirusZ(); //default constructor
        VirusZ(int, int); //row and col
        
        //functions
        int getRow(); //return row
        int getCol(); //return column
        void setRow(int); //set row
        void setCol(int); //set column
        void setLoc(int, int); //set location
            
};
#endif /* VirusZ_h */
