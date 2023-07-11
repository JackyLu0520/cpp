#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int l,r;
}t[1000010];
int d(int root){
	if(root==0)	return 0;
	return max(d(t[root].l),d(t[root].r))+1;
}
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>t[i].l>>t[i].r;
	cout<<d(1);
	return 0;
} 
