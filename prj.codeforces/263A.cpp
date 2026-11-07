#include<iostream>
#include<cmath>
int main(){
    int k = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 25; i ++){
        std::cin>>k;
        if (k == 1){
            x = abs((i % 5) - 2) + abs((i / 5) - 2);
            break;
        }
                }
    std::cout<<x;
}
