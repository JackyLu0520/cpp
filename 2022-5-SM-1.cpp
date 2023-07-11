#include<bits/stdc++.h>
using namespace std;
int n,q,x;
int a[500010],s[500010];
bool cmp(int a,int b){
	return a>b;
}
int search(int l,int r){
	int mid=(l+r)/2;
	if(l==r){
		if(x<=s[mid])	return mid;
		else			return -1;
	}
	if(x<=s[mid])	return search(l,mid);
	else			return search(mid+1,r);
}
int main(){
	scanf("%d%d",&n,&q);//cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);//cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&x);//cin>>x;
		printf("%d\n",search(1,n));//cout<<search(1,n)<<endl;
	}
	return 0;
}