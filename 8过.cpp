#include<iostream>
using namespace std;
int main()
{
	int i;
	for(i=1;i<=100;i++)
	{
      if(i%10==8 || i/10==8 || i%8==0)
        cout<<"¹ý ";
      else
	    cout<<i<<" "; 
    }
    return 0;
} 
