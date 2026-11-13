#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n), tm(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i] >> b[i];
        for (int i = 0; i < n; i++)
            std::cin >> tm[i];

        int dep = 0, prev_b = 0;    
        for (int i = 0; i < n; i++){
            int arr = dep + (a[i] - prev_b) + tm[i];
            if (i == n - 1){
                std::cout << arr << "\n";
                break;
            }
            dep = std::max(arr + (b[i] - a[i] + 1) / 2, b[i]);
            prev_b = b[i];
        }
    }
}