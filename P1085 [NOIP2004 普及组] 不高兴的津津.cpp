#include<iostream>
using namespace std;
int main(){
	int t[8][2],uhd=0,i,maxt=0;
	for(i=1;i<=7;i++)
		cin>>t[i][0]>>t[i][1];
	for(i=1;i<=7;i++)
		if(t[i][0]+t[i][1]>maxt)
			maxt=t[i][0]+t[i][1],uhd=i;
	cout<<uhd;
	return 0;
}
