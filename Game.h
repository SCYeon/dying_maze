//Game.h

#ifndef GAME_H
#define GAME_H

#include "Matrix.h"
#include "DFSMatrix.h"

class Game:public Matrix, public DFSMatrix{

protected:
    int count; //2�� ������ ������� Ƚ�� 
    int wrongAnsNum; //���� Ʋ�� ���� 
    
public:      
   Game();
   void mazeFrame();
   void upDown();
   void gawiBawiBo();
   void numBall();
   void nonSenseQuiz();
   bool isEqual();
   void grade();
   void display(int A);  
};

#endif
