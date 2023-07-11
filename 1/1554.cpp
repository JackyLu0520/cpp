#include<iostream>
using namespace std;
int main()
{
    int L,R,i,j,ans[10]={0,0,0,0,0,0,0,0,0,0},t;
    cin>>L>>R;
    for(i=0;i<10;i++)
    	for(j=L;j<=R;j++)
    	{
    		t=j;
    		while(t)
	    	{
	    		if(t%10==i)
	    			ans[i]++;
	    		t/=10; 
	    	}
		}
	for(i=0;i<10;i++)
		cout<<ans[i]<<' ';
	return 0;
}//P1554
