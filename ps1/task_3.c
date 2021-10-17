#include <superkarel.h>
void next_line();
void turn_right();

int main(){
turn_on("task_3.kw");
set_step_delay(30);

while (front_is_clear()){
step();
     if (beepers_present()){
         pick_beeper();
    }
}
    turn_left();
    turn_left();
while(front_is_clear()){
    if(right_is_blocked() && beepers_in_bag()){
        put_beeper();
    }
step();
}

while(left_is_clear() || front_is_clear()){
next_line();
}
turn_left();
turn_left();
while(front_is_clear()){
step();
    if(beepers_present()){
        turn_left();
        while(front_is_clear()){
                step();
        }
            turn_left();
        while(front_is_clear()){
            step();
        }
turn_left();
turn_left();
turn_off();
    }
}
turn_left();
turn_left();
while(front_is_clear()){
step();
}
turn_right();
step();
turn_right();



while(front_is_clear()){
 step();
     if(beepers_present()){
         turn_left();
        while(front_is_clear()){
                 step();
         }
             turn_left();
         while(front_is_clear()){
             step();
         }
 turn_left();
 turn_left();
 turn_off();
     }
 }
 turn_left();
 turn_left();
 while(front_is_clear()){
 step();
 }
 turn_right();
 step();
 turn_right();



while(front_is_clear()){
 step();
     if(beepers_present()){
         turn_left();
         while(front_is_clear()){
                 step();
         }
             turn_left();
         while(front_is_clear()){
             step();
         }
 turn_left();
 turn_left();
 turn_off();
     }
 }
 turn_left();
 turn_left();
 while(front_is_clear()){
 step();
 }
 turn_right();
 step();
 turn_right();
turn_off();
return 0;
}

void next_line(){
turn_left();
step();
turn_left();
while (front_is_clear()){
 step();
 if(beepers_present()){
    pick_beeper();
 }
 }
      turn_left();
     turn_left();
     
 while(beepers_in_bag()){ 
        turn_right();
        step();
        turn_left();
        turn_left();
        if(beepers_present()){
            step();
            put_beeper();
            turn_right();
            step();
        }
        else{
            step();
            turn_right();
            step();
        }
}
while(front_is_clear()){
step();
}
}

void turn_right(){
turn_left();
turn_left();
turn_left();
}
