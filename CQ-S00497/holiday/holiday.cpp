#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k;
ll a[2501];
int last[2501];
struct s{
	int t,to;
}nxet[10001];
int cd=1;
void lj(int x,int y){
	nxet[cd].t=last[x];
	nxet[cd].to=y;
	last[x]=cd++;
}
ll max_=0;
int fs[506];
ll hs(int l,int r,int sum,int jd){
	if(!jd)
		return sum;
	ll max_=0;
	for(int i=l;i<=min(r,l+k);i++)
		if((jd==1 && r-i<=k+1) || (r-i)/(jd-1)<=k+1)
			max_=max(max_,hs(i+1,r,sum+a[fs[i]],jd-1));
	return max_;
}
void dfs(int d,int bs){
	if(bs>5*k+5)
		return;
	if(d==1 && bs>=5)
		max_=max(max_,hs(1,bs-1,0,4));
	fs[bs]=d;
	for(int i=last[d];i;i=nxet[i].t)
		dfs(nxet[i].to,bs+1);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		lj(x,y);
		lj(y,x);
	}
	dfs(1,0);
	printf("%lld",max_);
	return 0;
}
