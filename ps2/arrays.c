#include<stdio.h>
#include<math.h>

//1

float lift_a_car(const int stick_length, const int human_weight, const int car_weight)  {
            float lift_a_car2 = human_weight + car_weight;
            float lift_a_car1 = stick_length * human_weight;
            float lift_a_car3 = lift_a_car1 / lift_a_car2; 
            float lift_a_car = roundf(lift_a_car3 * 100) / 100;
            return lift_a_car;
            }


//2

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
    float unit_price1 = pack_price / rolls_count;
    float unit_price2 = unit_price1 / pieces_count;
    float unit_price3 = unit_price2 * 100;
    float unit_price = roundf(unit_price3 * 100) / 100;
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
    else if((opposite_number1 < n)){
         p = opposite_number1;
    }
    else{
        p = 0;
    }
    int opposite_number = p;
    return opposite_number;
}

//5

void counter(const int input_array[], const int array_size, int result_array[2]){
    int o = 0, p = 0;
    for (int i = 0; i < array_size; i++) {

        if(i % 2 == 0){
             o = o + input_array[i];
        }
        
        else{
             p = p + input_array[i];
        }
        
    }
     result_array[0] = o;
     result_array[1] = p;
}


//6
unsigned long sum_squared(const int line){
    unsigned long long c[1000];
    unsigned long long p = 0;
 
    c[0] = 1;
    for( int i = 1; i <= line; i++ )
        c[i] = 0;
 
    for( int j = 1; j <= line; j++ )
        for( int i = line; i >= 1; i-- )
            c[i] += c[i - 1];
 
    for( int i = 0; i <= line; i++ )
        p += ( c[i] * c[i] );
 
    return p;
}

//7
int array_min(const int input_array[], const int array_size){
    int s; 
    if(!input_array){
     return -1;
    }
    for(int i=0; i < array_size; i++){
        if(input_array[i] < s){
            s = input_array[i];   
        }
    }   
      
    return s; 
}

int array_max(const int input_array[], const int array_size){
    int b; 
    if(!input_array){
     return -1;
    }
    for(int i=0; i < array_size; i++){
        if(b < input_array[i]){
            b = input_array[i];   
        }
    }     
    return b;
}      
 


//8
unsigned long special_counter(const int input_array[], const int array_size){
int o = 0, p = 0, sum;
    for (int i = 0; i < array_size; i++) {
        if(i % 2 == 0){
             o = o + input_array[i];
        }
        else{
             p = p + (input_array[i] * input_array[i]);
        }
        
    }
sum = o + p;
return sum;
}


int main(){

return 0;
}
