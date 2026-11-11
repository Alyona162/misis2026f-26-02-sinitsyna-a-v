#include <iostream>
int main(){
    int t, n, k, r, c, i, j, q;
    std::cin>>t;
    for (i = 1; i < t+1; i++){
        std::cin>>n>>k>>r>>c;
        int target = (r+c) % k;
        for (j = 1; j < n+1; j++){
            for (q = 1; q < n+1; q++){
                if ((q+j)%k == target){
                    std::cout<<'X';
                }else{
                    std::cout<<'.';
                }
                }std::cout<<"\n";
        }
    }
}
