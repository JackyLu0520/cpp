#include<iostream>
#pragma GCC optimize(3)
using namespace std;
bool m[20][20]={{false}};
int solve(int x, int y){
	return m[x][y]?0:((x==0||y==0)?1:(solve(x-1,y)+solve(x,y-1)));
}
int main(){
	int bx,by,mx,my;
	cin>>bx>>by>>mx>>my;
	m[mx][my]=true;
	if(mx+2<=bx&&my+1<=by)	m[mx+2][my+1]=true;
	if(mx+1<=bx&&my+2<=by)	m[mx+1][my+2]=true;
	if(mx-1<=bx&&my+2<=by)	m[mx-1][my+2]=true;
	if(mx-2<=bx&&my+1<=by)	m[mx-2][my+1]=true;
	if(mx-2<=bx&&my-1<=by)	m[mx-2][my-1]=true;
	if(mx-1<=bx&&my-2<=by)	m[mx-1][my-2]=true;
	if(mx+1<=bx&&my-2<=by)	m[mx+1][my-2]=true;
	if(mx+2<=bx&&my-1<=by)	m[mx+2][my-1]=true;
	cout<<solve(bx,by);
	return 0;
}
