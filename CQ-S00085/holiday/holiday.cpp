#include<bits/stdc++.h>
using namespace std;
const int Maxn = 2e4+5;
long long s[2505],p[Maxn>>1],n,m,k,ans,sum;
int to[Maxn],nxt[Maxn],head[Maxn],vis[Maxn],tot;
void add(int a,int b){to[++tot]=b,nxt[tot]=head[a],head[a]=tot;}
bool pd(int x,int z)
{
	if(p[x]!=-1) return p[x];
	for(int i=head[x];i;i=nxt[i]){
	  if(i==1) return p[x]=1;
	  else if(z<k) pd(to[i],z+1);
	}
	return p[x]=0;
}
void dfs(int x,int dep,int z)
{
	if(dep==5){
	  if(sum>ans&&(k==0||to[x]==1||pd(x,0))) ans=sum;
	  return ;
	}
	for(int i=head[x];i;i=nxt[i]){
	  int v=to[i];
	  if(!vis[v]){
	  	vis[v]=1,sum+=s[v];
	  	dfs(v,dep+1,0);
	  	vis[v]=0,sum-=s[v];
	  }
	  if(z<k){
	  	dfs(v,dep,z+1);
	  }
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) cin>>s[i];
	for(int i=1;i<=m;i++){
	  int a,b;
	  cin>>a>>b;
	  add(a,b);add(b,a);
	}
	memset(p,-1,sizeof p);
	vis[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
