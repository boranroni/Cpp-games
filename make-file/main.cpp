#include "raylib.h"


int main(void)
{
    InitWindow(screenWidth, screenHeight, "GAME!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update Variables
        //----------------------------------------------------------------------------------
        
   
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

             
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();
    
    return 0;
}
