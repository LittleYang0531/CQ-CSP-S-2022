#include<bits/stdc++.h>
using namespace std;
long long int n,Q,kq,v[20000],a,b,mina,fys[10000][10000];
bool fs[10000][10000][4],fes[10000][10000];
long long int Min(long long int a,long long int b){
	return a<b?a:b;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&Q,&kq);
	for(int i = 1;i <= n;i++)
		scanf("%lld",&v[i]);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			fys[i][j] = 1000000;
	for(int i = 1;i < n;i++){
		scanf("%lld%lld",&a,&b);
		fes[a][b] = fes[b][a] = fs[a][b][1] = fs[b][a][1] = 1;
		fys[a][b] = fys[b][a] = v[a]+v[b];
	}
	for(int k = 2;k <= kq;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j)
					if(fs[i][j][k-1])
						for(int l = 1;l <= n;l++)
							if(l!=i && l!=j)
								if(fs[j][l][1]){
									fes[i][l] = fes[l][i] = fs[l][i][k] = fs[i][l][k] = 1;
									fys[i][l] = fys[l][i] = v[i]+v[l];
								}				
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			for(int k = 1;k <= n;k++)
				if(i!=k && j!=k && i!=j){
					if(fes[i][k]==1 && fes[k][j]==1){
						fys[i][j] = Min(fys[i][j],fys[i][k]+fys[k][j]-v[k]);
						fes[i][j] = 1;
					}
				}
	while(Q--){
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",fys[a][b]);
	}
	return 0;
} 
