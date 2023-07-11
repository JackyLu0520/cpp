#include<iostream>
using namespace std;
int main(){
	int i,j,k;
	for(i=1;i<=33;i++)
	    for(j=1;j<(100-i)/2-3;j++){
	    	k=100-i-j;
			if(i*3+j*2+k/3.0==100)
				cout<<i<<" "<<j<<" "<<k<<endl;
		}
    return 0;
}
