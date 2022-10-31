#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q,a[100010],b[100010];
ll c[1010][1010];
namespace f1{
struct seg{
	#define ls (p<<1)
	#define rs ((p<<1)|1)
	#define mid ((l+r)>>1)
	ll tr[4010];
	void cl(){fill(tr+1,tr+4005,0x3f3f3f3f3f3f3f3f);}
	void build(int p,int l,int r,int i){
		if(l==r){
			tr[p]=c[i][l];
			return;
		}
		build(ls,l,mid,i);build(rs,mid+1,r,i);
		tr[p]=min(tr[ls],tr[rs]);
		return;
	}
	ll ask(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return tr[p];
		if(R<=mid)return ask(ls,l,mid,L,R);
		if(L>mid)return ask(rs,mid+1,r,L,R);
		return min(ask(ls,l,mid,L,mid),ask(rs,mid+1,r,mid+1,R));
	}
	#undef ls
	#undef rs
	#undef mid
}s[1010];
void f1(){
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)c[i][j]=1ll*a[i]*b[j];
		s[i].cl();
		s[i].build(1,1,n,i);
	}
	while(q--){
		int la,ra,lb,rb;ll ans=-0x3f3f3f3f3f3f3f3f;
		cin>>la>>ra>>lb>>rb;
		for(int i=la;i<=ra;++i)ans=max(ans,s[i].ask(1,1,n,lb,rb));
		cout<<ans<<'\n';
	}
	exit(0);
}
}
namespace f2{
struct seg1{
	#define ls (p<<1)
	#define rs ((p<<1)|1)
	#define mid ((l+r)>>1)
	int tr[400010];
	void cla(){fill(tr+1,tr+400005,-0x3f3f3f3f);}
	void clb(){fill(tr+1,tr+400005,0x3f3f3f3f);}
	void builda(int p,int l,int r){
		if(l==r){
			tr[p]=a[l];
			return;
		}
		builda(ls,l,mid);builda(rs,mid+1,r);
		tr[p]=max(tr[ls],tr[rs]);
		return;
	}
	void buildb(int p,int l,int r){
		if(l==r){
			tr[p]=b[l];
			return;
		}
		buildb(ls,l,mid);buildb(rs,mid+1,r);
		tr[p]=min(tr[ls],tr[rs]);
		return;
	}
	int aska(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return tr[p];
		if(R<=mid)return aska(ls,l,mid,L,R);
		if(L>mid)return aska(rs,mid+1,r,L,R);
		return max(aska(ls,l,mid,L,mid),aska(rs,mid+1,r,mid+1,R));
	}
	int askb(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return tr[p];
		if(R<=mid)return askb(ls,l,mid,L,R);
		if(L>mid)return askb(rs,mid+1,r,L,R);
		return min(askb(ls,l,mid,L,mid),askb(rs,mid+1,r,mid+1,R));
	}
	#undef ls
	#undef rs
	#undef mid
}sa,sb;
void f2(){
	sa.cla();sa.builda(1,1,n);
	sb.clb();sb.buildb(1,1,n);
	while(q--){
		int la,ra,lb,rb;
		cin>>la>>ra>>lb>>rb;
		cout<<1ll*sa.aska(1,1,n,la,ra)*sb.askb(1,1,n,lb,rb)<<'\n';
	}
	exit(0);
}
}
namespace f3{
struct seg1{
	#define ls (p<<1)
	#define rs ((p<<1)|1)
	#define mid ((l+r)>>1)
	int tra[400010],trb[400010];
	void cl(){fill(tra+1,tra+400005,-0x3f3f3f3f);fill(trb+1,trb+400005,0x3f3f3f3f);}
	void builda(int p,int l,int r){
		if(l==r){
			tra[p]=trb[p]=a[l];
			return;
		}
		builda(ls,l,mid);builda(rs,mid+1,r);
		tra[p]=max(tra[ls],tra[rs]);
		trb[p]=min(trb[ls],trb[rs]);
		return;
	}
	void buildb(int p,int l,int r){
		if(l==r){
			tra[p]=trb[p]=b[l];
			return;
		}
		buildb(ls,l,mid);buildb(rs,mid+1,r);
		tra[p]=max(tra[ls],tra[rs]);
		trb[p]=min(trb[ls],trb[rs]);
		return;
	}
	int askmx(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return tra[p];
		if(R<=mid)return askmx(ls,l,mid,L,R);
		if(L>mid)return askmx(rs,mid+1,r,L,R);
		return max(askmx(ls,l,mid,L,mid),askmx(rs,mid+1,r,mid+1,R));
	}
	int askmn(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R)return trb[p];
		if(R<=mid)return askmn(ls,l,mid,L,R);
		if(L>mid)return askmn(rs,mid+1,r,L,R);
		return min(askmn(ls,l,mid,L,mid),askmn(rs,mid+1,r,mid+1,R));
	}
	#undef ls
	#undef rs
	#undef mid
}sa,sb;
void f3(){
	sa.cl();sa.builda(1,1,n);
	sb.cl();sb.buildb(1,1,n);
	while(q--){
		int la,ra,lb,rb;
		cin>>la>>ra>>lb>>rb;
		if(la==ra){
			if(a[la]>0)cout<<sb.askmn(1,1,n,lb,rb);
			else if(a[la]==0)cout<<0;
			else cout<<sb.askmx(1,1,n,lb,rb);
		}else if(lb==rb){
			if(b[lb]>0)cout<<sa.askmx(1,1,n,la,ra);
			else if(b[lb]==0)cout<<0;
			else cout<<sa.askmn(1,1,n,la,ra);
		}
		cout<<'\n';
	}
}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	freopen("game3.in","r",stdin);
//	freopen("game3.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	if(n<=1000&&m<=1000&&q<=1000)f1::f1();
	int f=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		f|=(a[i]<=0);
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
		f|=(b[i]<=0);
	}
	if(!f)f2::f2();
	else f3::f3();
	return 0;
}
/*
1.调试后打开freopen
2.注意开long long
3.最后5分钟不要敲代码，编译运行并使用文件输入输出 
*/
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
3 3 18
2 -1 -4
-3 5 1
1 1 1 2
1 1 1 3
1 1 2 3
2 2 1 2
2 2 1 3
2 2 2 3
3 3 1 2
3 3 1 3
3 3 2 3
1 2 1 1
1 3 1 1
2 3 1 1
1 2 2 2
1 3 2 2
2 3 2 2
1 2 3 3
1 3 3 3
2 3 3 3
85pts
*/
