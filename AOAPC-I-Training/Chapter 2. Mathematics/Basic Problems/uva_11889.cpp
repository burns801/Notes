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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */

const int MAXN = 1024 * 10;
vector<int> primes;
void primes_init(){
  vector<bool> isPrime(MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      int s = n * p;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}

int solve(int A, int C){
  if (C % A != 0) return -1;
  int B = 1;
  for (size_t i = 0; i < primes.size(); i++){
    int p = primes[i];
    //cout << p << endl;
    int cnt_a = 0; while(A % p == 0) A /= p, cnt_a++;
    int cnt_c = 0; while(C % p == 0) C /= p, cnt_c++;
    //cout << p << ", " << cnt_a << ", " << cnt_c << endl;
    if (cnt_a != cnt_c){
      while (cnt_c--) B *= p;
    }
  }
  if (C != 1 && A == 1) B *= C;
  //return B == 1 ? 0 : B;
  return B;
}

int gcd(int A, int B){
  return B == 0 ? A : gcd(B, A % B);
}
int lcm(int A, int B){
  return A * B / gcd(A, B);
}
int main(){
  primes_init();
  //for (auto i : primes) cout << i << ", " ;
  int T; cin >> T;
  while (T--){
    int A, C; cin >> A >> C;
    int B = solve(A, C);
    if (B != -1) cout << B << endl;
    else cout << "NO SOLUTION" << endl;
  }
}
