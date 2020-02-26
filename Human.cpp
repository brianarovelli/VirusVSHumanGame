/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12 2019 9:30 PM
 *
 * Function: Implemented the Human class from prototypes of Human.h to mimic a Human. Variables include age, gender, immunity, class, etc.
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
#include "Human.h"
#include "Earth.h"
using namespace std;

Human::Human()
{
    age = 0;
    row = -1;
    col = -1;
    gender = "Unknown";
    immunity = 1.0;
    doctor = false;
}

/* Human()
    Description: default constructor

    Input: none

    Output: none
*/

Human::Human(int r, int c, string g)
{
    row = r;
    col = c;
    gender = g;
    immunity = 1.0;
    doctor = false;
    age = 0;
}

/* Human(int, int string)
    Description: constructor for row, column and gender

    Input: int r: row
           int c: column
           string g: gender

    Output: none
*/

void Human::printInfo()
{
    cout << "This " << gender << " gender " << age << "year old human is located at [" << row << "][" << col << "]!" << endl;
}

/* void printInfo()
    Description: prints information for testing

    Input: none

    Output: none
*/

int Human::getRow()
{
    return row;
}

/* int getRow()
    Description: return row

    Input: none

    Output: int: row
*/

int Human::getCol()
{
    return col;
}

/* int getCol()
    Description: return col

    Input: none

    Output: int: col
*/

void Human::increaseAge()
{
    age++;
}

/* void increaseAge()
    Description: increase age by 1

    Input: none

    Output: none
*/

int Human::getAge()
{
    return age;
}

/* void getAge()
    Description: return age

    Input: none

    Output: int: age
*/

void Human::setLoc(int r, int c)
{
    row = r;
    col = c;
}

/* void secLoc(int, int)
    Description: set location to [r][c]

    Input: int r: row
           int c: column

    Output: none
*/

bool Human::decreaseImmunity()
{
    double num = rand() % 20;
    num = num/100;
    immunity = immunity - num;
    if(immunity > 0.25)
    {
        return false;
    }
    return true;
}

/* bool descreaseImmunity()
    Description: get random number to decrease immunity by

    Input: none

    Output: true if immunity is too low, false otherwise
*/

bool Human::decreaseLargeImmunity()
{
    double num = rand() % 100;
    num = num/100;
    immunity = immunity - num;
    if(immunity > 0.25)
    {
        return false;
    }
    return true;
}

/* bool descreaseImmunity()
    Description: get random number to decrease immunity by

    Input: none

    Output: true if immunity is too low, false otherwise
*/

double Human::getImmunity()
{
    return immunity;
}

/* double getImmunity()
    Description: returns immunity

    Input: none

    Output: double: immunity
*/

bool Human::checkFemale()
{
    if(gender == "Female")
        return true;
    return false;
}

/* bool checkFemale()
    Description: checks if human is female

    Input: none

    Output: true if female, false if not
*/

void Human::childChance()
{
    int num = rand() %8;
    if(num == 0)
    {
        cout << "Lucky! Child was born with more immunity!" << endl;
        immunity = immunity +1;
    }
}

/* void Human::childChance()
    Description: chance for child to have double immunity

    Input: none

    Output: none
*/

void Human::createDoctor()
{
    doctor = true;
}

/* void Human::createDoctor()
    Description: set doctor to true

    Input: none

    Output: none
*/

void Human::setAge(int a)
{
    age = a;
}

/* void Human::setAge(int)
    Description: set age to given value

    Input: int - age

    Output: none
*/

string Human::getGender()
{
    return gender;
}

/* string Human::getGender()
    Description: return gender

    Input: none

    Output: string gender
*/
