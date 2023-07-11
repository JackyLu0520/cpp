#include<iostream>
#include<string>
using namespace std;
struct linked_list{
	struct node{
		int data;
		struct node *next;
	}*head,*p,*q,*t;
	int len;
	void list_init(int arr[],int n){
		len=n;
		int i;
		head=NULL;
		for(i=0;i<n;i++){
			p=new node;
			p->data=arr[i];
			p->next=NULL;
			if(head==NULL)
				head=p;
			else
				q->next=p;
			q=p;
		}
	}
	void print_list(string s){
		t=head;
		while(t!=NULL){
			cout<<t->data<<s;
			t=t->next;
		}
	}
	void ins_list(int n,int a){
		int i;
		t=head;
		for(i=0;t!=NULL;i++){
			if(i<n){
				p=new node;
				p->data=a;
				p->next=t->next;
				t->next=p;
				break;
			}
			t=t->next;
		}
		len++;
	}
	void del_list(int n){
		int i;
		t=head;
		for(i=0;t!=NULL;i++){
			if(i<n){
				p=t->next;
				t->next=t->next->next;
				delete p;
				break;
			}
			t=t->next;
		}
		len--;
	}
};

