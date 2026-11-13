#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, k, i;
    std::cin>> n >> k;
    std::vector<int> a(n);
    for (i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    for(i = n - 1; i >= 0; i--){
        if (k % a[i] == 0){
            std:: cout << k/a[i];
            break;
        }
    }
}