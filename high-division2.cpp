#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int a[1010]={0},b[1010]={0},c[1010]={0};
void input(int a[]){
	string s;
	cin>>s;a[0]=s.size();
	for(int i=0;i<a[0];i++)	a[a[0]-i]=s[i]-'0';
}
void print(int a[]){
	if(a[0]==0)	cout<<0<<endl;
	else{
		for(int i=a[0];i>=1;i--)	cout<<a[i];
		cout<<endl;
	}
}
int cmp(int a[],int b[]){
	if(a[0]>b[0])	return 1;
	if(a[0]<b[0])	return -1;
	return memcmp(a,b,sizeof(a));
}
void highminus(int a[],int b[]){
	if(cmp(a,b)==0)	{a[0]=0;return;}
	for(int i=1;i<=a[0];i++){
		if(a[i]<b[i])	{a[i+1]--;a[i]+=10;}
		a[i]-=b[i];
	}
	while(a[a[0]]==0&&a[0]>1)	a[0]--;
}
void highdivision(int a[],int b[],int c[]){
	int i,j,t[1010];
	if(a[0]<b[0])	c[0]=1;
	else			c[0]=a[0]-b[0]+1;
	for(i=c[0];i>=1;i--){
		memset(t,0,sizeof(t));
		for(j=0;j<=b[0];j++)	t[j+i-1]=b[j];
		t[0]=b[0]+i-1;
		while(cmp(a,t)>=0)	{c[i]++;highminus(a,t);}
	}
	while(c[c[0]]==0&&c[0]>1)	c[0]--;
}
int main(){
	input(a);input(b);
	highdivision(a,b,c);
	print(c);print(a);
	return 0;
}
