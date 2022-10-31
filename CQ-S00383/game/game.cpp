#include<cstdio>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
typedef long long  ll;
int n,m,k;
int arr[100005],brr[100005];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
struct Subtree{
	bool zero;
	int max_z,min_z,max_f,min_f;
	Subtree(){
		zero=false;
		max_z=0,min_z=0x3f3f3f3f,max_f=-0x3f3f3f3f,min_f=0;
	}
	Subtree operator +(const Subtree& that)const{
		Subtree res;
		res.max_f=max(max_f,that.max_f);
		res.min_f=min(min_f,that.min_f);
		res.max_z=max(max_z,that.max_z);
		res.min_z=min(min_z,that.min_z);
		res.zero=zero|that.zero;
		return res;
	}
}Treea[400006],Treeb[400006];
void builda(int rt,int l,int r){
	if(l==r){
		if(arr[l]>0)Treea[rt].max_z=arr[l],Treea[rt].min_z=arr[l];
		else if(arr[l]==0)Treea[rt].zero=true;
		else Treea[rt].max_f=arr[l],Treea[rt].min_f=arr[l];
		return;
	}
	int m=(l+r)>>1;
	builda(ls,l,m),builda(rs,m+1,r);
	Treea[rt]=Treea[ls]+Treea[rs];
}
Subtree aska(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R)return Treea[rt];
	int m=(l+r)>>1;
	Subtree res;
	if(m>=L)res=res+aska(ls,l,m,L,R);
	if(m<R) res=res+aska(rs,m+1,r,L,R);
	return res;
}
void buildb(int rt,int l,int r){
	if(l==r){
		if(brr[l]>0)Treeb[rt].max_z=brr[l],Treeb[rt].min_z=brr[l];
		else if(brr[l]==0)Treeb[rt].zero=true;
		else Treeb[rt].min_f=brr[l],Treeb[rt].max_f=brr[l];
		return;
	}
	int m=(l+r)>>1;
	buildb(ls,l,m),buildb(rs,m+1,r);
	Treeb[rt]=Treeb[ls]+Treeb[rs];
}
Subtree askb(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R)return Treeb[rt];
	int m=(l+r)>>1;
	Subtree res;
	if(m>=L)res=res+askb(ls,l,m,L,R);
	if(m<R) res=res+askb(rs,m+1,r,L,R);
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
	for(int i=1;i<=m;i++)scanf("%d",&brr[i]);
	builda(1,1,n);
	buildb(1,1,m);
	while(k--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		Subtree a=aska(1,1,n,l1,r1);
		Subtree b=askb(1,1,m,l2,r2);
		int maxn=-0x3f3f3f3f,minn=0x3f3f3f3f;
		if(b.max_z!=0)maxn=b.max_z;else if(b.zero)maxn=0;else maxn=b.max_f;
		if(b.min_f!=0)minn=b.min_f;else if(b.zero)minn=0;else minn=b.min_z;
		if(maxn>0&&minn>0){
			if(a.max_z!=0)printf("%lld\n",(ll)a.max_z*minn);
			else if(a.zero)printf("%lld\n",0ll);
			else printf("%lld\n",(ll)a.max_f*maxn);
		}else if(maxn>0&&minn==0){
			if(a.max_z!=0)printf("%lld\n",0ll);
			else if(a.zero)printf("%lld\n",0ll);
			else printf("%lld\n",(ll)a.max_f*maxn);
		}
		else if(maxn>0&&minn<0){
			if(a.zero)printf("%lld\n",0ll);
			else{
				long long x=-0x3f3f3f3f3f3f3f3f,y=-0x3f3f3f3f3f3f3f3f;
				if(a.min_z!=0x3f3f3f3f)x=(ll)a.min_z*minn;
				if(a.max_f!=-0x3f3f3f3f)y=(ll)a.max_f*maxn;
				printf("%lld\n",x>y?x:y);
			}
		}//
		else if(maxn==0&&minn==0)printf("%lld\n",0ll);
		else if(maxn==0&&minn<0){
			if(a.min_f!=0)printf("%lld\n",0ll);
			else if(a.zero)printf("%lld\n",0ll);
			else printf("%lld\n",(ll)a.min_z*minn);
		}
		else if(maxn<0&&minn<0){
			if(a.min_f!=0)printf("%lld\n",(ll)a.min_f*maxn);
			else if(a.zero)printf("%lld\n",0ll);
			else printf("%lld\n",(ll)a.min_z*minn);
		}
	}
	return 0;
}
