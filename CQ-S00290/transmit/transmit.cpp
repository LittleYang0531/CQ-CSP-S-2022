#include <bits/stdc++.h>

using namespace std;

int road(int s,int e,int a[],int b[],int v[],int n,int Q)
{
	int c[10000],q=0;
	c[q]=s;
	int score=0;
	score+=v[s];
	
	for(int i=0;i<n-1;i++)
	{
		if(c[q]==a[i])
		{
			q++;
			c[q]=b[i];
			if(b[i]==e) return score+v[i];
			else return score+road(c[q],e,a,b,v,n,Q);
		}
	 }
}

int main(int argc, char** argv)
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,Q,k;
	cin >> n >> Q >> k;
	int v[n];
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int a[n-1],b[n-1];
	for(int i=0;i<n-1;i++)
	{
		cin >> a[i] >> b[i];
	}
	int s[Q],t[Q];
	for(int i=0;i<Q;i++)
	{
		cin >> s[i]>> t[i];
	}
	int times=0;
	while(times<Q)
	{
		if(times!=0) cout << endl;
		cout << road(s[times],t[times],a,b,v,n,Q);
		times++;
	}
	
	
	
	return 0;
}
