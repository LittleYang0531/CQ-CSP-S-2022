#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,a,b;
int h[2505],to[20005],nxt[20005],dis[2505][2505];
bool bl[2505];
long long s[2505],ans;
queue<int> q;
int p[2505][2505],cnt[2505];
void jb(int u,int v){
	++tot;
	to[tot]=v;
	nxt[tot]=h[u];
	h[u]=tot;
}
void bfs(int st){
	for(int i=1;i<=n;i++) bl[i]=0,dis[st][i]=1e9;
	dis[st][st]=0;
	bl[st]=1;
	q.push(st);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i!=0;i=nxt[i]){
			int v=to[i];
			if(bl[v]==0){
				dis[st][v]=dis[st][u]+1;
				bl[v]=1;
				q.push(v);
			}
		}
	}
}
bool cmp(int p1,int p2){
	return s[p1]>s[p2];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);k++;
	for(int i=2;i<=n;i++) scanf("%lld",&s[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		jb(a,b);jb(b,a);
	}
	for(int i=1;i<=n;i++) bfs(i);
	for(int j=2;j<=n;j++){
		if(dis[1][j]>k) continue;
		for(int i=2;i<=n;i++){
			if(i==j||dis[j][i]>k) continue;
			p[i][++cnt[i]]=j;
		}
	}
	for(int i=2;i<=n;i++) sort(p[i]+1,p[i]+cnt[i]+1,cmp);
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||dis[i][j]>k) continue;
			int di=1,dj=1;
			if(p[i][di]==j) di++;
			if(p[j][dj]==i) dj++;
			if(p[i][di]==p[j][dj]){
				int ei=di+1;
				if(p[i][ei]==j) ei++;
				if(ei<=cnt[i]&&dj<=cnt[j])
					ans=max(ans,s[i]+s[j]+s[p[i][ei]]+s[p[j][dj]]);
				int ej=dj+1;
				if(p[j][ej]==i) ej++;
				if(ej<=cnt[j]&&di<=cnt[i])
					ans=max(ans,s[i]+s[j]+s[p[i][ej]]+s[p[j][di]]);
			}
			else{
				if(di<=cnt[i]&&dj<=cnt[j])
					ans=max(ans,s[i]+s[j]+s[p[i][di]]+s[p[j][dj]]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
