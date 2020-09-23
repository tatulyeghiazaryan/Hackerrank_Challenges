#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <class T>
class AddElements{
private:
    T m_x;
public:
    AddElements(T &x){
        m_x=x;
    }
    T add(T &y){
        return m_x+y;
    }
};

template<>
class AddElements<std::string>{
private:
    std::string m_x;

public:
    AddElements(std::string &x){
        m_x=x;
    }
    std::string concatenate(std::string &y){
        std::vector<std::string>v1{y};
    }
};


int main () {
    int n,i;
    cin >> n;
    for(i=0;i<n;i++) {
        string type;
        cin >> type;
        if(type=="float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
