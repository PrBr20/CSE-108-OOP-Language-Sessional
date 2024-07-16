#include <iostream>
#include <cmath>
using namespace std;

class Point
{
// x and y coordinate
    int x, y;
public:
//Add necessary constructor(s) to initialize x and y
    Point(int,int);
    Point(){};
//Add your set and get functions for x and y

    void setx(int a){x=a;}
    void sety(int a){y=a;}
    int getx(){return x;}
    int gety(){return y;}

    void print()
    {
        cout << "Coordinate: "<< x <<", " <<y <<endl;
    }
};

Point::Point(int a,int b){
    x=a;
    y=b;
}

class Circle
{
    Point p;
    int radius;
public:
// Add necessary constructor(s) to initialize p and radius
    Circle(int,int,int);
// Overload “upload” functions

    void update(int a, int b){
        int x=p.getx(),y=p.gety();
        x+=a;
        y+=b;
        p.setx(x);
        p.sety(y);
    }

    void update(int a,int b,int r){
        int x=p.getx(),y=p.gety();
        x+=a;
        y+=b;
        p.setx(x);
        p.sety(y);
        radius+=r;
    }

    void update(int r){
        radius+=r;
    }

    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl;
    }
};

Circle::Circle(int a,int b,int r){
    p.setx(a);
    p.sety(b);
    radius=r;
}

class Line{
    Point p1,p2;
public:
    Line(int a1, int b1, int a2, int b2){
        p1.setx(a1);
        p1.sety(b1);
        p2.setx(a2);
        p2.sety(b2);
    }

    void length(){
        float l;
        int a1=p1.getx(),a2=p2.getx(),b1=p1.gety(),b2=p2.gety();
        l=sqrt(pow(a1-a2,2)+pow(b1-b2,2));
        cout << "The length of the line: " << l << endl;
    }
};

int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;

    //First update
    cout << "First Update" << endl;
    // call “update” function of Circle class to increase the center’s x coordinate by 5 and y coordinate by 5;
    c.update(5,5);
    c.print();
    cout <<endl;

    //Second update
    cout << "Second Update" << endl;
    // call “update” function of Circle class to increase the radius by 6;
    c.update(6);
    c.print();
    cout << endl;

    //Third update
    cout << "Third Update" << endl;
    // call “update” function of Circle class to increase the center’s x coordinate by 2 and y coordinate by 2 and the radius by 2;
    c.update(2,2,2);
    c.print();
    cout << endl;

    Line l(2,4,6,8);
    l.length();


return 0;
}
