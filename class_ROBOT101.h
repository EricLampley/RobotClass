//------------------------------------------------------------------
// File name:   class_ROBOT101.h
// Assign ID:   TERMproject
// Due Date:    12/5/2021      
//
// Purpose:     Base robot class.
//
// Author:      lampleyE023 Eric Lampley
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifndef ROBOT101_CLASS
#define ROBOT101_CLASS

class ROBOT101
{
  private:
     float curX, curY;              // current position, e.g., (x,y).
     float xmin, ymin, xmax, ymax;  // Grid robot can not leave. 
     bool Active;                   // true when turned on.

  public:
     // Constructor: default grid is (0,0) to (10,10);
     // Make inactive, and set current position to (0,0).  
     ROBOT101();

     // Set grid to specified (Xmin, Ymin) to (Xmax, Ymax) only if
     // the grid is valid..
     void Establish_Grid(float Xmin, float Ymin, float Xmax, float Ymax);
     
     // Display the grid coordinates
     void Show_Grid(string Label);
     
     // Activate robot in specified starting position only if position is valid..
     void StartUp (float xStart, float yStart);
    
     // Return whether robot is active.
     bool IsActive ();
    
     // Return current robot position x-coordinate..
     float Get_Xcoord();
    
     // Return current robot position y-coordinate..
     float Get_Ycoord();

     // Attempt move [ N S E W ] or [U D R L]. Return false when move prohibited.
     // due to: being inactive, or the move would take robot off grid.
     bool Move (char direction); 

     // Show position of active robot; use caller-supplied label..
     void Show_Position(string Label);

     // Shutdown (make robot inactive).
     void ShutDown();
            
}; // class ROBOT101

#endif
