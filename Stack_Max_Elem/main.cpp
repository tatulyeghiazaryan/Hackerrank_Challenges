#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::stack<int>nums;
    std::stack<int>maxNums;

    int N, x;
    int type;
    int currentMax=-1;
    std::cin>>N;

    for(int i=0; i<N; i++){
        std::cin>>type;
        if(type==1){
            std::cin>>x;
            nums.push(x);
            if(x>currentMax){
                currentMax=x;
                maxNums.push(currentMax);
            }
            else{
                maxNums.push(currentMax);
            }
        }
        else if(type==2){
            nums.pop();
            maxNums.pop();
            if(!maxNums.empty()){
                currentMax=maxNums.top();
            }
            else{
                currentMax=-1;
            }
        }
        else if(type==3){
            std::cout<<maxNums.top()<<std::endl;
        }
    }


    return 0;
}
