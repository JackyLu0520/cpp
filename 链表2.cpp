#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
}*head,*p,*q,*t;
int main(){
	int i,n,a;
	cin>>n;
	head=NULL;
	for(i=0;i<n;i++){
		cin>>a;
		p=new node;
		p->data=a;
		p->next=NULL;
		if(head==NULL)
			head=p;
		else
			q->next=p;
		q=p;
	}
	
	t=head;
	cin>>a;
	while(t!=NULL){
		if(t->next->data>a){
			p=new node;
			p->data=a;
			p->next=t->next;
			t->next=p;
			break;
		}
		t=t->next;
	}
	
	t=head;
	cin>>n;
	for(i=0;t!=NULL;i++){
		if(i=n-1){
			p=t->next;
			t->next=t->next->next;
			delete p;
			break;
		}
		t=t->next;
	}
	
	t=head;
	while(t!=NULL){
		cout<<t->data<<" ";
		t=t->next;
	}
}
