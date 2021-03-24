// include required libraries

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;
    
int width = 20, height = 20,gameOver = 0,length = 1,score = 0, snake_x = 0, snake_y = 0, fruit_x = 0, fruit_y = 0, coord_x[30],coord_y[30];

// to control the directions of the snake
enum directions
{
    LEFT, RIGHT, DOWN, UP
}dir;
    
bool equal = true;
    
void setup()
{      
    snake_x = rand() %  width + 1;
    snake_y = rand() % height + 1; 
        
    do{
        fruit_x = rand() % width +1;
        fruit_y = rand() % height +1;
            
    }while(( fruit_x == snake_x ) && (fruit_y == snake_y) );
        
    dir = DOWN;       
} 
    
// drawing the game field +the snake's body + the fruit  
void draw()
{
    int i = 0, j = 0;

    for(i = 0 ; i< height; i++)cout<<"#";

    cout<<"\n";

    for( i = 0 ; i< height; i++)
    {
        for( j = 0 ; j < width; j++)
        {
            if (j == 0) cout<<"#";
                        
            else if( snake_x == j && snake_y == i) cout<<"O";
            else if( fruit_x == j && fruit_y == i) cout<<"F";

            else 
            {
                bool printed = false;
                
                for(int k = 0; k < length ; k++)
                
                    if (( coord_x[k] == j ) && (coord_y[k] == i ))
                    {
                        cout << "o";
                        printed = true;
                    }
                        // if the coordinations doesn't match the same coordination 
                        //of any point of the sbake so let's draw in place a space 
                     
                        if ( !printed ) cout<<" ";
                if ( j == width - 1 ) cout << "#";
            }
        }
        cout<<"\n";
    }

    for( j = 0 ; j < height ; j++ )
           cout<<"#";

    cout<<"\n"<<"your score is : "<<score<<"\n";
}
    
// take control of the snake  
void input()
{    
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'w': 
            dir = UP;
            break;
            
            case 'a':
            dir = LEFT;
            break;
            
            case 's':
            dir = DOWN;
            break;
            
            case 'd':
            dir  = RIGHT;
            break;
            
            case 'q':
            gameOver = 1;
        }
    }
}
    
// setting the logic of the game     
void logic()
{   
    int prev_x = coord_x[0];
    int prev_y = coord_y[0];
    
    for(int i = 1; i <length; i++)
    {
        int prev_x2 = coord_x[i];
        int prev_y2 = coord_y[i];

        coord_x[i] = prev_x;
        coord_y[i] = prev_y;

        prev_x = prev_x2;
        prev_y = prev_y2;    
    }
           
    switch(dir)
    {
        case UP:
            snake_y++;
            break;
            
        case DOWN:
            snake_y--;
            break;
            
        case LEFT:
            snake_x--;
            break;
            
        case RIGHT:
            snake_x++;
            break;
    }

    coord_x[0] = snake_x;
    coord_y[0] = snake_y;

    if(snake_x > width ) snake_x = 0; if  (snake_y > height ) snake_y = 0;
    if(snake_x < 0) snake_x = width; if (snake_y < 0) snake_y = height;
    
    if (( snake_x == fruit_x) && (fruit_y == snake_y)) 
    {
        length++;
        score+= 25;
        fruit_x = (rand() % width )+1;
        fruit_y = (rand() % height)+1;
    }
        
    for ( int k = 1 ; k < length ; k++)
    {
        if ((snake_x == coord_x[k]) && (snake_y == coord_y[k])) gameOver = 1;
    } 
}
    
int main()
{
    setup();
    while(!gameOver)
    {
        input();
        logic();
        draw();
        Sleep(100);
        system("cls");
    }
    return 0 ;
}