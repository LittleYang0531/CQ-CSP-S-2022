#include<bits/stdc++.h>
#define l1 long long
using namespace std;
const l1 N=1e5+10;
l1 n,m,k;
l1 a[N];
l1 d[N],dis[N],ans;
struct node{
	l1 x,y,next;
}e[N*2];
l1 elast[N];
void dfs(l1 u,l1 fa){
	d[u]=d[fa]+1;
	dis[u]=max(dis[u],dis[fa]+a[u]);
	for(l1 i=elast[u];i;i=e[i].next){
		l1 v=e[i].y;
		if(v!=fa&&v!=1){
			dfs(v,u);
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(l1 i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(l1 i=1,j=1;i<=m;i++){
		l1 x,y;
		scanf("%lld %lld",&x,&y);
		e[j].x=x;
		e[j].y=y;
		e[j].next=elast[x];
		elast[x]=j++;
	}
	dfs(1,0);
	for(l1 i=1;i<=n;i++){
		for(l1 j=1;j<=n;j++){
			if(abs(d[i]-d[j])<=k*4){
				ans=max(abs(dis[i]-dis[j-1]),ans);
			}
		}
	}
	printf("%lld",ans);
	return 0; 
} /*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
