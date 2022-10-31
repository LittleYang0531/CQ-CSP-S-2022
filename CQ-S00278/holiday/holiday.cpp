#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,d[2505];
ll a[2505],ans;
vector<int>e[2505];
vector<int>t[2505];
bool v[2505];
struct node{
	vector<int>vis;
	ll val;
}S;
queue<node>q;
void bfs(){
	queue<int>fq;
	fq.push(1);
	while(!fq.empty()){
		int x=fq.front();
		fq.pop();
		for(auto y:e[x])
			if(!d[y]){
				d[y]=d[x]+1;
				fq.push(y);
			}
	}
	for(int i=2;i<=n;i++)
		if(d[i]<=k+1)t[1].push_back(i);
}
void dfs(int v0,int x,int dep){
	if(dep>k+1)return;
	t[v0].push_back(x);
	v[x]=1;
	for(auto y:e[x])
		if(!v[y])dfs(v0,y,dep+1);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	bfs();
	for(int i=2;i<=n;i++){
		memset(v,0,sizeof(v));
		dfs(i,i,0);
	}
	S.vis.push_back(1);
	q.push(S);
	while(!q.empty()){
		node now=q.front();
		q.pop();
		int p=now.vis.size(),x=*--now.vis.end();
		if(p==5){
			if(d[x]<=k+1)ans=max(ans,now.val);
			continue;
		}
		for(auto y:t[x]){
			bool fl=1;
			for(auto z:now.vis)
				if(y==z)fl=0;
			if(fl){
				node T=now;
				T.val+=a[y];
				T.vis.push_back(y);
				q.push(T);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
