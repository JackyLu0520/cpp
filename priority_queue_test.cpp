#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	srand(time(0));
	for(int i=0;i<10;i++)
		q.push(rand()%100+1);
	while(!q.empty()){
		cout<<q.top()<<' ';
		q.pop();
	}
	return 0;
}
