#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	bool f[4];
	cout<<"��������ѡ1~15�е�һ�������Ǻá�"<<endl; 
	system("pause");
	system("cls");
	cout<<"����������ǵ����𣿻ش�1��0��";
	cin>>f[0];
	system("cls");
	cout<<"�����������2,3,6,7,10,11,14,15���𣿻ش�1��0��";
	cin>>f[1];
	system("cls");
	cout<<"�����������4,5,6,7,12,13,14,15���𣿻ش�1��0��";
	cin>>f[2];
	system("cls");
	cout<<"�����������8,9,10,11,12,13,14,15���𣿻ش�1��0��";
	cin>>f[3];
	system("cls");
	cout<<"��������ǣ�"<<pow(2,3)*f[3]+pow(2,2)*f[2]+pow(2,1)*f[1]+pow(2,0)*f[0]<<endl;
	system("pause");
	return 0;
}
