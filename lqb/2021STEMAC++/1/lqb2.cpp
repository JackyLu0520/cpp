#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++)
			for(k=1;k<=n;k+=2)
				if(i!=j&&j!=k&&k!=i)
					cnt++;
	cout<<cnt;
	return 0;
}
