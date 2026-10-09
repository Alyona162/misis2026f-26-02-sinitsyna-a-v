#include <iostream>
#include <vector>
int main(){
    int t, i, j, k;
    std::vector<std::vector<char>> a(8, std::vector<char>(8, 0));
    std::cin>>t;
    for (k = 0; k < t; k++){  
        for (i = 0; i < 8; i++){
            for (j = 0; j < 8; j++){
                std::cin>>a[i][j];
            }
        }
        for (i = 1; i < 7; i++){
            for (j = 1; j < 7; j++){
                if (a[i][j] == '#' && a[i-1][j-1] == '#' && a[i+1][j+1] == '#' && a[i+1][j-1] == '#' && a[i-1][j+1] == '#'){
                    std::cout<<i+1<<" "<<j+1<<" ";
                }
            }
        }
}
}