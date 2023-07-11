#include<bits/stdc++.h>
using namespace std;
char s[20];
int n;
char o='a';int a,b;
int main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s;
		if(s[0]<'a'||s[0]>'c'){
			sscanf(s,"%d",&a);
			cin>>b;
		}
		else{
			o=s[0];
			cin>>a>>b;
		}
		/*for(j=0;j<16;j++)
			s[j]=0;*/
		if(o=='a')
			sprintf(s,"%d+%d=%d",a,b,a+b);
		else if(o=='b')
			sprintf(s,"%d-%d=%d",a,b,a-b);
		else if(o=='c')
			sprintf(s,"%d*%d=%d",a,b,a*b);
		printf("%s\n%d\n",s,strlen(s));
		/*for(j=0;j<16;j++)
			s[j]=0;*/
	}
	return 0;
}
