#include<superkarel.h>

void zabor_down();
void zabor_up();

int main(){
turn_on("task_4.kw");
set_step_delay(10);

while(front_is_clear() || left_is_clear()){
zabor_up();
zabor_down();
turn_left();
if(front_is_blocked()){
turn_off();
}
step();
}

turn_off();
return 0;
}

void zabor_up(){
    turn_left();
    if(beepers_present()){
        while(front_is_clear()){
            if(beepers_present()){
            step();
            }
            else{
            put_beeper();
            step();
            }
            if(no_beepers_present()){
            put_beeper();
            }
        }


    }

 while(front_is_clear()){
            step();
            if(beepers_present()){
               turn_left();
               turn_left();
               while(front_is_clear()){
                     step();
               }
               turn_left();
               turn_left();
               
          while(front_is_clear()){
             if(beepers_present()){
             step();
             }
             else{
             put_beeper();
             step();
             }
             if(no_beepers_present()){
             put_beeper();
             }
         } }
    }
    turn_left();
    turn_left();
}

void zabor_down(){
   if(beepers_present()){
         while(front_is_clear()){
             if(beepers_present()){
             step();
             }
             else{
             put_beeper();
             step();
             }
             if(no_beepers_present()){
             put_beeper();
             }
         }


     } 

    while(front_is_clear()){
        step();
    }


}
