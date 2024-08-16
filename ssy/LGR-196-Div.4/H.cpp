#include<bits/stdc++.h>
using namespace std;
const int N=100,M=100;
int n,m,k,t;
vector<int> b[N][M];
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&t);
    while(t--){
        int a,x,y;
        scanf("%d%d%d",&a,&x,&y);
        if(b[x][y].size()>=k){
            int p=0;
            for(int i=1;i<b[x][y].size();i++)
                if(b[x][y][p]>=b[x][y][i])
                    p=i;
            printf("%d %d\n",b[x][y][p],k-p-1);
            b[x][y].erase(b[x][y].begin()+p);
        }else   printf("-1\n");
        b[x][y].push_back(a);
    }
    return 0;
}