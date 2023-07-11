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
string pre,in;
int newnode(char val){
	t[idx]=node(val,-1,-1);
	return idx++;
}
int create(int inl,int inr,int prel,int prer){
	int k;
	if(prel>prer)	return -1;
	int root=newnode(pre[prel]);
	for(k=inl;k<=inr;k++)
		if(in[k]==pre[prel])
			break;
	int numl=k-inl;
	t[root].l=create(inl,k-1,prel+1,prel+numl);
	t[root].r=create(k+1,inr,prel+numl+1,prer);
	return root;
}
void postorder(int root){
	if(root==-1)	return;
	postorder(t[root].l);
	postorder(t[root].r);
	cout<<t[root].v;
}
int main(){
	cin>>in>>pre;
	int n=pre.size();
	int root=create(0,n-1,0,n-1);
	postorder(root);
	return 0;
}
