#include<iostream>
#include<string>
using namespace std;
int main(){
	string a,s;
	int top=0,next,mid,i,len;
	getline(cin,a);
	len=a.size();
	mid=len/2-1;
	next=len%2?mid+2:mid+1;
	for(i=next;i<len;i++,top--)
		if(a[i]!=s[top])
			break;
	cout<<(top?"NO":"YES");
	return 0;
}
