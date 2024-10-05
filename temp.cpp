#include<bits/stdc++.h>
using namespace std;
mt19937 Rand(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
int main(){
    while(1){
        int len=Rand()%20;
        putchar(Rand()%26+'A');
        _sleep(50);
        for(int i=1;i<=len;i++){
            putchar(Rand()%26+'a');
            _sleep(50);
        }
        int c[10]={',',':',' ','.','\n'};
        putchar(c[Rand()%5]);
        _sleep(50);
    }
    return 0;
}
