#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, x, a, b;
    std::cin>>N;
    std::vector<int>vecArr;
    int temp;

    for(int i=0; i<N; i++){
        std::cin>>temp;
        vecArr.push_back(temp);
    }

    std::cin>>x;
    vecArr.erase(vecArr.begin()+(x-1));

    std::cin>>a>>b;
    int decArrSize=1;
    for(int i=a; i<b; i++){
        vecArr.erase(vecArr.begin()+(i-decArrSize));
        decArrSize++;
    }

    std::cout<<vecArr.size()<<std::endl;
    for(int i=0; i<vecArr.size(); i++){
        std::cout<<vecArr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
