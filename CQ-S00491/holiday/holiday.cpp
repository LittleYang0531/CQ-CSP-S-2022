#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int F[10000];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<n+1;i++)
		cin>>F[i];
	for(int i=2;i<m+2;i++)
	{
		int z;
		cin>>z>>z;
	}
	sort(F,F+n-1);
	cout<<F[n-1]+F[n-2]+F[n-3]+F[n-4];
	return 0;
}

