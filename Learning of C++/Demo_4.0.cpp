/* FileName: Demo_4.cpp
 * Author:Li Zhen ����
 * Function: Juding of Palindrome
 * Date: Jan 07, 2020
 * E-mail: 798663691@qq.com
   ���룺 Y/Nѡ���Ƿ������������
   ����� �´��ټ�/(Yes/No)
*/
#include<iostream>

using namespace std;

int main(){
   char choice_1;
   judge:;
   cout<<"������������жϳ�����������Y��N";
   cin>>choice_1;
   if(choice_1=='Y'){
    goto loop;
   }
   else goto end;
   int myriabit,kilobit,decade,unit,number;
   loop:while(1){
   cout<<"������һ����λ����";
   cin>>number;
   myriabit=number/10000;
   kilobit=(number%10000)/1000;
   decade=(number%100)/10;
   unit=number%10;
   if(myriabit==unit&&kilobit==decade){
       cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    goto judge;
    }
    end:;
    cout<<"�´��ټ�"<<endl;
   return 0;
}//�ж��������λ���Ƿ��ǻ�����
