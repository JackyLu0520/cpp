#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	int l,r;
	int num;
	node(){}
	node(int _val,int _l,int _r,int _num){
		val=_val;
		l=_l;
		r=_r;
		num=_num;
	} 
}t[10010];
int idx=-1;
int newnode(int x){
	t[idx]=node(x,-1,-1,1);
	return idx++;
}
void insert(int &root,int x){
	if(root=-1){
		root=newnode(x);
		return;
	}
	if(t[root].val==x){
		t[root].num++;
		return;
	}
	if(x<t[root].val)
		insert(t[root].l,x);
	else
		insert(t[root].r,x);
}
int Max(int root){
	if(t[root].r==-1)	return t[root].val;
	return Max(t[root].r);
}
int pre(int root,int x){
	if(t[root].l==-1&&t[root].l==-1)	return -2147483647; 
	if(t[root].val==x)	return Max(t[root].l);
	if(t[root].val>x)	return pre(t[root].l,x);
	else				return pre(t[root].r,x);
}
int Min(int root){
	if(t[root].l==-1)	return t[root].val;
	return Max(t[root].l);
}
int next(int root,int x){
	if(t[root].l==-1&&t[root].l==-1)	return 2147483647; 
	if(t[root].val==x)	return Min(t[root].r);
	if(t[root].val>x)	return next(t[root].l,x);
	else				return next(t[root].r,x);
}
int x_rank(int root,int x){
	
}
int main(){
	
}
