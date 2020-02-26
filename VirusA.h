/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12, 2019, 9:30pm
 *
 * Function: Implemented the VirusA class headers
 *
 * Input:  Inputs listed and specified below each function in the executable.
 *
 * Output:   Outputs listed and specified below each function in the executable.
 *
 * Additional Comments:
 *
 *
 ***************************************************************************/
#ifndef VirusA_h
#define VirusA_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Virus.h"
using namespace std;

class VirusA : public Virus
{
    public:
        //constructors
        VirusA();
        VirusA(int, int);

    
        //methods
        int getRow(); //return row
        int getCol(); //return column
        void setRow(int); //set row
        void setCol(int); //set column
        void setLoc(int, int); //set location
};

#endif /* VirusA_h */
