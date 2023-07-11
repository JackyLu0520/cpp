#include<iostream>
using namespace std;
int main()
{
    int L,R,i,ans=0,t;
    cin>>L>>R;
    for(i=L;i<=R;i++)
    {
    	t=i;
    	while(t)
	    {
	    	if(t%10==2)
	    		ans++;
	    	t/=10; 
	    }
	}
	cout<<ans;
	return 0;
}
