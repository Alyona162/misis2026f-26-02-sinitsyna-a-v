#include <iostream>
#include <cmath>
int main(){
    int t, a, b, c, i;
    std::cin>>t;
    for (i = 0; i < t; i++){
        std::cin>>a>>b>>c;
        double d = abs(a - b);
        std::cout<<ceil(d/(2*c))<<std::endl;
    }
}
