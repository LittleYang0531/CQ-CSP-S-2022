#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,q;
int f[N][N],out[N];
int check(){
	for(int i=1;i<=n;i++) if(out[i]!=1) return 0;
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		f[x][y]=1;
		out[x]++;
	}
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][y]=-1;
			out[x]--;
		}
		else if(op==2){
			int x;
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				if(f[i][x]==1) f[i][x]=-1,out[i]--;
			}
		}
		else if(op==3){
			int x,y;
			scanf("%d%d",&x,&y);
			f[x][y]=1;
			out[x]++;
		}
		else if(op==4){
			int x;
			scanf("%d",&x);
			for(int i=1;i<=n;i++){
				if(f[i][x]==-1) f[i][x]=1,out[i]++;
			}
		}
		if(check()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
