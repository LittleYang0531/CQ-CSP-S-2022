#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2][100005];
int n[2];
bool zero[2][100005][21];
//真正的大小
ll sz[2][100005][21], sf[2][100005][21];
ll bz[2][100005][21], bf[2][100005][21];
int lg[100005];
void upd(ll &x, ll y) {
	if(!x&&y) x=y;
}
int main() {
//	cout << sizeof(sz)/1024.0/1024;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int q;
	scanf("%d%d%d", &n[0], &n[1], &q);
	for(int i=1; i<=n[0]; ++i) {
		scanf("%lld", &a[0][i]);
	}
	for(int i=1; i<=n[1]; ++i) {
		scanf("%lld", &a[1][i]);
	}
	for(int i=1, j=0; i<=100000; ++i) {
		while(i>=(1<<(j+1))) ++j;
		lg[i]=j;
	}
	memset(zero, -1, sizeof(zero));
	memset(sz, 0, sizeof(sz));
	memset(sf, 0, sizeof(sf));
	memset(bz, 0, sizeof(bz));
	memset(sz, 0, sizeof(sz));
	for(int k=0; k<=1; ++k) {
		for(int i=1; i<=n[k]; ++i) {
			if(a[k][i]==0) {
				zero[k][i][0]=1;
				sz[k][i][0]=sf[k][i][0]=bz[k][i][0]=bf[k][i][0]=0;
			} else {
				zero[k][i][0]=0;
				if(a[k][i]>0) {
					sz[k][i][0]=bz[k][i][0]=a[k][i];
					sf[k][i][0]=bf[k][i][0]=0;
				} else {
					sf[k][i][0]=bf[k][i][0]=a[k][i];
					sz[k][i][0]=bz[k][i][0]=0;
				}
			}
//			if(!k) printf("%d %d %lld\n", i, 0, sz[k][i][0]);
		}
		for(int j=1; j<=20; ++j) {
			for(int i=1; i+(1<<(j-1))<=n[k]; ++i) {
				zero[k][i][j]=zero[k][i][j-1]|zero[k][i+(1<<(j-1))][j-1];

				upd(sz[k][i][j], sz[k][i][j-1]);
				upd(sz[k][i][j], sz[k][i+(1<<(j-1))][j-1]);
				if(sz[k][i+(1<<(j-1))][j-1]) {
					sz[k][i][j]=min(sz[k][i][j], sz[k][i+(1<<(j-1))][j-1]);
				}
				
				upd(sf[k][i][j], sf[k][i][j-1]);
				upd(sf[k][i][j], sf[k][i+(1<<(j-1))][j-1]);
				if(sf[k][i+(1<<(j-1))][j-1]) {
					sf[k][i][j]=min(sf[k][i][j], sf[k][i+(1<<(j-1))][j-1]);
				}

				upd(bz[k][i][j], bz[k][i][j-1]);
				upd(bz[k][i][j], bz[k][i+(1<<(j-1))][j-1]);
				if(bz[k][i+(1<<(j-1))][j-1]) {
					bz[k][i][j]=max(bz[k][i][j], bz[k][i+(1<<(j-1))][j-1]);
				}

				upd(bf[k][i][j], bf[k][i][j-1]);
				upd(bf[k][i][j], bf[k][i+(1<<(j-1))][j-1]);
				if(bf[k][i+(1<<(j-1))][j-1]) {
					bf[k][i][j]=max(bf[k][i][j], bf[k][i+(1<<(j-1))][j-1]);
				}
			}
		}
	}
	while(q--) {
		int al, ar, bl, br;
		scanf("%d%d%d%d", &al, &ar, &bl, &br);
		ll asz, bsz, asf, bsf, abz, bbz, abf, bbf, aze, bze;
		int k=lg[ar-al+1];
		asz=min(sz[0][al][k]?sz[0][al][k]:1e10, sz[0][ar-(1<<k)+1][k]?sz[0][ar-(1<<k)+1][k]:1e10);
		asf=min(sf[0][al][k], sf[0][ar-(1<<k)+1][k]);
		abz=max(bz[0][al][k], bz[0][ar-(1<<k)+1][k]);
		abf=max(bf[0][al][k]?bf[0][al][k]:-1e10, bf[0][ar-(1<<k)+1][k]?bf[0][ar-(1<<k)+1][k]:-1e10);
		aze=zero[0][al][k]|zero[0][ar-(1<<k)+1][k];

		k=lg[br-bl+1];
		bsz=min(sz[1][bl][k]?sz[1][bl][k]:1e10, sz[1][br-(1<<k)+1][k]?sz[1][br-(1<<k)+1][k]:1e10);
		bsf=min(sf[1][bl][k], sf[1][br-(1<<k)+1][k]);
		bbz=max(bz[1][bl][k], bz[1][br-(1<<k)+1][k]);
		bbf=max(bf[1][bl][k]?bf[1][bl][k]:-1e10, bf[1][br-(1<<k)+1][k]?bf[1][br-(1<<k)+1][k]:-1e10);
		bze=zero[1][bl][k]|zero[1][br-(1<<k)+1][k];

		ll ans=-6e18;
		if(aze) ans=0;
		// L 有正整
		if(abz) {
			//Q只有正整 L最大正整，Q 0/最小正整
			if(bsf==0) {
				if(bze) ans=max(ans, 0ll);
				else if(bsz!=1e10) ans=max(ans, abz*bsz);
			}
			//L取最小正整，Q取最大(min)负整
			if(bsf){
				ans=max(ans, asz*bsf);
			}
		}
		// L 有负整 
		if(asf){
			//Q只有负整，L最大（min）负整，Q最小（max）负整 
			if(bbz==0){
				if(bze) ans=max(ans, 0ll);
				else if(bbf!=-1e10) ans=max(ans, asf*bbf);
			}
			//L取最小（max）负整，Q最大正整
			if(bbz){
				ans=max(ans, abf*bbz);
			} 
		}
		
		if(bze) ans=min(ans, 0ll);
		printf("%lld\n", ans);
//		cout << asz << " " << asf << " " << abs <<
//		printf("%lld %lld %lld %lld %lld\n", asz, asf, abz, abf, aze);
	}
	return 0;
}

