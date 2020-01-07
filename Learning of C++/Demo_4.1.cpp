/* FileName: Demo_4.1.cpp
 * Author:Li Zhen 李振
 * Function: Using switch to choose to judge prime or judge palindrome 
 * Date: Jan 07, 2020
 * E-mail: 798663691@qq.com
*/
#include<iostream>
#include<string.h>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    string choice_1,choice_2;
    char s[1000]; 
    int fir,palindromenum,myriabit,kilobit,decade,unit,primenum,i,length,r,v;
    int t=10000;
        cout<<"你想玩判断素数游戏，或者回文数游戏吗？输入1是判断素数，输入0是判断回文数";
        cin >>fir;
        switch(fir)
        {
        case 0:
            while(1)
        {
        cout<<"请输入五位数";
        cin>>s;
        length=strlen(s);
        for(r=0;r<length;r++){
        	if(s[i]-'0'>=0&&s[i]-'0'<='9'){
			    palindromenum+=(s[i]-'0')*t;
			    t/=10;
			} 
			else{
				palindromenum=0;
				break;
			}
		} 
        while(palindromenum<10000||palindromenum>99999)
        {
            cout<<"您输入的不是五位数，请重新输入：";
            /*cin>>s;
		    length=strlen(s);
		    for(v=0;v<length;v++){
        	if(s[i]-'0'>=0&&s[i]-'0'<='9'){
			    n+=(s[i]-'0')*t;
			    t/=10;
			} 
			else{
				n=0;
				break;
			}
		    }*/
		    cin>>palindromenum;
		} 
        myriabit=palindromenum/10000;
        kilobit=(palindromenum%10000)/1000;
        decade=(palindromenum%100)/10;
        unit=palindromenum%10;
        if(myriabit==unit&&kilobit==decade)
        {
            cout<<"该五位数是回文数"<<endl;
        }
        else
        {
            cout<<"该五位数不是回文数"<<endl;
        }
        cout<<"你还想玩判断回文数程序吗？Please input 'y' or 'n'";
        cin>>choice_1;
        while(choice_1!="y"&&choice_1!="n"||choice_1.size()!=1)
        {
            cout<<"请按规则重新输入:";
            cin>>choice_1;
        }
        if(choice_1=="n")
        {
            break;
        }
        }
        break;
        case 1:
            cout<<"即将进入判断素数小游戏"<<endl;
            while(1){
                cout<<"请输入一个数"<<endl;
                cin>>primenum;
                for(i=2;i<=sqrt(primenum);i++){
                   if(m%i==0){
                    cout<<primenum<<"不是素数"<<endl;
                    break;
                   }
                }
                if(i>sqrt(primenum)){
                    cout<<primenum<<"是素数"<<endl;
                }
                cout<<"你还想再玩一次吗？y or n";
                cin>>choice_2;
                while(choice_2!="y"&&choice_2!="n"||choice_2.size()!=1){
                    cout<<"请重新输入";
                    cin>>choice_2;
                }
                if(choice_2=="n"){
                    break;
                }
            }
            break;
        default:cout<<"好吧,"<<endl;
        }
    cout<<"那下次再见吧！"<<endl;
    return 0;
}
