#include<iostream>
using namespace std;
int n,A,B,tx,k[201];
int offset[2]={1,-1};
bool b[201]={0},flag=0;
int x[201],step[201],head=1,tail=1;
int main(){
	int i,j;
	cin>>n>>A>>B;
	for(i=1;i<=n;i++)
		cin>>k[i];
	if(A!=B){
		x[tail]=A;step[tail]=0;tail++;b[A]=1;
		while(head<tail){
			for(i=0;i<2;i++){
				tx=x[head]+offset[i]*k[x[head]];
				if(!b[tx]&&tx>=1&&tx<=n){
					x[tail]=tx;step[tail]=step[head]+1;tail++;b[tx]=1;
					if(tx==B){flag=1;break;}
				}
			}
			if(flag)	break;
			head++;
		}
		if(flag)	cout<<step[tail-1];
		else		cout<<-1;
	}
	else	cout<<0;
	return 0;
}
/*
5 4
0 0 1 0
0 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1
1 1 4 3

7
*/ 
