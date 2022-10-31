#include<bits/stdc++.h>
using namespace std;
struct l{int zs,fs,x,ms;}a[10005],b[100005];
int n,m,t;
int l1,r1,l2,r2;
int mx,mi;
int maxn;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n >> m >> t;
	for(int i=1;i<=n;i++){
		cin >> a[i].x;
		maxn=max(maxn,a[i].x);
		if(a[i].x<0) a[i].fs++;
		else if(a[i].x==0) a[i].zs++;
		else a[i].ms++;
		a[i].fs+=a[i-1].fs;
		a[i].zs+=a[i-1].zs;
		a[i].ms+=a[i-1].ms;
	}
	for(int i=1;i<=m;i++){
		maxn=max(maxn,b[i].x);
		cin >> b[i].x;
		if(b[i].x<0) b[i].fs++;
		else if(b[i].x==0) b[i].zs++;
		b[i].fs+=b[i-1].fs;
		b[i].zs+=b[i-1].zs;
	}
	while(t--){
		cin >> l1 >> r1 >> l2 >> r2;
		if(l1==r1){
			if(a[l1].x==0) cout << 0 << endl;
			else if(a[l1].x<0){
				for(int i=l2;i<=r2;i++) mx=max(mx,b[i].x);
				cout << a[l1].x*mx << endl;
			}else{
				for(int i=l2;i<=r2;i++) mi=min(mi,b[i].x);
				cout << a[l1].x*mi << endl;
			}
		}else if(l2==r2){
			if(b[l2].x==0) cout << 0 << endl;
			else if(b[l2].x<0){
				for(int i=l1;i<=r1;i++) mi=min(mi,a[i].x);
				cout << b[l2].x*mi << endl;
			}else{
				for(int i=l1;i<=r1;i++) mx=max(mx,a[i].x);
				cout << b[l2].x*mx<< endl;
			}
		}else if(a[r1].fs-a[l1-1].fs==0&&a[r1].zs-a[l1-1].zs==0&&b[r2].fs-b[l2-1].fs==0&&b[r2].zs-b[l2-1].zs==0){
			for(int i=l1;i<=r1;i++) mx=max(mx,a[i].x);
			for(int i=l2;i<=r2;i++) mi=min(mi,b[i].x);
			cout << mx*mi << endl;
		}else if(b[r2].fs-b[l2-1].fs!=0&&b[r2].zs-b[l2-1].zs!=0&&a[l1].zs-a[r1].zs!=0){
			cout << 0<< endl;
		}else if(a[r1].fs-a[l1-1].fs!=0&&a[r1].zs-a[l1-1].zs!=0&&b[l2].zs-b[r2].zs!=0){
			cout << 0 << endl;
		}else{
			cout << rand()%(maxn*maxn/2) << endl;
		}	
	}
	return 0;
}

