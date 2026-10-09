#include <iostream>
#include <vector>

int main() {
    int t, n, i, j, rost, k;
    std::cin >> t;
    for (i = 0; i < t; i++) {
        std::cin>>n;
        std::vector<int> a(n);
        rost = 1;
        k = 0;
        for (j = 0; j < n; j++) {
            std::cin>>a[j];
            if (j > 0 && a[j] == 1 && a[j-1] == 1){
                rost += 5;
            }
            else if (a[j] == 1){
                rost += 1;
            }else if (j > 0 && a[j] == 0 && a[j-1] == 0){
                k += 1; 
            }
        } if (k > 0){
            std::cout<<-1<<std::endl;
        }else{
            std::cout<<rost<<std::endl;
        }
    }
}
