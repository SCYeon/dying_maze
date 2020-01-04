//DFSMatrix.cpp

#include "DFSMatrix.h"

#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // �ܼ�â�� �ڵ������� �޾ƿɴϴ�.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // ���

DFSMatrix::DFSMatrix(){
   q = 0; 
   m = 20;
   n = 30; 
   dfs_map = new int* [m];
    
    for(int i=0; i<m; i++){
       dfs_map[i] = new int[n];
    }
}

DFSMatrix::~DFSMatrix(){
   for(int i=0; i<m; i++){
       delete[]dfs_map[i];
    }
    delete[]dfs_map;
}

void DFSMatrix::setDFSMatrix(){
   ifstream input;
    input.open("dfsMaze.txt");//���Ϸ� �Է� ���� 
    
   if(input.fail()){
       cout<<"���ϻ��� �� �ٽý���"<<endl;
       return;
   }
    
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(!input.eof())
               input>>dfs_map[i][j];
            else{
               cout<<"����"<<endl;
               return;
           }
        }
    }
   dfs(2, 0, 1); 
   input.close();
}

void DFSMatrix::dfs(int tr, int tc, int d){
   int min = 600;
   dfs_map[tr][tc] = 0; // ������ ���� 0�� ǥ��
   if(tr == 13 && tc == 29){
      if(min > d)
           min=d;
        
       stPath[q].a = tr;
        stPath[q].b = tc;
        q++;
        
      return;
    }
    else if(dfs_map[tr][tc+1]!=0 && tc+1<30){//�ϴ� 3�� ������ 0���� �˻� �մϴ�.//������ġ�� �� �������� �ƴϸ� ����
           stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
           dfs(tr, tc+1, d + 1);            
       }
        else if(dfs_map[tr+1][tc]!=0 && tr+1<20){
         
            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
                    
          dfs(tr+1, tc, d + 1);
       }
       else if(dfs_map[tr-1][tc]!=0 && tr-1>=0){

            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
          dfs(tr-1, tc, d + 1); 
       }
       else if(dfs_map[tr][tc-1]!=0 && tc-1>=0){

            stPath[q].a = tr;
            stPath[q].b = tc;
            q++;
            
          dfs(tr, tc-1, d + 1);     
       }
   dfs_map[tr][tc] = 1; // �ǵ��ư��Ƿ� 1���� ǥ��. ������ �κ��Դϴ�.     
}
