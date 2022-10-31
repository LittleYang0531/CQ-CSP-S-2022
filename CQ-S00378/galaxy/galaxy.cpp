#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define lll __int128
#define uns unsigned
#define fi first
#define se second
#define IF (it->fi)
#define IS (it->se)
#define lowbit(x) ((x)&-(x))
#define END putchar('\n')
#define inline jzmyyds
using namespace std;
const int MAXN=5e5+5;
const ll INF=1e18;
ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int ptf[50],lpt;
void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	ptf[lpt=1]=x%10;
	while(x>9)x/=10,ptf[++lpt]=x%10;
	while(lpt)putchar(ptf[lpt--]^48);
	if(c>0)putchar(c);
}
int n,m,k;
int du[MAXN];
set<int>G[MAXN],D[MAXN];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		if(du[u]==1)k--;
		du[u]++;
		if(du[u]==1)k++;
		G[v].insert(u);
	}
	for(int Q=read();Q--;){
		int op=read();
		if(op==1){
			int u=read(),v=read();
			if(G[v].count(u)){
				if(du[u]==1)k--;
				du[u]--;
				if(du[u]==1)k++;
				G[v].erase(u),D[v].insert(u);
			}
		}else if(op==3){
			int u=read(),v=read();
			if(D[v].count(u)){
				if(du[u]==1)k--;
				du[u]++;
				if(du[u]==1)k++;
				D[v].erase(u),G[v].insert(u);
			}
		}else if(op==2){
			int v=read();
			for(int u:G[v]){
				if(du[u]==1)k--;
				du[u]--;
				if(du[u]==1)k++;
				D[v].insert(u);
			}G[v].clear();
		}else if(op==4){
			int v=read();
			for(int u:D[v]){
				if(du[u]==1)k--;
				du[u]++;
				if(du[u]==1)k++;
				G[v].insert(u);
			}D[v].clear();
		}
		printf(k==n?"YES\n":"NO\n");
	}
	return 0;
}
