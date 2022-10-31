#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1){
			if(b[l2]>=0){
				int p=1000000005;
				for(int j=l2;j<=r2;j++){
					p=min(p,b[j]);
				}
				cout<<a[l1]*p<<endl;
			}
			else{
				int p=-1000000005;
				for(int j=l2;j<=r2;j++){
					p=max(p,b[j]);
				}
				cout<<a[l1]*p<<endl;
			}
		}
		else if(l2==r2){
			if(b[l2]>=0){
				int p=-1000000005;
				for(int j=l1;j<=r1;j++){
					p=max(p,a[j]);
				}
				cout<<p*b[l2]<<endl;
			}
			else{
				int p=1000000005;
				for(int j=l1;j<=r1;j++){
					p=min(p,a[j]);
				}
				cout<<p*b[l2]<<endl;
			}
		}
		else{
			int p1=-1000000005,p2=1000000005;
			for(int j=l1;j<=r1;j++){
				p1=max(p1,a[j]);
			}
			for(int j=l2;j<=r2;j++){
				p2=min(p2,b[j]);
			}
			cout<<p1*p2<<endl;
		}
	}
	return 0;
}
