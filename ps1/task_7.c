#include<superkarel.h>

void turn_right();

int main(){
turn_on("task_7.kw");
set_step_delay(30);

while(front_is_clear()){
    put_beeper();
    step();
    }
put_beeper();
turn_left();
turn_left();
while(front_is_clear()){
    step();
    }
turn_left();
turn_left();



while(front_is_clear()){

while(left_is_blocked() || no_beepers_present()){
step();
if(front_is_blocked()){
turn_left();
turn_left();
while(front_is_clear()){
step();
if(beepers_present()){
pick_beeper();
}
}
turn_left();
turn_left();
while(front_is_clear()){
step();
}
if(beepers_present()){
pick_beeper();
}
turn_off();
}
}
put_beeper();
turn_left();
step();
while (no_beepers_present()) {
        if (right_is_clear()) {
            turn_right();
        }
        else if (left_is_clear() && front_is_blocked()) {
            turn_left();
        }
        else if (front_is_blocked()) {
            turn_left();
            turn_left();
        }
        step();
    }



pick_beeper();
if(beepers_present()){
    pick_beeper();
    turn_right();
    while(front_is_clear()){
        step();
        if(beepers_present()){
            pick_beeper();
            }
        }
        turn_left();
        turn_left();
    }
else{
    turn_left();
    turn_left();
    step();
    put_beeper();
    turn_left();
    turn_left();
    step();
    turn_right();
    step();
    while(beepers_present() && right_is_blocked()){
        pick_beeper();
        step();
    }
    pick_beeper();
    pick_beeper();
    turn_right();
    step();
    put_beeper();
    turn_left();
    turn_left();
    step();
    turn_right();
    while(front_is_clear()){
        step();
    }
    turn_left();
    turn_left();
    }
}






turn_off();
return 0;
}

void turn_right() {
turn_left();
turn_left();
turn_left();
}
