#include<iostream>
using namespace std;

// Singleton class
class MySingleton {
	private:
		static MySingleton * iInstance;
	public:
		static MySingleton * GetInstance();
	private:
		// private constructor
		MySingleton();
                ~MySingleton();
};

MySingleton * MySingleton::iInstance = NULL;

MySingleton::MySingleton()
{
	cout<<"In construtor..."<<endl;
}

MySingleton::~MySingleton()
{
    if(iInstance){
        iInstance = NULL;
    }
}

MySingleton * MySingleton::GetInstance()
{
        if(iInstance == NULL){
		iInstance = new MySingleton();
        }
        return iInstance;
}


int main()
{
	MySingleton * obj_1;
        obj_1 = MySingleton::GetInstance();
	MySingleton * obj_2;
        obj_2 = MySingleton::GetInstance();

        cout<<"Dia chi obj_1 la: "<<obj_1<<endl;
        cout<<"Dia chi obj_2 la: "<<obj_2<<endl;

	return 0;
}
