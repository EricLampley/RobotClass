//------------------------------------------------------------------
// File name:   test_class_ROBOT101.cpp
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
#include "class_ROBOT101.h"


int main()

{
   // Declare variables used in test.
   float Xtest, Ytest;
   int numTests=0, numPassed=0,  numFailed=0;

   //-|-----------------------------------------------------------------------
   //-| STEP 1. Test constructors.
   //-|-----------------------------------------------------------------------
   ROBOT101 R1, R2;
   R2.Establish_Grid(0,0, 7, 9);
   R1.Show_Grid("R1 via default constructor: "); 
   R2.Show_Grid("R2 via default constructor + Establish_Grid: "); 

   R1.Show_Position("R1 via default constructor: "); 
   if ( R1.IsActive() ) 
      cout << "R1 is ACTIVATED.\n";
   else
      cout << "R1 is NOT Activated.\n";

   R2.Show_Position("R2 after Establish_Grid: "); 
   if ( R2.IsActive() ) 
      cout << "R2 is ACTIVATED.\n";
   else
      cout << "R2 is NOT Activated.\n";


   //-|-----------------------------------------------------------------------
   //-| STEP 2. Start up robots with different, correct, coordinates.
   //-|         Verify Activation and Coordinates. 
   //-|-----------------------------------------------------------------------
   
   R1.StartUp (2, 3);
   R1.Show_Position("R1 after start-up (2,3): "); 
   if ( R1.IsActive() ) 
      cout << "R1 is ACTIVATED.\n";
   else
      cout << "R1 is NOT Activated.\n";
   cout << "\nR1 Xcoord = " << R1.Get_Xcoord() << " Ycoord = " << R1.Get_Ycoord() << endl;

   R2.StartUp (4, 1);
   R2.Show_Position("R2 after start-up (4,1): "); 
   if ( R2.IsActive() ) 
      cout << "R2 is ACTIVATED.\n";
   else
      cout << "R2 is NOT Activated.\n";
   cout << "\nR2 Xcoord = " << R2.Get_Xcoord() << " Ycoord = " << R2.Get_Ycoord() << endl;


   //-|-----------------------------------------------------------------------
   //-| STEP 3. Error handling - GRID.
   //-|-----------------------------------------------------------------------
   ROBOT101 badR3;
   badR3.Establish_Grid(5,0,2, 5);
   badR3.Show_Grid("badR3 after Establish_Grid (5,0)-(2,5): "); 
   badR3.StartUp (2, 3);
   badR3.Show_Position("badR3 after start-up (2,3): "); 

   //-|-----------------------------------------------------------------------
   //-| STEP 4. Test valid moves for R1.
   //-|-----------------------------------------------------------------------
   if (R1.Move('R'))
       R1.Show_Position("\nEXPECTED R1 move RIGHT to "); 
   if (R1.Move('E'))
       R1.Show_Position("\nEXPECTED R1 move EAST to "); 
   if (R1.Move('N'))
       R1.Show_Position("\nEXPECTED R1 move NORTH to "); 
   if (R1.Move('D'))
       R1.Show_Position("\nEXPECTED R1 move SOUTH to "); 

   //-|-----------------------------------------------------------------------
   //-| STEP 5. Test invalid moves off gridfor R2, after starting at (0,0).
   //-|-----------------------------------------------------------------------
   R2.StartUp(0,0);
   R2.Show_Position("\nR2 starting ");
   if (R2.Move('W'))
       R2.Show_Position("\nUNEXPECTED R2 move LEFT to "); 
   else
       R2.Show_Position("\nEXPECTED FAILED R2 move WEST ..."); 
   if (R2.Move('D'))
       R2.Show_Position("\nUNEXPECTED R2 move DOWN to "); 
   else
       R2.Show_Position("\nEXPECTED FAILED R2 move SOUTH ... ");

   //-|-----------------------------------------------------------------------
   //-| STEP 6. Test invalid moves off grid for R2, after starting at (7,9).
   //-|-----------------------------------------------------------------------
   R2.StartUp(7,9);
   R2.Show_Position("\nR2 starting ");
   if (R2.Move('E'))
       R2.Show_Position("\nUNEXPECTED R2 move RIGHT to "); 
   else
       R2.Show_Position("\nEXPECTED FAILED R2 move EAST ..."); 
   if (R2.Move('N'))
       R2.Show_Position("\nUNEXPECTED R2 move NORTH to "); 
   else
       R2.Show_Position("\nEXPECTED FAILED R2 move UP ... ");

   //-|-----------------------------------------------------------------------
   //-| STEP 7. Test shutdown: expect inactive, no moves allowed.
   //-|-----------------------------------------------------------------------
   cout << "\n\nSHUTTING DOWN R1 ...\n";
   R1.ShutDown();
   if (R1.IsActive())
      cout << "UNEXPECTED: R1 is still ACTIVE \n";
   else
      cout << "EXPECTED: R1 is now INACTIVE \n";
   if (R1.Move('E'))
       R1.Show_Position("\nUNEXPECTED R1 move RIGHT to "); 
   else
       R1.Show_Position("\nEXPECTED FAILED R1 move EAST ..."); 
   cout << "\nR1 now at (" << R1.Get_Xcoord() << "," << R1.Get_Ycoord() << ")\n";


   //-|-----------------------------------------------------------------------
   //-| STEP 8. Display test statistics.
   //-|-----------------------------------------------------------------------
   cout << "\n=====================================================\n";
   cout << "#TESTS PERFORMED  = " << numTests << endl;
   cout << "#TESTS PASSED     = " << numPassed << endl;
   cout << "#TESTS FAILED     = " << numFailed << endl;
   cout << "\n=====================================================\n";

   cout << endl; return 0;
} 
