//lunaticMatrix.h
#ifndef LUNATIC_MATRIX_H
#define LUNATIC_MATRIX_H
class LunaticMatrix{
protected:
   int m, n; //map�� ���� ���� 
    int** map; //input �޾ƿ��� �̷� matrix 
     
public:      
     LunaticMatrix();
     ~LunaticMatrix();
     void gotoxy(int x, int y);
     void setLunaticMatrix();
     void endingFrame();
     };

#endif
