/* FileName: Demo_4.cpp
 * Author:Li Zhen 李振
 * Function: Juding of Palindrome
 * Date: Jan 07, 2020
 * E-mail: 798663691@qq.com
   输入： Y/N选择是否玩回文数程序
   输出： 下次再见/(Yes/No)
*/
#include<iostream>

using namespace std;

int main(){
   char choice_1;
   judge:;
   cout<<"你想玩回文数判断程序吗？请输入Y或N";
   cin>>choice_1;
   if(choice_1=='Y'){
    goto loop;
   }
   else goto end;
   int myriabit,kilobit,decade,unit,number;
   loop:while(1){
   cout<<"请输入一个五位数：";
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
    cout<<"下次再见"<<endl;
   return 0;
}//判断输入的五位数是否是回文数
