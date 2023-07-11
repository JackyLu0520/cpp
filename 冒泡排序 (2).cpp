#include<iostream>
using namespace std;
int main()
{
	char a,b,c,d,e;
	cin>>a>>b>>c>>d;
	if(a>b)
	  {
	  e=a;
	  a=b;
	  b=e;
      }
    if(b>c)
	  {
	  e=b;
	  b=c;
	  c=e;
      }
	if(c>d)
	  {
	  e=c;
	  c=d;
	  d=e;
      }
    if(a>b)
	  {
	  e=a;
	  a=b;
	  a=e;
      }
	if(b>c)
	  {
	  e=b;
	  b=c;
	  c=e;
      }
	if(a>b)
	  {
	  e=a;
	  a=b;
	  b=e;
      }  
	cout<<a<<" "<<b<<" "<<c<<" "<<d; 
	return 0;    
}
