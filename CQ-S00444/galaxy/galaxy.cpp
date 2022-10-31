#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q,cnt1,cnt2,cnt3,rd[N],cd[N];
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		++rd[v];++cd[u];
	}
	for(int i=1;i<=n;++i)
	{
		if(cd[i]) ++cnt1;
		if(rd[i]) ++cnt2;
		if(cd[i]==1) ++cnt3;
	}
	cin>>q;
	while(q--)
	{
		int op,u,v;
		cin>>op>>u>>v;
//		cout<<cd[u]<<" "<<rd[v]<<"\n";
		if(op==1)
		{
			if(cd[u]==2) ++cnt3;
			if(cd[u]==1) --cnt3;
			--rd[v],--cd[u];
			if(!rd[v]) --cnt1;
			if(!cd[u]) --cnt2;
		}
		else if(op==3)
		{
			if(!rd[v]) ++cnt1;
			if(!cd[u]) ++cnt2;
			++rd[v],++cd[u];
			if(cd[u]==1) ++cnt3;
			if(cd[u]==2) --cnt3;
		}
//		cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<"\n";
		if(cnt1==n&&cnt2==n&&cnt3==n) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
4
1 3 2
1 2 3
1 1 3
1 1 2
*/
