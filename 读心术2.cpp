#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	bool f[5];
	cout<<"��������ѡ1~31�е�һ�������Ǻá�"<<endl; 
	system("pause");
	system("cls");
	system("color 4");
	cout<<"����������ǵ����𣿻ش�1��0��";
	cin>>f[0];
	system("cls");
	system("color 6");
	cout<<"�����������2,3,6,7,10,11,14,15,18,19,22,23,26,27,30,31���𣿻ش�1��0��";
	cin>>f[1];
	system("cls");
	system("color 2");
	cout<<"�����������4,5,6,7,12,13,14,15,20,21,22,23,28,29,30,31���𣿻ش�1��0��";
	cin>>f[2];
	system("cls");
	system("color 1");
	cout<<"�����������8,9,10,11,12,13,14,15,24,25,26,27,28,29,30,31���𣿻ش�1��0��";
	cin>>f[3];
	system("cls");
	system("color 9");
	cout<<"�����������16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31���𣿻ش�1��0��";
	cin>>f[4];
	system("cls");
	system("color 5");
	cout<<"��������ǣ�"<<pow(2,4)*f[4]+pow(2,3)*f[3]+pow(2,2)*f[2]+pow(2,1)*f[1]+pow(2,0)*f[0]<<endl;
	system("pause");
	return 0;
}
