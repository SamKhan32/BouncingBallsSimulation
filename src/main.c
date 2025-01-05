/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#define FPS 60 // defines frames per second
struct Ball {
    double postionX;
    double positionY;
    double velocityX;
    double velocityY;
};
    struct Ball balls[1];
void calculatePos( double* postionInital, double*velocityInital);
bool isCollison(struct Ball ball);
int main ()
{
    InitWindow(400, 200, "raygui - controls test suite");
    SetTargetFPS(FPS);
    bool showMessageBox = false;
    

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
	



        EndDrawing();
    }

    CloseWindow();
    return 0;
}
/*
Calculates the final position for each frame, given an initial position and initial velocity.
Then updates the position.
Delta time is 1/FPS.
Assumes constant acceleration.
*/
void calculatePosition(double* positionInitial, double* velocityInitial) {
    *positionInitial = *positionInitial + (1.0 / FPS) * *velocityInitial;
}
bool isCollison(struct Ball ball) {
    struct Ball* ballsPtr = balls;
    // top wall collision

    // right wall collision

    // bottom wall collision

    // left wall collision

    // Collison with other Ball

    return false;
}


