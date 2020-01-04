//Matrix.h

#ifndef MATRIX_H
#define MATRIX_H
#define MAX_STACK_SIZE 100

class Matrix{
protected:
   int m, n; //map�� ���� ���� 
    int** map; //input �޾ƿ��� �̷� matrix 
    struct XY{
       int a;
       int b;
    }; //������ ��� (a, b) �����ϴ� ����ü
    struct XY his[MAX_STACK_SIZE]; //������ ��� (a, b) ����� ����ü(historyXY)�� �迭(his)
   int p; //������ ��� (a, b) ����� ����ü(historyXY) �迭(his) index
    
public:      
    Matrix();
    ~Matrix();
    void gotoxy(int x, int y);
    void setMatrix();
    void introFrame();
    void endingFrame();
    void index();
    void explain(); 
    void title();  
};

#endif
