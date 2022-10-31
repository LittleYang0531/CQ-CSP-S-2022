#include<bits/stdc++.h>
using namespace std;
long long ak[100005],n,m,q,a[100005],b[100005],l[100005][2],e[100005][2];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=m; i++)
		cin>>b[i];
	for(int i=1; i<=q; i++) {
		long long ans=10e17,anss=-10e17;
		cin>>l[i][0]>>l[i][1]>>e[i][0]>>e[i][1];
		for(int j=l[i][0]; j<=l[i][1]; j++) {
			for(int l=e[i][0]; l<=e[i][1]; l++)
				if(a[j]*b[l]<ans)
					ans=a[j]*b[l];
			if(anss<ans)
				anss=ans;
			ans=10e17;
		}
		ak[i]=anss;
	}
	for(int i=1; i<=q; i++)
		cout<<ak[i]<<endl;
	return 0;
}
