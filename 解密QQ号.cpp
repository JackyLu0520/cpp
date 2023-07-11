#include<iostream>
using namespace std;
struct queue{
	int data[100];
	int head,tail;
};
int main(){
	struct queue q;
	q.head=0;
	for(q.tail=1;q.tail<=9;q.tail++)
		cin>>q.data[q.tail];
	int i;
	while(q.head<q.tail){
		cout<<q.data[q.head];
		q.head++;
		q.data[q.tail]=q.data[q.head];
		q.head++;
		q.tail++;
	}
	return 0;
}
