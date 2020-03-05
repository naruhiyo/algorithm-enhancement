#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string s;
  
  cin >> s;

  vector<int> ans(s.length(), 0);

  int r_counter = 0;
  int l_counter = 0;

  for(int i = 0; i < s.length(); ++i){
    if(s[i] == 'R') ++r_counter;
    if(1 <= i){
      if(s[i-1] == 'R' && s[i] == 'L'){
        ans[i-1] = 1;
        ans[i] = 1;
        if(2 <= r_counter){
          ans[i-1] += (r_counter - 1) / 2;
          ans[i] += (r_counter - 1) - (r_counter - 1) / 2;
        }
        r_counter = 0;
      }
    }
  }

  for(int i = s.length()-1; 0 <= i; --i){
    if(s[i] == 'L') ++l_counter;
    if(i <= s.length() - 2){
      if(s[i] == 'R' && s[i+1] == 'L'){
        if(2 <= l_counter){
          ans[i] += (l_counter - 1) - (l_counter - 1) / 2; 
          ans[i+1] += (l_counter - 1) / 2; 
        }
        l_counter = 0;
      }
    }
  }

  for(int i = 0; i < s.length()-1; ++i){
    cout << ans[i] << " ";
  }
  cout << ans[s.length()-1] << endl;

  return 0;
}
