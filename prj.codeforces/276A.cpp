#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    int n, k, i, f, t;
    std::vector <int> u;
    std::cin>>n>>k;
    for (i = 0; i < n; i++){
        std::cin>>f>>t;
        if (t > k){
            u.push_back(f - (t-k));
        }else{
             u.push_back(f);
        }
    }
    std::cout<<*std::max_element(u.begin(), u.end());
}
