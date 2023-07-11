#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,h[10010],h1[10010],i,j,b[100010]={0};
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",h+i);
			h1[i]=h[i];
		}
		for(int i=1;i<=n;i++)
			b[h1[i]]++;
		for(int i=1,j=1;i<=100005;i++)
			while(b[i]--)
				h1[j++]=i;
		for(i=1;h[i]==h1[i];i++);
		for(j=n;h[j]==h1[j];j--);
		if(i>j)	printf("0\n");
		else	printf("%d\n",j-i+1);
	}
	return 0;
}