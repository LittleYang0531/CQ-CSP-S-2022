#include<bits/stdc++.h>
//stO stO stO Orz Orz Orz¿¼Éñ£¨»®µô£©CCF±£ÓÓ 
using namespace std;
#define il inline
#define ll long long
#define N 100010
il ll read(){
	ll x=0;
	bool w=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch==45) w=0;
		ch=getchar();
	}while(ch>47&&ch<58){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return (w)?(x):(-x);
}
struct edge{
	int fr,nxt;
}a[N];
int n,m,q,d[N],tot,cd[N],rd[N],cd1[N];
bool vis[N],vis1[N];
il void lj(int l,int r){
	tot++;
	a[tot].fr=l;
	cd[l]++;
	a[tot].nxt=d[r];
	d[r]=tot;
	rd[r]++;
}
il void s1(){
	int u=read(),v=read();
	for(int i=d[v];i!=0;i=a[i].nxt){
		int ot=a[i].fr;
		if(ot==u){
			cd[u]--;
			vis[i]=1;
			rd[v]--;
			return;
		}
	}
}
il void s2(){
	int u=read();
	for(int i=d[u];i!=0;i=a[i].nxt){
		if(vis[i]==0){
			vis[i]=1;
			rd[u]--;
			cd[a[i].fr]--;
		}
	}
}
il void s3(){
	int u=read(),v=read();
	for(int i=d[v];i!=0;i=a[i].nxt){
		int ot=a[i].fr;
		if(ot==u){
			cd[u]++;
			vis[i]=0;
			rd[v]++;
			return;
		}
	}
}
il void s4(){
	int u=read();
	for(int i=d[u];i!=0;i=a[i].nxt){
		if(vis[i]==1){
			vis[i]=0;
			rd[u]++;
			cd[a[i].fr]++;
		}
	}
}
il void cs(){
	for(int i=1;i<=n;i++){
		cd1[i]=cd[i];
		vis1[i]=vis[i];
	}
}
bool TP(){
	bool t;
	int cnt=0;
	for(int j=1;j<=n;j++){
		if(cd[j]!=1) return 0;
	}
	while(cnt<n){
		t=0;
		for(int i=1;i<=n;i++){
			if(cd1[i]==0){
				for(int j=d[i];j!=0;j=a[j].nxt){
					int ot=a[j].fr;
					if(!vis1[j]){
						t=1;
						cd1[ot]--;
						vis1[j]=1;
						cnt++;
					}
				}
			}
		}
		if(!t) return 1;
	}
	return 0;
		
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	while(m--) lj(read(),read());
	q=read();
	cs();
//	if(TP()){
//		;
//	}else{
//		while(q--){
//			puts("NO");
//		}
//		return 0;
//	}
	while(q--){
		int op=read();
		if(op==1) s1();
		else if(op==2){
			s2();
			puts("NO");
			continue;
		}
		else if(op==3) s3();
		else s4();
		cs();
		if(TP()){
			puts("YES");
		}else puts("NO");
	}
	return 0;
}
