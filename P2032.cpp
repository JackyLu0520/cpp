#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
int n,k,a[MAXN];
deque<int> q;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(q.size()&&a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
		while(q.size()&&q.front()<i-k+1)
			q.pop_front();
		if(i-k+1>=0)	cout<<a[q.front()]<<endl;
	}
	return 0;
}