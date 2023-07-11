#include<bits/stdc++.h>
using namespace std;
struct tmp{
	int x;
	tmp(int _x){
		x=_x;
	} 
};
struct Greater{
	bool operator()(tmp a,tmp b){
		return a.x>b.x;
	}
};
int main(){
	priority_queue<tmp,vector<tmp>,Greater> q;
	srand(time(0));
	for(int i=0;i<10;i++)
		q.push(tmp(rand()%100+1));
	while(!q.empty()){
		cout<<q.top().x<<' ';
		q.pop();
	}
	return 0;
}
