#include<bits/stdc++.h>
using namespace std;
int k,n=0;
int main(){
	int i,j,l;
	cin>>k;
	for(i=1,l=1;;i++)
		for(j=1;j<=i;j++,l++)
			if(l<=k)
				n+=i;
			else{
				cout<<n;
				return 0;
			}
}
