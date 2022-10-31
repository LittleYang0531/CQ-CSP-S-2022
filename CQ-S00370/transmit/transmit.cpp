#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,k,nxt[400010],to[400010],tot,h[200010],f[200010][19],dep[200010];
ll v[200010],dis[200010];
void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	dis[x]=dis[fa]+v[x];f[x][0]=fa;
	for(int i=1;i<=18;++i)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=nxt[i]){
		int y=to[i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;--i)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=18;~i;--i)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void f1(){
	for(int i=1;i<=n;++i)cin>>v[i];
	for(int i=1,x,y;i<n;++i)cin>>x>>y,add(x,y),add(y,x);
	dfs(1,0);
	while(q--){
		int x,y,l;
		cin>>x>>y;
		l=lca(x,y);
		cout<<dis[x]+dis[y]-2*dis[l]+v[l]<<'\n';
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q>>k;
	if(k==1)f1();
	return 0;
}
/*
7 3 1
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2
*/
/*
1.调试后打开freopen
2.注意开long long
3.最后5分钟不要敲代码，编译运行并使用文件输入输出
16pts
*/
