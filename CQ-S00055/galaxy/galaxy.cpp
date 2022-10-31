#include<bits/stdc++.h>
using namespace std;
int N,M,Q,u,v,t;
int w[1004][1005],f[1005][1005],d[1005],k[1005];
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;++i){
		scanf("%d%d",&u,&v);
		w[u][v]=1;
		w[v][u]=1;
		f[u][v]=1;
		f[v][u]=1;
		d[u]++;
		//d[v]++;
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&u,&v);
			f[u][v]=0;
			d[u]--;
		} else if(t==2){
			scanf("%d",&u);
			for(int j=1;j<=N;++j){
				if(w[j][u]==1&&f[j][u]==1)d[j]--,f[j][u]=0;
			}
		} else if(t==3){
			scanf("%d%d",&u,&v);
			f[u][v]=1;
			d[u]++;
		} else {
			scanf("%d",&u);
			for(int j=1;j<=N;++j){
				if(w[j][u]==1&&f[j][u]==0)d[j]++,f[j][u]=1;
			}
		}
		//cout<<"a";
		int F=0;
		for(int i=1;i<=N;++i){
			if(d[i]!=1){
			//	cout<<i<<" "<<d[i]<<" ";
				F=1;
				break;
			}
		}
		if(F==1){
			printf("No\n");
		} else printf("Yes\n");
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
how bad!
*/
