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
	     cout<<"*                       你喜欢玩小游戏吗？                                     *"<<endl;
	     cout<<"*     我这里有三个游戏：                                                       *"<<endl;
	     cout<<"*         1.判断回文数小游戏                                                   *"<<endl;
	     cout<<"*            2.判断素数小游戏                                                  *"<<endl;
	     cout<<"*               3.判断天数小游戏              温馨提示：输入数字1、2、3即可    *"<<endl;
	     cout<<"********************************************************************************"<<endl;
	     cin >>fir;
	     switch(fir)
	        {
	        case '1':
	            while(1)
	            {   
					palindromenum=0;
					cout<<"请输入五位数";
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
	                    cout<<"您输入的不是五位数，请重新输入：";
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
	                    cout<<"该五位数是回文数"<<endl;
	                }
	                else
	                {
	                    cout<<"该五位数不是回文数"<<endl;
	                }
	                cout<<"你还想玩判断回文数程序吗？"<<endl;
	                cout<<"请输入 'y' 或者 'n'"<<endl;
	                cin>>choice_1;
	                while("y"!=choice_1&&"n"!=choice_1||1!=choice_1.size())
	                {
	                    cout<<"请按规则重新输入:";
	                    cin>>choice_1;
	                }
	                if("n"==choice_1)
	                {
	                    break;
	                }
	            }
	            break;
	        case '2':
	            cout<<"即将进入判断素数小游戏"<<endl;
	            while(1)
	            {
	                cout<<"请输入一个数"<<endl;
	                cin>>primenum;
	                for(in=2;in<=sqrt(primenum);in++)
	                {
	                   if(0==primenum%in){
	                    cout<<primenum<<"不是素数"<<endl;
	                    break;
	                   }
	                }
	                if(in>sqrt(primenum))
	                {
	                    cout<<primenum<<"是素数"<<endl;
	                }
	                cout<<"你还想再玩一次吗？y or n";
	                cin>>choice_2;
	                while("y"!=choice_2&&"n"!=choice_2||1!=choice_2.size())
	                {
	                    cout<<"请重新输入";
	                    cin>>choice_2;
	                }
	                if("n"==choice_2)
	                {
	                    break;
	                }
	            }
	            break;
	        case '3':
	            cout<<"即将进入判断日期小游戏"<<endl;
	            while(1)
	            {
	                 date=0;
	                 /*cout<<"你想玩判断日期小游戏吗？请输入y或n：";
	                 cin>>choice_3;
	                 while(choice_3!="y"&&choice_3!="n"||choice_3.size()!=1)
	                {
	                    cout<<"非法输入，请重新输入:";
	                    cin>>choice_3;
	                 }
	                 if(choice_3=="n")
	                {
	                    break;
	                 }*/
	                int arr_1[13]={0,31,28,31,30,31,31,30,31,30,31,30,31};
	                cout<<"请输入一个日期：（例如：2020 1 8）";
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
	                            cout<<"年份有误"<<" ";
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
	                            cout<<"月份有误"<<" ";
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
	                            cout<<"天数有误"<<" ";
	                            day=0;
	                            break;
	                        }
	                    }
	                    cout<<endl;
	                    if(0!=year&&0!=month&&0!=day&&999<=year&&9999>=year&&0<month&&12>=month&&0<day&&31>=day)
	                    {
	                        break;
	                    }
	                    cout<<"请按规则重新输入：";
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
	                cout<< year<<"年"<<month<<"月"<<day<<"日"<<"是"<<year<<"年的第"<<date<<"天"<<endl; 
	                cout<<"你还想继续玩吗？请输入'y'or'n'";
	                cin>>choice_3;
	                while("y"!=choice_3&&"n"!=choice_3||1!=choice_3.size())
	                {
	                    cout<<"请重新输入: ";
	                    cin>>choice_3;
	                }
	                if("n"==choice_3)
	                {
	                    break;
	                }
	            }
	            break;
	        default:cout<<"好吧,"<<endl;
	        }
	        cout<<"你不想玩游戏了吗？“y”or “n”"<<endl;
			cin>>choice_4;
			while("y"!=choice_4&&"n"!=choice_4||1!=choice_4.size())
			{
				cout<<"请重新输入： "<<endl; 
				cin>>choice_4;
			} 
			if("y"==choice_4){
				break;
			}
    }
    cout<<"那下次再见吧！"<<endl;
    return 0;
}
