#include<bits/stdc++.h>
using namespace std;
class Stack{
	private:
		int data[1000000],p;
	public:
		void init(){
			p=1;
		}
		bool Empty(){
			return p==1;
		}
		int Top(){
			if(!Empty())	return data[p-1];
			else			return -1;
		}
		int Size(){
			return p-1;
		}
		void Push(int n){
			data[p++]=n;
		}
		void Pop(){
			p--;
		}
}stack1;
int main(){
	stack1.init();
	for(int i=0;i<10;i++){
		stack1.Push(i);
		cout<<i<<' ';
	}
	cout<<endl;
	while(!stack1.Empty()){
		cout<<stack1.Top()<<' ';
		stack1.Pop();
	}
}

