#include<iostream>
#include<string>

using namespace std;

class Mobile
{
public:
    virtual string Camera()=0;
    virtual string KeyBoard()=0;
    void PrintSpecs(){
        cout<<" Camera: "<<Camera()<<endl;
        cout<<" KeyBoard: "<<KeyBoard()<<endl;
    }
};

class Samsung: public Mobile
{
    string Camera(){
        return "12 Mpx";
    }
    string KeyBoard(){
        return "Qwerty";
    }
};

class Xaomi: public Mobile
{
    string Camera(){
        return "5 Mpx";
    }
    string KeyBoard(){
        return "IRR";
    }
};

class MobileFactory
{
public:
    Mobile *GetMobile(string type){
        if(type == "Samsung") return new Samsung;
        if(type == "Xaomi") return new Xaomi;
        return NULL;
    }
};

int main()
{
    MobileFactory *myMobile = new MobileFactory();
    Mobile *mobile_1 = myMobile->GetMobile("Samsung");
    Mobile *mobile_2 = myMobile->GetMobile("Xaomi");

    mobile_1->PrintSpecs();
    mobile_2->PrintSpecs();

    return 0;
}
