#include "raylib.h"

typedef struct Ball
{
    float x;
    float y;
    float rad;
}Ball;


int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    const int Width = 25;
    const int Height = 230;

    const int radious = 16;


    Rectangle LeftPaddle = {30, screenHeight/2-Height/2, Width, Height};
    Rectangle RightPaddle = {screenWidth-(30+Width), screenHeight/2-Height/2, Width, Height}; 
    Ball Ball = {screenWidth/2, screenHeight/2, radious};


    int dx = 10;
    int dy = -10; //speed it up

    int LeftScore = 0, RightScore = 0;

    InitWindow(screenWidth, screenHeight, "Pong!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if(IsKeyDown(KEY_W) && LeftPaddle.y>10)
        {
                LeftPaddle.y -= 10;
        }
        if(IsKeyDown(KEY_S) && LeftPaddle.y<screenHeight-(Height+10))
        {
            LeftPaddle.y += 10;
        }
        if(IsKeyDown(KEY_UP)&& RightPaddle.y>10)
        {
            RightPaddle.y -= 10;            
        }
        if(IsKeyDown(KEY_DOWN) && RightPaddle.y<screenHeight-(Height+10))
        {
            RightPaddle.y += 10;
        }
        

        if(Ball.x-Ball.rad<= 0 || Ball.x+Ball.rad>=screenWidth)
        {
            Ball.x = screenWidth/2;
            Ball.y = screenHeight/2;
            dx = 10, dy = 10;
            if(Ball.x>10)
                LeftScore++;
            else
                RightScore++;
        }
        
        if(Ball.y-Ball.rad<= 0 || Ball.y+Ball.rad>=screenHeight)
        {
            dy *=-1;
        }

        
        if(CheckCollisionCircleRec(Vector2{Ball.x, Ball.y}, Ball.rad,RightPaddle))
        {

            if(Ball.x>RightPaddle.x)
            {
                dy *=-1;
            }
            else
            {
                dx *= -1.09;
            }
            
        }

        if(CheckCollisionCircleRec(Vector2{Ball.x, Ball.y}, Ball.rad,LeftPaddle))
        {
            if(Ball.x<LeftPaddle.x+Width)
            {
                dy*=-1;
            }   
            else
            {
                dx *= -1.09;
            }
            
        }
        
        Ball.x += dx;
        Ball.y += dy;

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);

            DrawRectangle(LeftPaddle.x,LeftPaddle.y,LeftPaddle.width,LeftPaddle.height,WHITE);
            
            DrawRectangle(RightPaddle.x,RightPaddle.y,RightPaddle.width,RightPaddle.height, WHITE);

            DrawCircle(Ball.x, Ball.y, Ball.rad, WHITE);

            DrawText(TextFormat("%i",RightScore),screenWidth/2 + 50,screenHeight/5,50,LIGHTGRAY);
            
            DrawText(TextFormat("%i",LeftScore),screenWidth/2 - 50,screenHeight/5,50,LIGHTGRAY);

            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();
    
    return 0;
}
