//------------------------------------------------------------------
// File name:   class_ROBOT101.cpp
// Assign ID:   TERMproject
// Due Date:    12/9/2021      
//
// Purpose:     Base robot class implementation.
//
// Author:      lampleyE023 Eric Lampley
//------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
#include "class_ROBOT101.h"


// Constructor: default grid is (0,0) to (10,10);
// Make inactive, and set current position to (0,0).  
ROBOT101 :: ROBOT101()
{
   xmin = ymin = 0;
   xmax = ymax = 10;
   curX = curY = 0;
   Active = false;
}


// Set grid to specified (Xmin, Ymin) to (Xmax, Ymax) only if
// the grid is valid..
void ROBOT101:: Establish_Grid(float Xmin, float Ymin, float Xmax, float Ymax)
{
    cout << endl; 
    if ((Xmin && Ymin >= 0) || (Xmax && Ymax <= 10) || (Xmin <= Xmax) || (Ymin <= Ymax) ) 
    {
        xmin = Xmin;
        ymin = Ymin; 
        xmax = Xmax; 
        ymax = Ymax; 
    }
}
     

// Display the grid coordinates.
void ROBOT101:: Show_Grid(string Label) 
{
    cout << Label << "(" << xmin << "," << ymin << ") to "; 
    cout << "(" << xmax << "," << ymax << ")" << endl << endl; 
}
     

// Activate robot in specified starting position only if position is valid..
void ROBOT101:: StartUp (float xStart, float yStart)
{
   if ((xmin && ymin >= 0) || (xmax && ymax <= 10) || (xmin <= xmax) && (ymin <= ymax) ) 
    {
        Active = true; 
        curX = xStart;  
        curY = yStart; 
    }
}
    
// Return whether robot is active.
bool ROBOT101:: IsActive () 
{
    return Active; 
}
    

// Return current robot position x-coordinate..
float ROBOT101:: Get_Xcoord() 
{
    return curX; 
}
    

// Return current robot position y-coordinate..
float ROBOT101:: Get_Ycoord() 
{
    return curY; 
}


// Attempt move [ N S E W ] or [U D R L]. Return false when move prohibited.
// due to: being inactive, or the move would take robot off grid.
bool ROBOT101:: Move (char direction) 
{
    switch(direction) 
    {
        // NORTH or UP
        case 'N':
        case 'U':
                 if ((Active = false) || (curY < 0) || (curY > 10)) {
                     return false; 
                 }
                 else {
                     curY = curY + 1;
                 }
                 break; 
        // SOUTH or Down
        case 'S':
        case 'D':
                 if ((Active = false) || (curY < 0) || (curY > 10)) {
                     return false; 
                 }
                 else {
                     curY = curY - 1;
                 }
                 break; 
        // EAST or RIGHT    
        case 'E':
        case 'R':
                if ((Active = false) || (curX < 0) || (curX > 10)) {
                     return false; 
                 }
                 else {
                     curX = curX + 1;
                 }
                 break; 
        // WEST or LEFT
        case 'W': 
        case 'L':  
                if ((Active = false) || (curX < 0) || (curX > 10)) {
                     return false; 
                 }
                 else {
                     curX = curX - 1;
                 }
                 break;  
    }
}


// Show position of active robot; use caller-supplied label..
void ROBOT101:: Show_Position(string Label) 
{
    cout << endl; 
    cout << Label << "(" << curX << "," << curY << ")";  
}


// Shutdown (make robot inactive).
void ROBOT101:: ShutDown()
{
    if (Active = true) {
        Active = true; 
    }
    else {
        Active = false;  
    }
}

