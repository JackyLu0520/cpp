#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,h[310],s=0,i,j;
	cin>>n;
	h[0]=0;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	sort(h+1,h+n+1);
	i=0,j=n;
	while(i<j){
		s+=(h[i]-h[j])*(h[i]-h[j]);
		i++;
		s+=(h[i]-h[j])*(h[i]-h[j]);
		j--;
	}
	cout<<s;
	return 0;
}
