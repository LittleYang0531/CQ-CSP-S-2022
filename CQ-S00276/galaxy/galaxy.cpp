#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,t,e[1005][1005],cnto[500005],ans;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=1000){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			e[x][y]=1;
			cnto[x]++;
		}
		for(int i=1;i<=n;i++){
			if(cnto[i]==1){
				ans++;
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d",&t);
			if(t==1){
				scanf("%d%d",&x,&y);
				e[x][y]=2;
				if(cnto[x]==1){
					ans--;
				}
				cnto[x]--;
				if(cnto[x]==1){
					ans++;
				}
			}else if(t==2){
				scanf("%d",&x);
				for(int i=1;i<=n;i++){
					if(e[i][x]==1){
						e[i][x]=2;
						if(cnto[i]==1){
							ans--;
						}
						cnto[i]--;
						if(cnto[i]==1){
							ans++;
						}
					}
				}
			}else if(t==3){
				scanf("%d%d",&x,&y);
				e[x][y]=1;
				if(cnto[x]==1){
					ans--;
				}
				cnto[x]++;
				if(cnto[x]==1){
					ans++;
				}
			}else if(t==4){
				scanf("%d",&x);
				for(int i=1;i<=n;i++){
					if(e[i][x]==2){
						e[i][x]=1;
						if(cnto[i]==1){
							ans--;
						}
						cnto[i]++;
						if(cnto[i]==1){
							ans++;
						}
					}
				}
			}
			if(ans==n){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}else{
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			cnto[x]++;
		}
		for(int i=1;i<=n;i++){
			if(cnto[i]==1){
				ans++;
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d",&t);
			if(t==1){
				scanf("%d%d",&x,&y);
				if(cnto[x]==1){
					ans--;
				}
				cnto[x]--;
				if(cnto[x]==1){
					ans++;
				}
			}else if(t==3){
				scanf("%d%d",&x,&y);
				if(cnto[x]==1){
					ans--;
				}
				cnto[x]++;
				if(cnto[x]==1){
					ans++;
				}
			}
			if(ans==n){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
