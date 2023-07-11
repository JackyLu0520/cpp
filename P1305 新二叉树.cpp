#include<bits/stdc++.h>
using namespace std;
struct node{
	char val;
	int l,r;
}t[26];
int n;
void preorder(int root){
	if(root==-1)	return;
	cout<<char(root+'a');
	preorder(t[root].l);
	preorder(t[root].r);
}
int main(){
	int i,root;
	cin>>n;
	for(i=0;i<n;i++){
		char s[4];
		cin>>s;
		t[s[0]-'a'].l=s[1]=='*'?-1:s[1]-'a';
		t[s[0]-'a'].r=s[2]=='*'?-1:s[2]-'a';
		if(i==0)	root=s[0]-'a';
	}
	preorder(root);
	return 0;
}
