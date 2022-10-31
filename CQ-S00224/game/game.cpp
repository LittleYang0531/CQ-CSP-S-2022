#include<bits/stdc++.h>
#include<climits>
//#define L k*2
//#define R k*2+1
using namespace std;
//一个人只有站在了悬崖边上才会真正坚强起来
//sto duanyixiu orz
//sto cool_milo orz
//sto tanyulin orz
//注意long long
//注意 (x^1) 优先级
//注意freopen
const int N=1e5+10;
const int M=4*N;
int n,m,q;
int a[N],b[N];
long long ans;

struct node{
	int posMax,posMin,negMax,negMin;
};

struct seg{
	node tr[M];
	
	void pushup(node &K,node L,node R){
		if(L.posMax<0&&R.posMax<0) K.posMax=-1;
		else K.posMax=max(L.posMax,R.posMax);

		if(L.posMin<0&&R.posMin<0) K.posMin=-1;
		else{
			K.posMin=INT_MAX;
			if(L.posMin>=0) K.posMin=min(K.posMin,L.posMin);
			if(R.posMin>=0) K.posMin=min(K.posMin,R.posMin);
		}
		
		if(L.negMax>0&&R.negMax>0) K.negMax=1;
		else{
			K.negMax=INT_MIN;
			if(L.negMax<=0) K.negMax=max(K.negMax,L.negMax);
			if(R.negMax<=0) K.negMax=max(K.negMax,R.negMax);
		}
		
		if(L.negMin>0&&R.negMin>0) K.negMin=1;
		else K.negMin=min(L.negMin,R.negMin);
	}
	
	void build(int k,int l,int r,bool mode){//1为a，0为b 
		tr[k].posMax=-1;
		tr[k].posMin=-1;
		tr[k].negMax=1;
		tr[k].negMin=1;
		if(l==r){
			int t=mode?a[l]:b[l];
			if(t>=0) tr[k].posMin=tr[k].posMax=t;
			if(t<=0) tr[k].negMin=tr[k].negMax=t;
			return;
		}
		int mid=l+(r-l)/2;
		build(k*2,l,mid,mode);
		build(k*2+1,mid+1,r,mode);
		pushup(tr[k],tr[k*2],tr[k*2+1]);
	}
	
	int queryStatus(int k,int l,int r,int x,int y){ //1全是正数 2全是负数 3有正有负 
		if(r<x||l>y){
//			############DEBUG!!!!!!!!!!!!!!!
			assert(0);
		}
		if(x<=l&&r<=y){
			int pos=0,neg=0;
			if(tr[k].posMax>=0) pos=1;
			if(tr[k].negMin<=0) neg=2;
			return pos+neg;
		}
		int mid=l+(r-l)/2;
		int lStatus=0,rStatus=0;
		if(x<=mid) lStatus=queryStatus(k*2,l,mid,x,y);
		if(mid<y) rStatus=queryStatus(k*2+1,mid+1,r,x,y);
		
		//important Check!
//		if(lStatus==rStatus) return lStatus;
//		else return lStatus+rStatus; 
		if(lStatus==3||rStatus==3) return 3;
		if(lStatus==2&&rStatus==2) return 2; 
		if(lStatus==1&&rStatus==1) return 1;
//		assert(lStatus+rStatus<=3);
		return lStatus+rStatus; 
	}
	
	node queryVal(int k,int l,int r,int x,int y){
		if(r<x||l>y){
//			############DEBUG!!!!!!!!!!!!!!!
			assert(0);
		}
		if(x<=l&&r<=y){
			return tr[k];
		}
		int mid=l+(r-l)/2;
		node res={-1,-1,1,1},lVal={-1,-1,1,1},rVal={-1,-1,1,1};
		if(x<=mid) lVal=queryVal(k*2,l,mid,x,y);
		if(mid<y) rVal=queryVal(k*2+1,mid+1,r,x,y);
		pushup(res,lVal,rVal);
		return res;
	}
	
}ta,tb;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	ta.build(1,1,n,true);
	tb.build(1,1,m,false);
	for(int i=1;i<=q;i++){
		int la,ra,lb,rb;
		scanf("%d%d%d%d",&la,&ra,&lb,&rb);
		
//		printf("___%d %d %d %d\n",la,ra,lb,rb);
		
		int statusA=ta.queryStatus(1,1,n,la,ra);
		int statusB=tb.queryStatus(1,1,m,lb,rb);
		
//		printf("## %d %d\n",statusA,statusB);
		node valA=ta.queryVal(1,1,n,la,ra);
		node valB=tb.queryVal(1,1,m,lb,rb);
//		printf("A:%d %d %d %d\n",valA.posMax,valA.posMin,valA.negMax,valA.negMin);
//		printf("B:%d %d %d %d\n",valB.posMax,valB.posMin,valB.negMax,valB.negMin);
		ans=0;
		if(statusA==1){
			if(statusB==1){
				ans=(long long)valA.posMax*valB.posMin;
			}else if(statusB==2){
				ans=(long long)valA.posMin*valB.negMin;
			}else if(statusB==3){
				ans=(long long)valA.posMin*valB.negMin;
			}
		}else if(statusA==2){
			if(statusB==1){
				ans=(long long)valA.negMax*valB.posMax;
			}else if(statusB==2){
				ans=(long long)valA.negMin*valB.negMax;
			}else if(statusB==3){
				ans=(long long)valA.negMax*valB.posMax;
			}
		}else if(statusA==3){
			if(statusB==1){
				ans=(long long)valA.posMax*valB.posMin;
			}else if(statusB==2){
				ans=(long long)valA.negMin*valB.negMax;
			}else if(statusB==3){
				ans=max((long long)valA.posMin*valB.negMin,(long long)valA.negMax*valB.posMax);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

