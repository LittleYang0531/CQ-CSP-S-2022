#include<bits/stdc++.h>
#define LL long long
#define Max(x,y) (x<y?y:x)
#define Min(x,y) (x<y?x:y)
#define LLF (1e18+10)
using namespace std;
int n,q,k;
LL mon[5005];
int dis[5005][5005];
/*
int t[200005],las[200005],fir[2505],num;
void add(int u,int v){
	t[++num]=v;
	las[num]=fir[u];
	fir[u]=num;
}*/
void sto_JLY_orz(){
	
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][l]+dis[l][j]){
					dis[j][i]=dis[i][j]=dis[i][l]+dis[l][j];
//					add(i,j);
				}
			}
		}
	}
}
LL ds[5005][5005];
void sto_HD_orz(){
	memset(ds,63,sizeof ds);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=k){
				ds[i][j]=ds[j][i]=mon[i]+mon[j];
			}
		}
		ds[i][i]=0;
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			if(l == i)continue;
			for(int j=1;j<=n;j++){
				if(i == j||j == l)continue;
				ds[j][i]=ds[i][j]=min(ds[i][j],ds[i][l]+ds[l][j]-mon[l]);

			}
		}
	}
}
void sto_YXY_orz(){
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",ds[x][y]);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	memset(dis,63,sizeof dis);
	for(int i=1;i<=n;i++){
		scanf("%lld",&mon[i]);
		dis[i][i]=0;	
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		dis[x][y]=dis[y][x]=1;
//		add(x,y);
	}
	sto_JLY_orz();
	sto_HD_orz();
	sto_YXY_orz();
	return 0;
}
/*
ÊÇÒ»¿ÅÊ÷ 
*/ 
