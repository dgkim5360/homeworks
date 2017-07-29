#include <iostream>
#include <ctime>
#include "pricing.h"
using namespace std;

int main(int argc, char **argv) {
  int num_sims;  // Number of simulated asset paths
  double S;  // Option price
  double K;  // Strike price
  double r;  // Risk-free rate (5%)
  double v;  // Volatility of the underlying (20%)
  double T;  // One year until expiry

  double call;
  clock_t begin, end;
  double timediff;

  // what you got
  do {  // simple check for #iterations
    cout << "Number of Simulations (should be less than 10 million): ";
    cin >> num_sims;
  } while (num_sims > 10000000);

  cout << "Underlying: ";
  cin >> S;
  cout << "Strike: ";
  cin >> K;
  cout << "Risk-Free Rate: ";
  cin >> r;
  cout << "Volatility: ";
  cin >> v;
  cout << "Maturity: ";
  cin >> T;

  // closed-form solution
  cout << "\n:: Calculation using the closed-form solution ::" << endl;

  begin = clock();
  call = call_price_closed_from(S, K, r, v, T);
  end = clock();
  timediff = double(end - begin)/CLOCKS_PER_SEC;
  cout << "Call Price: " << call << " with " << timediff << " seconds" << endl;

  // MC solution
  cout << "\n:: Calculation using MC ::" << endl;

  begin = clock();
  call = call_price_mc(S, K, r, v, T, num_sims);
  end = clock();
  timediff = double(end - begin)/CLOCKS_PER_SEC;
  cout << "Call Price: " << call << " with " << timediff << " seconds" << endl;

  return 0;
}
