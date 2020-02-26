/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12 2019 9:30 PM
 *
 * Function: Implemented the VirusA class from prototypes of VirusA.h
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
#include "VirusA.h"
using namespace std;

VirusA::VirusA()
{
    //default
}

VirusA::VirusA(int r, int c)
{
    row = r;
    col = c;
}

/* VirusA(int, int)
    Description: default constructor for row and col

    Input: int r = row
           int c = column

    Output: none
*/

int VirusA::getRow()
{
    return row;
}

/* VirusA::getRow()
    Description: returns row

    Input: none

    Output: int row
*/

int VirusA::getCol()
{
    return col;
}

/* VirusA::getCol()
    Description: returns column

    Input: none

    Output: int column
*/

void VirusA::setRow(int r)
{
    row = r;
}

/* VirusA::setRow(input)
    Description: set row to input value

    Input: int: row

    Output: none
*/

void VirusA::setCol(int c)
{
    col = c;
}

/* VirusA::setCol(input)
    Description: set column to input value

    Input: int: column

    Output: none
*/

void VirusA::setLoc(int r, int c)
{
    row = r;
    col = c;
}

/* VirusA::setLoc(int, int)
    Description: set row and column to input values

    Input: int row
           int column

    Output: none
*/
