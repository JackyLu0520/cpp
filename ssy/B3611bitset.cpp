#include<cstdio>
#include<bitset>
using namespace std;
const int N=110;
int n;
bitset<N> a[N];
int main(){
    //scanf("%d",&n);
    char c;
    while(1){c=getchar();if(c<'0'||c>'9')break;n=(n<<3)+(n<<1)+(c^48);}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char t;
            do{t=getchar();}while(t<'0'||t>'1');
            a[i].set(j,t-'0');
        }
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++)
            if(a[i][j])
                a[i]|=a[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            putchar(a[i][j]+'0'),putchar(' ');
        putchar('\n');
    }
    return 0;
}