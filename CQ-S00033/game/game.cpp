#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q;
ll a[3][100010];
ll s[3][4][100010];
int seg_mx[3][500007][2];
int seg_mn[3][500007][2];
void push_up(int id,int u){
	seg_mx[id][u][1] = max(seg_mx[id][u*2][1],seg_mx[id][u*2+1][1]);
	seg_mx[id][u][0] = max(seg_mx[id][u*2][0],seg_mx[id][u*2+1][0]);
	seg_mn[id][u][1] = min(seg_mn[id][u*2][1],seg_mn[id][u*2+1][1]);
	seg_mn[id][u][0] = min(seg_mn[id][u*2][0],seg_mn[id][u*2+1][0]);
}
void build(int id,int l,int r,int u){
	if(l>r){
		seg_mx[id][u][1] = seg_mx[id][u][0] = -1e9;
		seg_mn[id][u][1] = seg_mn[id][u][0] = 1e9;
		return ;
	}
	if(l==r){
		if(a[id][l]>0){
			seg_mx[id][u][1] = a[id][l];
			seg_mx[id][u][0] = -1e9;
			seg_mn[id][u][1] = a[id][l];
			seg_mn[id][u][0] = 1e9;
		}else if(a[id][l]<0){
			seg_mx[id][u][1] = -1e9;
			seg_mx[id][u][0] = a[id][l];
			seg_mn[id][u][1] = 1e9;
			seg_mn[id][u][0] = a[id][l];
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(id,l,mid,u*2);
	build(id,mid+1,r,u*2+1);
	push_up(id,u);
}
ll query_mx_1(int id,int L,int R,int u,int l,int r){
	if(R<l || L>r) return -1e9; 
	if(l<=L && R<=r) return seg_mx[id][u][1];
	int mid=(L+R)>>1;
	return max(query_mx_1(id,L,mid,u*2,l,r),query_mx_1(id,mid+1,R,u*2+1,l,r));
}
ll query_mx_0(int id,int L,int R,int u,int l,int r){
	if(R<l || L>r) return -1e9; 
	if(l<=L && R<=r) return seg_mx[id][u][0];
	int mid=(L+R)>>1;
	return max(query_mx_0(id,L,mid,u*2,l,r),query_mx_0(id,mid+1,R,u*2+1,l,r));
}
ll query_mn_1(int id,int L,int R,int u,int l,int r){
	if(R<l || L>r) return 1e9; 
	if(l<=L && R<=r) return seg_mn[id][u][1];
	int mid=(L+R)>>1;
	return min(query_mn_1(id,L,mid,u*2,l,r),query_mn_1(id,mid+1,R,u*2+1,l,r));
}
ll query_mn_0(int id,int L,int R,int u,int l,int r){
	if(R<l || L>r) return 1e9; 
	if(l<=L && R<=r) return seg_mn[id][u][0];
	int mid=(L+R)>>1;
	return min(query_mn_0(id,L,mid,u*2,l,r),query_mn_0(id,mid+1,R,u*2+1,l,r));
}
bool ask(int id,int l,int r,char lx){
	if(lx=='+'){
		return s[id][1][r]-s[id][1][l-1];
	}else if(lx=='-'){
		return s[id][2][r]-s[id][2][l-1];
	}else{
		return s[id][3][r]-s[id][3][l-1];
	}
}
ll mx(int id,int l,int r,char lx){
	int big;
	if(id==1) big = n;
	else big = m;
	if(lx=='+'){
		return query_mx_1(id,1,big,1,l,r);
	}else{
		return query_mx_0(id,1,big,1,l,r);
	}
}
ll mn(int id,int l,int r,char lx){
	int big;
	if(id==1) big = n;
	else big = m;
	if(lx=='+'){
		return query_mn_1(id,1,big,1,l,r);
	}else{
		return query_mn_0(id,1,big,1,l,r);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		cin >> a[1][i];
	} 
	for(int i=1;i<=m;i++){
		cin >> a[2][i];
	}
	for(int id=1;id<=2;id++){
		for(int i=1;i<=n;i++){
			s[id][1][i] = s[id][1][i-1]+(a[id][i]>0);
			s[id][2][i] = s[id][2][i-1]+(a[id][i]<0);
			s[id][3][i] = s[id][3][i-1]+(a[id][i]==0);
		}
	}
	build(1,1,n,1);
	build(2,1,m,1);
	while(q--){
		int l1,r1,l2,r2;
		ll ans=-1e18;
		cin >> l1 >> r1 >> l2 >> r2;
		if(ask(1,l1,r1,'+')){
			if(ask(2,l2,r2,'-')){
				ans = 1ll*max(mn(1,l1,r1,'+')*mn(2,l2,r2,'-'),ans);
			}else{
				ans = 1ll*max(mx(1,l1,r1,'+')*mn(2,l2,r2,'+'),ans); 
			}
		}
		if(ask(1,l1,r1,'-')){
			if(ask(2,l2,r2,'+')){
				ans = 1ll*max(mx(1,l1,r1,'-')*mx(2,l2,r2,'+'),ans);
			}else{
				ans = 1ll*max(mn(1,l1,r1,'-')*mx(2,l2,r2,'-'),ans);
			}
		}
		if(ans<0){
			if(ask(1,l1,r1,'=')){
				ans=0;
			}
		}else if(ans>0){
			if(ask(2,l2,r2,'=')){
				ans=0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

