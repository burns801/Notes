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
 * sizeof
 */
int a[7];
int main(){
  while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6]){
    if (a[1] == a[2] && a[2] == a[3] && a[3] == a[4] && a[4] == a[5] && a[5] == a[6] && a[6] == 0){
      break;
    }
    int s = 0;
    s += a[6];
    a[6] = 0;

    s += a[5];
    a[1] -= 11 * a[5];
    a[5] = 0;

    s += a[4];
    int t4 = a[4] * 5;
    if (a[2] >= t4){
      a[2] -= t4;
      a[4] = 0;
    }else{
      t4 -= a[2];
      a[2] = 0;
      t4 *= 4;
      a[1] -= t4;
      a[4] = 0;
    }

    s += (a[3] + 3) / 4;
    a[3] %= 4;
    if (a[3] == 1){
      a[2] -= 5;
      a[1] -= 7;
    }else if (a[3] == 2){
      a[2] -= 3;
      a[1] -= 6;
    }else if (a[3] == 3){
      a[2] -= 1;
      a[1] -= 5;
    }

    if (a[2] < 0){
      a[1] += a[2] * 4;
      a[2] = 0;
    }else{
      s += (a[2] + 8)/ 9;
      if (a[2] % 9 != 0){
        a[1] -= (9 - a[2] % 9) * 4;
      }
    }
    if (a[1] > 0){
      s += (a[1] + 35) / 36;
    }
    printf("%d\n", s);
  }
}

