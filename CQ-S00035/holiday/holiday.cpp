#include<bits/stdc++.h>
#define N 2505
using namespace std;
int n,m,k,vi[N][N],s1[N],s2[N];
long long V[N],asw,f1[N],f2[N],f3[N];
vector<int>v[N];
queue<int>q;
void bfs(int s,int vi[]) {
	vi[s]=0,q.push(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(vi[u]>k) continue;
		for(auto i:v[u]) if(vi[i]==-1) vi[i]=vi[u]+1,q.push(i);
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),memset(vi,-1,sizeof(vi));
	for(int i=2; i<=n; i++) scanf("%lld",V+i),f1[i]=f2[i]=f3[i]=-3e18;
	for(int x,y,i=1; i<=m; i++) {
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	}
	for(int i=1; i<=n; i++) bfs(i,vi[i]);
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=n; j++) if(i!=j&&vi[1][j]!=-1&&vi[i][j]!=-1) {
				if(V[j]>f1[i]) s2[i]=s1[i],s1[i]=j,f3[i]=f2[i],f2[i]=f1[i],f1[i]=V[j];
				else if(V[j]>f2[i]) s2[i]=j,f3[i]=f2[i],f2[i]=V[j];
				else if(V[j]>f3[i]) f3[i]=V[j];
			}
		f1[i]+=V[i],f2[i]+=V[i],f3[i]+=V[i];
	}
	for(int i=2; i<=n; i++) for(int j=i+1; j<=n; j++) if(vi[i][j]!=-1) {
				long long x,X,y,Y,si,sj;
				if(s1[i]==j) x=f2[i],X=f3[i],si=s2[i];
				else x=f1[i],X=f2[i],si=s1[i];
				if(s1[j]==i) y=f2[j],Y=f3[j],sj=s2[j];
				else y=f1[j],Y=f2[j],sj=s1[j];
				if(si==sj) asw=max(asw,max(x+Y,X+y));
				else asw=max(asw,x+y);
			}
	printf("%lld",asw);
	return 0;
}
