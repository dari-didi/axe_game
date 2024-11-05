#include "raylib.h"
int main(){
    //window Dimensions
    int width{800};
    float height{450};

    InitWindow( width, height, "Raylib Window");
    
    // circle drawing coordinates
    int circle_x{100};
    int circle_y{height/2};
    int radius{25};
    
    // circle edges
    int l_circle_x{circle_x - radius};
    int r_circle_x{circle_x + radius};
    int u_circle_y{circle_y - radius};
    int b_circle_y{circle_y + radius};

    // axe drawing coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_width{50};
    int direction{10};

    //axe_edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_width};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_width};
    
    // collision circle and axe condition
    bool collision_with_axe = 
                        b_axe_y >= u_circle_y && 
                        u_axe_y <= b_circle_y && 
                        l_axe_x <= r_circle_x && 
                        r_axe_x >= l_circle_x;

    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);
        
        // game over screen if the collision occurs
        if(collision_with_axe){
            DrawText("Game Over", width/2 - 20, height/2, 20, RED);
        } else {    
        //Game logic
        //update the edges
            l_circle_x = circle_x - radius;
            r_circle_x = circle_x + radius;
            u_circle_y = circle_y - radius;
            b_circle_y = circle_y + radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_width;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_width;

            // update  collision with axe for each frame
            collision_with_axe = 
                        b_axe_y >= u_circle_y && 
                        u_axe_y <= b_circle_y && 
                        l_axe_x <= r_circle_x && 
                        r_axe_x >= l_circle_x;

            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_width, axe_width, RED);

            // move the axe
            axe_y += direction;
            if(axe_y > 400 || axe_y < 0){

                direction = -direction;
            }

            if(IsKeyDown(KEY_D) && circle_x < (width - radius)){
                circle_x += 10;
            } 
            if (IsKeyDown(KEY_A) && circle_x > radius){
                circle_x -= 10;
            }
        }
        // Game logic ends
        EndDrawing();
    }
}