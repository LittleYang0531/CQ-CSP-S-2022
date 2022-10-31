#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,K,a[2505],st[2505],ed[2505],dist[2505][2505],t[2505][2505],tt[2505][2505],ans;
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&st[i],&ed[i]);
		dist[st[i]][ed[i]]=dist[ed[i]][st[i]]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dist[i][j]--;
	}
	if(n<=20){
		for(int i1=2;i1<=n;i1++){
			for(int i2=2;i2<=n;i2++){if(i2!=i1){
				for(int i3=2;i3<=n;i3++){if(i3!=i2&&i3!=i1){
					for(int i4=2;i4<=n;i4++){if(i4!=i3&&i4!=i2&&i4!=i1){
						if(dist[1][i1]<=K&&dist[i1][i2]<=K&&dist[i2][i3]<=K&&dist[i3][i4]<=K&&dist[i4][1]<=K){
							ans=max(ans,a[i1]+a[i2]+a[i3]+a[i4]);
						}
					}}
				}}
			}}
		}
		cout<<ans;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i!=j&&dist[1][i]<=K&&dist[i][j]<=K){
				t[i][j]=a[i]+a[j];
			}
		}
	}
	for(int j=2;j<=n;j++){
		for(int i=2;i<=n;i++){
			for(int ii=2;ii<=n;ii++){if(ii!=i){
				tt[i][j]=max(tt[i][j],t[ii][j]);
			}}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i!=j&&dist[i][j]<=K){
				for(int ii=2;ii<=n;ii++){
					if(ii!=i&&ii!=j) ans=max(ans,t[ii][i]+min(tt[ii][j],tt[i][j]));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
