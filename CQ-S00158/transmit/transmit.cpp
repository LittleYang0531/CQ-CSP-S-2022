#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=2e3+5,maxn=2e5+5;

ll n,Q,k,ans,fl;
ll v[maxn];

struct node{
	int fa,len;
	int ch[maxm];
}a[maxm];

void dfs(ll s,ll t,ll sum){
	if(s==t){
		ans=min(ans,sum);
		fl=1;
		return;
	}
	if(fl==1){
		return;
	}
	if(k==1){
		dfs(a[s].fa,t,sum+v[a[s].fa]);
		for(int i=1;i<=a[s].len;i++){
			dfs(a[s].ch[i],t,sum+v[a[s].ch[i]]);
		}
	}
	else if(k==2){
		int lo=a[s].fa;
		if(lo!=0){
			dfs(lo,t,sum+v[lo]);
			if(a[lo].fa!=0){
				dfs(a[lo].fa,t,sum+v[a[lo].fa]);
			}
		}
		for(int i=1;i<=a[s].len;i++){
			int ft=a[s].ch[i];
			dfs(ft,t,sum+v[ft]);
			for(int j=1;j<=a[ft].len;j++){
				int fr=a[ft].ch[j];
				dfs(fr,t,sum+v[fr]);
			}
		}
	}
	else{
		int lo=a[s].fa;
		if(lo!=0){
			dfs(lo,t,sum+v[lo]);
			if(a[lo].fa!=0){
				int loo=a[lo].fa;
				dfs(loo,t,sum+v[a[loo].fa]);
				if(a[loo].fa!=0){
					dfs(a[loo].fa,t,sum+v[a[a[loo].fa].fa]);
				}
			}
		}
		for(int i=1;i<=a[s].len;i++){
			int ft=a[s].ch[i];
			dfs(ft,t,sum+v[ft]);
			for(int j=1;j<=a[ft].len;j++){
				int fr=a[ft].ch[j];
				dfs(fr,t,sum+v[fr]);
				for(int d=1;d<=a[fr].len;d++){
					int fq=a[fr].ch[d];
					dfs(fq,t,a[fq].ch[d]);
				}
			}
		}
	}
}

ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();
	Q=read();
	k=read();
	for(int i=1;i<=n;i++){
		v[i]=read();
	}
	for(int i=1;i<n;i++){
		ll p,q;
		p=read();
		q=read();
		a[p].fa=q;
		a[q].ch[++a[q].len]=p;
	}
	while(Q--){
		ll s,t;
		ans=0x3f3f3f3f3f3f3f3f;
		fl=0;
		s=read();
		t=read();
		dfs(s,t,0);
		printf("%d\n",ans);
	}
	return 0;
}
