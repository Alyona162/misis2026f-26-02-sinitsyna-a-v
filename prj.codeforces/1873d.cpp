#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    int t, n, k, i, j, c;
    std::string s;
    std::cin>>t;
    for (i = 0; i < t; i++){
        std::cin>>n>>k;
        std::cin>>s;
        c = 0;
        for (j = 0; j < n; j++){
            if (s[j] == 'B'){
                c++;
                j = j + k - 1;
            }
        } std::cout<<c<<std::endl;
    }
}
