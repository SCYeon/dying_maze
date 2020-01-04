//main.cpp
#include "Game.h"
#include "lunaticGame.h"

#include<stdio.h> 
#include<Windows.h>
#include<conio.h>
#include<iostream>
#include<cstdlib>

#define col GetStdHandle(STD_OUTPUT_HANDLE)        // col�� enum �Ű� ���� STD_OUTPUT_HANDLE�� ȣ���Ͽ� ��� ǥ�� ����� (�ܼ�) �� â �ڵ��� �����մϴ�
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // ���

#define MAX_STACK_SIZE 100 

using namespace std;

int main() {
   Game g;
   LunaticGame l;

   int a ,A,end1;
   int num, point = 0; // a��title()���� �Էµ� ���� ,A�� index()���� �Էµ� ���� endl�� �ѹ� ���Ҳ����� ���� ���� 
  
   HWND console = GetConsoleWindow(); //  HWND�� ������ ��ũ�����̴�. â�� ���� �����ͷ� �� �� �ֽ��ϴ�. 
   RECT r; // ���ӵ��� ��µ� �������� ������ ��ũ���� 
   GetWindowRect(console, &r);
   MoveWindow(console, r.left, r.top, 900, 900, TRUE); // 800 width, 100 height
   
   system("cls");
   g.introFrame(); //����ȭ�� ��� 
   g.title();   // ���ӽ���, ���Ӽ���, ���Ӱ���,���� ���� 
   cin >> a;
   while(1){
       if(a == 29){ //���Ӽ���â���� esc�� �Է��Ұ��  
           system("cls");
           g.introFrame();
           g.title();
           cin >> a;
      }
       if (a == 1){// ���ӽ��� ���ð��  
           g.endingFrame();  //�⺻������ 
           g.index();
           g.gotoxy(39, 18);
           cout << "�ǵ��ư����� 29��" << endl;
           g.gotoxy(27, 17);
           cin >> A;
           system("cls");
           while (1) {
              if(A == 29){ //���Ӽ���â���� esc�� �Է��Ұ��  
                 system("cls");
                 g.introFrame();
                 g.title();
                 cin >> a;
                 break;
            }
              else if(A == 1){ //1�г� ��å�� ��� 
                  g.gotoxy(0,0); // �̷ΰ� ��µ� ������ 
                  g.setMatrix(); // 2�����迭�� ������� �̷������ ���� ���������ͷ� ���޸𸮿� ���� 
                  g.setDFSMatrix(); // �̷ξ��� �ִܰŸ��� ���� (��� �Լ� �̿�)
                  g.display(A); // ���ӹ� �̷��� ������ 
                  system("cls");// ������ ������ �� ȭ���� � ü������ ����ϴ� ��� clear ��Ų��. (stdlib.h)
                  g.endingFrame();
                  g.gotoxy(19, 6);// grade()�� ����� ������  
                  g.grade();// �ִܰŸ�, ������ �·� ������ �����ο� 
                  g.gotoxy(20,14);
                  cout <<"  1.�ѹ� ��  2.�׸�";
                  g.gotoxy(18,12);
                  cout << "�ѹ� �� �����Ͻðڽ��ϱ�?" << endl;
                  g.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2) // endl�� 1�϶��� ���ᰡ �ƴϹǷ� while�� ���� 1�� true�� ���� �ϹǷ� �Ǵٽ� �̷ΰ� ����ȴ�. 
                      return 0;
              }
               else if (A == 2){//2�г��϶� 
                  g.gotoxy(0,0);
                  g.setMatrix();
                  g.setDFSMatrix(); 
                  g.display(A);
                  system("cls");
                  g.endingFrame();
                  g.gotoxy(19, 6);
                  g.grade();
                  g.gotoxy(20,14);
                  cout <<"  1.�ѹ� ��  2.�׸�";
                  g.gotoxy(18,12);
                  cout << "�ѹ� �� �����Ͻðڽ��ϱ�?" << endl;
                  g.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2)
                      return 0;
               }
               else if(A == 7){ //�糪ƽ�϶� 
                  l.gotoxy(0,0);//���ο� ��ü�� �����Ͽ� �糪ƽ��Ʈ���� ���� ȣ�� 
                  l.setLunaticMatrix();  
                  l.display(A);
                  l.gotoxy(24,16);
                  cin >> end1;
                  system("cls");
                  if(end1==2)
                      return 0;
              }
           }
       }
       else if (a == 2){//�̷� ���� 
           system("cls");
           g.endingFrame();
           g.gotoxy(2, 7);
           cout << "����� ȣ����Ʈ �л� Walld H Ro.\n�� Ʈ�������� ��ʸ�Ʈ�� �����ڸ� �����ϴ� ���� �� �ӿ���\n�� ����� �̸��� �������ϴ�.\n�� �ְ����� Ÿ��Ʋ�� ������� ������ ������ ����ؾ��մϴ�.\n�� ������ ������ DYING MAZE.\n�� �������� ��Ƴ��� ������ �����ϼ���.";
           g.gotoxy(39, 18);
           cout << "�ǵ��ư����� 29��" << endl;
           g.gotoxy(52, 18);
           cin >> a;// window.h���ִ� esc�� 16���� �ڵ尡 �Էµ� ��츦 ������. 
       } 
       else if (a == 3){//���� ���� 
           system("cls");
           g.endingFrame();
           g.explain();
           g.gotoxy(39, 18);
           cout << "�ǵ��ư����� 29��" << endl;
           g.gotoxy(20, 16);
         cout<<"�Է�>> ";
           cin >> num;
           if(num == 29)
           {
              point++;
         } 
          while(1)
           {
              switch(num){
                 case 1 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(25, 4);
                     cout << "�ͼ��� ����" << endl;
                     g.gotoxy(17, 10);
                     cout <<"�� �״�� �ͼ��� �����Դϴ�." << endl;
                     g.gotoxy(39, 18);
                     cout << "�ǵ��ư����� 29��" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h���ִ� esc�� 16���� �ڵ尡 �Էµ� ��츦 ������.
                     point += 2;
                     break;
               case 2 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(23, 4);
                     cout << "����������"<<endl;
                     g.gotoxy(6, 10);
                     cout << "0:���� 1:���� 2:���� ��ǻ�Ϳ� ���˽ºθ� ��ġ����!" << endl;
                     g.gotoxy(39, 18);
                     cout << "�ǵ��ư����� 29��" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h���ִ� esc�� 16���� �ڵ尡 �Էµ� ��츦 ������.
                     point += 2;
                     break;
                 case 3 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(22, 4);
                     cout << "�������� ���߱�"<<endl;
                     g.gotoxy(2, 9);
                     cout<<"1~100���� �������ڸ� ���ؼ� �� ���ڸ� ���ߴ� �����Դϴ�. \n�� ���������� ������ up, ������ down �̶�� �˷��ݴϴ�. \n�� 5���� ��ȸ �ȿ� ���߽ñ� �ٶ��ϴ�.\n�� (���ֶѲ� ���ڸ��߱� ���� �ϼ��Ҥ���)"<<endl;
                     g.gotoxy(39, 18);
                     cout << "�ǵ��ư����� 29��" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h���ִ� esc�� 16���� �ڵ尡 �Էµ� ��츦 ������.
                     point += 2;
                    break;
                 case 4 :
                     system("cls");
                     g.endingFrame();
                     g.gotoxy(24, 4);
                     cout << "���ھ߱�����"<<endl;
                     g.gotoxy(2, 8);
                     cout<<"0���� 9������ ���� 3�� [3���� ����]�� ��Ȯ�� ���߸� �ȴ�.\n�� 3�ڸ� ������ ���Ե� ���� �÷��̾ ���� ���� �ڸ�����\n�� Ʋ���� ���� ���� �� �´� ���������� �ִ� 3[��]�� �����ϴ�.\n�� ���Ͽ� ���� �°� �ڸ������� ������ �ִ� 3[��Ʈ����ũ]�� \n�� ������ ����ȴ�."<<endl;
                     g.gotoxy(39, 18);
                     cout << "�ǵ��ư����� 29��" << endl;
                     g.gotoxy(52, 18);
                     cin >> num;// window.h���ִ� esc�� 16���� �ڵ尡 �Էµ� ��츦 ������.
                  point += 2; 
                     break;
              }
              if(num == 29 && point % 2 == 0)
              {
                 system("cls");
                 g.endingFrame();
                 g.explain();
                 g.gotoxy(39, 18);
                 cout << "�ǵ��ư����� 29��" << endl;
                 g.gotoxy(20, 16);
               cout << "�Է�>> ";
                 //num = _getch();
                 point = 0;
                 cin >> num;
                 if(num == 29)
                 {
                    point++;
               }
            }
            else if(num == 29 && point % 2 == 1)
            {
               a = num;
               num = 0;
               point = 0;
               break;
            }
         }
       }
       else if (a == 4){//ù ȭ�鼼�� ������ ��
           system("cls");
           g.endingFrame();
           g.gotoxy(26, 6);
           cout<<"The End";
           g.gotoxy(21, 12);
           cout<<"������ ���� �մϴ�.";
           g.gotoxy(26, 30);
           cout<<"";
           return 0;                  
       }
   }    
   return 0;
}
