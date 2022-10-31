#include <bits/stdc++.h>
using namespace std;
int n,m,a[5005][5005],q;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u][v]=0;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int t;
		scanf("%d",&t);
		if(t==1){
			int u,v;
			scanf("%d%d",&u,&v);
			cout<<"NO"<<endl;
		}
		if(t==2){
			int u;
			scanf("%d",&u);
			cout<<"NO"<<endl;
		}
		if(t==3){
			int u,v;
			scanf("%d%d",&u,&v);
			cout<<"NO"<<endl;
		}
		if(t==4){
			int u;
			scanf("%d",&u);
			cout<<"NO"<<endl;
		}
	}
}
