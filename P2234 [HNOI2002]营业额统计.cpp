#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *l,*r;
	Node(int v):val(v),l(NULL),r(NULL){}
};
Node* insert(Node* &cur,int val){
	if(cur==NULL){
		cur=new Node(val);
		return cur;
	}
	if(val<=cur->val)	return insert(cur->l,val);
	else				return insert(cur->r,val);
}
Node* findPred(Node* cur,int x){
	if(x>cur->val){
		if(cur->r==NULL)	return cur;
		Node* res=findPred(cur->r,x);
		if(res==NULL)	return cur;
		return res;
	}
	else{
		if(cur->l==NULL)	return NULL;
		else return findPred(cur->l,x);
	}
}
Node* findSucc(Node* cur,int x) {
    if (x<cur->val){
        if(cur->l==NULL)	return cur;
        Node* res=findSucc(cur->l,x);
        if(res==NULL)	return cur;
        return res;
    } else {
        if(cur->r==NULL)	return NULL;
        else	return findSucc(cur->r,x);
    }
}
int main(){
	int n,x;
	cin>>n>>x;
	int ans=x;
	Node* root=new Node(x);
	for(int i=1;i<n;i++){
		cin>>x;
		Node* pred=findPred(root,x);
		Node* succ=findSucc(root,x);
		if(!pred)	ans+=succ->val-x;
		else if(!succ)	ans+=x-pred->val;
		else	ans+=min(succ->val-x,x-pred->val);
		insert(root,x);
	}
	cout<<ans;
	return 0;
} 
