#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
struct node{
	deque<int> q;
	struct node *prev,*next;
};
struct node *head,*tail;
void init(){
	head=new node;
	tail=new node;
	head->next=tail;
	tail->prev=head;
}
void push_back(deque<int> q){
	tail->next=new node;
	tail->next->prev=tail;
	tail=tail->next;
	tail->q=q;
}
struct node* erase(struct node* p){
	struct node *prev=p->prev,*next=p->next;
	prev->next=next;
	next->prev=prev;
	delete p;
	return next;
}
list<deque<int>> fruits;
int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1;
	while(r<=n){
		deque<int> q;
		while(a[r]==a[l])
			q.push_back(r++);
		push_back(q);
		l=r;
	}
	while(head!=tail){
		struct node *p=head->next;
		while(p!=NULL){
			if((p->q).size()){
				cout<<*(p->q).begin()<<' ';
				(p->q).pop_front();
				p=p->next;
			}else{
				while(p!=NULL&&!(p->q).size()){
					p=erase(p);
					if(p!=head->next&&p!=tail){
						struct node* next=p->prev;
						(p->q).insert((p->q).end(),(next->q).begin(),(next->q).end());
						p=erase(next);
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
