/* FileName: Demo_3.cpp
 * Author:Li Zhen
 * Function: Juding of Palindrome
 * Date: Jan 07, 2020
 * E-mail: 798663691@qq.com
   输入： 多个五位数
   输出： 是/否
*/
#include<iostream>

using namespace std;

int main(){
   int myriabit,kilobit,decade,unit,number;
   while(1){
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
    }
   return 0;
}//判断输入的五位数是否是回文数
