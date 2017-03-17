template<typename scalar_t>
inline scalar_t sq(const scalar_t &x);  // (1) function template

inline double sq(const double &x);      // (2) overload

template<>
inline int sq(const int &x);            // (3) specialization of 1

inline double sq(float x);              // ok, overloaded sq may
// have different signature

template<>
// error: invalid specialization
inline int sq(const int x);             // it must have the same signature


// specializations are only possible at the same namespace level
