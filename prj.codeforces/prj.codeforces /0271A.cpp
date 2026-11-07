#include<iostream>

int main(){
    int a = 0;
    int k = 0;
    std::cin>>a;
    for(a += 1; a < 9999; a += 1){
        int a1 = a % 10;
        int a2 = a / 10 % 10;
        int a3 = a / 100 % 10;
        int a4 = a / 1000;
        if (a1 != a2 && a1 != a3 && a1 != a4 && a2 != a3 && a3 != a4 && a2 != a4){
            std::cout<<a;
            break;
        }
    }
}
