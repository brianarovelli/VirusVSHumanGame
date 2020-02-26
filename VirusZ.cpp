/***************************************************************************
* Name: Briana Rovelli and Maleesia Ragins
*
* Completed December 12, 2019 9:30 PM
*
* Function: Implemented the VirusZ class from prototypes of VirusZ.h and Virus.h to mimic function of a virus.
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
#include <cstdlib>
#include <iostream>
#include "VirusZ.h"

using namespace std;

VirusZ::VirusZ()
{
    //default, not needed
}

VirusZ::VirusZ(int r, int c)
{
    row = r;
    col = c;
}

/* VirusZ(int, int)
    Description: default constructor for row and col

    Input: int r = row
           int c = column

    Output: none
*/

int VirusZ:: getCol()
{
    return col;
}

/* VirusZ::getCol()
    Description: returns column

    Input: none

    Output: int column
*/

int VirusZ:: getRow()
{
    return row;
    }

/* VirusZ::getRow()
    Description: returns row

    Input: none

    Output: int row
*/

void VirusZ:: setRow(int r)
{
    row = r;
}

/* VirusZ::setRow(input)
    Description: set row to input value

    Input: int: row

    Output: none
*/

void VirusZ:: setCol(int c)
{
    col = c;
    }

/* VirusZ::setCol(input)
    Description: set column to input value

    Input: int: column

    Output: none
*/

void VirusZ::setLoc(int r, int c)
{
    row = r;
    col = c;
}

/* VirusZ::setLoc(int, int)
    Description: set row and column to input values

    Input: int row
           int column

    Output: none
*/
