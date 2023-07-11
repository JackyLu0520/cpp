#include<iostream>
using namespace std;
bool search(int l,int r,int n){
	int mid;
	if(l>=r)	return 0;
	mid=(l+r)/2;
	cout<<mid<<endl;
	if(mid==n)	return 1;
	if(mid>n)	return search(l,mid-1,n);
	else		return search(mid+1,r,n);
}
int main(){
	int i,n;
	cin>>n;
	if(search(0,100,n))
		cout<<"©°©¤©¤©¤©à©È©°©Ğ©´©à©¤©´\n©À©¤©´¡¡©¦¡¡¡¡©¦¡¡©¦¡¡©¦\n©¦¡¡©¦¡¡©¦¡¡¡¡©¦¡¡©¦¡¡©¦\n©¦¡¡©¦¡¡©¦©¦¡¡©¦¡¡©¦¡¡©¦\n©¦¡¡©¦¡¡©À©¼¡¡©¦¡¡©¦\n¨s©¸¨s©¸¨t©¼©¸©Ø¨s¨s©¤¨s";
	else
		cout<<"¨q©¤¡¡©°¡¡¡¡©°©¤¨r©´¡¡©´\n©¦©¤©¤©à©¤¨s©¦©¦©¦¨s©Ğ¨s\n¨s¡¡¡¡©¦¡¡¡¡©¦©¦©¦©¦©¦¡¡\n©¸©¤©¤©à©¤©¼©¦©¦©¦©¦©¦¡¡\n¡¡¡¡¡¡©¦¡¡¡¡¨t©¦©¼©¸©à©´\n¨t©¤©¤¨s©¤¨s©¸¨s©¼©¸¨s©¼";
	return 0;
}
