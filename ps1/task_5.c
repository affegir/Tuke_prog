#include<superkarel.h>

void povorot1();
void turn_right();

int main(){
turn_on("task_5.kw");
set_step_delay(30);

while(not_facing_south()){
    turn_left();
    }
while(front_is_clear()){
    step();
    }
turn_left();
while(front_is_clear()){
    step();
    }
turn_left();

put_beeper();
while(front_is_clear()){
while(front_is_clear()){
    step();
    } 
if(beepers_present()){
    
}
else{
    put_beeper();
    turn_left();
    }
}
turn_left();
step();

while(right_is_blocked() || left_is_blocked()){
while(no_beepers_present()){
    step();
    }
turn_left();
turn_left();
step();
step();
if(no_beepers_present()){
    turn_left();
    turn_left();
    step();
    put_beeper();
    turn_left();
    turn_left();
    step();
    }
else{
    turn_left();
    turn_left();
    step();
    put_beeper();
    if(right_is_blocked()){
        turn_left();
        }
    else{
        turn_right();
        }
    }
}

while(front_is_clear()){
    step();
    if(no_beepers_present()){
        put_beeper();
        }
    }
turn_left();
while(front_is_clear()){
    step();
    }
turn_left();
step();

while(right_is_blocked() || left_is_blocked()){
 while(no_beepers_present()){
     step();
     }
 turn_left();
 turn_left();
 step();
 step();
 if(no_beepers_present()){
     turn_left();
     turn_left();
     step();
     put_beeper();
     turn_left();
     turn_left();
     step();
     }
 else{
     turn_left();
     turn_left();
     step();
     put_beeper();
     if(right_is_blocked()){
         turn_left();
         }
     else{
         turn_right();
		}
	}
}

while(front_is_clear()){
	step();
	put_beeper();
	
}

turn_left();
while(front_is_clear()){
    step();
    }
turn_left();
while(left_is_clear() && front_is_clear()){
while(front_is_clear()){
    if(beepers_present()){
        pick_beeper();
        }
    step();
    }
turn_left();
if(beepers_present()){
    pick_beeper();
    }
step();
turn_left();


while(front_is_clear()){
     if(beepers_present()){
        pick_beeper();
        }
     step();
    }
turn_right();
if(beepers_present()){
    pick_beeper();
    }
step();
turn_right();
}
while(front_is_clear()){
    if(beepers_present()){
        pick_beeper();
        }
        step();
    }


turn_right();
while(front_is_clear()){
    if(no_beepers_present()){
        put_beeper();
        }
     step();
}

turn_right();
while(front_is_clear()){
    if(no_beepers_present()){
       put_beeper();
       }
    step();
}

turn_right();
while(front_is_clear()){
    if(no_beepers_present()){
       put_beeper();
       }
    step();
}

turn_right();
while(front_is_clear()){
    if(no_beepers_present()){
       put_beeper();
       }
    step();
}
povorot1();
while(no_beepers_present() && front_is_clear()){
while(front_is_clear()){
    if(beepers_present() && front_is_clear()){
        pick_beeper();
        turn_off();
    }
    else{
    step();
    }
    }
    turn_left();
    turn_left();
    while(front_is_clear()){
            step();
        }
        povorot1();
}



turn_off();
return 0;
}


void turn_right(){
turn_left();
turn_left();
turn_left();
}

void povorot1(){
turn_right();
step();
turn_right();
step();
}
