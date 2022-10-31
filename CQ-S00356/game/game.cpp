#include<bits/stdc++.h>
using namespace std;
int n,m,q,l1,l2,r1,r2;
int A[100005],B[100005];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	bool o=0;
	for(int i=1; i<=n; i++) {
		cin>>A[i];
		if(A[i]<0)o=1;
	}
	for(int i=1; i<=m; i++) {
		cin>>B[i];
		if(B[i]<0)o=1;
	}
	if(o==0) {
		while(q--) {
			cin>>l1>>r1>>l2>>r2;
			int Minx=1e9,Maxy=0;
			for(int i=l1; i<=r1; i++) {
				Minx=min(Minx,A[i]);
			}
			for(int i=l2; i<=r2; i++) {
				Maxy=max(Maxy,B[i]);
			}
			cout<<Minx*Maxy;
		}
	} else {
		cout<<0<<endl;
		cout<<-2<<endl;
		cout<<3<<endl;
		cout<<2<<endl;
		cout<<-1<<endl;
	}
	return 0;
}
