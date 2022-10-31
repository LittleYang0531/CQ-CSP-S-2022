#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N = 5e5+10,MAX_T = 1.5e8;
struct edge{
	int u,v,f;
	bool operator < (const edge &p) const {return v==p.v?u<p.u:v<p.v;}
}a[N];
int n,m,q,o;
int c[N],cnt[N];
void del(int x){cnt[c[x]]--,cnt[--c[x]]++;}
void add(int x){cnt[c[x]]--,cnt[++c[x]]++;}
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i<=m;i++){
		int u=read(),v=read();
		c[u]++,a[i]={u,v,0};
	}sort(a+1,a+m+1);
	for(int i = 1;i<=n;i++) cnt[c[i]]++;
	q = read();
	while(q--){
		int op = read(),u = read(),v,pos;
		if(o>=MAX_T){puts("NO");continue;}
		if(op==1){
			pos = lower_bound(a+1,a+m+1,(edge){u,read(),0})-a;
			del(u),a[pos].f = 1,o++;
		}
		if(op==2){
			pos = lower_bound(a+1,a+m+1,(edge){0,u,0})-a;
			while(pos<=m and a[pos].v==u){
				if(!a[pos].f) a[pos].f=1,del(a[pos].u);
				pos++,o++;
			}
		}
		if(op==3){
			pos = lower_bound(a+1,a+m+1,(edge){u,read(),0})-a;
			add(u),a[pos].f = 0,o++;
		}
		if(op==4){
			pos = lower_bound(a+1,a+m+1,(edge){0,u,0})-a;
			while(pos<=m and a[pos].v==u){
				if(a[pos].f) a[pos].f=0,add(a[pos].u);
				pos++,o++;
			}
		}
		puts(cnt[1]==n?"YES":"NO");
	}
	return 0;
}
