#include<bits/stdc++.h>
using namespace std;
const int MAXNM = 1e5+1;
int l[MAXNM],q[MAXNM],n,m,T;
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>T;
	for(int i=1; i<=n; i++)
		cin>>l[i];
	for(int i=1; i<=m; i++)
		cin>>q[i];
	while(T--) {
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		bool flag=true,temp=true;
		for(int i=l2; i<=r2; i++)
			if(q[i]<0)
				flag=false;
			else
				temp=false;
		if(!flag&&!temp) {
			bool f=false;
			for(int i=l1; i<=r1; i++)
				if(l[i]==0) {
					cout<<0<<endl;
					f=true;
					break;
				}
			if(!f) {
				int max1=1e9,min1=-1e9,max2=-1,min2=1e9;
				for(int i=l1; i<=r1; i++)
					if(l[i]>0)
						max1=min(max1,l[i]);
					else if(l[i]<0)
						min1=max(min1,l[i]);
				for(int i=l2; i<=r2; i++)
					if(q[i]>0)
						max2=max(max2,q[i]);
					else if(q[i]<0)
						min2=min(min2,q[i]);
				cout<<max(max1*min2,max2*min1)<<endl;
			}
		} else if(!flag&&temp) {
			int max1=0;
			for(int i=l1; i<=r1; i++) {
				if(l[i]<0)
					max1=min(max1,l[i]);
			}
			if(max1!=0) {
				int min2=-1e9;
				for(int i=l2; i<=r2; i++)
					min2=max(min2,q[i]);
				cout<<min2*max1<<endl;
			} else {
				int min2=0;
				for(int i=l2; i<=r2; i++)
					min2=min(min2,q[i]);
				int max2=1e9;
				for(int i=l1; i<=r1; i++)
					max2=min(max2,l[i]);
				cout<<min2*max2<<endl;
			}
		} else {
			int min1=1e9,max1;
			for(int i=l2; i<=r2; i++)
				min1=min(min1,q[i]);
			for(int i=l1; i<=r1; i++)
				max1=max(max1,l[i]);
			cout<<max1*min1<<endl;
		}
	}
	return 0;
}
