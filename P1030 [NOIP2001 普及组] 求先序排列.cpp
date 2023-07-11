#include<bits/stdc++.h>
using namespace std;
struct node{
	char v;
	int l,r;
	node(){}
	node(char _v,int _l,int _r){
		v=_v;
		l=_l;
		r=_r;
	}
}t[26];
int idx=0;
string post,in;
int newnode(char val){
	t[idx]=node(val,-1,-1);
	return idx++;
}
int create(int inl,int inr,int postl,int postr){
	int k;
	if(postl>postr)	return -1;
	int root=newnode(post[postr]);
	for(k=inl;k<=inr;k++)
		if(in[k]==post[postr])
			break;
	int numl=k-inl;
	t[root].l=create(inl,k-1,postl,postl+numl-1);
	t[root].r=create(k+1,inr,postl+numl,postr-1);
	return root;
}
void preorder(int root){
	if(root==-1)	return;
	cout<<t[root].v;
	preorder(t[root].l);
	preorder(t[root].r);
}
int main(){
	cin>>in>>post;
	int n=post.size();
	int root=create(0,n-1,0,n-1);
	preorder(root);
	return 0;
}
