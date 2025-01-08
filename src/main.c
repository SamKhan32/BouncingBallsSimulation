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
#define NUM_OF_BALLS 2 // deifnes the number of balls simulated
struct Ball {
    double positionX;
    double positionY;
    double velocityX;
    double velocityY;
};
struct Ball balls[NUM_OF_BALLS];
void calculatePos( double* postionInital, double*velocityInital);
bool isCollison();
void update();
int main ()
{
    for(int i = 0; i < NUM_OF_BALLS; i++) {
        balls[i].positionY = 20 + i *5;
        balls[i].positionX = 10 + i *10;
        balls[i].velocityX = -80;
        balls[i].velocityY = -50;
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
            /*Debug Bounding system*/
            DrawTexture(ball, balls[i].positionX, balls[i].positionY, WHITE);
            // Left line
            DrawLine(balls[i].positionX + 30, 0, balls[i].positionX, 800, BLUE);
            //top line
            DrawLine(0, balls[i].positionY, 1000, balls[i].positionY, RED);
            // right line
            DrawLine(balls[i].positionX +78, 0, balls[i].positionX +78, 800, YELLOW);
            // bottom line
            DrawLine(0, balls[i].positionY +57, 1000, balls[i].positionY +57, WHITE);
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
    bool result = isCollison();
    
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
/*
The ball-red-3d-small.png texture has these true bounds. (0,0) is the top left corner
    top: 0 px
    right: 78 px
    bottom: 57 px
    left: 30 px
*/
bool isCollison() {
    for(int i =0; i < NUM_OF_BALLS; i++) 
    {
    // top wall collision
        if((balls[i]).positionY <= 0 ) {
            balls[i].velocityY = balls[i].velocityY * -1;
        }
    // right wall collision
        if((balls[i]).positionX + 78 >= GetScreenWidth() ) {
            balls[i].velocityX = balls[i].velocityX * -1;
        }    
    // bottom wall collision
        if((balls[i]).positionY + 57 >= GetScreenHeight() ) {
            balls[i].velocityY = balls[i].velocityY * -1;
        }
    // left wall collision
        if((balls[i]).positionX + 30 <= 0 ) {
            balls[i].velocityX = balls[i].velocityX * -1;
        }
    }
    // Collison with other Ball


    return false;
}


