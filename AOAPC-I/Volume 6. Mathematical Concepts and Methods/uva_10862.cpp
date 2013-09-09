//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 */
const int BASE = 10*1000;
const int WIDTH = 4;
string strFromInt(int n, int w){
  char buf[32];
  sprintf(buf, "%0*d", w, n);
  return buf;
}
vector<int> bignFromStr(string s){
  reverse(s.begin(), s.end());
  vector<int> a;
  for (size_t i = 0; i < s.size(); i += WIDTH) {
    string t = s.substr(i, WIDTH); reverse(t.begin(), t.end());
    a.push_back(atoi(t.c_str()));
  }
  return a;
}
string strFromBign(vector<int> a){
  if (a.size() == 0) return "0";
  reverse(a.begin(), a.end());
  string s = strFromInt(a[0], 0);
  for (size_t i = 1; i < a.size(); i++) {
    s += strFromInt(a[i], WIDTH); 
  }
  return s;
}
vector<int> bignAdd(vector<int> a, vector<int> b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++) {
    int da = i < a.size()? a[i] : 0;
    int db = i < b.size()? b[i] : 0;
    int dc = da + db + carry;
    c.push_back(dc % BASE);
    carry = dc / BASE;
  }
  if (carry) c.push_back(carry);
  return c;
}
vector<int> bignTimes(vector<int> a, int n){
  vector<int> b;
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++) {
    int db = a[i] * n + carry;
    b.push_back(db % BASE);
    carry = db / BASE;
  }
  if(carry)b.push_back(carry);
  return b;
}
vector<int> bign0 = bignFromStr("0");
vector<int> bign1 = bignFromStr("1");

vector<int> F_cache[2048];
bool F_visited[2048];
vector<int> SumF_cache[2048];
bool SumF_visited[2048];

vector<int> F(int n);
vector<int> SumF(int n);

vector<int> SumF(int n){
  vector<int> &res = SumF_cache[n];
  if (SumF_visited[n]) return res;
  SumF_visited[n] = true;
  if (n == 0) res = F(n);
  else res = bignAdd(F(n) , SumF(n - 1));
  return res;
}
vector<int> F(int n){
  vector<int> &res = F_cache[n];
  if (F_visited[n]) return res;
  F_visited[n] = true;
  if (n == 0) res = bign1;
  else if (n == 1) res = bign1;
  else{
    //for (int i = 1; i <= n; i++) res = bignAdd(res, bignTimes(F(n - i), i));
    res = bignAdd(F(n - 1), SumF(n - 1));
  }
  return res;
}
int TestNum;
int main(){
  int N;
  while (cin >> N && N) {
    cout << strFromBign( F(N) ) << endl;
  }
}

