/* FileName: Demo_6.0.cpp
 * Author:Li Zhen
 * Function: Using switch to choose to judge prime or judge palindrome or computer data
 * Date: Jan 07, 2020
 * E-mail: 798663691@qq.com
*/

 #include<iostream>
 #include<cstring>
 #include<cmath>
 #include<stdlib.h>

 using namespace std;

 int main ()
 {
	system("color E4");
	string choice_1,choice_2,choice_3,choice_4;
	int palindromenum,year,month,day,length_1,length_2,length_3;
	int myriabit,kilobit,decade,unit,primenum,in,length,rc,v;
	int t=10000;
	char arr_2[10],arr_3[10],arr_4[10],s[1000],fir;
	int date=0;
	while(1)
	{     
		 cout<<"********************************************************************************"<<endl;
	     cout<<"*                       ��ϲ����С��Ϸ��                                     *"<<endl;
	     cout<<"*     ��������������Ϸ��                                                       *"<<endl;
	     cout<<"*         1.�жϻ�����С��Ϸ                                                   *"<<endl;
	     cout<<"*            2.�ж�����С��Ϸ                                                  *"<<endl;
	     cout<<"*               3.�ж�����С��Ϸ              ��ܰ��ʾ����������1��2��3����    *"<<endl;
	     cout<<"********************************************************************************"<<endl;
	     cin >>fir;
	     switch(fir)
	        {
	        case '1':
	            while(1)
	            {   
					palindromenum=0;
					cout<<"��������λ��";
	                cin>>s;
	                length=strlen(s);
	                for(rc=0;rc<length;rc++)
	                {
	                    if(0<=s[rc]-'0'&&9>=s[rc]-'0')
	                    {
	                        palindromenum+=(s[rc]-'0')*t;
	                        t/=10;
	                    }
	                    else
	                    {
	                        palindromenum=0;
	                        break;
	                    }
	                }
	                while(10000>palindromenum||99999<palindromenum)
	                {
	                    cout<<"������Ĳ�����λ�������������룺";
	                    cin>>s;
	                    t=10000; 
	                    length=strlen(s);
	                    for(v=0;v<length;v++){
	                    if(0<=s[v]-'0'&&9>=s[v]-'0')
						{
	                        palindromenum+=(s[v]-'0')*t;
	                        t/=10;
	                    }
	                    else{
	                        palindromenum=0;
	                        break;
	                    }
	                    }
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
	                cout<<"�㻹�����жϻ�����������"<<endl;
	                cout<<"������ 'y' ���� 'n'"<<endl;
	                cin>>choice_1;
	                while("y"!=choice_1&&"n"!=choice_1||1!=choice_1.size())
	                {
	                    cout<<"�밴������������:";
	                    cin>>choice_1;
	                }
	                if("n"==choice_1)
	                {
	                    break;
	                }
	            }
	            break;
	        case '2':
	            cout<<"���������ж�����С��Ϸ"<<endl;
	            while(1)
	            {
	                cout<<"������һ����"<<endl;
	                cin>>primenum;
	                for(in=2;in<=sqrt(primenum);in++)
	                {
	                   if(0==primenum%in){
	                    cout<<primenum<<"��������"<<endl;
	                    break;
	                   }
	                }
	                if(in>sqrt(primenum))
	                {
	                    cout<<primenum<<"������"<<endl;
	                }
	                cout<<"�㻹������һ����y or n";
	                cin>>choice_2;
	                while("y"!=choice_2&&"n"!=choice_2||1!=choice_2.size())
	                {
	                    cout<<"����������";
	                    cin>>choice_2;
	                }
	                if("n"==choice_2)
	                {
	                    break;
	                }
	            }
	            break;
	        case '3':
	            cout<<"���������ж�����С��Ϸ"<<endl;
	            while(1)
	            {
	                 date=0;
	                 /*cout<<"�������ж�����С��Ϸ��������y��n��";
	                 cin>>choice_3;
	                 while(choice_3!="y"&&choice_3!="n"||choice_3.size()!=1)
	                {
	                    cout<<"�Ƿ����룬����������:";
	                    cin>>choice_3;
	                 }
	                 if(choice_3=="n")
	                {
	                    break;
	                 }*/
	                int arr_1[13]={0,31,28,31,30,31,31,30,31,30,31,30,31};
	                cout<<"������һ�����ڣ������磺2020 1 8��";
	                cin>>arr_2;
	                cin>>arr_3;
	                cin>>arr_4;
	                year=0;
	                month=0;
	                day=0;
	                while(999>year||9999<year||0>=month||12<=month||0>=day||30<=day)
	                {   length_1=strlen(arr_2);
	                    length_2=strlen(arr_3);
	                    length_3=strlen(arr_4);
	                    year=0;
	                    month=0;
	                    day=0;
	                    int thousand=1000;
	                    int decde,f=10;
	                    for(int i=0;i<length_1;i++)
	                    {
	                        if(0<=arr_2[i]-'0'&&9>=arr_2[i]-'0')
	                        {
	                            year+=(arr_2[i]-'0')*thousand;
	                            thousand/=10;
	                        }
	                        else{
	                            cout<<"�������"<<" ";
	                            year=0;
	                            break;
	                        }
	                    }
	                    for(int m=0;m<length_2;m++)
	                    {
	                        if(0<=arr_3[m]-'0'&&9>=arr_3[m]-'0')
	                        {
	                            if(1==length_2)
	                            {
	                                f=1;
	                            }
	                            else
	                            {
	                                if(1!=f){
	                                    f=pow(10,(length_2-1));
	                                }
	                            }
	                            month+=(arr_3[m]-'0')*f;
	                            f/=10;
	                        }
	                        else{
	                            cout<<"�·�����"<<" ";
	                            month=0;
	                            break;
	                        }
	                    }
	                    for(int p=0;p<length_3;p++)
	                    {
	                        if(0<=arr_4[p]-'0'&&9>=arr_4[p]-'0')
	                        {
	                            if(1==length_3)
	                            {
	                                decde=1;
	                            }
	                            else
	                            {
	                                if(1!=decde){
	                                    decde=pow(10,(length_3-1));
	                                }
	                            }
	                            day+=(arr_4[p]-'0')*decde;
	                            decde/=10;
	                        }
	                        else
	                        {
	                            cout<<"��������"<<" ";
	                            day=0;
	                            break;
	                        }
	                    }
	                    cout<<endl;
	                    if(0!=year&&0!=month&&0!=day&&999<=year&&9999>=year&&0<month&&12>=month&&0<day&&31>=day)
	                    {
	                        break;
	                    }
	                    cout<<"�밴�����������룺";
	                    cin>>arr_2;
	                    cin>>arr_3;
	                    cin>>arr_4;
	                }
	                if(0==year%4&&0!=year%100||0==year%400)
	                {
	                    arr_1[2]+=1;
	                }
	                for(int r=1;r<month;r++)
	                {
	                    date+=arr_1[r];
	                }
	                date+=day;
	                cout<< year<<"��"<<month<<"��"<<day<<"��"<<"��"<<year<<"��ĵ�"<<date<<"��"<<endl; 
	                cout<<"�㻹���������������'y'or'n'";
	                cin>>choice_3;
	                while("y"!=choice_3&&"n"!=choice_3||1!=choice_3.size())
	                {
	                    cout<<"����������: ";
	                    cin>>choice_3;
	                }
	                if("n"==choice_3)
	                {
	                    break;
	                }
	            }
	            break;
	        default:cout<<"�ð�,"<<endl;
	        }
	        cout<<"�㲻������Ϸ���𣿡�y��or ��n��"<<endl;
			cin>>choice_4;
			while("y"!=choice_4&&"n"!=choice_4||1!=choice_4.size())
			{
				cout<<"���������룺 "<<endl; 
				cin>>choice_4;
			} 
			if("y"==choice_4){
				break;
			}
    }
    cout<<"���´��ټ��ɣ�"<<endl;
    return 0;
}
