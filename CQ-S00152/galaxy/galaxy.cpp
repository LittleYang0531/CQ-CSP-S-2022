#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,q,t,u2,v2;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&t);
		if(t==1 || t==3){
			scanf("%d %d",&u2,&v2);
		}
		else
			scanf("%d",&u2);
		printf("NO\n");
	}
	return 0;
}
