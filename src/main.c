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
#define NUM_OF_BALLS 1 // deifnes the number of balls simulated
struct Ball {
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
};
struct Ball balls[NUM_OF_BALLS];
void calculatePos( double* postionInital, double*velocityInital);
bool isCollison(struct Ball ball);
void update();
int main ()
{
    for(int i = 0; i < NUM_OF_BALLS; i++) {
        balls[i].positionY = 20 + i *5;
        balls[i].positionX = 10 + i *5;
        balls[i].velocityX = 10;
        balls[i].velocityY = 5;
    }
    InitWindow(1000, 800, "raygui - controls test suite");
    SetTargetFPS(FPS);
    Texture2D ball = LoadTexture("resources/ball-red-3d-small.png");
    bool showMessageBox = false;


    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
         for(int i = 0; i < NUM_OF_BALLS; i++)
         {
            DrawTexture(ball, balls[i].positionX, balls[i].positionY, WHITE);
         }
         update();
         

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
void update() {
    // need to work out the logic on white board
    for(int i = 0; i < NUM_OF_BALLS; i++)
    {
    calculatePosition(&balls[i].positionX, &balls[i].velocityX); 
    calculatePosition(&balls[i].positionY, &balls[i].velocityY); 
    }
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


