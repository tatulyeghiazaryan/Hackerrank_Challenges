#include<iostream>

using namespace std;
//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :
class Box{
private:
    int m_length, m_breadth, m_height;
public:
    Box():m_length(0), m_breadth(0), m_height(0){}
    Box(int length, int breadth, int height):m_length(length),
                                             m_breadth(breadth),
                                             m_height(height)
    {}
    Box(Box &b){
        this->m_length=b.m_length;
        this->m_breadth=b.m_breadth;
        this->m_height=b.m_height;
    }
    bool operator<(Box &b){
        if(this->m_length<b.m_length){
            return true;
        }
        else if(this->m_breadth<b.m_breadth && this->m_length==b.m_length){
            return true;
        }
        else if(this->m_height<b.m_height && this->m_length==b.m_length &&                             this->m_breadth==b.m_breadth){
            return true;
        }
        return false;
    }
    friend ostream& operator<<(ostream &os, const Box &b){
        os<<b.m_length<<" "<<b.m_breadth<<" "<<b.m_height;
        return os;
    }

    int getLength(){
        return m_length;
    }
    int getBreadth(){
        return m_breadth;
    }
    int getHeight(){
        return m_height;
    }
    long long CalculateVolume(){
        return (long long)(this->m_length)*(this->m_breadth)*(this->m_height);
    }
};



// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
//            std::cout<<"temp length is: "<<temp.getLength()<<std::endl;
//            std::cout<<"temp breadth is: "<<temp.getBreadth()<<std::endl;
//            std::cout<<"temp height is: "<<temp.getHeight()<<std::endl;
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}