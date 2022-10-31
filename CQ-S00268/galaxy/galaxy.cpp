#include<bits/stdc++.h>
#define l1 long long
using namespace std;
const l1 N=6e5+10;
l1 n,m,q;
struct node{
	l1 x,y,next;
	bool p;
}e[N*2];
l1 r[N],c[N];
l1 elast[N];
bool check(l1 x){
	for(l1 i=elast[x];i;i=e[i].next){
		l1 v=e[i].y;
		for(l1 j=elast[v];j;j=e[j].next){
			if(x==e[j].y) return false;
		}
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(l1 i=1;i<=m;i++){
		scanf("%lld %lld",&e[i].x,&e[i].y);
		e[i].p=true;
		e[i].next=elast[e[i].x];
		elast[e[i].x]=i;
		r[e[i].y]++;
		c[e[i].x]++;
	}
	scanf("%lld",&q);
	while(q--){
		l1 t;
		scanf("%lld",&t);
		if(t==1){
			l1 u,v;
			scanf("%lld %lld",&u,&v);
			c[u]--;
			r[v]--;
			for(l1 i=elast[u];i;i=e[i].next){
				l1 j=e[i].y;
				if(j==v){
					e[i].p=false;
					break;
				}
			}
		}else if(t==2){
			l1 u;
			scanf("%lld",&u);
			c[u]=0;
			for(l1 i=elast[u];i;i=e[i].next){
				l1 j=e[i].y;
				r[j]--;
				e[i].p=false;
			}
		}else if(t==3){
			l1 u,v;
			scanf("%lld %lld",&u,&v);
			c[u]++;
			r[v]++;
			for(l1 i=elast[u];i;i=e[i].next){
				l1 j=e[i].y;
				if(j==v){
					e[i].p=true;
					break;
				}
			}
		}else if(t==4){
			l1 u;
			scanf("%lld",&u);
			for(l1 i=elast[u];i;i=e[i].next){
				l1 j=e[i].y;
				c[u]++;
				r[j]++;
				e[i].p=true;
			}
		} 
		bool cnt1=true,cnt2=true;
		for(l1 i=1;i<=n;i++){
			if(c[i]!=1){
				cnt1=false;
				break;
			}
		}
		for(l1 i=1;i<=n;i++){
			if(check(i)){
				cnt2=false;
				break;
			}
		}		
		if(cnt1&&cnt2) printf("YES\n");
		else printf("NO\n");
	} 
	return 0; 
} 
