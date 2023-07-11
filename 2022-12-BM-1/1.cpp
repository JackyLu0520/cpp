#include<bits/stdc++.h>
using namespace std;
bool sq[1000010]={0};
int main(){
	for(int i=1;i<=1000;i++)
		sq[i*i]=1;
	int a,b,c,d,k,cnt=0;
	cin>>a>>b>>c>>d>>k;
	for(int x1=1;x1<=k;x1++)
		for(int x2=1;x2<=k;x2++)
			for(int x3=1;x3<=k;x3++)
				for(int x4=1;x4<=k;x4++)
					if(a*x1*x1+b*x2*x2+c*x3*x3+d*x4*x4==0)
						cnt++;
	cout<<cnt*16;
	return 0;
}