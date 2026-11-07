#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main(){
    int t, n, x, k = 0, m, j, i, a;
    std::vector <int> v;
    std::cin>>t;
    std::cin>>n>>x;
    for (j = 0; j < t; j++){
        for (i = 0; i < n; i++){
                std::cin>>a;
                v.push_back(a);
        }
        //std::sort(v.begin(), v.end());
        std::set<int> s(v.begin(), v.end());
        k = 0;
        for (i = 1; i <= n; i++){
                if (v[i] != i){
                    k += 1;
                } if (k == x){
                    m = i;
                    break;
                }
        }std::cout<<m;
    }
}
