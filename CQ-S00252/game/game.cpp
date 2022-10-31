//Author: Zealous_YH in CSP-S2022
//Su Chanzi & Xiaobao
//Who AKs IOI and who not?
//Who loves a person and who breaks up?
//Who gets 1= and who not?
//I, can do my best now.
#include <bits/stdc++.h>
#define ET return 0
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define fv(i,p) for(int (i)=0;(i)<(p).size();(i)++)
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define ptc putchar
#define il inline
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define il inline
#define int ll
using namespace std;
const int N=1e5+10;
int n,m,q;
int a[N],b[N];
//int f1=0,f2=0;
int l1,r1,l2,r2;
#define mid ((l+r)>>1)
struct node{
	int maxf,minf,maxz,minz,cnt0;
};
struct Segment_Tree{
	int val[N<<2],minn[N<<2],maxn[N<<2],maxf[N<<2],minf[N<<2],maxz[N<<2],minz[N<<2],cnt0[N<<2];
	void pushup(int p){
		minn[p]=min(minn[p<<1],minn[p<<1|1]);
		maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
		maxf[p]=max(maxf[p<<1],maxf[p<<1|1]);
		minf[p]=min(minf[p<<1],minf[p<<1|1]);
		maxz[p]=max(maxz[p<<1],maxz[p<<1|1]);
		minz[p]=min(minz[p<<1],minz[p<<1|1]);
		cnt0[p]=cnt0[p<<1]+cnt0[p<<1|1];
	}
	void merge(node &ans,node d){
		ans.cnt0+=d.cnt0;
		ans.maxf=max(ans.maxf,d.maxf);
		ans.minf=min(ans.minf,d.minf);
		ans.maxz=max(ans.maxz,d.maxz);
		ans.minz=min(ans.minz,d.minz);
	}
	il void build(int p,int l,int r){
		maxf[p]=LONG_LONG_MIN;
		minf[p]=0;
		maxz[p]=0;
		cnt0[p]=0;
		minz[p]=LONG_LONG_MAX;
		if(l==r){
			minn[p]=maxn[p]=val[l];
			if(val[l]<0){
				maxf[p]=val[l];
				minf[p]=val[l];
			}
			else if(val[l]>0){
				maxz[p]=val[l];
				minz[p]=val[l];
			}
			else{
				cnt0[p]=1;
			}
			return;
		}
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	il pii query(int p,int l,int r,int ml,int mr){
		if(ml<=l&&r<=mr){
			return mp(minn[p],maxn[p]);
		}
		pii ans=mp(LONG_LONG_MAX,LONG_LONG_MIN);
		if(ml<=mid){
			pii d=query(p<<1,l,mid,ml,mr);
			ans.fi=min(ans.fi,d.fi);
			ans.se=max(ans.se,d.se);
		}
		if(mid<mr){
			pii d=query(p<<1|1,mid+1,r,ml,mr);
			ans.fi=min(ans.fi,d.fi);
			ans.se=max(ans.se,d.se);
		}
		return ans;
	}
	il node queryb(int p,int l,int r,int ml,int mr){
		if(ml<=l&&r<=mr){
			return {maxf[p],minf[p],maxz[p],minz[p],cnt0[p]};
		}
		node ans={LONG_LONG_MIN,0,0,LONG_LONG_MAX,0};
		if(ml<=mid){
			node d=queryb(p<<1,l,mid,ml,mr);
			merge(ans,d);
		}
		if(mid<mr){
			node d=queryb(p<<1|1,mid+1,r,ml,mr);
			merge(ans,d);
		}
		return ans;
	}
} T1,T2;
#undef mid
void solve2(){
//	int d1[N];
	while(q--){
		int ans=LONG_LONG_MIN; 
		cin>>l1>>r1>>l2>>r2;
		node d=T1.queryb(1,1,n,l1,r1);
		int x=T2.query(1,1,m,l2,r2).fi;
		int y=T2.query(1,1,m,l2,r2).se;
		if(d.cnt0!=0){
			ans=0;
		}
		if(y>0&&d.minf!=0){
			ans=max(ans,y*d.maxf);
		}
		if(y<=0&&d.maxf!=LONG_LONG_MIN){
			ans=max(ans,y*d.minf);
		}
		if(x<=0&&d.minz!=LONG_LONG_MAX){
			ans=max(ans,x*d.minz);
		}
		if(x>0&&d.maxz!=0){
			ans=max(ans,x*d.maxz);
		}
//		cout<<d.cnt0<<","<<d.maxf<<","<<d.minf<<","<<d.maxz<<","<<d.minz<<endl;
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	fr1(i,1,n){
		cin>>a[i];
		T1.val[i]=a[i];
	}
	fr1(i,1,m){
		cin>>b[i];
		T2.val[i]=b[i];
	}
	T1.build(1,1,n);
	T2.build(1,1,m);
	solve2();
	ET;
}
//RP++
//Don't FST.
/*
10 10 1
1 2 3 4 5 6 7 8 9 10
2 3 4 5 6 7 1 2 3 7
2 4 3 6
*/

