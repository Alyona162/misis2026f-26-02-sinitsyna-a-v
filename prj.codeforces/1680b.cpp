#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    int t, n, m, i, j, k;
    std::cin>> t;
    for (k = 0; k < t; k++){
    std::cin >> n >> m;
    std::vector<std::vector<char>> a(n, std::vector<char>(m));
    int minx=1000000000, miny=1000000000;
        for (i = 0; i < n; i++){
            for (j = 0; j < m; j++){
                std::cin >> a[i][j];
            }
        }
        for (i = 0; i < n; i++){
            for( j = 0; j < m; j++){
                if (a[i][j] == 'R'){
                    minx = std::min(minx, i);
                    miny = std::min(miny, j);
                }
            }
        }
        if (a[minx][miny] == 'R'){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
}

}