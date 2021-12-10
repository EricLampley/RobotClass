//------------------------------------------------------------------
// File name:   class_ROBOT201.h
// Assign ID:   TERMproject
// Due Date:    12/5/2021      
//
// Purpose:     Derived robot class.
//
// Author:      teacherK123 Dr. Jones
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

#ifndef LOCATION_STRUCT
#define LOCATION_STRUCT
struct LOCATION
{
   float xpos, ypos;
};
#endif
#include "class_ROBOT101.h"

#ifndef ROBOT201_CLASS
#define ROBOT201_CLASS

class ROBOT201 : public ROBOT101
{
  private:
    string RobotID;      // Each driver (robot) has a name.
    bool inService;      // true when activated and actively moving.
    float Power;         // Power level: 0-1000..
    float totDist;       // Total distance moved since being in service.
    LOCATION Current;    // Current location.
    LOCATION gridLO;     // Lower-bound of grid.
    LOCATION gridHI;     // Upper-bound of grid.


  public:
     // Constructor: default grid is (0,0) to (20,20);
     //              default power = 500, location at origin.
     //              Initialize counters, accumulators to zero. 
     ROBOT201();

     // Set Grid.
     void Set_Grid(LOCATION MIN, LOCATION MAX);
     
     // Set Robot ID.
     void Set_RobotID(string ID);
	  
     // Set Robot Power.
     void Set_Power(float power );
	  
     // Get current power level.
     float Get_Power();
	  
     // Get distance moved while in service.
     float Get_Distance();

     // Return whether robot is in service.
     bool InService();
     
     // Place make robot in-service.
     void Place_InService();
    
     // Return current location. 
     LOCATION Get_CurLocation();

     // Move from current location to destination if robot .
     bool MoveTo(LOCATION dest);  

     // Take robot out of service.
     void Take_OutOfService();
            
}; // class ROBOT201

#endif
