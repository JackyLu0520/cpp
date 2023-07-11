#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
    int T;
    cin>>T;
    if (T==1) {
        cout<<"I love Luogu!";
    }else if(T==2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }else if(T==3) {
    	cout<<14/4<<endl;
    	cout<<14/4*4<<endl;
    	cout<<14-14/4*4;
    }else if(T==4) {
    	cout<<setprecision(6)<<500.0/3;
    }else if(T==5) {
    	cout<<(260+220)/(12+20);
    }else if(T==6) {
    	cout<<sqrt(6*6+9*9);
    }else if(T==7) {
    	cout<<110<<endl;
    	cout<<90<<endl;
    	cout<<0;
    }else if(T==8) {
    	double pi=3.141593;
    	cout<<2*pi*5<<endl;
    	cout<<pi*5*5<<endl;
    	cout<<4*pi*5*5*5/3;
    }else if(T==9) {
    	cout<<(((1+1)*2+1)*2+1)*2;
    }else if(T==10) {
    	float v,s;
    	v=(8*30-10*6)*1.0/(30-6);
    	s=8*30-v*30;
    	cout<<s/10+v;
    }else if(T==11) {
    	cout<<100.0/(8-5);
    }else if(T==12) {
    	cout<<int('M'-'A'+1)<<endl;
		cout<<char('A'+18-1);
    }else if(T==13) {
    	float pi=3.141593;
    	cout<<int(pow(4*pi*10*10*10/3+4*pi*4*4*4/3,1.0/3));
    }else if(T==14) {
    	cout<<50;
    }
    return 0;
}
