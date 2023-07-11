#include<bits/stdc++.h>
using namespace std;
int n,m=1;
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
		m=(m+1)*2;
	printf("%d",m);
	return 0;
}
