#include<bits/stdc++.h>
using namespace std;
list<int> l;
int n,m,k,p,x;
int main(){
	scanf("%d",&n);
	int i;
	list<int>::iterator it;
	l.push_back(1);
	for(i=2;i<=n;i++){
		scanf("%d%d",&k,&p);
		for(it=l.begin();it!=l.end();it++)
			if(*it==k){
				if(p==1)
					it++;
				l.insert(it,i);
				break;
			}
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&x);
		for(it=l.begin();it!=l.end();it++)
			if(*it==x){
				l.erase(it);
				break;
			}
	}
	for(it=l.begin();it!=l.end();it++)
		printf("%d",*it);
	return 0;
}
