//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int MX = 30 ;

int cs , t , vis[30][30] , prsn[30];
pii dp[30][30];
string inp;
int mx ;
bool Alphabet(char cha)
{
    return cha >='A' && cha <= 'Z' ;
}
pii DP(int pos , int lst )
{
   // printf("mx :: %d\n",mx);
    if( pos > mx )
    {
        if( lst ) return mp(0,1);
        else return mp(0,0);
    }
    if( vis[pos][lst] == cs ) return dp[pos][lst];
    vis[pos][lst] = cs ;
    dp[pos][lst] = DP(pos+1,lst);
    pii tmp ;
    tmp.ff = tmp.ss = 0 ;
    if( prsn[pos] == cs && ( lst * 5 <= 4 * pos ) )
    {
        tmp = DP(pos+1,pos);
        tmp.ff++;
    }
    if( tmp.ff > dp[pos][lst].ff )
    {
        dp[pos][lst] = tmp;
    }
    else if ( tmp.ff == dp[pos][lst].ff ) dp[pos][lst].ss += tmp.ss ;
    return dp[pos][lst];
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    for ( cs = 1 , t = II ; cs <= t ; cs++ )
    {
        getline( cin , inp );
        int sz = inp.size();
        mx = 0 ;
        rep(i,sz)
        {
            if( Alphabet(inp[i]))
            {
                prsn[inp[i]-'A'+1] = cs ;
                if( inp[i]-'A'+1 > mx ) mx = inp[i] - 'A' + 1 ;
            }
        }
        pii ans = DP(1,0);
        printf("%d %d\n",ans.ff,ans.ss);

    }

    return 0;
}
