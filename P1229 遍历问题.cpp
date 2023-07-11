#include<bits/stdc++.h>
using namespace std;
int ans=0;
string preorder,postorder;
int main(){
	cin>>preorder>>postorder;
	for(int i=0;i<preorder.size();i++)
		for(int j=1;j<postorder.size();j++)
			if(preorder[i]==postorder[j]&&preorder[i+1]==postorder[j-1])
				ans++;
	cout<<(1<<ans);
	return 0;
}
