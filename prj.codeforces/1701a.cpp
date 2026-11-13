#include <iostream>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int cnt = 0, x;
        for (int k = 0; k < 4; k++){
            std::cin >> x;
            cnt += x;
        }
        if (cnt == 0)
            std::cout << 0 << "\n";
        else if (cnt == 4)
            std::cout << 2 << "\n";
        else
            std::cout << 1 << "\n";
    }
}