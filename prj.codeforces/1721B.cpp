
#include <iostream>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n, m, sx, sy, d;
        std::cin >> n >> m >> sx >> sy >> d;
        bool blocked = (sx - 1 <= d || m - sy <= d) && (n - sx <= d || sy - 1 <= d);
        if (blocked){
            std::cout << -1 << std::endl;
        } else {
            std::cout << n + m - 2 << std::endl;
        }
    }
}