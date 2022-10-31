#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
const long long N=1e5+10;

long long a[N];
long long n,m,k;
long long e[2550][2550],ans=-99999999,book[2550][2550];

inline void dfs(long long x,long long vaul,long long cnt){
	if(cnt==4){
		ans=max(ans,vaul);
		vaul=0;
		cnt=0;
	}
	for(long long i=1;i<=n;i++)
		if(e[x][i]>0 && !book[x][i] && !book[i][x]){
			book[x][i]=1;
			book[i][x]=1;
			dfs(x,vaul+a[x],cnt+1);
			dfs(i,vaul+a[i],cnt+1);
//			book[x][i]=0;
//			book[i][x]=0;
		}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=2;i<=n;i++)
		cin>>a[i];
	a[1]=0;
	for(long long i=1;i<=m;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	if(k==0){
		dfs(1,0,0);
		printf("%lld",ans+1);
	}else {
		dfs(1,1,0);
		printf("%lld",ans+k);
	}
 } 
