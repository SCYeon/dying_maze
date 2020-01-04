//Game.cpp

#include "Game.h"

#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<iostream>
#include<cstdlib>
#include <ctime>

#define col GetStdHandle(STD_OUTPUT_HANDLE)     // �ܼ�â�� �ڵ������� �޾ƿɴϴ�.
#define WHITE  SetConsoleTextAttribute(col, 0x000f) // ���
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define TRUE 1
#define FALSE 0

#define GAWI 0
#define BAWI 1
#define BO 2
#define MY_WIN 0
#define PC_WIN 1
#define DRAW 2
using namespace std;

Game::Game(){
    count = 0;
    wrongAnsNum = 0;
}

void Game::upDown() //���ٿ� ���� 
{
   gotoxy(0, 0);
   int seed=time(NULL);
   srand(seed);
   int number = rand() % 100 + 1;
   int answer, count = 0;
   
   cout << "(��ȸ�� �ټ� �� �Դϴ�.)" << endl; 
   for(int i = 0; i < 5; i++)
   {
      cout << "�����ϴ� �������� ���ÿ�: ";
      cin >> answer;
      
      if(number > answer)
      {
         cout << "up" << endl;
      }
      else if(number < answer)
      {
         cout << "down" << endl;
      }
      else if(number == answer)
      {
         cout << "correct!" << endl;
         count++;
         Sleep(1000);
       break;
      }
   }
   if(count == 0)
   {
      cout << "������ ������ ���߽��ϴ�. ������ " << number << "�Դϴ�." << endl;
      Sleep(1000);
        wrongAnsNum++; 
   }
}

void Game::gawiBawiBo(){ //���������� ���� 
    int player, computer;
    int count = 0;
    int no=0;
    int winner;
    cout << "����� ���������� ���迡 �������ϴ�. 3���� ������������ ���� �¸��� �����Ͻʼ�." << endl;
 
    while(count < 3){
   int seed=time(NULL);
      srand(seed);    
    computer = rand()%3;
    
    cout <<"����: 0, ���� 1: ��:2 >";
    cin >> player;
    
   if(player <= 2){
    if (player == computer) winner = DRAW;
    if ((player == GAWI) && (computer == BAWI)) winner = PC_WIN; 
    if ((player == GAWI) && (computer == BO))  winner = MY_WIN;   
    if ((player == BAWI) && (computer == BO)) winner = PC_WIN;
    if ((player == BAWI) && (computer == GAWI))   winner = MY_WIN;
    if ((player == BO) && (computer == GAWI))  winner = PC_WIN;
    if ((player == BO) && (computer == BAWI))    winner = MY_WIN;  
   
   
     switch (winner){
       case DRAW:       
          cout <<"���º��Դϴ�. ���� ���� �ڳ�.\n";
          break;
        case PC_WIN:
             cout <<"����� �����ϴ�. �ּ��̱�.\n";
             no++;
             count++;
             break;
       case MY_WIN:
             cout <<"����� �̰���ϴ�. ��.\n";
              count++;
              break;
          } 
   }
   else if(player > 2) 
      cout << "0, 1, 2 �߿� �����ϼ���.\n";
      
    if(count == 3 && no >= 2){
       wrongAnsNum++; 
       Sleep(1000);
    }
    else if (count == 3 && no < 2){
       Sleep(1000);
   }
 }
}

void Game::numBall(){ //���ھ߱� ���� 
   int COM[3];
   int USER[3];
   int i,j;
   int num=1;
   int Strike=0;
   int Ball=0;
   
   for(i=0;i<3;i++){
      COM[i]=(rand()%9)+1;
      for(j=0;j<i;j++)
         if(COM[i]==COM[j]&&i!=j)
            i--;
   }
   while(1){
      cout<<num<<" ��° �õ� "<<endl;   
      while(1){
      cout<<"1~9������ ���� 3���� �Է��ϼ���: ";
      cin>>USER[0]>>USER[1]>>USER[2];
      if(USER[0]<1||USER[0]>9||USER[1]<1||USER[1]>9||USER[2]<1||USER[2]>9)
      {
         cout<<"������������ �Է��ϼ���.."<<endl;
         continue; 
         }   
       else if(USER[0]==USER[1]||USER[1]==USER[2]||USER[2]==USER[0])
       {
          cout<<"�ߺ��ؼ� �Է����� ������.."<<endl;
         continue; 
          }   
      break;    
    }
   for(i=0;i<3;i++)
      for(j=0;j<3;j++)
         if(COM[i]==USER[j])
            if(i==j)
               Strike++;
            else
               Ball++;
                  
   if(Strike||Ball)
      cout<<"=> "<<Strike<<" ��Ʈ����ũ & "<<Ball<<" ��"<<endl<<endl;
   else
      cout<<"...... �ƿ�! "<<endl<<endl;
   if(Strike==3){
      if(num<4){
         cout<<"����� ����Դϴ�"<<endl;
       Sleep(1000); 
      } 
      else if(num==4){
         cout<<"����� õ���Դϴ�.. ������!"<<endl;
       Sleep(1000); 
      } 
      else if(num<9){
         cout<<"����� �����Դϴ�"<<endl;
       Sleep(1000); 
      } 

      Strike=Ball=0;
      num=1;
      break;       
   }
   
   else if(num==9){
         cout<<"���� �׸��ϼ���...������"<<endl; 
         cout<<"������ [ "<<COM[0] << COM[1] << COM[2]<<" ] �Դϴ�" <<endl;
         wrongAnsNum++; 
       Sleep(1000);
        
      Strike=Ball=0;
      num=1;
      break;    
   }
   Strike=Ball=0;       
   ++num;   
  }
      system("cls");
      mazeFrame();   
}

void Game::nonSenseQuiz(){ //�ͼ��� ���� 
   string ans;
   string userAns; 
   int x = rand() % 10;
   switch(x){
         case 0: 
            ans = "��������"; 
            cout<<"\n\n\t\t ����---  �ͼ��� ������������--- ����"<<endl<<endl; 
            cout << "\t\t �� ���� �Ʊ⸦ �� ���� �������̰� ��ҽ��ϴ�. \n\t ���� �������̴� ȣ����� ���� �Ʊ� �������̰� ������ �⵵�߽��ϴ�.";
          cout<<"\n \t\t ��ĥ�� ���� �Ʊ� ���̰� �¾���ϴ�.\n\n\t\t ���� �� �Ʊ� ������ �̸��� �����ϱ��?"<<endl<<endl;
            cout << "\n\t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
         cin >> userAns;
            if(ans == userAns)
               cout << "\n\t\t\t ----- �����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "��! Ʋ�Ƚ��ϴ�! ���� '��������'�Դϴ�!";
            wrongAnsNum++; 
            }
            break; 
         case 1:
            ans = "�н�ƮǪ��";
            cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t\t|| ���������� ����κ�Ʈ��? ||"<<endl<<endl;
           cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t ��! Ʋ�Ƚ��ϴ�! ���� '�н�ƮǪ��'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
        case 2:
           ans = "�Ϻ����";
           cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; ; 
            cout << "\t\t || ȭ��� ���� ��� ���� �����?? ||"<<endl<<endl;
             cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�Ϻ����'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
        case 3:
         ans = "�ŵ���";
        cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t || ������Ͼ� '�ŵ�' ���� �ִ� �����?? ||"<<endl<<endl;
            cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�ŵ���'�Դϴ�!";
               wrongAnsNum++;
         }
            break; 
        case 4:
         ans = "������";
         cout<<"\n\n\t\t ����---  �ͼ��� ������������--- ����"<<endl<<endl; 
            cout << "\t\t || ���ְ� �ױ� ��, �� ����? ||"<<endl<<endl;
             cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '������'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
      case 5:
         ans ="��ä�����";
         cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t || ���󿡼� ���� ������ �������?? ||" <<endl<<endl;
             cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��ä�����'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
      case 6:
         ans ="��������";
         cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t\t|| �ο��� ���ϴ� ������?? ||"<<endl<<endl;
             cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
          cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��������'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
      case 7:
         ans ="�۷ι�";
         cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t\t|| �ݼ����� ����� �ϸ�? ||"<<endl<<endl;
             cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�۷ι�'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
      case 8:
         ans ="��ó�ڼ�";
        cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl; 
            cout << "\t\t\t|| �߻��� ��ó����?? ||"<<endl<<endl;
            cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
       cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��ó�ڼ�'�Դϴ�!";
               wrongAnsNum++;
            }
            break;
      case 9:
         ans ="�����ؼ�";
         cout<<"\n\n\t\t ������ ---  �ͼ��� ������������--- ������"<<endl<<endl;  
            cout << "\t\t|| 3���� �Ǹ� ���л��� ���� ������??||"<<endl<<endl;
            cout << "\n \t���� ���� �亯�� �ۼ����ּ���. �𸣸� '?'�� �����ּ���!" << endl;
            cout<<"\n\t\t\t��: ";
          cin >> userAns;
         if(ans == userAns)
               cout << "\n\t\t\t-----�����Դϴ�!!-----";
            else if(userAns == "?"){
                cout << "�ñ��ϰ����� �� �� �˷���^_^";
                wrongAnsNum++;
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�����ؼ�'�Դϴ�!";
               wrongAnsNum++;
            }
            break;   
       }
      Sleep(1000);
}

bool Game::isEqual(){ //grade()���� ������ ��ο� �ִܰ�� ���۾��� ���� �Լ�
   int equal = 0;
   for(int i = 0; i < q; i++)
   {
       for(int j = 0; j < p; j++)
       {
          if(his[j].b == stPath[i].b && his[j].a == stPath[i].a)
          {
              equal++;
              //break;
          }
      }
   }
   if(equal < p)
   {
      equal = 0;
      return false;
   }
   else if(equal == p)
   {
      equal = 0;
      return true;
   }
}

void Game::grade(){ //�ִܰ�η� ������(����1)�� Ʋ�� ���� ����(����2)�� ���� �̷� Ż�� ���� �ű�� 
   if(isEqual() == true)
   {
      switch(wrongAnsNum){
          case 0:
              cout<<"����� ������ A+ ! (��:0 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         case 1:
              cout<<"����� ������ A0 ! (��:1 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 2:
              cout<<"����� ������ A0 ! (��:2 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 3:
              cout<<"����� ������ B+ ! (��:3 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 4:
              cout<<"����� ������ B+ ! (��:4 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 5:
              cout<<"����� ������ B0 ! (��:5 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break; 
          case 6:
              cout<<"����� ������ C+ ! (��:6 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 7:
              cout<<"����� ������ C0 ! (��:7 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 8:
              cout<<"����� ������ D+ ! (��:8 / ʥ+) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;   
          default:
               cout<<"Good Bye �ٽź������� "<<endl; 
              cout<<"����� ������ F ! (��:9+)"<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         }
   }
   else if(isEqual() == false)
   {
      switch(wrongAnsNum){
          case 0:
              cout<<"����� ������ A0 ! (��:0) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
         case 1:
              cout<<"����� ������ A0 ! (��:1) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 2:
              cout<<"����� ������ A- ! (��:2) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 3:
              cout<<"����� ������ B0 ! (��:3) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 4:
              cout<<"����� ������ B0 ! (��:4) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 5:
              cout<<"����� ������ B- ! (��:5) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break; 
          case 6:
              cout<<"����� ������ C0 ! (��:6) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 7:
              cout<<"����� ������ D0 ! (��:7) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
          case 8:
              cout<<"����� ������ D- ! (��:8) "<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;   
          default:
               cout<<"Good Bye �ٽź������� "<<endl; 
              cout<<"����� ������ F ! (��:9+)"<<endl;
              wrongAnsNum = 0;
              p = 0;
           q = 0;
              break;
       }
   }
}

void Game::display(int A){
   int x = 2, y = 0;
    int trapx, trapy = 0;
    
    his[p].a = x; //����ü �迭�� ���� 
    his[p].b = y; 
    p++;
    char dir;
   //////////////////////////////////////////
   mazeFrame();
   gotoxy(y, x);
   cout << "��";
   while (1) {
      dir = _getch(); //����Ű ���� ���� 
      if (dir == 72) { //����Ű UP 
        if (map[x - 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x - 1;
            gotoxy(y * 2, x);
            cout<<"��";
            
            his[p].a = x; //����ü �迭�� ���� 
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 80) { //����Ű DOWN
        if (map[x + 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x + 1;
            gotoxy(y * 2, x);
            cout<<"��";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 75) { //����Ű LEFT
        if (map[x][y - 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y - 1;
            gotoxy(y * 2, x);
            cout<<"��";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 77) { //����Ű RIGHT
        if (map[x][y + 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y + 1;
            gotoxy(y * 2, x);
            cout<<"��";
            
            his[p].a = x;
            his[p].b = y; 
            p++;
        }
      }
      else if (dir == 'r') {
         gotoxy(y * 2, x);
         cout<<"  ";
         x = 2;
         y = 0;
         gotoxy(y * 2, x);
         cout<<"��";
         count = 0;
      }
      
      if(A == 1){ //1�г� 
      if(map[x][y] == 2) //2�� ������ ������ �� 
      {
         system("cls");
         int a = rand() % 3;
       switch(a) //�������� ���� ���� 
         {
            case 0:
               upDown();
               count++;
               break;
            case 1:
               gawiBawiBo();
               count++;
               break;
         case 2:
            nonSenseQuiz();
            count++;
            break;    
         }
         system("cls");
         mazeFrame();
        if(count%7 == 1 || count%7 == 6 || count%7 == 0){
       y = y + 1;
        his[p].a = x;
         his[p].b = y; 
         p++; 
         }
        else if(count%7 == 2 || count%7 == 3 || count%7 == 5){
           x = x + 1;
            his[p].a = x;
         his[p].b = y; 
         p++; 
    	}
    	else if(count % 7 == 4)
    	{
    		x = x -1;
    		his[p].a = x;
        	his[p].b = y; 
        	p++;
		}
         gotoxy(y * 2, x);
         cout << "��";
      }
      
   if(map[x][y] == 4) //4�� ������ ������ �� 
   {
      trapx = x;
      trapy = y;
   }
   if(map[x][y] == 3) //3�� ������ ������ �� 
      { 
        system("cls");
        int a = rand() % 3;
        
       switch(a)
        {
            case 0:
                  upDown();
                  break;
            case 1:
                  gawiBawiBo();
                  break;
            case 2:
               nonSenseQuiz();
               break;
        }
         system("cls");
         mazeFrame();
         y = trapy;
         x = trapx;
         gotoxy(y * 2, x);
         cout << "��"; 
         his[p].a = x;
         his[p].b = y; 
         p++; 
      }
  }
  else if(A == 2){ //2�г� 
     
      if(map[x][y] == 2)
      {
         system("cls");
        int a = rand() % 4;
        
       switch(a)
         {
            case 0:
               upDown();
               count++;
               break;
            case 1:
               gawiBawiBo();
               count++;
               break;
            case 2:
               numBall();
               count++;
               break;
            case 3:
               nonSenseQuiz();
               count++;
               break;    
         }
         system("cls");
         mazeFrame();
        if(count%7 == 1 || count%7 == 6 || count%7 == 0){
       y = y + 1;
        his[p].a = x;
         his[p].b = y; 
         p++; 
         }
        else if(count%7 == 2 || count%7 == 3 || count%7 == 5){
           x = x + 1;
            his[p].a = x;
         	his[p].b = y; 
         	p++; 
    	}
    	else if(count % 7 == 4)
    	{
    		x = x -1;
    		his[p].a = x;
        	his[p].b = y; 
        	p++;
		}
         gotoxy(y * 2, x);
         cout << "��"; 

      }
   if(map[x][y] == 4)
   {
      trapx = x;
      trapy = y;
   }
   if(map[x][y] == 3)
      { 
         system("cls");
         int a = rand() % 4;
        // int a = 3;
       switch(a)
         {
            case 0:
               upDown();
               break;
            case 1:
               gawiBawiBo();
               break;
            case 2:
               numBall();
               break; 
         case 3:
            nonSenseQuiz();
            break;
         }
         system("cls");
         mazeFrame();
         y = trapy;
         x = trapx;
         gotoxy(y * 2, x);
         cout << "��"; 
          his[p].a = x;
         his[p].b = y; 
         p++; 
      }
  }
      if (map[x][y] == 9){
        break;
     }
   }
   gotoxy(66, 20);
   cout<<"!!!!!!success!!!!!!"<<endl;
   ////////////////////////////////////

   gotoxy(66, 22);
   cout<<"�ƹ�Ű�� ������ ����\n";
   _getch();
  }

void Game::mazeFrame(){
     for(int i=0; i < Matrix::m; i++){
            for(int j=0; j < Matrix::n; j++){
       
         if (map[i][j] == 9) {
            cout<<"��";
         }
         else if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
            cout<<"  ";
         }
         else if (map[i][j] == 0) {
            cout<<"��";
         }
        
      }
      printf("\n");
   }
   
   gotoxy(66, 10);
   cout<<"��[��]";
   gotoxy(66, 11);
   cout<<"�Ʒ�[��]";
   gotoxy(66, 12);
   cout<<"����[��]";
   gotoxy(66, 13);
   cout<<"������[��]";
   gotoxy(66, 14);
   cout<<"r == ����";
  }
