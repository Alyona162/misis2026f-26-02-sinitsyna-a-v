#include <iostream>
#include <string>
int main(){
    int t, i, a, rez, j, k, q, c;
    std::string st;
    std::cin >> t;
    for (i = 0; i < t; i ++){
        std:: cin >> a;
        st = std::to_string(a);
        c = 0;
        for (q = 0; q < st.size(); q++){
            if (st[q] != '0'){
                c += 1;
            }
        } std::cout<<c<<std::endl;
        for (j = st.size()-1; j >= 0; j --){
            if (st[j] != '0'){
                    rez = st[j] - '0'; //строка в число
                    for(int k = 0; k < st.size()-1-j; k ++){
                        rez *= 10;
                    }
            std::cout<<rez<< ' ';
            }
        }
        }
    }
