#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t, c, i, j, k;
    std::cin>>t;
    std::vector<std::vector<char>> v(10, std::vector<char>(10));
    for (k = 0; k < t; k++){
        c = 0;
        for (i = 0; i < 10; i++){
            for (j = 0; j < 10; j++){
                std::cin>>v[i][j];
                if (v[i][j] == 'X'){
                    c += 1 + std::min({i, j, 9 - i, 9 - j});
                }
            }
        }
        std::cout<<c<<std::endl;
    }
}
