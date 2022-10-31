/*
50 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,q,u,v,p,num[N],now;
map<int,int> c[N],f[N];
signed main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	while(m--){
		scanf("%d %d",&u,&v);
		c[u][v]=f[u][v]=1;
		num[u]++;
	}
	for(int i=1;i<=n;i++){
		if(num[i]==1){
			now++;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&p);
		if(p==1){
			scanf("%d %d",&u,&v);
			f[u][v]=0;
			if(num[u]==2){
				now++;
			}
			if(num[u]==1){
				now--;
			}
			num[u]--;
		}
		else if(p==2){
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				if(f[i][u]==1){
					if(num[i]==2){
						now++;
					}
					if(num[i]==1){
						now--;
					}
					num[i]--;
				}
				f[i][u]=0;
			}
		}
		else if(p==3){
			scanf("%d %d",&u,&v);
			f[u][v]=1;
			if(num[u]==0){
				now++;
			}
			if(num[u]==1){
				now--;
			}
			num[u]++;
		}
		else if(p==4){
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				if(c[i][u]==1&&f[i][u]==0){
					if(num[i]==0){
						now++;
					}
					if(num[i]==1){
						now--;
					}
					num[i]++;
				}
				f[i][u]=c[i][u];
			}
		}
		if(now==n){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
