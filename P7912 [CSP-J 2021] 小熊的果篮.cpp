#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
list<deque<int>> fruits;
int main(){
	cin>>n;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=1,r=1;
	while(r<=n){
		deque<int> q;
		while(a[r]==a[l])
			q.push_back(r++);
		fruits.push_back(q);
		l=r;
	}
	while(fruits.size()){
		auto it=fruits.begin();
		while(it!=fruits.end()){
			if((*it).size()){
				cout<<*(*it).begin()<<' ';
				(*it).pop_front();
				it++;
			}else{
				while(it!=fruits.end()&&!(*it).size()){
					it=fruits.erase(it);
					if(it!=fruits.begin()&&it!=fruits.end()){
						auto next=it--;
						(*it).insert((*it).end(),(*next).begin(),(*next).end());
						it=fruits.erase(next);
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
