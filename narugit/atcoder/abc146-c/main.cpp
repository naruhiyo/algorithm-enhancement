#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

bool isOk(const ll &a, const ll &b, const ll &num, const ll &x){
  return a * num + b * to_string(num).length() <= x ? true : false;
}

int main(){
  ll a, b, x;
  cin >> a >> b >> x;

  ll ok = 0;

  // 1'000'000'000がokか判断
  if(isOk(a, b, 1'000'000'000, x)){
    cout << 1'000'000'000 << endl;
    return 0;
  }
  ll ng = 1'000'000'000;

  while(1){
    ll mid = (ok + ng)/2;
    
    if(mid == ok || mid == ng){
      break;
    }

    if(isOk(a, b, mid, x)){
      ok = mid;
    }else{
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
