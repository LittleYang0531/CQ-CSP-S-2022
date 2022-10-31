#include<bits/stdc++.h>
using namespace std;
long long n,m,q,vis[1050][1050];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++){
		long long fr,to;
		scanf("%lld%lld",&fr,&to);
		vis[fr][to]=1;
	}
	for(int i=1;i<=q;i++){
		long long op;
		scanf("%lld",&op);
		if(op==1){
			long long fr,to;
			scanf("%lld%lld",&fr,&to);
			if(vis[fr][to]){
				vis[fr][to]=2;
			}
		}else{
			if(op==2){
				long long u;
				scanf("%lld",&u);
				for(int i=1;i<=n;i++){
					if(vis[i][u]){
						vis[i][u]=2;
					}
				}
			}else{
				if(op==3){
					long long fr,to;
					scanf("%lld%lld",&fr,&to);
					if(vis[fr][to]){
						vis[fr][to]=1;
					}
				}else{
					long long u;
					scanf("%lld",&u);
					for(int i=1;i<=n;i++){
						if(vis[i][u]){
							vis[i][u]=1;
						}
					}
				}
			}
		}
		printf("NO\n");//No time to continue to finish this problem
//		for(int i=1;i<=n;i++){
//			long long num=0;
//			for(int j=1;j<=n;j++){
//				
//			}
//		}
	}
	return 0;
}

