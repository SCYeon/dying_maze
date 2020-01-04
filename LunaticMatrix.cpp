//LunaticMatrix.cpp
#include "LunaticMatrix.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // �ܼ�â�� �ڵ������� �޾ƿɴϴ�.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // ���

LunaticMatrix::LunaticMatrix(){ //���� �迭 ���� 
   m = 20;
   n = 30;
      map = new int* [m];
      
      for(int i=0; i<m; i++){
         map[i]=new int[n];
     }
}

LunaticMatrix::~LunaticMatrix(){
    for(int i=0; i<m; i++){
        delete[]map[i];
     }
    delete[]map;
}

void LunaticMatrix::setLunaticMatrix(){
    ifstream input;
    input.open("LunaticMaze.txt"); //���Ϸ� �Է� ���� 
       
   if(input.fail()){
       cout<<"���ϻ��� �� �ٽý���"<<endl;
       return;
    }
     
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
          if(!input.eof())
            input>>map[i][j];
          else{
            cout<<"����"<<endl;
            return;
            }
      }
    } 
    input.close();
  }
  
void LunaticMatrix::gotoxy(int x, int y) //Ŀ�� �̵� �Լ� 
{
   COORD A = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), A);
}

void LunaticMatrix::endingFrame(){//������ �⺻ ����Ʋ�� �ϼ������ִ� �Լ��� ���븦 �׸��� �ִ�.
 int i;
 gotoxy(0, 0);
 cout<<"��-----------------------------------------------------------��"<<endl;
 for (i = 0; i<18; i++){
  gotoxy(0, i + 1);
  cout<<"��                                                           ��"<<endl;
  }
    gotoxy(0, i + 1);
     cout<<"��-----------------------------------------------------------��"<<endl;
    gotoxy(0, 0);
}
