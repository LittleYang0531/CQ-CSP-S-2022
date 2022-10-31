#include<bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+5;
long long v[Maxn],q[Maxn],n,k,Q,s,t,ans,sum,cnt;
int head[Maxn<<1],to[Maxn<<1],nxt[Maxn<<1],vis[Maxn<<1],tot;
void add(int a,int b){to[++tot]=b,nxt[tot]=head[a],head[a]=tot;}
void dfs(int x,int z)
{
	if(sum>=ans) return ;
	if(x==t){
	  if(sum+v[s]<ans) ans=sum+v[s];
	  return ;
	}
	for(int i=head[x];i;i=nxt[i]){
	  if(!vis[to[i]])
	    if(z<k){
	  	  sum+=v[to[i]],vis[to[i]]=1;
	  	  q[++cnt]=to[i];
	  	  dfs(to[i],z+1);
	  	  if(sum+v[s]==ans) q[cnt--]=0;
	  	  sum-=v[to[i]],vis[to[i]]=0;
	    }
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>Q>>k;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<n;i++){
	  int a,b;
	  cin>>a>>b;
	  add(a,b);add(b,a);
	}
	while(Q--){
	  memset(vis,0,sizeof vis);
	  ans=1e9,sum=cnt=0;
	  cin>>s>>t;
	  vis[s]=1;
	  dfs(s,0);
	  if(ans==1e9){
	  	ans=v[s]+v[t];
	  	int a=(cnt+k-1)/k;
	  	for(int i=0;i<a;i++){
	  	  sum=1e9;
	  	  for(int j=1;j<=k;j++){
	  	  	int b=i*k+j;
	  	    if(v[q[b]]<sum) sum=v[q[b]];
		  }
		  ans+=sum;
		}
	  }
	  cout<<ans<<endl;
	}
	return 0;
}
