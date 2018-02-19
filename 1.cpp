#include <iostream>
#include <limits.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
#include <iomanip>
#include <deque>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <regex>
#include <sstream>

#define FOR(i,a,b)          for(auto i=a;i<=b;i++)
#define FORR(i,a,b)         for(auto i=b;i>=a;i--)
#define REP(i,n)            FOR(i,0,(int)n-1)
#define REPR(i,n)           FORR(i,0,(int)n-1)
#define TR(it,v)            for(auto it:v)
#define pb              push_back
#define mp              make_pair   
#define all(x)              x.begin(),x.end()
#define BUG             cout<<"BUG"<<endl
#define INF             INT_MAX
#define fast                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pr(x)               REP(i,x.size()) cout<<x[i]<<" "
#define prr(x)              REP(i,x.size()) { REP(j,x[i].size()) cout<<x[i][j]<<" ";el;}
#define MOD             1000000007
#define el              cout<<endl
#define fi              first
#define se              second

using namespace std;

typedef stack<int>          si;
typedef queue<int>          qi;
typedef vector<int>             vi;
typedef vector<vi >         vii;
typedef pair<int,int>           ii;
typedef pair<int,ii >           edge;
typedef vector<edge >           vpi;
typedef vector<bool>            vb;
typedef vector<long>            vl;
typedef vector<vl >         vll;
typedef pair<long,long>         ll;
typedef vector<ll >         vli;
typedef vector<ii >         pii;
typedef vector<pii >            vvi;

#ifndef INP
istream &in=cin;
#else
ifstream file("1.txt");
istream &in=file;
#endif

unsigned int FindFunctionDefn(const char* strFunctionName, const char* strSourceCode) {
    string fname(strFunctionName);
    string code(strSourceCode);

    string regStr = "[a-zA-Z0-9\\* \\[\\]&_\n]*" + fname + "( |\n)*\\([a-zA-Z0-9_,\\*&\\[\\] ]*\\)( |\n)*\\{";

    regex reg(regStr);
    istringstream cstr(code);

    string line;  
    int count = 1;  
    while (getline(cstr, line)) {
        smatch m;
        regex_search(line,m,reg);
        if(!m.empty()) return count;
        ++count;
    }
    return 0;
}

int main() {
    fast;
    string funcName = "main";
    string program = "func1();\nint func1(){ return 0; }\n int func2(){ return 1; }\n" "int main(int argc, char*argv[]){ return func2(); }\n";
    int n = FindFunctionDefn(funcName.c_str(), program.c_str());
    cout<<n<<endl;
}
