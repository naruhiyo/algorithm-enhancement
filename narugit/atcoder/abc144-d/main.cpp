#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  long double a, b, x;
  cin >> a >> b >> x;

  long double theta;

  if(2*x/(a*b) <= a){
    theta = atan(a*b*b/(2.0*x));
  }else{
    theta = atan(2*(b-x/(a*a))/a);
  }

  cout << setprecision(10) << theta * 180.0 / M_PI << endl;

  return 0;
}
