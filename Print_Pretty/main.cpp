#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        /* Enter your code here */
        int A_dec=A;
        std::cout<<1<<std::endl;
        std::cout<<std::left<<"0x" <<std::hex<<A_dec<<std::endl;

        if(B>0){
            std::cout<<std::setfill('_')<<std::setw(15)
                     <<std::internal<<std::fixed<<std::setprecision(2)<<"+"<<B<<std::endl;
        }
        else{
            std::cout<<std::setfill('_')<<std::setw(15)
                     <<'-'<<std::fixed<<std::setprecision(2)<<B<<std::endl;
        }

        std::cout<<std::fixed<<std::setprecision(9)<<std::scientific<<C<<std::endl;



    }
    return 0;

}
