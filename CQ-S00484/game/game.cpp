#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define mp make_pair
#define pii pair<ll,ll>

using namespace std;
const ll N=1e6+10;

ll q,n[2],a[2][N],zr[2][N],l[2],r[2],cnt[2],can[2][5],ans,now,mx[2];

ll mxz[2][N],mxf[2][N],mnz[2][N],mnf[2][N],bjz[2][N],bjf[2][N]; 
void pushup(ll v,ll id){
	if(bjz[id][v*2]||bjz[id][v*2+1]){
		bjz[id][v]=1;ll num=0;
		if(bjz[id][v*2])mxz[id][v]=mxz[id][v*2],mnz[id][v]=mnz[id][v*2],num++;
		if(bjz[id][v*2+1])mxz[id][v]=mxz[id][v*2+1],mnz[id][v]=mnz[id][v*2+1],num++;
		if(num==2){
			mxz[id][v]=max(mxz[id][v*2],mxz[id][v*2+1]);
			mnz[id][v]=min(mnz[id][v*2],mnz[id][v*2+1]);
		}
	}
	if(bjf[id][v*2]||bjf[id][v*2+1]){
		bjf[id][v]=1;ll num=0;
		if(bjf[id][v*2])mxf[id][v]=mxf[id][v*2],mnf[id][v]=mnf[id][v*2],num++;
		if(bjf[id][v*2+1])mxf[id][v]=mxf[id][v*2+1],mnf[id][v]=mnf[id][v*2+1],num++;
		if(num==2){
			mxf[id][v]=max(mxf[id][v*2],mxf[id][v*2+1]);
			mnf[id][v]=min(mnf[id][v*2],mnf[id][v*2+1]);
		}
	}
}
void build(ll v,ll l,ll r,ll id){
	if(l==r){
		mx[id]=max(mx[id],v);
		if(a[id][l]>0){bjz[id][v]=1;mxz[id][v]=mnz[id][v]=a[id][l];}
		if(a[id][l]<0){bjf[id][v]=1;mxf[id][v]=mnf[id][v]=a[id][l];}
		return;
	}
	ll mid=(l+r)>>1;build(v*2,l,mid,id);build(v*2+1,mid+1,r,id);pushup(v,id);
}

pii askz(ll v,ll l,ll r,ll x,ll y,ll id){
	if(!bjz[id][v]||v>mx[id])return mp(0,0);
	if(x<=l&&r<=y)return mp(mxz[id][v],mnz[id][v]);ll mid=(l+r)>>1;
	if(y<=mid||!bjz[id][v*2+1])return askz(v*2,l,mid,x,y,id);
	if(x>mid||!bjz[id][v*2])return askz(v*2+1,mid+1,r,x,y,id);
	pii xx=askz(v*2,l,mid,x,y,id),yy=askz(v*2+1,mid+1,r,x,y,id);
	if(!xx.X)return yy;if(!yy.X)return xx;
	return mp(max(xx.X,yy.X),min(xx.Y,yy.Y));
}
pii askf(ll v,ll l,ll r,ll x,ll y,ll id){
	if(!bjf[id][v]||v>mx[id])return mp(0,0);
	if(x<=l&&r<=y)return mp(mxf[id][v],mnf[id][v]);ll mid=(l+r)>>1;
	if(y<=mid||!bjf[id][v*2+1])return askf(v*2,l,mid,x,y,id);
	if(x>mid||!bjf[id][v*2])return askf(v*2+1,mid+1,r,x,y,id);
	pii xx=askf(v*2,l,mid,x,y,id),yy=askf(v*2+1,mid+1,r,x,y,id);
	if(!xx.X)return yy;if(!yy.X)return xx;
	return mp(max(xx.X,yy.X),min(xx.Y,yy.Y));
}


int main(){
	
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	cin>>n[0]>>n[1]>>q;
	for(ll az=0;az<=1;az++)for(ll i=1;i<=n[az];i++){
		cin>>a[az][i];zr[az][i]=zr[az][i-1];if(a[az][i]==0)zr[az][i]++;
	}
	build(1,1,n[0],0);build(1,1,n[1],1);
	
	while(q--){
		cin>>l[0]>>r[0]>>l[1]>>r[1];cnt[0]=cnt[1]=0;
		for(ll az=0;az<=1;az++){
			pii x=askz(1,1,n[az],l[az],r[az],az),y=askf(1,1,n[az],l[az],r[az],az);;
			if(x.X){can[az][++cnt[az]]=x.X;can[az][++cnt[az]]=x.Y;}
			if(y.X){can[az][++cnt[az]]=y.X;can[az][++cnt[az]]=y.Y;}
		}
		
		for(ll i=1;i<=cnt[0];i++){
			for(ll j=1;j<=cnt[1];j++){
				if(j==1){now=can[0][i]*can[1][j];continue;}
				now=min(now,can[0][i]*can[1][j]);
			}
			if(i==1){ans=now;continue;}
			ans=max(ans,now);
		}
		ll x=zr[0][r[0]]-zr[0][l[0]-1],y=zr[1][r[1]]-zr[1][l[1]-1];
		if(x)ans=max(ans,0ll);if(y)ans=min(ans,0ll);cout<<ans<<"\n"; 
	}
	
	return 0;
}
//(/>w<)/fw
