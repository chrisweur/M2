// Copyright 1998 Michael E. Stillman

#ifndef _weylfree_hpp_
#define _weylfree_hpp_

#include "weylalg.hpp"
#include "freemod.hpp"

class WeylFreeModule : public FreeModule
{
  friend class WeylAlgebra;	// The only class that can make one of these
protected:
  const WeylAlgebra *W;

  WeylFreeModule(const WeylAlgebra *WW, int rank);

  WeylFreeModule(const WeylAlgebra *WW, const FreeModule *F);

  vec weyl_diff(
		const ring_elem c,
		const int *expf,  // The exponent vector of f
		const int *derivatives, 
		const vec g) const;  // An entire polynomial

public:
  virtual ~WeylFreeModule();

  class_identifier class_id() const { return CLASS_WeylFreeModule; }

  virtual vec imp_mult_by_term(const ring_elem c, const int *m, const vec v) const;

  friend void i_stashes();
  static stash *mystash;
  void *operator new(size_t) { return mystash->new_elem(); }
  void operator delete(void *p) { mystash->delete_elem(p); }
};

#endif
