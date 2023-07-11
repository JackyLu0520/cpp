#include<bits/stdc++.h>
using namespace std;
int n,A,B,k[210];
bool b[210];
struct s{
	int f,step;
	void set(int _f,int _step){
		f=_f;
		step=_step;
	}
}t;
queue<s> q;
int main(){
	int i;
	cin>>n>>A>>B;
	for(i=1;i<=n;i++)
		cin>>k[i];
	if(A==B)	cout<<0;
	else{
		t.set(A,0);q.push(t);b[A]=1;
		while(!q.empty()){
			for(i=1;i!=-1;i*=-1){
				int tf=q.front().f+i*k[q.front().f];
				if(!b[tf]&&tf>=1&&tf<=n){
					t.set(tf,q.front().step+1);q.push(t);b[tf]=1;
					if(tf==B){
						cout<<q.back().step;
						return 0;
					}
				}
			}
		}
		cout<<-1; 
	}
	return 0;
} 
