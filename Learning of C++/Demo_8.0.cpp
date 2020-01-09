 /* FileName: Demo_8.0.cpp
  * Author: Li Zhen
  * E-mail: 798663691@qq.com
  * Function: Cout primes in a interval
  */

  #include <iostream>
  #include <cmath>
  using namespace std;

  int main()
  {
      int m,n,min,k,max,i;
      cin>>m>>n;
      if(m>n)
      {
          min=n;
          max=m;
       }
      else
      {
          min=m;
          max=n;
      }
      for(k=min;k<=max;k++)
      {
          for(i=2;i<sqrt(k);i++)
          {
              if(0==k%i)
              {
                break;
              }
          }
          if(i>sqrt(k)&&2!=k&&0!=k)
          {
              cout<<k<<" ";
          }
      }
      cout<<"是区间"<<min<<"~"<<max<<"中含有的素数"<<endl;
      return 0;
  }
