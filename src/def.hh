#ifndef DEF_HH
#define DEF_HH

#include <math.h>
#include <vector>
#include <deque>

const int MAX_WLEN=1000;
const double MINLOGPROB=-60;
const double MINPROB=1e-60;
const float LOG10TOe = M_LN10;
const float LOGeTO10 = 1.0 / M_LN10;

inline double safelogprob(double x) {
  if (x> MINPROB) return(log10(x));
  return(MINLOGPROB);
}

inline double safelogprob2(double x) {
  if (x> MINPROB) return(log10(x));
  if (x<0) return(0.0);
  return(MINLOGPROB);
}

inline float pow10(float a)
{
  return exp(a * LOG10TOe);
}

////////////////////////////////////////////////777
// For debug

inline void print_indices(int *v, int dim) {
  fprintf(stderr,"[");
  for (int i=0;i<dim;i++) fprintf(stderr," %d",v[i]);
  fprintf(stderr," ]");
}

inline void print_indices(unsigned short *v, int dim) {
  fprintf(stderr,"[");
  for (int i=0;i<dim;i++) fprintf(stderr," %d",v[i]);
  fprintf(stderr," ]");
}

inline void print_indices(std::vector<int> &v) {
  print_indices(&v[0], v.size());
}

inline void print_indices(std::vector<unsigned short> &v) {
  print_indices(&v[0], v.size());
}

typedef std::deque<int> Gram;

inline void print_indices(const Gram &v) {
  fprintf(stderr,"[");
  for (int i=0;i<v.size();i++) fprintf(stderr," %d",v[i]);
  fprintf(stderr," ]");
}
#endif
