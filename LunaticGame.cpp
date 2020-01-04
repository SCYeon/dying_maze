//LunaticGame.cpp
#include "LunaticGame.h"

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

LunaticGame::LunaticGame(){
   
}

void LunaticGame::upDown() //���ٿ� ���� 
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
       }
}

void LunaticGame::gawiBawiBo(){ //���������� ���� 
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
       Sleep(1000);
    }
    else if (count == 3 && no < 2){
       Sleep(1000);
   }

 }

}

void LunaticGame::numBall(){ //���ھ߱� ���� 
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
       Sleep(1000);
        
      Strike=Ball=0;
      num=1;
      break;    
   }
   Strike=Ball=0;       
   ++num;   
  }
      system("cls");
      lunaticMazeFrame();   
}

void LunaticGame::nonSenseQuiz(){ //�ͼ��� ���� 
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
             }
            else{
               cout << "��! Ʋ�Ƚ��ϴ�! ���� '��������'�Դϴ�!"; 
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
                
             }
            else{
               cout << "\n\t\t\t ��! Ʋ�Ƚ��ϴ�! ���� '�н�ƮǪ��'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�Ϻ����'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�ŵ���'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '������'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��ä�����'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��������'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�۷ι�'�Դϴ�!";
               
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
                
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '��ó�ڼ�'�Դϴ�!";
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
             }
            else{
               cout << "\n\t\t\t��! Ʋ�Ƚ��ϴ�! ���� '�����ؼ�'�Դϴ�!";
            }
            break;   
       }
      Sleep(1000);
}

void LunaticGame::display(int A){
   int x = 2, y = 0;
    char dir;
   //////////////////////////////////////////
   lunaticMazeFrame();
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
        }
      }
      else if (dir == 80) { //����Ű DOWN
        if (map[x + 1][y] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            x = x + 1;
            gotoxy(y * 2, x);
            cout<<"��";
        }
      }
      else if (dir == 75) { //����Ű LEFT
        if (map[x][y - 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y - 1;
            gotoxy(y * 2, x);
            cout<<"��";
        }
      }
      else if (dir == 77) { //����Ű RIGHT
        if (map[x][y + 1] != 0 && x >= 0 && y >= 0) {
            gotoxy(y * 2, x);
            printf(" ");
            y = y + 1;
            gotoxy(y * 2, x);
            cout<<"��";
        }
      }
      else if (dir == 'r') {
         gotoxy(y * 2, x);
         cout<<"  ";
         x = 2;
         y = 0;
         gotoxy(y * 2, x);
         cout<<"��";
      }
      
      if(A == 7){ //1�г� 
      if(map[x][y] == 2) //2�� ������ ������ �� 
      {
         system("cls");
         int a = rand() % 4;
       switch(a) //�������� ���� ���� 
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
           case 3:
              numBall();
              break;
         }
         system("cls");
         lunaticMazeFrame();
    
         gotoxy(y * 2, x);
         cout << "��";
      }
    else if (map[x][y] == 7){
    gotoxy(66, 20);
   cout<<"!!!!!!success!!!!!!"<<endl;
   gotoxy(66, 22);
   cout<<"�ƹ�Ű�� ������ ����\n";
   _getch();
    system("cls");
    endingFrame();
    gotoxy(23,6);
    cout << "GAME OVER ^��^";
    gotoxy(20,14);
    cout<<"  1.�ѹ� ��  2.�׸�";
    gotoxy(18,12);
    cout<<"�ѹ� �� �����Ͻðڽ��ϱ�?"<<endl;
        break;
     }
   else if (map[x][y] == 8){
        system("cls");
        endingFrame();
        key();
        system("cls");
        endingFrame();
		gotoxy(23, 6);
		cout << "!!!!!!success!!!!!!" << endl;
		gotoxy(20, 14);
		cout<<"  1.�ѹ� ��  2.�׸�";
    	gotoxy(18,12);
    	cout<<"�ѹ� �� �����Ͻðڽ��ϱ�?"<<endl;
        break;
     }
    else if (map[x][y] == 9){
        gotoxy(66, 20);
      cout<<"!!!!!!success!!!!!!"<<endl;
      gotoxy(66, 22);
      cout<<"�ƹ�Ű�� ������ ����\n";
      _getch();
       system("cls");
       endingFrame();
       gotoxy(23,6);
       cout << "I'll be Back...��";
       gotoxy(20,14);
       cout<<"  1.�ѹ� ��  2.�׸�";
       gotoxy(18,12);
       cout<<"�ѹ� �� �����Ͻðڽ��ϱ�?"<<endl;
        break;
     }
      }
   }
}

int LunaticGame::key()//����° �����κ��� ��Ʈ�� ��� ���������� Ż�� �� �� �ְ� �ϴ� �Լ��̴�.
{
int input[4];
int room;
   gotoxy(10, 10);
   cout<<" [Secret Room] �� �����Ͽ����ϴ�.";
   Sleep(1000);
position:
   system("cls");
   endingFrame();
   keyFrame();
    
   gotoxy(48, 4);
   cout<<"1th Room : ";
   cin>>room;
   gotoxy(60, 4);
   cout << " ";
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"�Ϸ�"; 
   gotoxy(48, 4);
   cout<<"2nd Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"�Ϸ�    �Ϸ�";
   gotoxy(48, 4);
   cout<<"3rd Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"�Ϸ�    �Ϸ�    �Ϸ�";
   gotoxy(48, 4);
   cout<<"4th Room : ";
   cin>>room;
   secretRoom(room);
   gotoxy(18, 7);
   cout<<"�Ϸ�    �Ϸ�    �Ϸ�    �Ϸ�";
    
   gotoxy(9, 10);
   printf("Ż�� ��� ��ȣ 4�ڸ��� �Է� (�𸣸� 0�� �Է�)");
   gotoxy(20, 12);
   cout<<"���������� ���������� ���������� ����������\n";
   gotoxy(20, 14);
   cout<<"���������� ���������� ���������� ����������\n";
   gotoxy(14, 16);
   cout<<"1��° �ڸ� : ";
   cin>>input[0];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"    "; 
   gotoxy(35, 16);
   cout<<"2��° �ڸ� : ";
   cin>>input[1];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1];
   gotoxy(14, 17);
   cout<<"3��° �ڸ� : ";
   cin>>input[2];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1]<<"     "<<input[2];
   gotoxy(35, 17);
   printf("4��° �ڸ� : ");
   cin>>input[3];
   gotoxy(20, 13);
   cout<<"  "<<input[0]<<"     "<<input[1]<<"     "<<input[2]<<"     "<<input[3];
   if(input[0]==0&&input[1]==8&&input[2]==2&&input[3]==9){
      gotoxy(20, 18);
      cout<<" --- correct --- ";
      fflush(stdin);
      getchar();
      return 3;
   }
   else if(input[0]==0&&input[1]==0&&input[2]==0&&input[3]==0)
      return 0;
   else{
      gotoxy(12, 20);
      cout<<"��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է��Ͻÿ�.";
   	  system("cls");
	  display(7);
	}
}

void LunaticGame::keyFrame(){
   gotoxy(5, 2);
   cout<<" �� ������ �´� ���ڸ� �Է��� ���� �����մϴ�";
   gotoxy(3, 4);
   cout<<" �濡�� ���� keyword�� �����Ͽ� Ż���ϼ���";
   gotoxy(16, 5);
   cout << "�������������� �������������� �������������� ��������������\n";
   gotoxy(18,6);
   cout<<"#1. \t  #2. \t  #3. \t  #4. ";
   gotoxy(16, 8);
   cout << "�������������� �������������� �������������� ��������������\n";
}

void LunaticGame::secretRoom(int k){
	string ans;
	string userAns;
	switch(k){
		case 1:
			system("cls");
			cout << "Q. ������ ��Ư�� ��ȣ�� ���� �ܾ����� �߰��ߴ�. \n�ܾ��忡�� �ܾ �ؼ��ϴ� ��� ���ڸ��� ���� �־���." << endl;
			gotoxy(12, 4);
    		cout<<"��--------------------------------------------------------------------��"<<endl;
    		gotoxy(12, 5);
    		cout<<"��         33-1-20-20-3 = ? : ��Ҹ��θ� �����ϴ� ���                ��"<<endl;
    		gotoxy(12, 6);
    		cout<<"��         32-4-20-13-3 = ? : ���ϵ��� �ִ� �Ŷ� õ���� ��        ��"<<endl;
    		gotoxy(12, 7);
    		cout<<"��         33-1-54-45-9-20 = ? : �η����Ͽ� �ٶ�� ��                 ��"<<endl;
    		gotoxy(12, 8);
    		cout<<"��--------------------------------------------------------------------��"<<endl;
    		gotoxy(12, 11);
    		cout << "���� ��Ģ�� ������ ��, �� ��ȣ�� ��Ÿ���� �ܾ�� �����ϱ�?" << endl;
			gotoxy(12, 12);
			cout << "20-3-13-3-33-1-54 ";
			
			ans = "���ּ�";
			cout << "�Է�>> "; 
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 16);
				cout << "�����մϴ�! 1�� ���� key�� '1'�Դϴ�.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
               }
            break;
            
        case 2:
        	system("cls");
			cout << "Q. What word am I thinking of?"<< endl;
			cout << endl;
			cout << "1. I am thinking of a seven letter word which we read almost daily." << endl;
			cout << "2. Letters 5, 6 and 7 increase every year." << endl;
			cout << "3. Letters 3 and 4 are the same." << endl;
			cout << "4. Letters 3, 2 and 5 cover about 70 percent of the world." << endl;
						
			ans = "message";
			cout << endl << endl;
			cout << "�Է�>> ";
			cin >> userAns;
			
			if(userAns == ans){
				cout << "�����մϴ�! 2�� ���� key�� '1'�Դϴ�.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
		
		case 3:
			system("cls");
			cout << "�׷�����Ʈ ä���̰� �ѱ��� �����Ͽ� �Ұ����Ʈ�� ��ź�� ��ġ�ߴ�. \n����Ʈ ������ ��ǻ�Ϳ��� ��ź�� ������ �� �ִ� ��ȣ�� ������ �־���.\n ��ȣ�� �����ΰ�?" <<endl;
			gotoxy(12, 4);
    		cout<<"��----------------------------------------------------------------------------------��"<<endl;
    		gotoxy(12, 5);
    		cout<<"��   ������ ������ ������ ��         ������ ������ ������   ��"<<endl;
    		gotoxy(12, 6);
    		cout<<"��   ��         ��      ��         �� ��         ��                 �� ��      ��   ��"<<endl;
    		gotoxy(12, 7);
    		cout<<"��   ��         ��      ��         �� ��         ��                 �� ��      ��   ��"<<endl;
    		gotoxy(12, 8);
    		cout<<"��   ��         ��      ��         �� ��         ��                 �� ��      ��   ��"<<endl;
    		gotoxy(12, 9);
			cout<<"��   ������ ������         �� ������ ������         �� ������   ��"<<endl;
    		gotoxy(12, 10);
    		cout<<"��----------------------------------------------------------------------------------��"<<endl;
    		
    		ans = "6573675";
    		gotoxy(12, 12);
			cout << "�Է�>> ";
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 15);
				cout << "�����մϴ�! 3�� ���� key�� '1'�Դϴ�.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
			
		case 4:
			system("cls");
			cout << "Q. �����̴� ���� �����忡�� ������ ���� �� ���� �߰��ߴ�. \n���� �� ���ΰ��� �����ϱ�?";
			gotoxy(12, 4);
    		cout<<"��---------------------------------------��"<<endl;
    		gotoxy(12, 5);
    		cout<<"��   �� T�� ������ �� �д��� �ϰ� ��     ��"<<endl;
    		gotoxy(12, 6);
    		cout<<"��   �� D�� ������ �ڲ� ����� �ϰ� ��   ��"<<endl;
    		gotoxy(12, 7);
    		cout<<"��   �� E�� ������ ������ �ְ� �;���    ��"<<endl;
    		gotoxy(12, 8);
			cout<<"��   ���� ����ϰڴ�?                    ��"<<endl;
    		gotoxy(12, 9);
    		cout<<"��---------------------------------------��"<<endl;
    
			ans = "car";
			gotoxy(12, 11); 
			cout << "�Է�>> ";
			cin >> userAns;
			
			if(userAns == ans){
				gotoxy(12, 15);
				cout << "�����մϴ�! 4�� ���� key�� '1'�Դϴ�.";
				Sleep(1000);
				system("cls");
				endingFrame();
				keyFrame();
			}
			else{
				system("cls");
				display(7);
			}
			break;
	}	
}

void LunaticGame::lunaticMazeFrame(){
     for(int i=0; i < LunaticMatrix::m; i++){
            for(int j=0; j < LunaticMatrix::n; j++){
       
         if (map[i][j] == 9 || map[i][j] == 8 || map[i][j] == 7) {
            cout<<"��";
         }
         else if (map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 5) {
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
