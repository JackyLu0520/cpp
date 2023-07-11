#include <iostream>

#include <cstdio>

using namespace std;
bool isprime(int n){
	if(n<2)	return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int b[26]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        b[s[i]-'a']++;
    int maxn=0,minn=101;
    for(int i=0;i<26;i++)
		if(b[i]!=0){
        	maxn=max(maxn,b[i]);
        	minn=min(minn,b[i]);
    	}
    if(isprime(maxn-minn))  cout<<"Lucky Word"<<endl<<maxn-minn;
    else                    cout<<"No Answer"<<endl<<0;
    return 0;
}

