#include<superkarel.h>

 void corner();
 void home();
 void turn_right();
 bool front_is_blocked();
 bool left_is_blocked();

 int main(){
 turn_on("task_2.kw");
 set_step_delay(100);


 while(no_beepers_in_bag()){
      if(front_is_clear()){
         step();
         if(beepers_present()){
             pick_beeper();
         }
      }
      else{
          corner();
          if(beepers_present()){
             pick_beeper();
          }
      }
     }
 turn_left();
 turn_left();
 while(beepers_in_bag()){
 if(front_is_blocked() && left_is_blocked() && right_is_blocked()){
     turn_off();
     }
     else{
     if(front_is_clear()){
           step();
        }
 else{
 home();

 }
 }
 }
 return 0;
 }


 void corner(){
     if(front_is_blocked()){
         turn_left();
     }

 }
void home(){
    if(front_is_blocked()){
         turn_right();
       }

        }



 void turn_right(){
 turn_left();
 turn_left();
 turn_left();
 }
