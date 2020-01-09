 /* FileName: Demo_7.0.cpp
  * Author: Li Zhen
  * E-mail: 798663691@qq.com
  * Function: Calculating the average grade point of students
  */

#include <iostream>

using namespace std;

int main()
{
    int i=0,k,length;
    double ave=0,sum=0;
    while(cin>>k)
    {
        sum+=k;
        i++;
    }
    if(0==i)
    {
        cout<<"False input!"<<endl;
    }
    else
    {
        ave=sum/(i);
        cout<<"The average agrade point of " <<i<<" "<<"students is "<<ave<<endl;
    }
    return 0;
}
