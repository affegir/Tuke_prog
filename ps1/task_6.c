#include<superkarel.h>

int main(){
turn_on("task_6.kw");
set_step_delay(500);

while(front_is_clear()){
    while(no_beepers_present()){
        step();
    }
if(beepers_present()){
    pick_beeper();
while(not_facing_north()){
    turn_left();
    }
}

 if(beepers_present()){
       pick_beeper();
         while(not_facing_west()){
               turn_left();
                     }
                       }


 if(beepers_present()){
       pick_beeper();
         while(not_facing_south()){
               turn_left();
                     }
                       }
 if(beepers_present()){
       pick_beeper();
         while(not_facing_east()){
               turn_left();
                     }
                       }
  if(beepers_present()){
        pick_beeper();
        turn_off(); 
         }



}
return 0;

}
