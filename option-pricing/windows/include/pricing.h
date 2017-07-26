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

__stdcall double call_price_closed_from(const double& S, const double& K, const double& r, const double& v, const double& T);
__stdcall double put_price_closed_from(const double& S, const double& K, const double& r, const double& v, const double& T);

__stdcall double call_price_mc(const long& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T);
__stdcall double put_price_mc(const long& num_sims, const double& S, const double& K, const double& r, const double& v, const double& T);

#ifdef __cplusplus
}
#endif

#endif  // PRICING_H
