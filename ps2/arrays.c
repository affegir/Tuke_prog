#include<stdio.h>
#include<math.h>

//1

float lift_a_car(const int stick_length, const int human_weight, const int car_weight)  {
            float lift_a_car2 = human_weight + car_weight;
            float lift_a_car1 = stick_length * human_weight;
            float lift_a_car = lift_a_car1 / lift_a_car2; 
            return lift_a_car;
            }
//2

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float unit_price1 = pack_price / rolls_count;
    float unit_price2 = unit_price1 / pieces_count;
    float unit_price3 = unit_price2 * 100;
    float unit_price4 = unit_price3 * 100;
	float unit_price = roundf(unit_price4 * 100) / 100;
    return unit_price;
    
}
//3
int collatz(const int number){
    int i = number;
    int collatz = 1;
    while(i != 1){
        if(i % 2 == 1){
            i=i*3+1;
        }
         else{
            i=i/2;
        }
    collatz++;
    }
    return collatz;
}
//4
int opposite_number(const int n, const int number){
    int i = n/2, p;
    int opposite_number1 = number + i;
    if(opposite_number1 > n){
          p = opposite_number1 - n;
    }
    else{
        p = opposite_number1;
    }
    int opposite_number = p;
    return opposite_number;
}


int main(){

return 0;
}