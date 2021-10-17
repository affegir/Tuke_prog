#include<superkarel.h>

void bcentr();
void turn_right();

int main(){
turn_on("task_5.kw");
set_step_delay(300);

put_beeper();


while(front_is_clear()){
  step();
  }
 put_beeper();
 turn_left();

while(front_is_clear()){
  step();
 }
 put_beeper();
 turn_left();


while(front_is_clear()){
 step();
 }
 put_beeper();
 turn_left();


while(front_is_clear()){
 step();
 }
  turn_left();

 while(front_is_clear()){
    bcentr();
 }




turn_off();
return 0;
}


void bcentr(){
step();
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
}
else {
        turn_left();
        turn_left();
        step();
        put_beeper();
        
}
}


void turn_right(){
turn_left();
turn_left();
turn_left();
}
