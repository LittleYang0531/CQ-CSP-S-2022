/*还是有一点紧张呢？开考之前写一点闲话，应该不会做不来题的吧？希望顺利，我想应该不会考什么我已经忘得差不多的算法了吧，毕竟是 提高组 难度了。做不来题就冷静一点 不要慌。*/
/*不慌a，但是现在属于是做不来 T3 了？看了下好像有 80 pts ，T4 的话，甩 15 pts 好写，再甩 15pts 更好写 拼暴力吧*/
/*哎，这次比赛还是大的很垃圾，315 了 这次？  T4 还有 15pts 没写 ，如果有时间可以拿 30 的，T3 真的不会，不知道自己是什么角度出了问题，做了 1h 没做出来*/
/*还是很难过吧，检查一下，没办法，做不来题有什么用呢？从头到尾脸都是烫的，不知道为什么非常紧张！*/
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long
#define dd double
#define LL __int128
#define ull unsigned ll
#define uLL __uint128_t 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2505;
int n,m,k;
vector<int>v[xx];
int I[xx][3];
ll s[xx];
void bfs(int x,int *d)
{
	for(int i=1;i<=n;i++)d[i]=n+1;
	queue<int>q;
	d[x]=0;//注意，合法是 dis <=k+1  
	q.push(x);
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(auto to:v[x])
			if(d[to]>d[x]+1)d[to]=d[x]+1,q.push(to);
	}
}
int d[xx][xx];
bool ck(int x,int y){return d[x][y]<=k+1;}
ll inf=4e18;
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++)s[i]=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		v[a].push_back(b),v[b].push_back(a);
	}
//	exit(0);
	ll ans=0;
	s[0]=-inf;
	for(int i=1;i<=n;i++)bfs(i,d[i]);
//	for(int i=2;i<=n;i++)cerr<<ck(i,1)<<"$\n";
	for(int i=2;i<=n;i++)
	{
		ll mv=-inf,mid=0,sv=-inf,sid=0,tv=-inf,tid=0;
		for(int j=2;j<=n;j++)
		{
			if(i==j)continue;
			if(!ck(1,j)||!ck(i,j))continue;
			if(mv<s[j])
			{
				tv=sv,tid=sid;
				sv=mv,sid=mid;
				mv=s[j],mid=j;
			}
			else if(sv<s[j])
			{
				tv=sv,tid=sid;
				sv=s[j],sid=j;
			}
			else if(tv<s[j])
			{
				tv=s[j],tid=j;
			}
		}
		I[i][0]=mid;
		I[i][1]=sid;
		I[i][2]=tid;
//		cerr<<i<<" "<<mid<<" "<<sid<<" "<<tid<<" "<<mv<<"#\n";
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i==j)continue;
			if(!ck(i,j))continue;
			for(int A=0;A<3;A++)
			{
				int tx,ty;
				if((tx=I[i][A])==j)continue;
				for(int w=0;w<3;w++)
				{
					if((ty=I[j][w])==i)continue;
					if(tx==ty||!tx||!ty)continue;
//					cerr<<i<<" "<<j<<" "<<tx<<" "<<ty<<" "<<s[i]+s[j]+s[tx]+s[ty]<<"%\n";
					ans=max(ans,s[i]+s[j]+s[tx]+s[ty]);
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}
