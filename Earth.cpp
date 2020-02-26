/***************************************************************************
 * Name: Briana Rovelli and Maleesia Ragins
 *
 * Completed December 12 2019 9:30 PM
 *
 * Function: Implemented the Earth class from prototypes of Earth.h to run game and apply rules from the given document. Has functions of adding and moving objects that interact with one another on the grid.
 *
 * Input:  Inputs listed and specified below each function.
 *
 * Output:   Outputs listed and specified below each function
 *
 * Additional Comments:
 *
 ***************************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Earth.h"
#include "Human.h"
using namespace std;

Earth::Earth()
{
    day = 1;
    humanCount = 0;
    infectNum = 0;
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            grid[r][c] = ' ';
        }
    }
    initGrid();
}

/* Earth()
    Description: default constructor for Earth, fills grid empty

    Input: none

    Output: none
*/

void Earth::PrintGrid()
{
    cout << " ---------------------------------------" << endl;
	for (int r = 0; r < 10; r++)
	{
        cout << "|";
		for (int c = 0; c < 10; c++)
		{
			cout << " " << grid[r][c] << " |";
		}
		cout << endl;
        cout << " ---------------------------------------" << endl;
	}
}

/* PrintGrid()
	Description: prints grid

	Input: none

	Output: none
*/

void Earth::UpdateGrid()
{
    moveGrid();
    if(day%5 == 0) //every 5 years
    {
        spawnVirusA();
    }
    if(day%7 == 0) //every 5 years
    {
        spawnVirusZ();
    }
    if(day%10 == 0) //every 10 years
    {
        spawnDoctor();
    }
}

/* UpdateGrid()
	Description: updates and applies rules to grid

	Input: none

	Output: none
*/

void Earth::initGrid()
{
    int num1, num2;
    int count = 0;
    
    //spawn VIRUS A
    num1 = rand() % 10;
    num2 = rand() % 10;
    VirusA v1(num1, num2);
    infectA.push_back(v1);
    infectNum++;
    grid[num1][num2] = '@';
    
    //SPAWN VIRUS Z
    spawnVirusZ();

    //spawn 5 FEMALE humans
    while(count < 5)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ') //empty spot
        {
            Human h1(num1, num2, "Female");
            vect.push_back(h1);
            grid[num1][num2] = 'f';
            humanCount++;
            count++;
        }
    }
    
    //spawn 5 MALE humans
    count = 0;
    while(count < 5)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ') //empty spot
        {
            Human h2(num1, num2, "Male");
            vect.push_back(h2);
            grid[num1][num2] = 'm';
            humanCount++;
            count++;
        }
    }
}

/* initGrid()
	Description: sets up grid

	Input: none

	Output: none
*/

int Earth::getYear()
{
    return day;
}

/* getYear()
    Description: returns day (years)

    Input: none

    Output: int day - number of years
*/


void Earth::moveGrid()
{
    int newr, newc;
    int c = 0;
    
    //MOVE HUMANS
    for(auto it = vect.begin(); it != vect.end(); it++)
    {
        if(c>=vect.size()) //fixed bug that caused segmentation error
            return;
        //IF BOARD IS FULL, PRINT AND END SESSION
        if(checkBoard() == true)
        {
            PrintGrid();
            return;
        }
        
        //GET COORDS
        newr = it->getRow();
        newc = it->getCol();
        //GET NEW COORDS
        chooseDirection(newr, newc);
        
        //CHECK NEW COORDS
        if(checkBounds(newr, newc) == false || checkEmpty(newr, newc) == false)
        { //RULE #7, ILLEGAL MOVE = IMMUNE SYSTEM DOWN
            if(findatPointHU(it->getRow(), it->getCol()).decreaseImmunity() == true)
            { //IMMUNITY < 0.25, REMOVE HUMAN
                humanInfected(it->getRow(), it->getCol());
                continue; //move to next human
            }
        }
        else if(checkBounds(newr, newc) == true)
        {
            //SPAWN CHILDREN (RULE 2)
            if((findatPointHU(it->getRow(), it->getCol()).getAge()) >= 18 && (findatPointHU(newr, newc).getAge()) >= 18)
            {
                if((findatPointHU(it->getRow(), it->getCol()).checkFemale()) == true && (findatPointHU(newr, newc).checkFemale()) == false)
                {
                    cout << "A child is born!" << endl;
                    spawnChild();
                }
                else if((findatPointHU(it->getRow(), it->getCol()).checkFemale()) == false && (findatPointHU(newr, newc).checkFemale()) == true)
                {
                    cout << "A child is born!" << endl;
                    spawnChild();
                }
            }
        }
        
        if(checkBounds(newr, newc) == true && grid[newr][newc] == '@' && grid[it->getRow()][it->getCol()] == 'D') //not out of bounds, virus in spot but doctor landed!
        {
            cout << "Doctor landed on a virus! Virus will be cured into a child." << endl;
            infectNum--;
            humanCount++;
            int rand3 = rand()%2;
            if(rand3 == 0)
            {
                Human h1(newr, newc, "Female");
                h1.childChance();
                vect.push_back(h1);
                grid[newr][newc] = 'f';
            }
            else if(rand3 == 1)
            {
                Human h2(newr, newc, "Male");
                h2.childChance();
                vect.push_back(h2);
                grid[newr][newc] = 'm';
            }
            
        }
        else if(checkBounds(newr, newc) == true && grid[newr][newc] == '@') //not out of bounds, virus in spot
        {
            cout << "Landed on an A virus! Immunity was " << findatPointHU(it->getRow(), it->getCol()).getImmunity() << endl;
            if(findatPointHU(it->getRow(), it->getCol()).decreaseLargeImmunity() == true)
            { //IMMUNITY < 0.25, REMOVE HUMAN
                cout << "Immunity is now " << findatPointHU(it->getRow(), it->getCol()).getImmunity() << endl;
                humanInfected(it->getRow(), it->getCol());
                continue; //move to next human
            }
        }
        else if(checkBounds(newr, newc) == true && grid[newr][newc] == '$') //not out of bounds, virus in spot
        {
            cout << "Landed on a Z virus! Human will be converted. " << endl;
            infectNum++;
            humanCount--;
            humanInfected(it->getRow(), it->getCol());
            grid[it->getRow()][it->getCol()] = '$';
            VirusZ v1(it->getRow(), it->getCol());
            infectZ.push_back(v1);
            continue;
        }
        
        if(checkBounds(newr, newc) == true && checkEmpty(newr, newc) == true) //not out of bounds, change location
        {
            changeMapLoc(it->getRow(), it->getCol(), newr, newc);
            it->setLoc(newr, newc);
        }
        
        //CHANGE AGE
        it->increaseAge(); //age++
        if(it->getAge() == 18) //children represented by little m and f
        {
            char temp;
            temp = grid[it->getRow()][it->getCol()];
            grid[it->getRow()][it->getCol()] = toupper(temp);
        }
        
        c++; //fix to segmnetation error
    }
}

/* Earth::moveGrid()
    Description: moves objects, applies rules such as spawning child, changing age, removing objects, decreasing immunity, etc.

    Input: none

    Output: none
*/

void Earth::chooseDirection(int& newr, int& newc)
{
    int ran = rand() % 8 + 1;
    switch(ran)
    {
        case 1: newr = newr-1; // up
                break;
        case 2: newr = newr-1; // diagonal up right
                newc = newc+1;
                break;
        case 3: newc = newc+1; //right
                break;
        case 4: newr = newr+1; // diagonal down right
                newc = newc+1;
                break;
        case 5: newr = newr+1; //down
                break;
        case 6: newr = newr+1; //diagonal down left
                newc = newc-1;
                break;
        case 7: newc = newc-1; //left
                break;
        case 8: newr = newr-1; // diagonal up left
                newc = newc-1;
                break;
    }
}

/* chooseDirection(int&, int&)
    Description: create new coords to move to

    Input: int& newr: change old coords to new coords (row)
           int& newc: change old coords to new coords (col)

    Output: none
*/

void Earth::changeMapLoc(int oldr, int oldc, int r, int c)
{
    char temp;
    temp = grid[oldr][oldc];
    grid[oldr][oldc] = ' ';
    grid[r][c] = temp;
    
}

/* changeMapLoc(int, int, int, int)
    Description: change location on the grid

    Input:  int oldr: old row
            int oldc: old column
            int newr: new row coord
            int newc: new column coord

    Output: none
*/

Human& Earth::findatPointHU(int r, int c)
{
    for(auto it = vect.begin(); it != vect.end(); it++)
    {
        if(it->getRow() == r && it->getCol() == c)
            return *it;
    }
    return *vect.begin();
}

/* Human findatPointHU(int, int)
    Description: return Human at [r][c]

    Input:  int r: row
            int c: column

    Output: Human: human object at [r][c]
*/

void Earth::increaseYear()
{
    day++;
}

/* increaseYear()
    Description: increase day by 1 (years)

    Input: none

    Output: none
*/

void Earth::humanInfected(int r, int c)
{
    int index = 0;
    int finish = 0;
    for(auto it = vect.begin(); it != vect.end(); it++)
    {
        if(it->getRow() == r && it->getCol() == c)
            finish = index;
        index++;
    }
    cout << "Deleting a value at [" << r << "][" << c << "]...." << endl;
    grid[r][c] = ' ';
    PrintGrid();
    humanCount--;
    vect.erase(vect.begin() + finish);
}

/* void humanInfected(int, int)
    Description: remove human at [r][c] and remove from human vector.

    Input: int r: row
           int c: column

    Output: none
*/

void Earth::spawnChild()
{
    int num1, num2, num3;
    int count = 0;
    while(count == 0)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ')
        {
            num3 = rand() % 2;
            if(num3 == 0)
            {
                Human h1(num1, num2, "Female");
                h1.childChance();
                vect.push_back(h1);
                grid[num1][num2] = 'f';
            }
            else if(num3 == 1)
            {
                Human h2(num1, num2, "Male");
                h2.childChance();
                vect.push_back(h2);
                grid[num1][num2] = 'm';
            }
            humanCount++;
            count++;
        }
    }
}

/* void spawnChild()
    Description: spawn new Human and place on random spot on grid

    Input: none

    Output: none
*/


void Earth::spawnVirusA()
{
    int num1, num2;
    int count = 0;
    while(count != 1)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ')
        {
            VirusA v1(num1, num2);
            //infect.push_back(v1);
            infectNum++;
            grid[num1][num2] = '@';
            count++;
        }
    }
}

/* void spawnVirusA()
    Description: spawn new VirusA and place on random spot on grid

    Input: none

    Output: none
*/

void Earth::spawnVirusZ()
{
    int num1, num2;
    int count = 0;
    while(count != 1)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ')
        {
            VirusZ v1(num1, num2);
            infectZ.push_back(v1);
            infectNum++;
            grid[num1][num2] = '$';
            count++;
        }
    }
}

/* void spawnVirusZ()
    Description: spawn new VirusZ and place on random spot on grid

    Input: none

    Output: none
*/

bool Earth::checkBoard()
{
    bool check;
    check = true;
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if(grid[r][c] == ' ')
            {
                check = false;
            }
        }
    }
    return check;
}

/* bool checkBoard()
    Description: checks if board is full

    Input: none

    Output: false if board is not full, true if full
*/


bool Earth::checkBounds(int n1, int n2)
{
	if(n1 >= 10 || n2 >= 10 || n1 < 0 || n2 < 0)
    {
        return false;
    }
    return true;
}

/* bool checkBounds(int, int)
	Description: checks if row and col are out of bounds

	Input: int n1: row
           int n2: col

	Output: false if out of bounds, true if in bounds
*/

bool Earth::checkEmpty(int n1, int n2)
{
    if(grid[n1][n2]== ' ')
        return true;
    return false;
}

/* Earth::checkEmpty()
    Description: checks if [n1][n2] is empty

    Input: int n1: rows int n2: columns

    Output: false is spot is not empty, true if empty
*/

void Earth::printHumans()
{
    for(auto it = vect.begin(); it != vect.end(); it++)
    {
        it->printInfo();
    }
}

/* Earth::printHumans()
    Description: prints Human vector names

    Input: none

    Output: none
*/

bool Earth::lastHuman()
{
    if(vect.size() == 1)
    {
        cout << "Only one human remains. The virus wins." << endl;
        return true;
    }
    return false;
}

/* Earth::lastHuman()
    Description: checks if there is only one human left on grid

    Input: none

    Output: true if only one human on grid, false otherwise
*/

void Earth::spawnDoctor()
{
    cout << "A doctor has been added to your board!" << endl;
    int num1, num2;
    int count = 0;
    while(count == 0)
    {
        num1 = rand() % 10;
        num2 = rand() % 10;
        if(grid[num1][num2] == ' ')
        {
            Human h1(num1, num2, "Doctor");
            h1.setAge(25);
            h1.createDoctor();
            vect.push_back(h1);
            grid[num1][num2] = 'D';
            humanCount++;
            count++;
        }
    }
}

/* void Earth::spawnDoctor()
    Description: spawn new Doctor and place on random spot on grid

    Input: none

    Output: none
*/

int Earth::numInfect()
{
    return infectNum;
}

/* Earth::numInfect()
    Description: returns number of viruses

    Input: none

    Output: int infectNum - # of viruses
*/

int Earth::numHuman()
{
    return humanCount;
}
/* Earth::numHuman()
    Description: returns number of humans

    Input: none

    Output: int humanCount - # of humans
*/
