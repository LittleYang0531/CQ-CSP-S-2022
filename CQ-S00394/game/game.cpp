#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
int n,m,q,a[N],b[N];
int st1[N][25],st2[N][25],st3[N][25],st4[N][25],st5[N][25],st6[N][25];
template<typename T>void read(T &x){
	char ch=getchar();
	int f=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=1;
		}
		ch=getchar();
	}
	x=0;
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(f){
		x=-x;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]>0){
			st1[i][0]=-INF;
			st2[i][0]=a[i];
		}else if(a[i]<0){
			st1[i][0]=a[i];
			st2[i][0]=INF;
		}else{
			st1[i][0]=st2[i][0]=0;
		}
		st5[i][0]=st6[i][0]=a[i];
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			if(j+(1<<i)-1<=n){
				st1[j][i]=max(st1[j][i-1],st1[j+(1<<(i-1))][i-1]);
				st2[j][i]=min(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
				st5[j][i]=max(st5[j][i-1],st5[j+(1<<(i-1))][i-1]);
				st6[j][i]=min(st6[j][i-1],st6[j+(1<<(i-1))][i-1]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		read(b[i]);
		st3[i][0]=st4[i][0]=b[i];
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=m;j++){
			if(j+(1<<i)-1<=m){
				st3[j][i]=max(st3[j][i-1],st3[j+(1<<(i-1))][i-1]);
				st4[j][i]=min(st4[j][i-1],st4[j+(1<<(i-1))][i-1]);
			}
		}
	}
	while(q--){
		ll res;
		int l1,r1,l2,r2;
		read(l1),read(r1),read(l2),read(r2);
		int pa=l1,pb=l2,maxb=-INF,minb=INF;
		for(int i=20;i>=0;i--){
			if(pb+(1<<i)-1<=r2){
				maxb=max(maxb,st3[pb][i]);
				minb=min(minb,st4[pb][i]);
				pb+=(1<<i);
			}
		}
		if(minb>=0){
			int va=-INF;
			for(int i=20;i>=0;i--){
				if(pa+(1<<i)-1<=r1){
					va=max(va,st5[pa][i]);
					pa+=(1<<i);
				}
			}
			if(va>0){
				res=1ll*va*minb;
			}else{
				res=1ll*va*maxb;
			}
		}else if(maxb<=0){
			int va=INF;
			for(int i=20;i>=0;i--){
				if(pa+(1<<i)-1<=r1){
					va=min(va,st6[pa][i]);
					pa+=(1<<i);
				}
			}
			if(va<0){
				res=1ll*va*maxb;
			}else{
				res=1ll*va*minb;
			}
		}else{
			int maxa=-INF,mina=INF;
			for(int i=20;i>=0;i--){
				if(pa+(1<<i)-1<=r1){
					maxa=max(maxa,st1[pa][i]);
					mina=min(mina,st2[pa][i]);
					pa+=(1<<i);
				}
			}
			res=max(1ll*maxa*maxb,1ll*mina*minb);
		}
		printf("%lld\n",res);
	}
	return 0;
}
