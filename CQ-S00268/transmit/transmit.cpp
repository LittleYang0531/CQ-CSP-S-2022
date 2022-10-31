#include<bits/stdc++.h>
#define l1 long long
using namespace std;
const l1 N=2e5+10;
l1 n,q,k;
l1 a[N],inf=1e10;
struct node{
	l1 x,z,next;
	l1 y;
}e[N*2];
l1 elast[N];
l1 dis[N];
bool mark[N];
struct pqnode{
	l1 p,dis;
};
bool operator<(pqnode p,pqnode q){
	return p.dis>q.dis;
}
priority_queue<pqnode> pq;
l1 djstl(l1 l,l1 r){
	for(l1 i=1;i<=n;i++){
		dis[i]=inf;
		mark[i]=false;
	}
	dis[l]=0;
	pq.push((pqnode){l,dis[l]});
	while(!pq.empty()){
		l1 u=pq.top().p;
		pq.pop();
		if(mark[u]) continue;
		if(u==r) break;
		mark[u]=true;
		for(l1 j=elast[u];j;j=e[j].next){
			l1 v=e[j].y;
			if(dis[v]>dis[u]+e[j].z){
				dis[v]=dis[u]+e[j].z;
				pq.push((pqnode){v,dis[v]});
			}
		}
	}
	return dis[r];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&n,&q,&k);
	for(l1 i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(l1 i=1,j=1;i<=n-1;i++){
		l1 x,y;
		scanf("%lld %lld",&x,&y);
		e[j].x=x;
		e[j].y=y;
		e[j].z=1;
		e[j].next=elast[x];
		elast[x]=j++;
		e[j].x=y;
		e[j].y=x;
		e[j].z=1;
		e[j].next=elast[y];
		elast[y]=j++;
	}
	while(q--){
		l1 l,r;
		scanf("%lld %lld",&l,&r);
		bool flag=true;
		if(djstl(l,r)<=k) flag=true;
		else flag=false;
		for(l1 j=1;j<=2*n-2;j+=2){
			e[j].z=a[e[j].y];
			if(e[j].y==1||e[j].x==1) e[j].z+=a[1];
		}
		for(l1 j=2;j<=2*n-2;j+=2){
			e[j].z=a[e[j].x];
			if(e[j].y==1||e[j].x==1) e[j].z+=a[1];
		}
		if(flag){
			printf("%lld\n",djstl(l,r));
		}
		else{
			l1 ans=1e10,p;
			for(l1 i=1;i<=n;i++){
				if((djstl(l,i)+djstl(i,r))>ans){
					p=i;
				}
			}
			printf("%lld\n",a[p]+a[l]+a[r]);
		}
	}
	return 0; 
} /*
7 1 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
1 2
*/
