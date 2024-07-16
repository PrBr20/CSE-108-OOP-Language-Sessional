#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    Vector(const Vector &a){
        name = new char[1];
        name[0] = '\0';
        x=a.x;
        y=a.y;
        z=a.z;
    }

    int setX(int a){x=a;}
    int setY(int b){y=b;}
    int setZ(int c){z=c;}

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    Vector operator^(Vector a){
        int ax=a.x, ay=a.y, az=a.z;

        Vector temp("tem");

        temp.x=y*az-z*ay;
        temp.y=z*ax-x*az;
        temp.z=x*ay-y*ax;

        return temp;
    }

    void operator=(Vector a){
        x=a.x;
        y=a.y;
        z=a.z;
    }

    int operator==(Vector a){
        return (x==a.x) && (y==a.y) &&(z==a.z);
    }

    Vector operator*(int p){
        Vector temp("tem");

        temp.x=this->x*p;
        temp.y=this->y*p;
        temp.z=this->z*p;

        return temp;
    }

    Vector operator*(Vector a){
        Vector temp("tem");

        temp.x=this->x*a.x;
        temp.y=this->y*a.y;
        temp.z=this->z*a.z;

        return temp;
    }

    friend Vector operator*(int p, Vector a);

    void print(){
        cout << name << ": " << x << "x";
        if(y>0)cout << "+";
        cout << y << "y" ;
        if(z>0)cout << "+";
        cout << z << "z" << endl;
    }

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}

    char *getName(){return name;}

    ~Vector()
    {
        delete []name;
    }

};


Vector operator*(int p, Vector a){
    int ax=a.x, ay=a.y, az=a.z;
    Vector temp("");

    temp.x=ax*p;
    temp.y=ay*p;
    temp.z=az*p;

    return temp;
}

int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2

    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;       ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}
