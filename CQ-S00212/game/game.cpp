#include<bits/stdc++.h>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=0;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

template <class T>
void write(T x){
	if (x<0) putchar('-'),x=-x;
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

#define ll long long

const int MAXN=1e5+5;
const int MAXM=355;
const int INF=0x3f3f3f3f;

int a[MAXN],b[MAXN];

struct Sgt{
	struct Node{
		int l,r,mx,mn;
	}t[MAXN<<2];
	void pushup(int p){
		t[p].mn=min(t[p<<1].mn,t[p<<1|1].mn);
		t[p].mx=max(t[p<<1].mx,t[p<<1|1].mx);
	}
	void build(int p,int l,int r,int *a){
		t[p].l=l;t[p].r=r;
		if (l==r){
			t[p].mn=t[p].mx=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid,a);build(p<<1|1,mid+1,r,a);
		pushup(p);
	}
	int qmin(int p,int l,int r){
		if (l<=t[p].l&&t[p].r<=r) return t[p].mn;
		int res=INF,mid=(t[p].l+t[p].r)>>1;
		if (l<=mid) res=min(res,qmin(p<<1,l,r));
		if (r>mid) res=min(res,qmin(p<<1|1,l,r));
		return res;
	}
	int qmax(int p,int l,int r){
		if (l<=t[p].l&&t[p].r<=r) return t[p].mx;
		int res=-INF,mid=(t[p].l+t[p].r)>>1;
		if (l<=mid) res=max(res,qmax(p<<1,l,r));
		if (r>mid) res=max(res,qmax(p<<1|1,l,r));
		return res;
	}
}t;

int n,m,q,len;
ll ans[MAXN];

struct Query{
	int l1,r1,l2,r2,id;
	bool operator <(const Query &x){
		if (l1/len!=x.l1/len) return l1/len<x.l1/len;
		return r1<x.r1;
	}
}Q[MAXN];

struct Block{
	int L[MAXM],R[MAXM],belong[MAXN],num[MAXM],val[MAXN],blo;
	void init(){
		blo=n/len;
		if (blo*len!=n) blo++;
		for (int i=1;i<=blo;i++){
			L[i]=R[i-1]+1;
			R[i]=min(i*len,n);
			for (int j=L[i];j<=R[i];j++) belong[j]=i;
		}
	}
	void insert(int pos,int delta){
		num[belong[pos]]+=delta;
		val[pos]+=delta;
	}
	int qmin(int l,int r){
		int p=belong[l],q=belong[r];
		if (p==q){
			for (int i=l;i<=r;i++){
				if (val[i]) return i;
			}
			return INF;
		}
		for (int i=l;i<=R[p];i++){
			if (val[i]) return i;
		}
		for (int i=p+1;i<q;i++){
			if (num[i]){
				for (int j=L[i];j<=R[i];j++){
					if (val[j]) return j;
				}
			}
		}
		for (int i=L[q];i<=r;i++){
			if (val[i]) return i;
		}
		return INF;
	}
	int qmax(int l,int r){
		int p=belong[l],q=belong[r];
		if (p==q){
			for (int i=r;i>=l;i--){
				if (val[i]) return i;
			}
			return -INF;
		}
		for (int i=r;i>=L[q];i--){
			if (val[i]) return i;
		}
		for (int i=q-1;i>=p+1;i--){
			if (num[i]){
				for (int j=R[i];j>=L[i];j--){
					if (val[j]) return j;
				}
			}
		}
		for (int i=R[p];i>=l;i--){
			if (val[i]) return i;
		}
		return -INF;
	}
}block;

void add(int pos){
	block.insert(a[pos],1);
}

void del(int pos){
	block.insert(a[pos],-1);
}

int lsh[MAXN],zero,tot;

ll query(Query x){
	int bn=t.qmin(1,x.l2,x.r2),bx=t.qmax(1,x.l2,x.r2);
	ll res=-1e18;
	if (bn<0){
		int it=block.qmin(zero,tot);
		if (it!=INF) res=max(res,1ll*(lsh[it])*bn);
	}
	else{
		if (bn==0) res=max(res,0ll);
		else{
			int it=block.qmax(zero,tot);
			if (it!=-INF&&lsh[it]>=0) res=max(res,1ll*(lsh[it])*bn);
		}
	}
	if (bx>0){
		int it=block.qmax(1,zero);
		if (it!=-INF) res=max(res,1ll*(lsh[it])*bx);
	}
	else{
		if (bx==0) res=max(res,0ll);
		else{
			int it=block.qmin(1,zero);
			if (it!=INF&&lsh[it]<=0) res=max(res,1ll*(lsh[it])*bx);
		}
	}
	return res;
}

void solve(){
	sort(Q+1,Q+1+q);
	int l=1,r=0;
	for (int i=1;i<=q;i++){		
		while(r<Q[i].r1) add(++r);
		while(Q[i].l1<l) add(--l);
		while(l<Q[i].l1) del(l++);
		while(Q[i].r1<r) del(r--);
		ans[Q[i].id]=query(Q[i]);
	}
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);read(q);
	len=sqrt(n);
	for (int i=1;i<=n;i++) read(a[i]),lsh[i]=a[i];
	lsh[n+1]=0;
	sort(lsh+1,lsh+2+n);
	tot=unique(lsh+1,lsh+2+n)-lsh-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(lsh+1,lsh+1+tot,a[i])-lsh;
	}
	zero=lower_bound(lsh+1,lsh+1+tot,0)-lsh;
	for (int i=1;i<=m;i++) read(b[i]);
	t.build(1,1,m,b);
	for (int i=1;i<=q;i++){
		read(Q[i].l1);read(Q[i].r1);read(Q[i].l2);read(Q[i].r2);
		Q[i].id=i;
	}
	solve();
	for (int i=1;i<=q;i++){
		write(ans[i]);
		putchar('\n');
	}
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

*/
