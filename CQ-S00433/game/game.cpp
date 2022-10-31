#include<bits/stdc++.h>
using namespace std;
namespace CSP2022_Senior_2022_10_29
{
	namespace IO
	{
		const int buf_size=1<<20;
		char buf[buf_size],*S,*T;
		inline char read_char()
		{
			if(S==T)
				T=(S=buf)+fread(buf,1,buf_size,stdin);
			return S!=T?*(S++):EOF;
		}
		inline int read_int()
		{
			char c=read_char();
			bool neg=false;
			while(c<'0'||c>'9')
			{
				neg=(c=='-');
				c=read_char();
			}
			int x=0;
			while(c>='0'&&c<='9')
			{
				x=x*10+(c^'0');
				c=read_char();
			}
			return neg?-x:x;
		}
		char fw[buf_size];
		int pw;
		inline void flush()
		{
			fwrite(fw,1,pw,stdout);
			pw=0;
		}
		inline void write_char(char x)
		{
			fw[pw++]=x;
			if(pw==buf_size)
				flush();
		}
		inline void write_ll(long long x)
		{
			if(!x)
			{
				write_char('0');
				return;
			}
			if(x<0)
			{
				write_char('-');
				x=-x;
			}
			char st[26];
			int tp=0;
			while(x)
			{
				st[++tp]=x%10^'0';
				x/=10;
			}
			while(tp>0)
				write_char(st[tp--]);
		}
	}
	const int max_n=1e5+5;
	int A[max_n],B[max_n],val[max_n];
	const int inf=1e9+1;
	struct ST
	{
		int type;
		inline ST() {}
		inline ST(int Type)
		{
			type=Type;
		}
		inline int calc(int x,int y)
		{
			return type?max(x,y):min(x,y);
		}
		int f[17][max_n],Log[max_n];
		inline void init(int *a,int len)
		{
			Log[0]=-1;
			for(int i=1;i<=len;++i)
			{
				Log[i]=Log[i>>1]+1;
				f[0][i]=a[i];
			}
			assert(Log[len]<=16);
			for(int i=1;i<=Log[len];++i)
				for(int j=1;j+(1<<i)-1<=len;++j)
					f[i][j]=calc(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
		inline int query(int l,int r)
		{
			assert(l<=r);
			int k=Log[r-l+1];
			int res=calc(f[k][l],f[k][r-(1<<k)+1]);
			assert(res!=inf&&res!=-inf);
			return res;
		}
	}ST_A[2][2]={{ST(0),ST(1)},{ST(0),ST(1)}},ST_B[2][2]={{ST(0),ST(1)},{ST(0),ST(1)}}; // about 52 MiB
	// ST_A[a][b]: a=[if the values are positive], b=[if we calc the max of their absolute values]
	int n,m,q;
	inline void init_A()
	{
		for(int i=1;i<=n;++i)
		{
			if(A[i]>0)
				val[i]=A[i];
			else
				val[i]=inf;
		}
		ST_A[1][0].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]>0)
				val[i]=A[i];
			else
				val[i]=-inf;
		}
		ST_A[1][1].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]<0)
				val[i]=-A[i];
			else
				val[i]=inf;
		}
		ST_A[0][0].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]<0)
				val[i]=-A[i];
			else
				val[i]=-inf;
		}
		ST_A[0][1].init(val,n);
	}
	inline void init_B()
	{
		for(int i=1;i<=n;++i)
		{
			if(A[i]>0)
				val[i]=A[i];
			else
				val[i]=inf;
		}
		ST_B[1][0].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]>0)
				val[i]=A[i];
			else
				val[i]=-inf;
		}
		ST_B[1][1].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]<0)
				val[i]=-A[i];
			else
				val[i]=inf;
		}
		ST_B[0][0].init(val,n);
		for(int i=1;i<=n;++i)
		{
			if(A[i]<0)
				val[i]=-A[i];
			else
				val[i]=-inf;
		}
		ST_B[0][1].init(val,n);
	}
	int cnt_pos_A[max_n],cnt_neg_A[max_n],cnt_zeros_A[max_n],cnt_pos_B[max_n],cnt_neg_B[max_n],cnt_zeros_B[max_n];
	int main()
	{
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
		n=IO::read_int(),m=IO::read_int(),q=IO::read_int();
		for(int i=1;i<=n;++i)
		{
			A[i]=IO::read_int();
			cnt_pos_A[i]=cnt_pos_A[i-1]+(A[i]>0);
			cnt_neg_A[i]=cnt_neg_A[i-1]+(A[i]<0);
			cnt_zeros_A[i]=cnt_zeros_A[i-1]+(!A[i]);
		}
		for(int i=1;i<=m;++i)
		{
			B[i]=IO::read_int();
			cnt_pos_B[i]=cnt_pos_B[i-1]+(B[i]>0);
			cnt_neg_B[i]=cnt_neg_B[i-1]+(B[i]<0);
			cnt_zeros_B[i]=cnt_zeros_B[i-1]+(!B[i]);
		}
		init_A();
		for(int i=1;i<=max(n,m);++i)
			swap(A[i],B[i]);
		swap(n,m);
		init_B();
		for(int i=1;i<=max(n,m);++i)
			swap(A[i],B[i]);
		swap(n,m);
		const long long INIT=-1e18-1;
		while(q--)
		{
			int l1=IO::read_int(),r1=IO::read_int(),l2=IO::read_int(),r2=IO::read_int();
			long long ans=INIT;
			if(cnt_pos_B[r2]>cnt_pos_B[l2-1]&&cnt_neg_B[r2]>cnt_neg_B[l2-1])
			{
				if(cnt_zeros_A[r1]>cnt_zeros_A[l1-1])
					ans=0;
				else
				{
					if(cnt_pos_A[r1]>cnt_pos_A[l1-1])
						ans=-1ll*ST_A[1][0].query(l1,r1)*ST_B[0][1].query(l2,r2);
					if(cnt_neg_A[r1]>cnt_neg_A[l1-1])
						ans=max(ans,-1ll*ST_A[0][0].query(l1,r1)*ST_B[1][1].query(l2,r2));
				}
			}
			else if(cnt_pos_B[r2]>cnt_pos_B[l2-1])
			{
				if(cnt_pos_A[r1]>cnt_pos_A[l1-1])
					ans=1ll*ST_A[1][1].query(l1,r1)*ST_B[1][0].query(l2,r2);
				else if(cnt_zeros_A[r1]>cnt_zeros_A[l1-1])
					ans=0;
				else
					ans=-1ll*ST_A[0][0].query(l1,r1)*ST_B[1][1].query(l2,r2);
			}
			else if(cnt_neg_B[r2]>cnt_neg_B[l2-1])
			{
				if(cnt_neg_A[r1]>cnt_neg_A[l1-1])
					ans=1ll*ST_A[0][1].query(l1,r1)*ST_B[0][0].query(l2,r2);
				else if(cnt_zeros_A[r1]>cnt_zeros_A[l1-1])
					ans=0;
				else
					ans=-1ll*ST_A[1][0].query(l1,r1)*ST_B[0][1].query(l2,r2);
			}
			else
			{
				assert(cnt_zeros_B[r2]-cnt_zeros_B[l2-1]==r2-l2+1);
				ans=0;
			}
			assert(ans!=INIT);
			if(cnt_zeros_B[r2]>cnt_zeros_B[l2-1]&&ans>0)
				ans=0;
			IO::write_ll(ans);
			IO::write_char('\n');
		}
		IO::flush();
		return 0;
	}
}
int main()
{
	return CSP2022_Senior_2022_10_29::main();
}


