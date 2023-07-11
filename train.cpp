#include<bits/stdc++.h>
using namespace std;
queue<int> q[1000];
int n,a,m=0,M;
int main(){
	int i,j;
	cin>>n;
	q[0].push(1000000000);
	for(i=0;i<n;i++){
		cin>>a;
		if(m==0){
			q[1].push(a);
			m++;
		}
		else{
			M=0;
			for(j=1;j<=m;j++)
				if(q[M].back()>q[j].back()&&q[j].back()>a)
					M=j;
			if(M==0){
				q[m+1].push(a);
				m++;
			}
			else	
				q[M].push(a);
		}
	}
	//cout<<m;
	for(i=1;i<=m;i++){
		while(!q[i].empty()){
			cout<<q[i].front()<<' ';
			q[i].pop();
		}
		cout<<endl;
	}
	return 0;
}
/*
9
8 4 2 5 3 9 1 6 7
*/
