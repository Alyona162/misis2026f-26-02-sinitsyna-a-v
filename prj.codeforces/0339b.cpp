#include <iostream>
#include <vector>
int main(){
    long long n, m, i, k, t = 0;
    std::cin>>n>>m;
    std::vector<int> a(m);
    for (i = 0; i < m; i++){
        std::cin>>a[i];
    }
    t += a[0] - 1;
    for (k = 0; k < m-1; k++){
        if (a[k+1] >= a[k]){
            t += a[k+1]-a[k];
        }else{
            t += n-a[k]+a[k+1];
        }
    }
    std::cout<<t<<std::endl;
}
