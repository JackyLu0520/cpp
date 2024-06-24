#include<bits/stdc++.h>
using namespace std;
struct node{
    bool end=0;
    struct node *next[2];
};
struct node *root;
void init(){
    root=new node;
}
bool insert(char s[]){
    struct node *p=root;
    int l=strlen(s);
    bool f1=0,f2=1;
    for(int i=0;i<l;i++){
        if(p->end==1)   f1=1;
        int c=s[i]-'0';
        if(p->next[c]==nullptr){
            p->next[c]=new node;
            f2=0;
        }
        p=p->next[c];
    }
    p->end=1;
    return f1||f2;
}
int main(){
    char s[15];
    int i=1,f=0;
    init();
    while(scanf("%s",s)){
        if(s[0]=='9'){
            init();
            if(f)
                printf("Set %d is not immediately decodable",i);
            else
                printf("Set %d is immediately decodable",i);
            f=0;
            i++;
        }else{
            if(insert(s))   f=1;
        }
    }
    return 0;
}