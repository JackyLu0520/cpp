#include<bits/stdc++.h>
using namespace std;
namespace INPUT_SPACE {
	const int N=(1<<24)+5;char S[N],*H,*T;inline int gc() { if(H==T) T=(H=S)+fread(S,1,N,stdin);return (H==T)?EOF:*H++; }
	inline int inn() { int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x; }
} using INPUT_SPACE::inn;
namespace OUTPUT_SPACE { // It is suggested to use file IO; or use ctrl+Z for windows to finish input
	char s[300000*15],t[20];int n,m;inline int Flush() { return fwrite(s+1,sizeof(char),n,stdout),n=0,0; }
	inline int print(int x) { if(!x) s[++n]='0';for(m=0;x;x/=10) t[++m]=char(x%10+'0');for(;m;m--) s[++n]=t[m];return s[++n]='\n'; }
} using OUTPUT_SPACE::print; using OUTPUT_SPACE::Flush;
inline int solve(int *c, int n, int L, int R, int a) {
    // your code here
    int cnt=0;
    for(int i=L;i<=R;i++)
        if(c[i]==a)
            cnt++;
    return cnt;
}
inline void update(int *c, int n, int k) {
    // your code here
    swap(c[k],c[k+1]);
}
int c[300010];
int main() {
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
	int n = inn() ,q = inn();
    for(int i = 1; i <= n; i++) c[i] = inn();
    while (q--) {
        if (inn() == 1) {
            int L = inn(), R = inn(), a = inn();
            print(solve(c, n, L, R, a));
        } else {
            int k = inn();
            update(c, n, k);
        }
    }
	Flush(); // MUST call flush() at the end of the program!
    return 0;
}
