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
		cout<<"����������ȩ��Щ��੤��\n������������������������\n������������������������\n������������������������\n��������������������\n�s���s���t�����بs�s���s";
	else
		cout<<"�q���������������r������\n�������੤�s�������s�Шs\n�s����������������������\n�������੤��������������\n�������������t�������ੴ\n�t�����s���s���s�����s��";
	return 0;
}
