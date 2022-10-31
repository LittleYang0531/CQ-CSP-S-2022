#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long read_long(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,q,k,G[2001][2001][5];
long long dis[2001][2001],c[2001];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	scanf("%d%d%d",&n,&q,&k);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) c[i]=dis[i][i]=read_long();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		dis[u][v]=dis[v][u]=c[u]+c[v];
		G[u][v][1]=G[v][u][1]=1;
	}
	for(int p=2;p<=k;p++){
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(G[i][l][p-1]&&G[l][j][1]){
						G[i][j][p]=1;
						dis[i][j]=c[i]+c[j];
					}
				}
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]-c[l]);
		}
	}
	while(q--){
		int u=read(),v=read();
		printf("%lld\n",dis[u][v]);
	}
	return 0;
}
