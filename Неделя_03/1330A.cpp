#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

int main(){
    int t, n, x, i, j, k, m, stop; 
    std::cin>>t;
    for (i = 0; i < t; i++){
        std::cin>>n>>x;
        std::vector<int> a(n);
        for (j = 0; j < n; j++){
            std::cin>>a[j];
        }
        std::set<int> s(a.begin(), a.end());
        k = 1;
        stop = 0;
        m = *s.begin();
        int h = m - 1;
        if (h > x){
            std::cout<<x<<std::endl;
            continue;
        }
        x -= h;
        for (auto y = s.begin(); y != s.end(); ++y){
            auto nxt = std::next(y);
            if (nxt != s.end()){
                int gap = *nxt - *y - 1;
                if (gap == 0){
                        m = *nxt;
                    }
                else if (gap <= x){
                    m = *nxt;
                    x -= gap;
                }else{
                    m += x;
                    stop = 1;
                    break;
                }
            }
        }
        if (stop != 1){
                m += x;
        }
        std::cout<<m<<std::endl;
    }
}