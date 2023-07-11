#include<bits/stdc++.h>
using namespace std;
struct score{
	int x,y;
	score(){}
	score(int _x,int _y){
		x=_x;
		y=_y;
	}
}a[6001],b[6001];
int i,na=1,nb=1;
char c;
int main(){
	fill(a,a+6001,score(0,0));
	fill(b,b+6001,score(0,0));
	do{
		c=getchar();
		if(c=='W')	a[na].x++,b[nb].x++;
		if(c=='L')	a[na].y++,b[nb].y++;
		if(a[na].x>=11&&a[na].x-a[na].y>=2||a[na].y>=11&&a[na].y-a[na].x>=2)
			na++;
		if(b[nb].x>=21&&b[nb].x-b[nb].y>=2||b[nb].y>=21&&b[nb].y-b[nb].x>=2)
			nb++;
	}while(c!='E');
	for(int i=1;i<=na;i++)
		cout<<a[i].x<<':'<<a[i].y<<endl;
	cout<<endl;
	for(int i=1;i<=nb;i++)
		cout<<b[i].x<<':'<<b[i].y<<endl;
	return 0;
}
