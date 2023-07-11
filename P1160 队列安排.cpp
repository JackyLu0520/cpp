#include<bits/stdc++.h>
using namespace std;
list<int> l;
list<int>::iterator pos[100010];
int n,m,k,p,x;
bool e[100010];
int main(){
	scanf("%d",&n);
	int i;
	list<int>::iterator it;
	l.push_back(1);
	pos[1]=l.begin();
	for(i=2;i<=n;i++){
		scanf("%d%d",&k,&p);
		it=pos[k];
		if(p==1)	it++;
		pos[i]=l.insert(it,i);
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		if(!e[x]){
			l.erase(pos[x]);
			e[x]=1;
		}
	}
	for(it=l.begin();it!=l.end();it++)
		printf("%d ",*it);
	return 0;
}
