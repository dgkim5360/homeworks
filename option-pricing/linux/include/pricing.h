#ifndef pricing_h__
#define pricing_h__

extern double call_price_closed_from(const double &S, const double &K, const double &r, const double &v, const double &T);
extern double call_price_mc(const double &S, const double &K, const double &r, const double &v, const double &T, const int &num_sims);

#endif  // pricing_h__
