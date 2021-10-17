#include <superkarel.h>
void jump_over();
void turn_right();
void jump_over2();

int main(){
turn_on("task_1.kw");
set_step_delay(100);

  put_beeper();
  if(front_is_clear()){
     step();
  }
  else{
    turn_left();
    step();
    turn_right();
    if(front_is_clear()){
    step();
    turn_right();
    step();
    turn_left();
    }
  }
 
    while(no_beepers_present()){
       if(front_is_clear()){
        step();
        }
        else{
           jump_over();
          }
          }
     pick_beeper();
     turn_left();
     turn_left();
 while(no_beepers_present()){
       if(front_is_clear()){
          step();
          }
       else{
           jump_over2();
     }
     }
     pick_beeper();

            turn_off();
             return 0;
               }


  void jump_over(){
  turn_left();
  while (right_is_blocked()){
      step();
      }
      turn_right();
      do {
         step();
          }
      while (right_is_blocked());
              turn_right();
              while (front_is_clear()){
                     step();
                    }
  turn_left();
    }



 void jump_over2(){
   turn_right();
   while (left_is_blocked()){
       step();
       if(beepers_present()){
            pick_beeper();
            turn_off();
                   }
       }
       turn_left();
       do {
          step();
          if(beepers_present()){
            pick_beeper();
            turn_off();
          }
           }
       while (left_is_blocked());
               turn_left();
               while (front_is_clear()){
                      step();
                            }             
  turn_right();
     }


  void turn_right(){
  turn_left();
  turn_left();
  turn_left();

 }
