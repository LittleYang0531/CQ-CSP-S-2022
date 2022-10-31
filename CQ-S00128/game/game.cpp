#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;i++)
#define rep2(i,l,r) for(int i=l;i>=r;i--)
const int N=1e5+10;
using namespace std;
int n,m,q,a[N],b[N],l_1,l_2,r_1,r_2; 
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	rep1(i,1,n) cin>>a[i];
	rep1(i,1,m) cin>>b[i];
	while(q--)
	{
		cin>>l_1>>r_1>>l_2>>r_2;
		int s1=LONG_LONG_MAX,s2=LONG_LONG_MIN,s3=LONG_LONG_MAX,s4=LONG_LONG_MIN,k1=0,f1=LONG_LONG_MAX,f2=LONG_LONG_MIN,f3=LONG_LONG_MAX,f4=LONG_LONG_MIN,k2=0;
		rep1(i,l_1,r_1)
		{
			if(a[i]<0)
			{
				s1=min(s1,a[i]);
				s2=max(s2,a[i]);
			}
			else if(a[i]>0)
			{
				s3=min(a[i],s3);
				s4=max(a[i],s4);
			}
			else k1=1;
		}
		rep1(i,l_2,r_2)
		{
			if(b[i]<0)
			{
				f1=min(f1,b[i]);
				f2=max(f2,b[i]);
			}
			else if(b[i]>0)
			{
				f3=min(b[i],f3);
				f4=max(b[i],f4);
			}
			else k2=1;
		}
		if(s1==LONG_LONG_MAX&&s2==LONG_LONG_MIN)
		{
			if(f1==LONG_LONG_MAX&&f2==LONG_LONG_MIN)
			{
				if(k2==1) cout<<0<<endl;
				else cout<<s4*f3<<endl;
			}
			else
			{
				if(k1==1) cout<<0<<endl;
				else cout<<s3*f1<<endl;
			}
		}
		else if(s3==LONG_LONG_MAX&&s4==LONG_LONG_MIN)
		{
			if(f3==LONG_LONG_MAX&&f4==LONG_LONG_MIN)
			{
				if(k2==1) cout<<0<<endl;
				else cout<<s1*f2<<endl;
			}
			else
			{
				if(k1==1) cout<<0<<endl;
				else cout<<s2*f4<<endl; 
			}
		}
		else
		{
			if(f1==LONG_LONG_MAX&&f2==LONG_LONG_MIN)
			{
				if(k2==1) cout<<0<<endl;
				else cout<<s4*f3<<endl;
			}
			else if(f3==LONG_LONG_MAX&&f4==LONG_LONG_MIN)
			{
				if(k2==1) cout<<0<<endl;
				else cout<<s1*f2<<endl;
			}
			else
			{
				if(k1==1) cout<<0<<endl;
				else cout<<max(s2*f4,s3*f1)<<endl;
			}
		}
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/

