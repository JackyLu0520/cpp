#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=200;
int n,b[MAXN+5][MAXN+5];
bitset<MAXN*MAXN+10> a[MAXN*MAXN+10];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int x=i*n+j,y=i*n+j;
            a[x][y]=1;
            y=i*n+j+1;
            if(j+1<n)   a[x][y]=1;
            y=i*n+j-1;
            if(j-1>=0)  a[x][y]=1;
            y=(i+1)*n+j;
            if(i+1<n)   a[x][y]=1;
            y=(i-1)*n+j;
            if(i-1>=0)  a[x][y]=1;
            a[x][n*n]=1;
        }
    /*for(int i=0;i<n*n;i++){
        for(int j=0;j<=n*n;j++)
            cout<<a[i][j];
        cout<<endl;
    }*/
    for(int i=0;i<n*n;i++){
        for(int j=i;j<n*n;j++)
            if(a[j][i])
                swap(a[i],a[j]);
        for(int j=0;j<n*n;j++){
            if(i==j)    continue;
            if(a[j][i])
            a[j]^=a[i];
        }
    }
    for(int i=0;i<n*n;i++)
        b[i/n][i%n]=a[i][n*n];
    /*for(int i=0;i<n*n;i++){
        for(int j=0;j<=n*n;j++)
            cout<<a[i][j];
        cout<<endl;
    }*/
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<(b[i][j]?'#':' ');
        cout<<endl;
    }
    return 0;
}