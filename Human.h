/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12 2019 9:30 PM
 *
 * Function: Implemented the Human class headers
 *
 * Input:  Inputs listed and specified below each function in the executable.
 *
 * Output:   Outputs listed and specified below each function in the executable.
 *
 * Additional Comments:
 *
 *
 ***************************************************************************/
#ifndef Human_h
#define Human_h

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Human
{
public:
	//constructors
    Human();
    Human(int, int, string); // location
    
    //variable
    double immunity; //immunity level

	//functions
    int getRow(); //return row
    int getCol(); //return col
    void setLoc(int, int); //set new coords
    void increaseAge(); //age++
    int getAge(); //return age
    void setAge(int); //set age
    bool checkFemale(); //true if female, false if male
    void printInfo(); //print information for testing, MIGHT REMOVE LATER
    bool decreaseImmunity(); //decrease immunity levels for making an illegal move
    bool decreaseLargeImmunity(); //decrease immunity levels for landing on a virus
    void createDoctor(); //changes Human to doctor
    double getImmunity(); //return immunity
    void childChance(); //chance of double immunity
    string getGender(); //return gender

protected:
    //variables
	int age;
	string gender;
    int row;
    int col;
    bool doctor;

};

#endif /* Human_h */
