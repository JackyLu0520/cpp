#include<bits/stdc++.h>
using namespace std;
int n,w,winnum,t;
vector<int> score;
int main(){
	int i,j;
	cin>>n>>w;
	for(i=1;i<=n;i++){
		cin>>t;
		winnum=max(1,i*w/100);
		score.insert(lower_bound(score.begin(),score.end(),t),t);
		cout<<score[score.size()-winnum]<<' ';
	}
	return 0;
}
