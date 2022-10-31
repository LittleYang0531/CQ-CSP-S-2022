#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=1e9+1;
void File(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
}

struct zz{
	int l,r,Max,Min;
};
struct Tree{
	zz t[400005];
	#define lc p<<1
	#define rc p<<1|1
	void Build_Tree(int p,int l,int r){
//		printf("%d %d %d\n",p,l,r);
		t[p].l=l,t[p].r=r,t[p].Max=-INF,t[p].Min=INF;
		if(l==r) return ;
		int mid=(l+r)>>1;
		Build_Tree(lc,l,mid),Build_Tree(rc,mid+1,r);;		
	}
	void Change_Tree(int p,int l,int val){
		if(t[p].l==t[p].r&&t[p].r==l) return t[p].Max=t[p].Min=val,void();
		int mid=(t[p].l+t[p].r)>>1;
		if(l<=mid) Change_Tree(lc,l,val);
		else Change_Tree(rc,l,val);
		t[p].Max=max(t[lc].Max,t[rc].Max),t[p].Min=min(t[lc].Min,t[rc].Min);
	}
	int Find_Tree_Min(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r) return t[p].Min;
		int mid=(t[p].l+t[p].r)>>1,ans=INF;
		if(l<=mid) ans=min(ans,Find_Tree_Min(lc,l,r));
		if(mid+1<=r) ans=min(ans,Find_Tree_Min(rc,l,r));
		return ans;
	}
	int Find_Tree_Max(int p,int l,int r){
		if(l<=t[p].l&&t[p].r<=r) return t[p].Max;
		int mid=(t[p].l+t[p].r)>>1,ans=-INF;
		if(l<=mid) ans=max(ans,Find_Tree_Max(lc,l,r));
		if(mid+1<=r) ans=max(ans,Find_Tree_Max(rc,l,r));
		return ans;
	}
}T[4];

int a[200005],b[200005];
int n,m,k;

int main(){
	File();cin>>n>>m>>k;
	T[0].Build_Tree(1,1,n),T[1].Build_Tree(1,1,m);
	T[2].Build_Tree(1,1,n);
	T[3].Build_Tree(1,1,n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),T[0].Change_Tree(1,i,a[i]),T[a[i]>0?2:3].Change_Tree(1,i,a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),T[1].Change_Tree(1,i,b[i]);
	
	int l1,r1,l2,r2;
	F__k:;if(!(k--)) goto ZXL;{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int Max1=T[0].Find_Tree_Max(1,l1,r1),Min1=T[0].Find_Tree_Min(1,l1,r1);
		int Max2=T[1].Find_Tree_Max(1,l2,r2),Min2=T[1].Find_Tree_Min(1,l2,r2);
//		printf("qwq::%d,%d %d,%d\n",Max1,Min1,Max2,Min2);
		if(Max1>=0&&Min1>=0){
			if(Min2<0) printf("%lld\n",1ll*Min1*Min2);
			else printf("%lld\n",1ll*Max1*Min2);
		}
		else if(Max1>=0&&Min1<0){
			if(Min2>=0) printf("%lld\n",1ll*Max1*Min2);
			else if(Max2>=0&&Min2<0){
				int Min3=T[2].Find_Tree_Min(1,l1,r1),Max3=T[3].Find_Tree_Max(1,l1,r1);
				printf("%lld\n",max(1ll*Max3*Max2,1ll*Min3*Min2));
			}
			else printf("%lld\n",1ll*Min1*Max2);
		}
		else{
			if(Max2>=0) printf("%lld\n",1ll*Max1*Max2);
			else printf("%lld\n",1ll*Min1*Max2);
		}
	}goto F__k;ZXL:;
	return 0;
}
/*
no game no life./wx
*/

