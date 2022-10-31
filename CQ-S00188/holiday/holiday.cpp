#include<bits/stdc++.h>
using namespace std;
int n,m,kq,a,b;
long long int ss[2505];
bool fs[2505][2505][105],fes[2505][2505];
long long int Max(long long int a,long long int b){
	return a>b?a:b;
}
long long int ans;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&kq);
	for(int i = 2;i <= n;i++)
		scanf("%lld",&ss[i]);
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&a,&b);
		fes[a][b] = fes[b][a] = fs[a][b][0] = fs[b][a][0] = 1;
	}
	for(int k = 1;k <= kq;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j) 
					if(fs[i][j][k-1])
						for(int l = 1;l <= n;l++)
							if(l!=i && l!=j)
								if(fs[j][l][0])
									fes[i][l] = fes[l][i] = fs[l][i][k] = fs[i][l][k] = 1;
	for(int i = 2;i <= n;i++)
		if(fes[1][i])
			for(int j = 2;j <= n;j++)
				if(fes[i][j] && i!=j)
					for(int k = 2;k <= n;k++)
						if(fes[j][k] && i!=k && j!=k)
							for(int l = 2;l <= n;l++)
								if(fes[k][l] && fes[l][1] && i!=l && j!=l && k!=l){
									ans = Max(ans,ss[i]+ss[j]+ss[k]+ss[l]);
								}
	printf("%lld",ans);
	return 0;
} 
