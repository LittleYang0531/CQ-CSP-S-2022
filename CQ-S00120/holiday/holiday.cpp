#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
vector<int>G[2510];
queue<int>q;
int go[2510][2510],dis[2510];
int fima[2510],sema[2510],thima[2510];
ll val[2510];
void bfs(int s){
	memset(dis,0x3f,sizeof(dis));
	q.push(s);dis[s]=-1;
	while(!q.empty()){
		int x=q.front();
		go[s][x]=1;
		q.pop();
		if(dis[x]>=k)continue;
		for(int to:G[x]){
			if(dis[to]<=k)continue;
			dis[to]=dis[x]+1;
			q.push(to);
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++)
	for(int j=2;j<=n;j++)
	if(i!=j&&go[i][j]&&go[1][j]){
		if(val[j]>val[fima[i]]){thima[i]=sema[i];sema[i]=fima[i];fima[i]=j;}
		else if(val[j]>val[sema[i]]){thima[i]=sema[i];sema[i]=j;}
		else if(val[j]>val[thima[i]])thima[i]=j;
	}
	ll ans=0;
	for(int B=2;B<=n;B++)
	for(int C=2;C<=n;C++)
	if(B!=C&&go[B][C]&&fima[B]&&fima[C]){
		ll sum=val[B]+val[C];
		int fib=fima[B],seb=sema[B],thb=thima[B],fic=fima[C],sec=sema[C],thc=thima[C];
		if(fib==C&&fic==B){
			if(!seb||!sec)continue;
			if(sec!=seb)ans=max(ans,sum+val[seb]+val[sec]);
			if(thb&&sec!=thb)ans=max(ans,sum+val[sec]+val[thb]);
			if(thc&&seb!=thc)ans=max(ans,sum+val[seb]+val[thc]);
			if(thb&&thc&&thc!=thb)ans=max(ans,sum+val[thc]+val[thb]);
			continue;
		}
		if(fib==C){//fic!=B
			if(!seb)continue;
			if(seb!=fic)ans=max(ans,sum+val[fic]+val[seb]);
			if(thb&&thb!=fic)ans=max(ans,sum+val[thb]+val[fic]);
			continue;
		}
		if(fic==B){//fib!=C
			if(!sec)continue;
			if(sec!=fib)ans=max(ans,sum+val[sec]+val[fib]);
			if(thc&&thc!=fib)ans=max(ans,sum+val[thc]+val[fib]);
			continue;
		}
		//fib!=C&&fic!=B
		if(fib==fic){
			if(sec&&sec!=B&&sec!=fib)ans=max(ans,val[fib]+val[sec]+sum);
			if(seb&&seb!=C&&seb!=fic)ans=max(ans,val[seb]+val[fic]+sum);
			if(thc&&thc!=B&&thc!=fib)ans=max(ans,val[fib]+val[thc]+sum);
			if(thb&&thb!=C&&thb!=fic)ans=max(ans,val[thb]+val[fic]+sum);
		}
		else ans=max(ans,val[fib]+val[fic]+sum);
	}
	printf("%lld",ans);
	return 0;
}
