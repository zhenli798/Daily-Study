/* FileName: Demo_4.1.cpp
 * Author:Li Zhen ����
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
        cout<<"�������ж�������Ϸ�����߻�������Ϸ������1���ж�����������0���жϻ�����";
        cin >>fir;
        switch(fir)
        {
        case 0:
            while(1)
        {
        cout<<"��������λ��";
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
            cout<<"������Ĳ�����λ�������������룺";
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
            cout<<"����λ���ǻ�����"<<endl;
        }
        else
        {
            cout<<"����λ�����ǻ�����"<<endl;
        }
        cout<<"�㻹�����жϻ�����������Please input 'y' or 'n'";
        cin>>choice_1;
        while(choice_1!="y"&&choice_1!="n"||choice_1.size()!=1)
        {
            cout<<"�밴������������:";
            cin>>choice_1;
        }
        if(choice_1=="n")
        {
            break;
        }
        }
        break;
        case 1:
            cout<<"���������ж�����С��Ϸ"<<endl;
            while(1){
                cout<<"������һ����"<<endl;
                cin>>primenum;
                for(i=2;i<=sqrt(primenum);i++){
                   if(m%i==0){
                    cout<<primenum<<"��������"<<endl;
                    break;
                   }
                }
                if(i>sqrt(primenum)){
                    cout<<primenum<<"������"<<endl;
                }
                cout<<"�㻹������һ����y or n";
                cin>>choice_2;
                while(choice_2!="y"&&choice_2!="n"||choice_2.size()!=1){
                    cout<<"����������";
                    cin>>choice_2;
                }
                if(choice_2=="n"){
                    break;
                }
            }
            break;
        default:cout<<"�ð�,"<<endl;
        }
    cout<<"���´��ټ��ɣ�"<<endl;
    return 0;
}
