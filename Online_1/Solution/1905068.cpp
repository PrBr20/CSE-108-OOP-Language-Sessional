#include<iostream>

using namespace std;

class Matrix {
    int** mat;
    int row,col;
public:
    Matrix(int,int);
    void set(int,int,int);
    ~Matrix();
    void print();
    int get(int,int);
    void add(int);
    int add();
};

Matrix::Matrix(int a,int b){
    row=a;
    col=b;
    mat = (int**) malloc( row*sizeof(int*));
    for(int i=0;i<row;i++){
        *(mat+i) = (int*) malloc(col*sizeof(int));
    }
}

Matrix::~Matrix(){
    for(int i=0; i<row; i++){
        free(*(mat+i));
    }
    free(mat);
}



void Matrix::set(int r, int c, int v){
    mat[r][c]=v;
}

void Matrix::print(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << mat[i][j] << ' ' ;
        }
        cout << endl;
    }
}

int Matrix::get(int r, int c){
    return mat[r][c] ;
}

void Matrix::add(int n){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat[i][j]+=n;
        }
    }
}


int Matrix::add(){
    int res=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            res+=mat[j][i];
    }
    return  res;
}

int main()
{
    cout<<"Hello World"<<'\n';
    Matrix m(3,3);
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    m.set(i,j,i+j);
    m.print();
    cout<<m.get(0,0)<<'\n';
    m.set(0,0,100);
    cout<<m.get(0,0)<<'\n';
    m.add(100);
    m.print();
    cout<<m.add()<<'\n';
    return 0;
}
