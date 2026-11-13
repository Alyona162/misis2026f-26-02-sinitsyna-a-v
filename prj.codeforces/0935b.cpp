#include <iostream>
#include <string>

int main(){
    int n, i = 0, j = 0, k = 0, v = 0, niz = 0, score = 0;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    for (char c : s){
        if (c == 'U'){
            j++;
        }else{
            i++;
        }
        if (i > j){
            if (niz == 0){
                score++;
            }
            niz = 1;
            v = 0;
        }else if (i < j){
            if (v == 0){
                score++;
            }
            v = 1;
            niz = 0;
        }
        k ++;
    }
    std::cout << score - 1;
}