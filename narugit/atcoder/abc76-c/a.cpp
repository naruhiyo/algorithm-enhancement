#include <iostream>
#include <string>

using namespace std;

int main(){
  string S, T;
  cin >> S >> T;

  int fit_index = -1;

  for(int i = S.length() - T.length(); 0 <= i; --i){
    if(0 <= fit_index) break;
    for(int j = 0; j < T.length(); ++j){
      if(S[i+j] != '?' && S[i+j] != T[j]) break;
      if(j == T.length()-1) fit_index = i;
    }
  }

  if(fit_index < 0){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  for(int i = 0; i < S.length(); ++i){
    if(fit_index <= i && i <= fit_index+T.length()-1){
      S[i] = T[i-fit_index];
      continue;
    }
    if(S[i] == '?') S[i] = 'a';
  }

  cout << S << endl;

  return 0;
}
