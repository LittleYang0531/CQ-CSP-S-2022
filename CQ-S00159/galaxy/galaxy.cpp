#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m,q;
bool vis[1010],v[1010][1010],wk[1010][1010],in[1010];
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(wk,true,sizeof(wk));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x][y]=true;
	}
	scanf("%d",&q);
	while(q--){
		int op,u,vv;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&u,&vv);
			wk[u][vv]=false;
		}
		if(op==2){
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				wk[i][u]=false;
			}
		}
		if(op==3){
			scanf("%d%d",&u,&vv);
			wk[u][vv]=true;
		}
		if(op==4){
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				wk[i][u]=true;
			}
		}
		bool fl=false;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(v[i][j]&&wk[i][j])sum++;
			}
			if(sum!=1){
				printf("NO\n");
				fl=true;
				break;
			}
		}
		if(fl)continue;
		int sum=0;
		for(int i=1;i<=n;i++){
			fl=false;
			memset(vis,false,sizeof(vis));
			memset(in,false,sizeof(in));
			queue<int>q;
			in[i]=true;
			q.push(i);
			while(!q.empty()){
				int pos=q.front();
				q.pop();
				vis[pos]=true;
				for(int j=1;j<=n;j++){
					if(v[pos][j]&&wk[pos][j]){
						if(vis[j]){
							fl=true;
							break;
						}else{
							if(!in[j])q.push(j);
							in[j]=true;
						}
					}
				}
				if(fl)break;
			}
			if(fl)sum++;
		}
		if(sum==n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
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
