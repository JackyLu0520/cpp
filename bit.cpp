#include<iostream>
using namespace std;
int main(){
	int num=0,n;
	bool f=true;
	float sum=0.0,sumone=0.0;
	while(f){
		sumone=0.0;
		do{
			cin>>n;
			if(n==-1){
				f=false;
				break;
			}
			sumone+=n;
		}while(n!=0);
		cout<<sumone<<"Ôª"<<endl;
		cout<<"-----------------"<<endl;
		num++;
		sum+=sumone;
	}
	cout<<num<<"ÈË"<<sum<<"Ôª";
	return 0;
}
