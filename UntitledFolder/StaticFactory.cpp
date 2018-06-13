#include<iostream>
#include<string>

using namespace std;

class Shape
{
public:
    virtual void Draw()=0;
    static Shape* Create(string type);
};

class Circle: public Shape
{
public:
    void Draw(){
        cout<<"I am Circle"<<endl;
    }
    friend class Shape;
};

class Square: public Shape
{
public:
    void Draw(){
        cout<<"I am Square"<<endl;
    }
    friend class Shape;
};

Shape* Shape::Create(string type)
{
    if(type == "Circle") return new Circle();
    if(type == "Square") return new Square();
    return NULL;
}

int main()
{
    Shape *Obj_1, *Obj_2;
    Obj_1= Shape::Create("Circle");
    Obj_2= Shape::Create("Square");

    Obj_1->Draw();
    Obj_2->Draw();

    return 0;
}
