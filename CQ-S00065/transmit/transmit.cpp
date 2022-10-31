#include<bits/stdc++.h>
using namespace std;
#define maxn 2005
const long long maxk=1e2;
struct node{
	long long v,Next;
}e[maxn];
long long n,idx,dis,q,Depth,k,ork,value[maxn],head[maxn],father[maxn][32],Val[maxn][32],dep[maxn],Fa[maxn][maxk],dp[maxn][maxk],Memory[maxn];
void add(long long u,long long v);
long long Min(long long a,long long b,long long c);
void Dfs(long long u,long long fa,long long deep);
long long lowbit(long long x);
long long lca(long long u,long long v);
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
srand(time(0));
	memset(head,-1,sizeof head);
	scanf("%lld%lld%lld",&n,&dis,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&value[i]);
	for(long long i=1,a,b;i<=n-1;i++){
		scanf("%lld%lld",&a,&b);
		add(a,b);add(b,a);
	}
	if(n<=2000||k==1){
		Dfs(1,0,0);Depth=log2(Depth);
		for(long long j=1;j<=Depth;j++){
			for(long long i=1;i<=n;i++){
				father[i][j]=father[father[i][j-1]][j-1],Val[i][j]=Val[i][j-1]+Val[father[i][j-1]][j-1];
			}
		}long long s,t;
		while(q--){
			scanf("%lld%lld",&s,&t);
			printf("%lld\n",lca(s,t));
		}
	}else{
		Dfs(1,0,0);k=sqrt(Depth);
		for(long long i=1;i<=n;i++){
			for(long long j=1,nod=Fa[i][1];j<=min(k,dep[i]);nod=Fa[nod][1],j++,Fa[i][j]=nod){
				for(long long sub=1;sub<=dis;sub++){
					if(sub<=j)dp[i][j]=min(dp[i][j],dp[i][j-sub])+value[nod];
				}
			}
		}while(q--){
			long long s,t,ans=0;
			scanf("%lld%lld",&s,&t);ans=value[s]+value[t];
			if(dep[s]<dep[t])swap(s,t);
			long long num[5];num[1]=num[2]=num[3]=0;
			queue<pair<long long,long long> >q;memset(Memory,0x3f,sizeof Memory);
			q.push(make_pair(s,0));Memory[s]=0;
			while(!q.empty()){
				long long u=q.front().first,val=q.front().second;q.pop();
				if(Memory[u]<val||dep[u]>dep[t])continue;
				q.push(make_pair(Fa[u][k],dp[u][k]));q.push(make_pair(Fa[u][k-1],dp[u][k-1]));q.push(make_pair(Fa[u][k-2],dp[u][k-2]));
			}
			ans+=Memory[t];
			if(s==t){
				printf("%lld\n",ans);continue;
			}
			while(s!=t){
				long long Up=rand();
				ans+=dp[s][Up%k+1]+dp[t][Up%k+1];s=Fa[s][Up%k+1],t=Fa[t][Up%k+1];
			}
			printf("%lld\n",ans);
		}		
	}
	return 0;
}
long long Min(long long a,long long b,long long c){
	return min(a,min(b,c));
}
void add(long long u,long long v){
	e[idx].v=v,e[idx].Next=head[u];
	head[u]=idx++;
}
void Dfs(long long u,long long fa,long long deep){
	Fa[u][1]=fa;father[u][0]=fa,Val[u][0]=value[u];
	Depth=max(Depth,deep);dep[u]=deep;
	for(long long i=head[u];i!=-1;i=e[i].Next){
		if(e[i].v==fa)continue;
		Dfs(e[i].v,u,deep+1);
	}
}
long long lowbit(long long x){
	return x&(-x);
}
long long lca(long long u,long long v){
	if(dep[u]<dep[v])swap(u,v);long long ret=0;
	for(long long i=dep[u]-dep[v];i>=1;i-=lowbit(i)){
		long long up=log2(lowbit(i));
		ret+=Val[u][up];u=father[u][up];
	}
	if(u!=v){
		long long Dep=log2(dep[u]);
		for(long long i=Dep;i>=0;i--){
			if(father[u][i]==father[v][i])continue;
			ret+=Val[u][i]+Val[v][i];
			u=father[u][i],v=father[v][i];
		}
		ret+=Val[u][0]+Val[v][0];
		u=father[u][0],v=father[v][0];
	}
	return ret+value[u];
}
