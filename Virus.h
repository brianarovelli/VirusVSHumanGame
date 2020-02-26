/***************************************************************************
* Name: Briana Rovelli and Maleesia Ragins
*
* Completed December 12, 2019, 9:30pm
*
* Function: Implemented the VirusAclass headers
*
* Input:  Inputs listed and specified below each function in the executable.
*
* Output:   Outputs listed and specified below each function in the executable.
*
* Additional Comments:
*
*
***************************************************************************/

#ifndef Virus_h
#define Virus_h
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

class Virus
{
    
    public:
        Virus() {};
    
    virtual int getRow() = 0; //get row
    virtual int getCol() = 0; //get column
    virtual void setRow(int) = 0; //set row
    virtual void setCol(int) = 0; //set column
    virtual void setLoc(int, int) = 0; //set location
    
    protected:
    int row;
    int col;
    
};


#endif /* Virus_h */
