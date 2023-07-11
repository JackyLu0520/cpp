#include<iostream>
using namespace std;
struct score{
	int x,y;
}a[6000]={0},b[6000]={0};
int i,n1=1,n2=1;
char s;
int main(){
	do{
		cin>>s;
		if(s=='W')	a[n1].x++,b[n2].x++;
		if(s=='L')	a[n1].y++,b[n2].y++;
		if(a[n1].x>=11&&a[n1].x-a[n1].y>=2||a[n1].y>=11&&a[n1].y-a[n1].x>=2)
			n1++;
		if(b[n2].x>=21&&b[n2].x-b[n2].y>=2||b[n2].y>=21&&b[n2].y-b[n2].x>=2)
			n2++;
	}while(s!='E');
	for(i=1;i<=n1;i++)
		cout<<a[i].x<<':'<<a[i].y<<endl;
	cout<<endl;
	for(i=1;i<=n2;i++)
		cout<<b[i].x<<':'<<b[i].y<<endl;
	return 0;
}
