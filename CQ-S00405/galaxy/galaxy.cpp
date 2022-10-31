#include<bits/stdc++.h>
#define R register
#define MAXN 500050
using namespace std;
int n,m,q,g[MAXN],g2[MAXN];
struct ex{
	int v,id;
};
vector<int> p[MAXN];
vector<int> cl[MAXN];
inline int read(){
	int x=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){	if(ch=='-') w=-1;	ch=getchar();	}
	while(ch>='0'&&ch<='9'){ x=(x<<3)+(x<<1)+ch-'0'; ch=getchar(); }
	return x*w;
}
bitset<8002> v,v2,v3,op;
bitset<8002> h[8050];
inline void dfs(int k){
	if(op[k]){
		return;
	}
	if(v[k]) {
	//cout<<'k'<<':'<<k<<'\n'; 
		op[k]=1;
	}
	v[k]=1;
	for(int j=0;j<p[k].size();j++)
	if(!h[k][p[k][j]])
	dfs(p[k][j]);
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<=8001;i++) v2[i]=1;
	for(R int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		g[u]++,g2[v]++;
		p[u].push_back(v);
	}
	q=read();
	R int t,x,y,mi=1e8,id;
	while(q--){
		t=read();
		if(t==1){
			x=read(),y=read();
			g[x]--;
			g2[y]--;
			h[x][y]=1;
			h[y][x]=1;
		}else{
			if(t==2){
				x=read();
				g[x]-=p[x].size();
				for(int i=0;i<p[x].size();i++) g2[p[x][i]]--;
				h[x]|=v2;
			}else{
				if(t==3){
					x=read(),y=read();
					g[x]++;
					g[y]++;
					h[x][y]=0;
					h[y][x]=0;
				}else{
					x=read();
					g[x]+=p[x].size();
					for(int i=0;i<p[x].size();i++) g2[p[x][i]]++;
					h[x]&=v3;
				}
			}
		}
		id=1;
		for(int j=1;j<=n;j++){
			if(!g2[j]) continue;
			v&=v3,op&=v3;
			dfs(j);
			//cout<<op[j]<<" "<<g[j]<<'\n';
			if(!op[j]||g[j]!=1){
				puts("NO");
				id=-1;
				break;
			}
		}
		/*	for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cout<<h[i][j];
				}
				cout<<'\n';
			}*/
		if(id==1) puts("YES"); 
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/

