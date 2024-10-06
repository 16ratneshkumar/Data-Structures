/*11. WAP to calculate factorial and to compute the factors of a given no.
    1. using recursion
    2. using iteration 
*/

//==============================================
// Using Recursion
//==============================================

#include <iostream>
int factorial(int num){
    if (num<2){
        return 1;
    } else{
        return num*factorial(num-1);
    }
}
int main(){
    int num;
    std::cout<<"Enter Number For Finding Factorial:: ";
    std::cin>>num;
    std::cout<<"Factorial of "<<num<<" is:: "<<factorial(num);
}



//==============================================
// Using Iteration
//==============================================
#include <iostream>
int factorial(int num){
    int fact=1;
    for (int i =2;i<num+1;i++){
        fact*=i;
    }
    return fact;
}
int main(){
    int num;
    std::cout<<"Enter Number For Finding Factorial:: ";
    std::cin>>num;
    std::cout<<"Factorial of "<<num<<" is:: "<<factorial(num);
}