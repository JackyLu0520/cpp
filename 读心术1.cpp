#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int bin[16]={0001,0010,0011,0100,0101,0110,0111,1000,1001,1010,1011,1100,1101,1110,1111},i,t[16],j,n[4];
	cout<<"����1~15֮��ѡһ������"<<endl;
	system("pause");
	system("cls");
	for(i=0;i<4;i++)
	{
		cout<<"���ʣ�������������0��û�� 1���� ������Ĭ��Ϊ�С�"<<endl;
		for(i=0;i<16;i++)
			t[i]=bin[i];
		for(j=0;j<16;j++)
		{
			if(t[j]%10==1)
				cout<<j+1<<' ';
			t[j]/=10;
		}
		cin>>n[i];
	}
	cout<<8*n[3]+4*n[2]+2*n[1]+1*n[0];
	return 0;
}
