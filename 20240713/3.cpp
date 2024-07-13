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
typedef vector<int>::iterator vit;
const int N=300010,C=300010;
int c[N],n,q;
vector<int> p[C];
inline int solve(int L, int R, int a) {
    // your code here
    vit lit=lower_bound(p[a].begin(),p[a].end(),L);
    vit rit=upper_bound(p[a].begin(),p[a].end(),R);
    return rit-lit;
}
inline void update(int k) {
    // your code here
    vit it1=lower_bound(p[c[k]].begin(),p[c[k]].end(),k);
    vit it2=lower_bound(p[c[k+1]].begin(),p[c[k+1]].end(),k+1);
    vit t1=it1,t2=it2;t1++;t2--;
    (*it1)++;if(t1!=p[c[k]].end()&&*it1>*t1) swap(*it1,*t1);
    (*it2)--;if(it2!=p[c[k+1]].begin()&&*it2<*t2) swap(*it2,*t2);
    swap(c[k],c[k+1]);
}
int main() {
	n = inn() ,q = inn();
    //scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i++) c[i] = inn();
    //for(int i = 1; i <= n; i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)   p[c[i]].push_back(i);
    while (q--) {
        int op=inn();
        //int op;scanf("%d",&op);
        if (op == 1) {
            int L = inn(), R = inn(), a = inn();
            //int L,R,a;
            //scanf("%d%d%d",&L,&R,&a);
            print(solve(L, R, a));
            //printf("%d\n",solve(L, R, a));
        } else {
            int k = inn();
            //int k;
            //scanf("%d",&k);
            update(k);
        }
        /*for(int i = 1; i <= n; i++) printf("%d ",c[i]);
        printf("\n");
        for(int i=1;i<=C;i++)
            if(!p[i].empty()){
                printf("#%d ",i);
                for(int j:p[i])
                    printf("%d ",j);
                printf("\n");
            }*/
    }
	Flush(); // MUST call flush() at the end of the program!
    return 0;
}
