#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int main(){
    char s[N];int n;
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int i=1,j=n;
        for(;s[i]==s[j]&&i<=j;i++,j--);
        if(i>j){printf("Draw\n");continue;}
        for(;i<=j&&s[i]==s[i+1];i+=2);
        printf(i>j?"Draw\n":"Alice\n");
    }
    return 0;
}