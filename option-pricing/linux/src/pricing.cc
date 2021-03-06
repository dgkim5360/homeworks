#define _USE_MATH_DEFINES
#include <random>
#include <cmath>
#include <iostream>

// https://stackoverflow.com/questions/2328258/cumulative-normal-distribution-function-in-c-c
double norm_cdf(const double &x) {
  return 0.5*erfc(-x*M_SQRT1_2);
}

// Calculate d_j, for j in {1,2} for closed-form solution
double d_j(const int &j, const double &S, const double &K, const double &r, const double &v, const double &T) {
  return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

// Calculate the European vanilla call price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double call_price_closed_from(const double& S, const double& K, const double& r, const double& v, const double& T) {

  if (S <= 0) return -1;  // exception on the first argument S
	if (K <= 0) return -2;  // exception on the second argument K
	if (v <= 0) return -4;  // exception on the fourth argument v
	if (T <= 0) return -5;  // exception on the fifth argument T

  return S*norm_cdf(d_j(1, S, K, r, v, T)) - K*exp(-r*T)*norm_cdf(d_j(2, S, K, r, v, T));
}

// Pricing a European vanilla call option with a Monte Carlo method
double call_price_mc(const double& S, const double& K, const double& r, const double& v, const double& T, const int& num_sims) {
  const double S_adjust = S*exp(T*(r-0.5*v*v));
  double S_cur = 0.0;
  double payoff_sum = 0.0;
  double rnorm;

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(0.0, 1.0);

  if (S <= 0) return -1;  // exception on the first argument S
	if (K <= 0) return -2;  // exception on the second argument K
	if (v <= 0) return -4;  // exception on the fourth argument v
	if (T <= 0) return -5;  // exception on the fifth argument T
	if (num_sims <= 0) return -6;  // exception on the sixth argument num_sims

  for (int i=0; i<num_sims; i++) {
    rnorm = distribution(generator);
    S_cur = S_adjust*exp(sqrt(v*v*T)*rnorm);
    payoff_sum += (S_cur - K > 0.0)? (S_cur - K): 0.0;
  }

  return (payoff_sum / static_cast<double>(num_sims))*exp(-r*T);
}
