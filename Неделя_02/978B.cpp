#include <iostream>
int main(){
    int n, c = 0, k = 0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (char x:s){
        if (x == 'x'){
            c += 1;
            if (c == 3){
                    k += 1; c -=1;
            }
        }else{ c = 0;
        }
    }
    std::cout<< k;
}
