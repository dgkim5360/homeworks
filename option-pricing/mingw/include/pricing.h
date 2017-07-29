#ifndef PRICING_H
#define PRICING_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_PRICING
#define PRICING __declspec(dllexport)
#else
#define PRICING __declspec(dllimport)
#endif

double __stdcall PRICING call_price_closed_from(const double &S, const double &K, const double &r, const double &v, const double &T);
double __stdcall PRICING call_price_mc(const double &S, const double &K, const double &r, const double &v, const double &T, const int &num_sims);

#ifdef __cplusplus
}
#endif

#endif  // PRICING_H
