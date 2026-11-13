
#include <iostream>
#include <vector>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<std::vector<char>> a(n, std::vector<char>(n));
        int r[2], c[2], cnt = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                std::cin >> a[i][j];
                if (a[i][j] == '*'){
                    r[cnt] = i;
                    c[cnt] = j;
                    cnt++;
                }
            }
        }

        if (r[0] == r[1]){
            int r3;
            if(r[0] == 0){
                r3 = 1;
            }else{
                r3 = 0;
            }
            a[r3][c[0]] = '*';
            a[r3][c[1]] = '*';
        } else if (c[0] == c[1]){
            int c3;
            if (c[0] == 0){
                c3 = 1;
            } else {
                c3 = 0;
            }
            a[r[0]][c3] = '*';
            a[r[1]][c3] = '*';
        } else {
            a[r[0]][c[1]] = '*';
            a[r[1]][c[0]] = '*';
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                std::cout << a[i][j];
            std::cout << std::endl;
        }
    }
}
