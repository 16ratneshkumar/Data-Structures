/*12. WAP to display fibonacci series 
    1. using recursion
    2. using iteration 
*/

//==============================================
// Using Recursion
//==============================================
#include <iostream>
int fibonacci_series(int num){
    if (num==0){
        return 0;
    }
    if (num==1){
        return 1;
    }
    return fibonacci_series(num-1)+fibonacci_series(num-2);
}

void print_fibonacci_series(int num){
    for (int i=0;i<num;i++){
        std::cout<<fibonacci_series(i)<<" ";
    }
}

int main(){
    int num;
    std::cout<<"Enter Length Of Series :: ";
    std::cin>>num;
    std::cout<<"Fibonacci Series are:: ";
    fibonacci_series(num);
}



//==============================================
// Using Iteration
//==============================================
void fibonacci_series(int num){
    int prev=0,curr=1;
    if (num==0){
        std::cout<<prev;
    }
    if (num>=1){
        std::cout<<prev<<" "<<curr<<" ";
    }
    for(int i=2;i<num;i++){
        int next=prev+curr;
        std::cout<<next<<" ";
        prev=curr;
        curr=next;
    }
}
int main(){
    int num;
    std::cout<<"Enter Length Of Series :: ";
    std::cin>>num;
    std::cout<<"Fibonacci Series are:: ";
    fibonacci_series(num);
}