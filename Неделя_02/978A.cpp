#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, i;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<int> b;
    for (i = 0; i < n; i++){
        std::cin>>a[i];
    }
    for (i = n - 1; i >= 0; i--){
        if (std::count(b.begin(), b.end(), a[i]) == 0){
            b.push_back(a[i]);
        } 
    }
    //std::reverse(b.begin(), b.end());
    int k = b.size();
    std::cout<<k<<std::endl;
    a.clear();
    for (i = 0; i < k; i++){
        //std::cout<<b[i]<<' ';
        a.insert(a.begin(), b[i]);
    }
    for (i = 0; i < k; i++){
        std::cout<<a[i]<<' ';
    }
}