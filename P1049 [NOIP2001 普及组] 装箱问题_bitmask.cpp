#include<bits/stdc++.h>
using namespace std;
int v,n,a[40],Min=2147483647,s=0;
int main(){
	cin>>v>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int mask=0;mask<(1<<n);mask++){
		s=0;
		for(int i=0;i<n;i++)
			if(mask&(1<<i))	s+=a[i];
		if(v>=s)	Min=min(Min,v-s);
	}
	cout<<Min;
	return 0;
}