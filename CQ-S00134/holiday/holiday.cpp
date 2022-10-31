#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int MAXN=2503,MAXN2=21;
int val[MAXN],dis[MAXN2][MAXN2];
	
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int N=read(),M=read(),K=read()+1,ans=0;
	if(N<=20){
		for(int i=2;i<=N;++i) val[i]=read();
		for(int i=1;i<=M;++i){
			int a=read(),b=read();
			dis[a][b]=dis[b][a]=1;
		}
		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i){
	//			if(i==k) continue;
				for(int j=1;j<=N;++j){
	//				if(j==k||j==i) continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}	
		}
//		int ans=0;
		for(int i=2;i<=N;++i)
			for(int j=2;j<=N;++j){
				if(i==j) continue;
				for(int k=2;k<=N;++k){
					if(j==k||k==i) continue;
					for(int l=2;l<=N;++l){
						if(l==i||l==j||l==k) continue;
						if(dis[i][j]>K||dis[j][k]>K||dis[k][l]>K||dis[l][1]>K||dis[1][i]>K) continue;
	//					printf("%lld %lld %lld %lld\n",i,j,k,l);
						ans=max(ans,val[i]+val[j]+val[k]+val[l]);
					}
				}
			}
	}
	else{
		sort(val+2,val+1+N);
		ans=val[N]+val[N-1]+val[N-2]+val[N-3];
	}
	printf("%lld\n",ans);
	return 0;
	//	for(int i=1;i<=N;++i) BFS(i);
}


