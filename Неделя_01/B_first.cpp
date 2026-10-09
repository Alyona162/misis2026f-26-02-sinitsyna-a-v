#include<iostream>
int main(){
    int a = 0;
    int b = 0;
    std::cin>>a;
    b = a / 5;
    if (a % 5 > 0){
        b += 1;
    }
    std::cout<<b;
}
