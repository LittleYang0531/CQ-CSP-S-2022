#include<bits/stdc++.h>
using namespace std;
long long n,q,k;
long long a[2005][2005];
long long s[2005];
long long x,y;
long long b,c;
long long dfs(long long L,long long R){
	long long ans=1e18;
	if(a[L][R]>k){
		for(long long i=1;i<=n;i++){
			if(a[i][L]<=k&&a[i][R]<=k)ans=min(ans,s[i]);
		}
		if(ans==1e18){
			for(long long i=1;i<=n;i++)
				ans=min(ans,dfs(L,i)+dfs(i,R));
		}
		return ans;
	}
	return ans;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(long long i=1;i<=n;i++)scanf("%lld",&s[i]);
	memset(a,-1,sizeof(a));
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		for(int k=1;k<=n;k++)
			for(int j=1;j<=n;j++)
				if(a[i][k]!=-1&&a[k][j]!=-1)//¸¥ÂåÒÁµÂ 
					if(a[i][j]!=-1)
						a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
					else a[i][j]=a[i][k]+a[k][j];
	for(int i=1;i<=k;i++){
		scanf("%lld%lld",&b,&c);
		if(a[b][c]<=k)printf("%lld\n",s[b]+s[c]);
		else{
			long long as=dfs(b,c);
			printf("%lld\n",s[as]+s[b]+s[c]);
		}
	}
	return 0;
}

