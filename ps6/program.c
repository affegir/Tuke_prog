#include <ncurses.h>                    
#include <stdlib.h>                     
#include <string.h>                     
#include <time.h>                       
#include <unistd.h> 



void start();
void login_page (char *name);
int game_core(char *name, int score, int *last_score, int *high_score, int maxY, int maxX);
int random_number (int maxX);
int speed(int score);
int end_game(char *name, int *last_score, int *high_score, int maxY, int maxX);
int pouse (char *name, int score, int maxX, int maxY);


void make_window_and_box(int start_y, int start_x, int end_y, int end_x)
{
    WINDOW *win;                                              //define and make a new window
    win = newwin(start_y, start_x , end_y , end_x);           //make the window for login page
    refresh(); 
    box(win, 0, 0);                                           
    wrefresh(win);                                            
}




//intro car
void welcome_car (int y, int x)
{
    attron(COLOR_PAIR(4));
    curs_set(0);  
    mvprintw(y   , x , "        __*_          ");                   
    mvprintw(y+1 , x , "     __[    ]____     ");
    mvprintw(y+2 , x , "     `()----()-'      ");
    attroff(COLOR_PAIR(4));
    refresh();
}



//delete intro car
void delete_welcome_car (int y, int x)
{
    mvprintw(y   , x , "                      ");
    mvprintw(y+1 , x , "                      ");
    mvprintw(y+2 , x , "                      ");
    refresh();
}



void display_welcome_page(int maxY,int maxX)
{
    attron(COLOR_PAIR(4));
    mvprintw(maxY/4+8, maxX/2-10, "Welcome to SPEED RACER");  
    attroff(COLOR_PAIR(4));
    int y_welcome = maxY/4 +12 , x_welcome = maxX/4 +1;         
    for( int go = maxX/4; go < maxX*3/4 - 24; go++)             //this loop makes the intro car move
    {
        delete_welcome_car (y_welcome, x_welcome);            //call the function that deletes the intro car in previous location
        x_welcome ++;                                           //change x location 
        welcome_car(y_welcome, x_welcome);                    //print the intro car in the new location
        usleep(30*1000);                                        //delay 
    }
    delete_welcome_car (y_welcome, x_welcome);                //  delete intro car after the loop
}

void print_login_text(int maxY, int maxX)
{
    attron(COLOR_PAIR(2));
    mvprintw(maxY/4+8, maxX/2-strlen("Enter your name please:")/2, "Enter your name please:");  
    attroff(COLOR_PAIR(2)); 
    attron(COLOR_PAIR(5));  
    mvprintw(maxY/4+14, maxX/2-strlen("Then press Enter to start the game!")/2, "Then press Enter to start the game!");
    attroff(COLOR_PAIR(5));
    refresh();
}

void print_pouse_text(int maxY, int maxX,char *name, int score)
{
    mvprintw(maxY/2-6, maxX/2-strlen(" name ")/2, "%s", name);
    mvprintw(maxY/2-4, maxX/2-strlen("Game is Paused")/2, "Game is Paused");
    mvprintw(maxY/2-2, maxX/2-strlen("To Resume -> Press Space")/2, "To Resume : Press Space");  
    mvprintw(maxY/2  , maxX/2-strlen("Your current score :   ")/2, "Your current score : %d", score); 
    refresh();
}

void print_game_over_text(int maxY,int maxX,char *name,int *high_score)
{
    attron(COLOR_PAIR(4));
    mvprintw(maxY/2-2, maxX/2-strlen("Game Over")/2, "Game Over"); 
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(5));                                             
    mvprintw(maxY/2+2, maxX/2-strlen(name)/2, "%s", name);                                                           
    mvprintw(maxY/2+4, maxX/2-strlen("Your high score is: ")/2, "Your high score is: %d", *high_score);  
    attroff(COLOR_PAIR(5));  
    attron(COLOR_PAIR(1));         
    mvprintw(maxY/2+6, maxX/2-strlen("Press R or Space to play again")/2, "Press R or Space to play again");       
    mvprintw(maxY/2+8, maxX/2-strlen("Press E or Esc to play exit")/2, "Press E or Esc to exit");
    attroff(COLOR_PAIR(1));
    refresh();
}

//main car
void print_car (int y_car, int x_car)
{
    attron(COLOR_PAIR(3));
     mvprintw( y_car   , x_car , "      <========>     ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
     mvprintw( y_car+1 , x_car , "    _     ||     _   ");
     mvprintw( y_car+2 , x_car , "   |_|--[    ]--|_|  ");
     mvprintw( y_car+3 , x_car , "       [  ()  ]      ");
     mvprintw( y_car+4 , x_car , "    _ .[      ]. _   ");
     mvprintw( y_car+5 , x_car , "   |_|-__|  |__-|_|  ");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
     mvprintw( y_car+6 , x_car , "      |________|     ");
    attroff(COLOR_PAIR(3));
    refresh(); 
}


//      <========>      
//    _     ||     _    
//   |_|--[    ]--|_|   
//       [  ()  ]       
//    _ .[      ]. _    
//   |_|-__|  |__-|_|   
//      |________|      

//delete main car
void delete_car (int y_car, int x_car)              
{   
    mvprintw( y_car   , x_car , "                     ");
    mvprintw( y_car+1 , x_car , "                     ");
    mvprintw( y_car+2 , x_car , "                     ");
    mvprintw( y_car+3 , x_car , "                     ");
    mvprintw( y_car+4 , x_car , "                     ");
    mvprintw( y_car+5 , x_car , "                     ");
    mvprintw( y_car+6 , x_car , "                     ");
    refresh();
}
// enemy car
void show_obstacle(int y_obstacle, int x_obstacle)
{
  attron(COLOR_PAIR(2));
  mvprintw( y_obstacle   , x_obstacle , "      <========>     ");
  mvprintw( y_obstacle+1 , x_obstacle , "    _     ||     _   ");
  mvprintw( y_obstacle+2 , x_obstacle , "   |_|--[    ]--|_|  ");
  mvprintw( y_obstacle+3 , x_obstacle , "       [  ()  ]      ");
  mvprintw( y_obstacle+4 , x_obstacle , "    _ .[      ]. _   ");
  mvprintw( y_obstacle+5 , x_obstacle , "   |_|-__|  |__-|_|  ");
  attroff(COLOR_PAIR(2)); 
  refresh();
}
//     ________
//  ()|________|()
//    |        |
//    |________|
//  ()|________|()
//     TITITITI


//delete enemy car
void delete_obstacle(int y_obstacle, int x_obstacle)
{
  mvprintw( y_obstacle   , x_obstacle , "                     ");
  mvprintw( y_obstacle+1 , x_obstacle , "                     ");
  mvprintw( y_obstacle+2 , x_obstacle , "                     ");
  mvprintw( y_obstacle+3 , x_obstacle , "                     ");
  mvprintw( y_obstacle+4 , x_obstacle , "                     ");
  mvprintw( y_obstacle+5 , x_obstacle , "                     ");
  refresh();
}
//print boarder
void print_boarder1 (int y_boarder, int maxX)
{
    attron(COLOR_PAIR(4));
    mvprintw( y_boarder     , maxX/2-40, "v");
    mvprintw( y_boarder     , maxX/2+40, "v");
    attroff(COLOR_PAIR(4));
    refresh();
}
//delete boarder
void print_boarder2 (int y_boarder, int maxX)
{
    mvprintw( y_boarder     , maxX/2-40, "  ");
    mvprintw( y_boarder     , maxX/2+40, "  ");
    refresh();
}
//game info
void view_scoreboard (int maxY, int maxX, char*name, int score, int *high_score)
{
    attron(COLOR_PAIR(5));
    mvprintw( 1 , maxX/2+45, "Player's Name: %s", name);                       
    mvprintw ( 3 , maxX/2+45, "Score: %d", score);                             
    mvprintw ( 5 , maxX/2+45, "High Score: %d", *high_score);                  
    mvprintw ( 7 , maxX/2+45, "To Pause -> Press Space"); 
    attroff(COLOR_PAIR(5));
    refresh();
}

//------------------------------------------------------------------------------------------------------------------------



void start()
{ 
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); 
    init_pair(2, COLOR_GREEN, COLOR_BLACK); 
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    srand(time(NULL));                          //random
    int maxX,maxY;
    getmaxyx(stdscr, maxY, maxX); 
    int score = 0;                              
    int last_score = 0;                         
    int high_score = 0;                                 
    char user_name [50];                        
    login_page(user_name);                      //login 
    noecho();                                   //dont display input key value 
    game_core(user_name, score, &last_score, &high_score, maxY, maxX);  //start game
    nodelay(stdscr, 0);                         

    while(1)                                    
    {
        int play_again = end_game(user_name, &last_score, &high_score, maxY, maxX);
        if (play_again == 0)
            break;
        if (play_again == 1)
            game_core(user_name, score, &last_score, &high_score, maxY, maxX);
    }
}

//login
void login_page (char *name)
{
        int maxX , maxY;                                            
        getmaxyx (stdscr, maxY, maxX);                              //get maximum x and y of standard screen and assing the values to maxY and maxX;
        make_window_and_box(maxY/2, maxX/2 , maxY/4 , maxX/4);      
        display_welcome_page(maxY,maxX);                                        
        print_login_text(maxY,maxX);                                
        curs_set(1);                                                //set the curses on
        mvscanw(maxY/4+10, maxX/2-strlen(name)/2, "%s" , name);     // username
        curs_set(0);                                                //set the curser display off
}

//speedUP!
int speed (int score)
{
    if(score <= 5)                                                  
        usleep (30*1000);

    if(score > 5 && score <=10)                                     
        usleep (25*1000);

    if(score > 10 && score <=20)                                    
        usleep (20*1000);

    if(score > 20 && score<=50)                                     
        usleep (15*1000);

    if(score > 50)                                                  
        usleep (12*1000);

}
//start game
int game_core(char *name, int score, int *last_score, int *high_score, int maxY, int maxX)    
{
    nodelay(stdscr, 1);                                             //dont stop for user input
    clear();                                                        //clear the window
    int y_car = maxY-10, x_car = maxX/2-10, y_obstacle = maxY, x_obstacle, y_boarder = 0; 
    int ch;                                                         
    
    while(1)                                                       
    {
        print_boarder1 (y_boarder, maxX);                           
        y_boarder += 1;                                             //increese y coordinate of obstacle(enemy car) to change location
        print_boarder2 (y_boarder, maxX);                           
        if (y_boarder >= maxY)                                      
            y_boarder = 0 ;                                         
        ch = getch();                                               //get a key from keybourd and assign it to int ch
        switch (ch)                                                 
        {
        case 'd':                                                   
        case 'D':
        case KEY_RIGHT:
            delete_car(y_car,x_car);                 
            if (x_car <= maxX/2+ 10)                           //if x coordinate of car was not more than the boarders of the game
                x_car += 21;                                   //increase x coordinate to move car to the righ 
            break;
        case 'a':                                                   
        case 'A':
        case KEY_LEFT:
            delete_car(y_car,x_car);
            if (x_car >= maxX/2- 10)                            //if x coordinate of car was not more than the boarders of the game
                x_car -= 21;                                   //decrease x coordinate to move car to left
            break;
        default:
            break;
        case 32:
            pouse (name, score,  maxX,  maxY);
            *last_score = score; 
            game_core(name, score, last_score, high_score, maxY, maxX);
            return 0;
        }

        print_car(y_car,x_car);                      
        
        if (y_obstacle == maxY)                                     //check if y coordinate of obstacle(enemy car) equals maximum y
        {
            y_obstacle = 0;                                         
            x_obstacle = random_number(maxX);                       
        }

        delete_obstacle( y_obstacle, x_obstacle);                   
        y_obstacle++;                                               
        show_obstacle (y_obstacle, x_obstacle);                     

        if ( (y_car == y_obstacle+6) && (x_car == x_obstacle) )       //if  true - player lose
        { 
            *last_score = score;                                      //assign current score to last score
            break;
        }
        if ( (y_car + 6 == y_obstacle + 5) && (x_car != x_obstacle))  // if true - an obstacle(enemy car) passes without hitting the car
            score ++;                                                          
                             
        view_scoreboard (maxY, maxX, name, score, high_score);                      
        speed (score);                                                         
    }
}

//random number
int random_number (int maxX)
{
    /* 
    A random number between 0 and 3 is generated, then minus one, gives one of the numbers : -1 or 0 or 1 . 
    then multiply by 21(the width of car) and plus the x coordinate of the middle of the screen.
    finally the function retunrs one number from three numbers to make the obstacle(enemy car) apper in 3 random different collums 
    */
    return ((rand()%3)-1) * 21 + maxX/2 - 10; 
}
//pause game
int pouse (char *name, int score, int maxX, int maxY)
{
    clear();
    int ch;
    print_pouse_text(maxY,maxX,name,score);             
    while (1)
    {   
        usleep(10000);
        ch = getch();
        switch (ch)                                                 
        {
            case 32:
                return 0;
        }
    } 
}
//end game screen
int end_game(char *name, int *last_score, int *high_score, int maxY, int maxX)
{             
    usleep(10000);                                                       
    clear();    
    if (*last_score >= *high_score)  
        *high_score = *last_score;  
        
        

    print_game_over_text(maxY,maxX,name,high_score);                       
    
    int ch;                                                                                               
    if(ch=getch()){                   
        switch(ch){                
            case 'e':              
            case 'E':
            case 27:               //esc
                return 0;
            break;   
            case 'r':              
            case 'R': 
            case 32:               //space 
                return 1;
            break;
        }
    }
}






int main ()
{
    initscr();                  //initiates the screen 
    keypad(stdscr, true);       //enables the keypad
    start_color();       
    start();                    
    endwin();                   //finish program
    return 0;                                  
}