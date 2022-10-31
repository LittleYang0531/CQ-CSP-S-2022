#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005];
int al,ar,bl,br;
struct node{
	int x,y,p,q;
}tree[2][400000];
node merge(node t1,node t2){
	node res;
	res.x=max(t1.x,t2.x);
	res.y=min(t1.y,t2.y);
	res.p=max(t1.p,t2.p);
	res.q=min(t1.q,t2.q);
	return res;
}
void tre(int f,int q,int l,int r){
	if(l==r){
		if(f==0){
			tree[0][q].x=tree[0][q].y=a[l];
			if(a[l]<0) tree[0][q].p=a[l],tree[0][q].q=1e9;
			else tree[0][q].q=a[l],tree[0][q].p=-1e9;
		}
		else{
			tree[1][q].x=tree[1][q].y=b[l];
			if(b[l]<0) tree[1][q].p=b[l],tree[1][q].q=1e9;
			else tree[1][q].q=b[l],tree[1][q].p=-1e9;
		}
		return;
	} 
	int mid=(l+r)/2;
	tre(f,q*2,l,mid);
	tre(f,q*2+1,mid+1,r);
	tree[f][q]=merge(tree[f][q*2],tree[f][q*2+1]);
}
node qry(int f,int q,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return tree[f][q];
	int mid=(l+r)/2;
	if(ql<=mid){
		node f1=qry(f,q*2,l,mid,ql,qr);
		if(mid<qr){
			node f2=qry(f,q*2+1,mid+1,r,ql,qr);
			return merge(f1,f2);
		}
		return f1;
	}
	return qry(f,q*2+1,mid+1,r,ql,qr);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	tre(0,1,1,n);tre(1,1,1,m);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&al,&ar,&bl,&br);
		node f1=qry(0,1,1,n,al,ar);
		node f2=qry(1,1,1,m,bl,br);
		if(f2.y>=0){
			if(f1.x>=0) printf("%lld\n",1ll*f1.x*f2.y);
			else printf("%lld\n",1ll*f1.x*f2.x);
		}
		else if(f2.x<0){
			if(f1.y<0) printf("%lld\n",1ll*f1.y*f2.x);
			else printf("%lld\n",1ll*f1.y*f2.y);
		}
		else printf("%lld\n",max(1ll*f1.p*f2.x,1ll*f1.q*f2.y));
	}
	return 0;
}
