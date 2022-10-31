#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N,M,Q,cnt0_A[100005],cnt0_B[100005];ll A[100005],B[100005];
struct SEG{
	int cnt[400005];
	ll Max[400005],Min[400005];
	void pushup(int p){
		Max[p]=max(Max[p<<1],Max[p<<1|1]);
		Min[p]=min(Min[p<<1],Min[p<<1|1]);
		cnt[p]=cnt[p<<1]+cnt[p<<1|1];
	}
	void build(int p,int l,int r,int op){
		Max[p]=(ll)(-1e9)-1LL;Min[p]=(ll)(1e9)+1LL;cnt[p]=0;
		if(l==r){
			if(op==1||op==3){
				if(op==1){
					if(A[l]>0LL)Min[p]=Max[p]=A[l],cnt[p]=1;
				}else {
					if(A[l]<0LL)Min[p]=Max[p]=A[l],cnt[p]=1;
				}
			}else{
				if(op==2){
					if(B[l]>0LL)Min[p]=Max[p]=B[l],cnt[p]=1;
				}else{
					if(B[l]<0LL)Min[p]=Max[p]=B[l],cnt[p]=1;
				}
			}
			return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid,op);
		build(p<<1|1,mid+1,r,op);
		pushup(p);
	} 
	int getcnt(int p,int l,int r,int a,int b){
		if(a<=l&&r<=b)return cnt[p];
		int mid=l+r>>1,lcnt=0,rcnt=0;
		if(a<=mid)lcnt=getcnt(p<<1,l,mid,a,b);
		if(b>mid)rcnt=getcnt(p<<1|1,mid+1,r,a,b);
		return (lcnt+rcnt);
	}
	ll getmin(int p,int l,int r,int a,int b){
		if(a<=l&&r<=b)return Min[p];
		int mid=l+r>>1;ll lmin=(ll)(1e9)+1LL,rmin=(ll)(1e9)+1LL;
		if(a<=mid)lmin=getmin(p<<1,l,mid,a,b);
		if(b>mid)rmin=getmin(p<<1|1,mid+1,r,a,b);
		return min(lmin,rmin);
	}
	ll getmax(int p,int l,int r,int a,int b){
		if(a<=l&&r<=b)return Max[p];
		int mid=l+r>>1;ll lmax=(ll)(-1e9)-1LL,rmax=(ll)(-1e9)-1LL;
		if(a<=mid)lmax=getmax(p<<1,l,mid,a,b);
		if(b>mid)rmax=getmax(p<<1|1,mid+1,r,a,b);
		return max(lmax,rmax);
	}
}Tree1,Tree2,Tree3,Tree4;
bool vis[10],vis1[10];int tot;
ll Val[10],Val1[10];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=1;i<=N;++i)scanf("%lld",&A[i]),cnt0_A[i]=cnt0_A[i-1]+(A[i]==0LL);
    for(int i=1;i<=M;++i)scanf("%lld",&B[i]),cnt0_B[i]=cnt0_B[i-1]+(B[i]==0LL);
    Tree1.build(1,1,N,1);Tree2.build(1,1,M,2);
    Tree3.build(1,1,N,3);Tree4.build(1,1,M,4);
    while(Q--){
    	int l1,r1,l2,r2;
    	scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    	tot=5;for(int i=1;i<=tot;++i)vis[i]=vis1[i]=false;
    	if(cnt0_A[r1]-cnt0_A[l1-1]>0)vis[1]=true,Val[1]=0LL;
    	if(cnt0_B[r2]-cnt0_B[l2-1]>0)vis1[1]=true,Val1[1]=0LL;
    	if(Tree1.getcnt(1,1,N,l1,r1)>0){
    		vis[2]=vis[3]=true;
    		Val[2]=Tree1.getmax(1,1,N,l1,r1);
    		Val[3]=Tree1.getmin(1,1,N,l1,r1);
		}
		if(Tree3.getcnt(1,1,N,l1,r1)>0){
    		vis[4]=vis[5]=true;
    		Val[4]=Tree3.getmax(1,1,N,l1,r1);
    		Val[5]=Tree3.getmin(1,1,N,l1,r1);
		}
		if(Tree2.getcnt(1,1,M,l2,r2)>0){
    		vis1[2]=vis1[3]=true;
    		Val1[2]=Tree2.getmax(1,1,M,l2,r2);
    		Val1[3]=Tree2.getmin(1,1,M,l2,r2);
		}
		if(Tree4.getcnt(1,1,M,l2,r2)>0){
    		vis1[4]=vis1[5]=true;
    		Val1[4]=Tree4.getmax(1,1,M,l2,r2);
    		Val1[5]=Tree4.getmin(1,1,M,l2,r2);
		}
		ll res=(ll)(-1e18),res1;
		for(int i=1;i<=tot;++i){
			if(!vis[i])continue;
			res1=(ll)(1e18);
			for(int j=1;j<=tot;++j)if(vis[i]&&vis1[j])res1=min(res1,Val[i]*Val1[j]);
			res=max(res,res1);
		}
		printf("%lld\n",res);
	}
	return 0;
}
