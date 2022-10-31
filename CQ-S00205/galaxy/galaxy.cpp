#include<bits/stdc++.h>
#define N 1000005

using namespace std;
int n,m,Q,f[1010][1010],s[1010],vis[1010];
set<int> st[1010];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;memset(f,-1,sizeof(f));
	for(int i=1,uu,vv;i<=m;i++){
		scanf("%d%d",&uu,&vv);
		f[uu][vv]=1;s[uu]++;
		st[uu].insert(vv);
	}
	cin>>Q;
	for(int opt,u,v;Q;Q--){
		scanf("%d%d",&opt,&u);
		if(opt&1){
			scanf("%d",&v);
			f[u][v]=opt>>1;
			if(opt==1) s[u]--,st[u].erase(v);
			else s[u]++,st[u].insert(v);
		}
		else{
			for(int i=1;i<=n;i++){
				if(opt==2){
					if(f[i][u]==1)s[i]--,st[i].erase(u);
				}else{
					if(f[i][u]==0)s[i]++,st[i].insert(u);
				}
				if(f[i][u]!=-1)f[i][u]=opt>>2;
			}
		}
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(st[i].size()!=1){flag=0;break;}
		}
//		if(flag){
//			memset(vis,0,sizeof(vis));
//			for(int i=1;i<=n;i++){
//				if(!vis[i]){
//					int th=i;
//					while(1){
//						if(vis[th]==1) break;
//						vis[th]=1;
//						if(st[th].begin()==st[tth].end())
//						th=st[th].begin();
//					}
//				}
//			}
//		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
