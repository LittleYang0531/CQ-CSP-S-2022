#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,q,r[1001],r1[1001],c[1001];
int mp[1001][1001];
vector<int> e[1001];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		e[u].push_back(v);
		mp[u][v]=1;
		c[u]++;
		r[v]++;
	}q=read();
	while(q--){
		int t=read();
		if(t==1){
			int u=read(),v=read();
			mp[u][v]=2;
			c[u]--;
			r[v]--;
		}
		if(t==2){
			int a=read();
			for(int i=1;i<=n;i++)
			if(mp[i][a]==1)mp[i][a]=2,c[i]--;
			r[a]=0;
		}
		if(t==3){
			int u=read(),v=read();
			mp[u][v]=1;
			r[v]++;
			c[u]++;
		}
		if(t==4){
			int a=read();
			for(int i=1;i<=n;i++)
			if(mp[i][a]==2)mp[i][a]=1,r[a]++,c[i]++;
		}
		int f=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=1){
				f=1;
				break;
			}
		}
		if(f){
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;i++)r1[i]=r[i];
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(r1[i]==0){
				q.push(i);
			}
		}
		int cnt=0;
		while(q.size()){
			int u=q.front();
			q.pop();
			cnt++;
			for(int i=0;i<(int)e[u].size();i++){
				int v=mp[u][i];
				if(mp[u][v]!=1)continue;
				r1[v]--;
				if(r1[v]==0)q.push(v);
			}
		}
		if(cnt<n){
			puts("YES");
		}else puts("NO");
	}
	return 0;
}
