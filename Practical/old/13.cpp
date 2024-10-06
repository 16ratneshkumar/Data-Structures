/*13. WAP to calculate GCD of 2 number 
    1. with recursion
    2. without recursion 
*/

//==============================================
// With Recursion
//==============================================
#include <iostream>
int gcd(int num1,int num2){
    if (num1==0){
        return num2;
    } else{
        return gcd(num2%num1,num1);
    }
}
int main(){
    int num1,num2;
    std::cout<<"Enter First Number :: ";
    std::cin>>num1;
    std::cout<<"Enter Second Number :: ";
    std::cin>>num2;
    std::cout<<"GCD of "<<num1<<" and "<<num2<<" are:: "<<gcd(num1,num2);
}



//==============================================
// Without Recursion
//==============================================
int gcd(int num1,int num2){
    int temp;
    while(num1!=0){
        temp=num1;
        num1=num2%num1;
        num2=temp;
    }
    return num2;
}
int main(){
    int num1,num2;
    std::cout<<"Enter First Number :: ";
    std::cin>>num1;
    std::cout<<"Enter Second Number :: ";
    std::cin>>num2;
    std::cout<<"GCD of "<<num1<<" and "<<num2<<" are:: "<<gcd(num1,num2);
}