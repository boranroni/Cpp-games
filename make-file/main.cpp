#include "raylib.h"
#include <stdlib.h>



void update_coordinates(float *arr, int size)
{
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
}


float Random()
{
    float num = (rand() % (GetScreenHeight()-20 - 30 + 1)) + 30;
    return num;
}



int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    const int size_object = 25;
    
    bool r = false, l = false, u = false, d = true;


    Rectangle snake = {screenWidth/2, screenHeight/2, size_object,size_object};
    Rectangle fruit = {screenWidth/2, screenHeight/2 +200, 20,20};
    
    int score = 0;
    
    int speed = 5;
    
    int dx = 0;
    int dy = speed;

    float x_coor[100] = {0};
    float y_coor[100] = {0};



    InitWindow(screenWidth, screenHeight, "Snake!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_W)&& !u && !d)
        {
            
            dy = -1*speed;
            dx = 0;


            u=true;
            d=false;
            l=false;
            r=false;

        }
        if(IsKeyPressed(KEY_S) && !u && !d)
        {
       
            dx = 0;
            dy = speed;


            u=false;
            d=true;
            l=false;
            r=false;
        }

        if(IsKeyPressed(KEY_A) && !l && !r)
        {
            dx = -1*speed;
            dy = 0;

            u=false;
            d=false;
            l=true;
            r=false;
        }
        if(IsKeyPressed(KEY_D) && !l && !r)
        {
            dx = speed;
            dy = 0;
                
            u=false;
            d=false;
            l=false;
            r=true;

        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            score+=2;
            speed+=1;

        }
        if(snake.x >= screenWidth)
        {
            //snake.x = 1;
            score = 0;
            //std::fill( std::begin( a ), std::end( a ), 0 );
            speed = 5;
            snake.x = GetScreenWidth()/2;
            snake.y = GetScreenHeight()/2;
        }
        if(snake.y >= screenHeight)
        {
            //snake.y = 1;
            score = 0;
            //std::fill( std::begin( a ), std::end( a ), 0 );
            speed = 5;
            snake.x = GetScreenWidth()/2;
            snake.y = GetScreenHeight()/2;
        }
        
        if(snake.x <= -20)
        {
            //snake.x = screenWidth-1;
            score = 0;
            //std::fill( std::begin( a ), std::end( a ), 0 );
            speed = 5;
            snake.x = GetScreenWidth()/2;
            snake.y = GetScreenHeight()/2;
        }
        if(snake.y <= -20)
        {
            //snake.y = screenHeight-1;
            score = 0;
            //std::fill( std::begin( a ), std::end( a ), 0 );
            speed = 5;
            snake.x = GetScreenWidth()/2;
            snake.y = GetScreenHeight()/2;
        }
        
        
        
    
        if(CheckCollisionRecs(snake, fruit))
        {
            fruit.x = Random();
            fruit.y = Random();
            
            score+=2;
            speed+=1;
            x_coor[score] = snake.x;
            y_coor[score] = snake.y;

        }
        
        
        
        update_coordinates(x_coor,score);
        update_coordinates(y_coor,score);
        x_coor[0] = snake.x;
        y_coor[0] = snake.y; 
        
        snake.x += dx;
        snake.y += dy;
      
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawText(TextFormat("%i",score/2), 100, 100, 50, LIGHTGRAY);
            
            DrawRectangle(snake.x,snake.y, size_object,size_object, LIGHTGRAY);
        
            
        for(int i = 1; i<score;i++)
        {
            Rectangle tail_piece {x_coor[i], y_coor[i],size_object, size_object};
            if(CheckCollisionRecs(snake, tail_piece) && i>5)
            {
                
                score = 0;
                //std::fill( std::begin( a ), std::end( a ), 0 );
                speed = 5;
                snake.x = GetScreenWidth()/2;
                snake.y = GetScreenHeight()/2;
                break;

            }

            DrawRectangle(x_coor[i], y_coor[i],size_object, size_object, LIGHTGRAY);

        }
            
            DrawRectangle(fruit.x,fruit.y, fruit.width,fruit.height, RED);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();
    
    return 0;
}
/*
            if(CheckCollisionRecs(snake, tail_piece))
            {
                

                for (auto& a : x_coor) a = 0;
                for (auto& a : y_coor) a = 0;


                
                
                snake.x = screenWidth/2;
                snake.y = screenHeight/2;

                score = 0;
                speed = 10;


            }
*/