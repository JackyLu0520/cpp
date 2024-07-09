#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,cnt=0;
bool inq[N]={0};
int a[N],head=0,tail=0;
int main(){
    scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
		if(!inq[t]){
			cnt++;
			inq[t]=1;
            a[tail++]=t;
			if(tail-head>m){
				inq[a[head]]=0;
				head++;
			}
		}
	}
    printf("%d",cnt);
	return 0;
}