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

long long n,m,q;
long long a[N],b[N],c[10005][10005];
long long mn[N];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=m;i++)
		cin>>b[i];
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	while(q--){
		long long l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		for(long long i=0;i<N;i++)
			mn[i]=9223372036854775807;
		long long ans=-9223372036854775807;
		for(long long i=l1;i<=r1;i++){
			for(long long j=l2;j<=r2;j++){
				mn[i]=min(c[i][j],mn[i]);
			}
		}
		for(long long i=l1;i<=r1;i++)
			ans=max(ans,mn[i]);
		cout<<ans<<"\n";
	}
}
