//Matrix.cpp 
#include "Matrix.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // �ܼ�â�� �ڵ������� �޾ƿɴϴ�.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // ���

Matrix::Matrix(){ //���� �迭 ���� 
   p = 0;
   m = 20;
   n = 30;
    map = new int* [m];
      
    for(int i=0; i<m; i++){
        map[i]=new int[n];
    }
}

Matrix::~Matrix(){
    for(int i=0; i<m; i++){
       delete[]map[i];
    }
    delete[]map;
}

void Matrix::setMatrix(){
   ifstream input;
    input.open("Maze.txt"); //���Ϸ� �Է� ���� 
       
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
  
void Matrix::gotoxy(int x, int y) //Ŀ�� �̵� �Լ� 
{
   COORD A = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), A);
}

void Matrix::introFrame() //ó�� ����ȭ�鿡 ��� �� Ʋ�� ¥�� �Լ��̴�.
{
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
    gotoxy(12, 4);
    cout<<"��------------------------------------��"<<endl;
    gotoxy(12, 5);
    cout<<"��         D Y I N G   M A Z E        ��"<<endl;
    gotoxy(12, 6);
    cout<<"��------------------------------------��"<<endl;
    gotoxy(12, 20);
}

void Matrix::endingFrame(){//������ �⺻ ����Ʋ�� �ϼ������ִ� �Լ��� ���븦 �׸��� �ִ�.
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

void Matrix::index()
{
   gotoxy(24,3);
   cout<<"1) 1�г��"<<endl;
   
   gotoxy(24,5);
   cout<<"2) 2�г��"<<endl;
   
   gotoxy(24,7);
   cout<<"3) 3�г��"<<endl;
   
   gotoxy(24,9);
   cout<<"4) 4�г��"<<endl;
   
   gotoxy(24,11);
   cout<<"5) 5�г��"<<endl;
   
   gotoxy(24,13);
   cout<<"6) 6�г��"<<endl;
   
   gotoxy(24,15);
   cout<<"7) �糪ƽ"<<endl;
   
   gotoxy(20, 17);
   cout<<"�Է�>> ";
}

void Matrix::explain()
{
   gotoxy(25, 5);
    cout << "���� ����" << endl;
    gotoxy(22, 8);
   cout << "1. �ͼ��� ����"<<endl;
   gotoxy(22, 10);
   cout << "2. ����������"<<endl;
   gotoxy(22, 12);
   cout << "3. �������� ���߱�"<<endl;
   gotoxy(22, 14);
   cout << "4. ���ھ߱�"<<endl;
      
}

void Matrix::title() //�� �κ� ���� ������ �� ���� ��Ÿ���� ���� ���� �������̴�.
{
   gotoxy(24, 8);
   cout<<"1. ���� ����";
   gotoxy(24, 10);
   cout<<"2. �̷� ����";
   gotoxy(24, 12);
   cout<<"3. ���� ����";
   gotoxy(24, 14);
   cout<<"4. ���� ����";
   gotoxy(20, 16);
   cout<<"�Է�>> ";
}
