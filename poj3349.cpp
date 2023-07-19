#include<iostream>
using namespace std;
const int MAXN=1e5,P=99991;
int n;
struct node{
    int a[7];
    int next;
}lst[MAXN+10];
int head[P+10],tot=0,s[2*MAXN+10][7];
int Hash(int i){
    int res=0;
    for(int j=1;j<=6;j++)
        res=(res+s[i][j]%P)%P;
    for(int j=1;j<=6;j++)
        res=(res*(s[i][j]%P))%P;
    return res;
}
bool cmp(int a[7],int b[7]){
    for(int i=1;i<=6;i++){
        bool f1=1;
        for(int j=1;j<=6;j++){
            //cout<<a[j]<<' '<<b[(i+j-1)%6==0?(i+j-1):(i+j-1)%6]<<"|";
            if(a[j]!=b[(i+j-1)%6==0?(i+j-1):(i+j-1)%6])
                f1=0;
        }
        if(f1)  return 1;
        //cout<<endl;
    }
    //cout<<endl;
    return 0;
}
int add(int i){
    int Hashval=Hash(i);
    for(int j=head[Hashval];j!=0;j=lst[j].next)
        if(cmp(s[i],lst[j].a))
            return 1;
    lst[++tot].next=head[Hashval];
    head[Hashval]=tot;
    for(int j=1;j<=6;j++)   lst[tot].a[j]=s[i][j];
    return 0;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=6;j++)
            cin>>s[i][j];
    for(int i=n+1;i<=2*n;i++)
        for(int j=1;j<=6;j++)
            s[i][j]=s[i-n][6-j+1];
    for(int i=1;i<=2*n;i++)
        if(add(i)){
            cout<<"Twin snowflakes found.";
            return 0;
        }
    cout<<"No two snowflakes are alike.";
    return 0;
}