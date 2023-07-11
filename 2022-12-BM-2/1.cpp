#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,h[10010],h1[10010],i,j;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",h+i);
			h1[i]=h[i];
		}
		sort(h1+1,h1+n+1);
		for(i=1;h[i]==h1[i];i++);
		for(j=n;h[j]==h1[j];j--);
		if(i>j)	printf("0\n");
		else	printf("%d\n",j-i+1);
	}
	return 0;
}