#include <bits/stdc++.h>
using namespace std;
int n,m,q;
long long a[10001],b[10001];
long long ans[10001];
int main()
{
    freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(int m = 0;m<q;m++)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        long long ma=-10e18;
        for(int i=l1-1;i<r1;i++)
        {
            long long mi = a[i]*b[l2-1];
            for(int j=l2-1;j<r2;j++)
            {
                mi = min(a[i]*b[j],mi);
            }
            ma = max(mi,ma);
            ans[m] = ma;
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
}
