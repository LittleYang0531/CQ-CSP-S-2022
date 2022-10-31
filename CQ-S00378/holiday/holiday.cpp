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
const int MAXN=2505;
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
int n,m,k,sk[MAXN],le;
ll a[MAXN],ans;
bool cmp(int x,int y){
	if(!y)return 1;
	if(!x)return 0;
	return a[x]>a[y];
}
struct itn{
	int a[3];
	void ins(int x){
		if(cmp(x,a[0]))a[2]=a[1],a[1]=a[0],a[0]=x;
		else if(cmp(x,a[1]))a[2]=a[1],a[1]=x;
		else if(cmp(x,a[2]))a[2]=x;
	}
}f[MAXN];
int ds[MAXN][MAXN];
vector<int>G[MAXN];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read()+1;
	for(int i=2;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int x=1;x<=n;x++){
		queue<int>q;
		for(int i=1;i<=n;i++)ds[x][i]=-1;
		ds[x][x]=0,q.push(x);
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int v:G[u])if(ds[x][v]<0)
				ds[x][v]=ds[x][u]+1,q.push(v);
		}
	}
	for(int x=2;x<=n;x++)for(int i=2;i<=n;i++)
		if(i!=x&&ds[1][i]<=k&&ds[x][i]<=k)f[x].ins(i);
	for(int x=2;x<n;x++)
		for(int y=x+1;y<=n;y++)if(ds[x][y]<=k){
			for(int i=0;i<3;i++){
				int u=f[x].a[i];
				if(!u||u==y)continue;
				for(int j=0;j<3;j++){
					int v=f[y].a[j];
					if(!v||v==x||v==u)continue;
					ans=max(ans,a[x]+a[y]+a[u]+a[v]);
				}
			}
		}
	print(ans);
	return 0;
}
