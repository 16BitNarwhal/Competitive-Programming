#include <bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define INF (int)2e9
#define LLINF LLONG_MAX
#define x first
#define y second
#define pb push_back
#define fill(a,v) memset(a, v, sizeof a)
#define mp make_pair
#define all(a) a.begin(), a.end()
#define COMPRESS(a) sort(all(a)); a.erase(unique(all(a)),a.end())
#define IOS ios::sync_with_stdio(0); cin.tie(0)
#define debug(args...) {vector<string> v = split(#args, ',');err(v.begin(), args);}
#define bits(a) __builtin_popcount(a)
#define ffs(a) __builtin_ffs(a)
#define maX(a,b) ( (a) > (b) ? (a) : (b))
#define miN(a,b) ( (a) < (b) ? (a) : (b))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
vector<string> split(const string& s, char c){vector<string> v;stringstream st(s);string x;while(getline(st, x, c))v.pb(x);return move(v);}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {cerr<<it->substr((*it)[0]==' ',it->length())<<" = "<<a<<'\n';err(++it, args...);}
template <typename T1, typename T2>
inline ostream&operator<<(ostream&os,const pair<T1, T2>&p){return os<<"("<<p.x<<", "<<p.y<<")";}
template<typename T>
inline ostream&operator<<(ostream&os,const vector<T>&v){bool _=1;os<<"[";for(auto i:v){if(!_)os<<", ";os<<i;_= 0;}return os<<"]";}
template<typename T>
inline ostream&operator<<(ostream&os,const set<T>&v){os<<"-BEGIN SET-\n";bool _=1;for(auto i:v){if(!_)os<<"\n";os<<i;_= 0;}return os<<"\n-END SET-";}
template<typename T>
inline ostream&operator<<(ostream&os,const unordered_set<T>&v){os<<"-BEGIN SET-\n";bool _= 1;for(auto i:v){if(!_)os<<"\n";os<<i;_= 0;}return os<<"\n--END SET--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(auto i:v){if(!_)os << "\n";os<<" "<<i;_=0;}return os<<"\n"<<"--END MAP--";}
template<typename T1, typename T2>
inline ostream&operator<<(ostream&os,const unordered_map<T1,T2>&v){os<<"-BEGIN MAP-\n";bool _= 1;for(auto i:v){if(!_)os<<endl;os<<" "<<i;_=0;}return os<<"\n--END MAP--";}
