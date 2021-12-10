//------------------------------------------------------------------
// File name:   test_class_ROBOT201.cpp
// Assign ID:   TERMproject
// Due Date:    12/9/2021      
//
// Purpose:     Test Base robot class implementation.
//
// Author:      lampleyE023 Eric Lampley
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
#include "class_ROBOT201.h"

int main()
{
   // Declare variables used in test.
   

   //-|-----------------------------------------------------------------------
   //-| STEP 1. Test ROBOT201 default constructor..
   //-|-----------------------------------------------------------------------
   ROBOT201 r1, r2, r3;
   LOCATION goodGRID_lo = {0,0};
   LOCATION goodGRID_hi = {12,15};
   LOCATION badGRID_lo = {3,10};
   LOCATION badGRID_hi = {1,15};
   LOCATION point;

   r1.Show_Grid("r1 GRID after default constructor: "); 
   cout << "\nr1 POWER = " << r1.Get_Power() << endl;;
   cout << "\nr1 DISTANCE MOVED = " << r1.Get_Distance() << endl;;
   r1.Show_Position("r1 POSITION after default constructor: ");
   r1.StartUp(4,4);
   r1.Show_Position("r1 AFTER start-up BEFORE in-service at (4,4): ");
   cout << "\nr1 Activated = " << r1.IsActive() << endl;
   cout << "\nr1 In-Service before Place_Inservice= " << r1.InService() << endl;
   r1.Place_InService();
   cout << "\nr1 In-Service AFTER Place_Inservice= " << r1.InService() << endl;
   r1.Show_Position("r1 AFTER Activated + In-Service at (4,4): ");
   cout << endl;

   cout << "\n\n\n===============================================\n\n";

   //-|-----------------------------------------------------------------------
   //-| STEP 2. Test successful and failed movements for robot r2.
   //-|-----------------------------------------------------------------------
   r2.Set_Grid(goodGRID_lo, goodGRID_hi);
   r2.Show_Grid("r2 GRID AFTER Establish GRID (0,0)-(12,15): "); 
   r2.Place_InService();
   r2.Show_Grid("r2 GRID AFTER Establish GRID (0,0)-(12,15): "); 
   r2.Show_Position("r2 AFTER Activated + In-Service at (0,0): ");
   cout << "\nr2 POWER BEFORE move = " << r2.Get_Power() << endl;
   point.xpos = 4; point.ypos = 5;
   if ( r2.MoveTo(point) )
   {
      r2.Show_Position("r2 AFTER EXPECTED MOVE to (4,5): ");
   }
   else
      cout << "\nUNEXPECTED FAILED MOVE from (0,0) to (4,5)\n";

   cout << "\nr2 EXPECTED DISTANCE 9 after 9-unit move = " << r2.Get_Distance() << endl;
   cout << "\nr2 EXPECTED 491 POWER AFTER ATTEMPTED 9-unit move = " << r2.Get_Power() << endl;
   r2.Show_Position("r2 AFTER ATTEMPTED (0,0) to (4,5) move: ");

   point.xpos = 14; point.ypos = 7;
   if ( r2.MoveTo(point) )
   {
      r2.Show_Position("r2 AFTER UNEXPECTED MOVE to (14,7): ");
   }
   else
      cout << "\nEXPECTED FAILED MOVE from (4,5) to (14,7) \n";
   cout << "\nr2 POWER AFTER ATTEMPTED 12-unit move = " << r2.Get_Power() << endl;
   r2.Show_Position("r2 AFTER ATTEMPTED (4,5) to (14,7) move: ");

   cout << "\n\n\n===============================================\n\n";

   //-|-----------------------------------------------------------------------
   //-| STEP 3. Test power exhaustion for robot r1..
   //-|-----------------------------------------------------------------------
   r1.Set_Power(5);
   cout << "\nr1 POWER BEFORE MOVEMENT = " << r1.Get_Power() << endl;
   r1.Show_Position("r1 POSITION BEFORE MOVEMENT: ");
   point.xpos = 2; point.ypos = 2;
   if ( r1.MoveTo(point) )
   {
      r1.Show_Position("r1 AFTER EXPECTED MOVE to (2,2): ");
   }
   else
      cout << "\nUNEXPECTED FAILED MOVE from (0,0) to (2,2)\n";

   cout << "\nr1 EXPECTED DISTANCE 4 after 4-unit move = " << r1.Get_Distance() << endl;
   cout << "\nr1 EXPECTED 1 POWER AFTER ATTEMPTED 4-unit move = " << r1.Get_Power() << endl;
   r1.Show_Position("r1 AFTER ATTEMPTED (4,4) to (2,2) move: ");

   point.xpos = 6; point.ypos = 7;
   if ( r1.MoveTo(point) )
   {
      r1.Show_Position("r1 AFTER UNEXPECTED MOVE to (6,7): ");
   }
   else
      cout << "\nEXPECTED FAILED MOVE from (2,2) to (6,7) \n";
   cout << "\nr1 POWER AFTER ATTEMPTED 9-unit move = " << r1.Get_Power() << endl;
   r1.Show_Position("r1 AFTER ATTEMPTED (2,2) to (6,7)  move: ");
   cout << "\nr1 EXPECTED DISTANCE 5 after 11-unit move = " << r1.Get_Distance() << endl;


   cout << "\n\n\n===============================================\n\n";

   cout << endl; return 0;
}//main
