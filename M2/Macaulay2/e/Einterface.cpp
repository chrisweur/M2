// Copyright 1999  Michael E. Stillman
#include "Einterface.hpp"
#include "ntuple.hpp"
#include "text_io.hpp"

EInterface::EInterface(const Ring *RR)
{
  const PolynomialRing *R1 = RR->cast_to_PolynomialRing();
  //if (R == 0) throw(expected_poly_ring);
  const PolynomialRing *R = R1->get_cover();
  if (R1->is_quotient_ring())
    {
      Rquotient = R1;
    }
  else
    {
      Rquotient = 0;
    }
  K = R->get_coefficient_ring();
  M = R->get_monoid();

  RWeyl = R->cast_to_WeylAlgebra();

  one_ = K->from_int(1);
  minus_one_ = K->from_int(-1);

  nvars_ = M->n_vars();
}

void EInterface::divide_exponents(const exponent_vector *exp1,
				  const exponent_vector *exp2,
				  exponent_vector *result,
				  int &sign) const
{
  ntuple::divide(nvars_,exp1,exp2,result);
  if (M->is_skew())
    sign = M->exp_skew_mult_sign(result,exp2);
}

void EInterface::exponent_syzygy(const exponent_vector *exp1,
				 const exponent_vector *exp2,
				 exponent_vector *result1,
				 exponent_vector *result2,
				 int &sign) const
{
  if (M->is_skew())
    {
      ntuple::syz(nvars_,exp1,exp2,result1,result2);
      sign *= M->exp_skew_mult_sign(result1,exp1);
      sign *= M->exp_skew_mult_sign(result2,exp2);
    }
  else
    ntuple::syz(nvars_,exp1,exp2,result1,result2);
}


Matrix EInterface::make_matrix(freemodule F, array< vec > &columns) const
{
  Matrix result(F);
  for (int i=0; i<columns.length(); i++)
    {
      result.append(columns[i]);
      columns[i] = 0;
    }
  return result;
}

void EInterface::cancel_lead_terms(vector_heap &h, vector_heap &hsyz,
			 const ringelement &hcoefficient, 
			 const exponent_vector *hexponents,
			 const exponent_vector *gexponents,
			 const vec &g,
			 const vec &gsyz) const
{
  int *mCancelExp = new int[nvars_];
  if (true) //(!coeffs_QQ)
    {
      // In this case we assume that 'g' is monic.
      int sign = 1;  
      vec f,fsyz;
      divide_exponents(hexponents, gexponents, mCancelExp, sign);
        // sign is only set in skew commutative case.

      if (sign == 1)
	{
	  ringelement c = negate_coefficient(hcoefficient);
	  f = mult_by_term(h.get_target(), c, mCancelExp, g);
	  fsyz = mult_by_term(hsyz.get_target(), c, mCancelExp, gsyz);
	  remove_coefficient(c);
	}
      else
	{
	  f = mult_by_term(h.get_target(), hcoefficient, mCancelExp, g);
	  fsyz = mult_by_term(hsyz.get_target(), hcoefficient, mCancelExp, gsyz);
	}
      h.add(f);
      hsyz.add(fsyz);
    }
  delete [] mCancelExp;
}

void EInterface::ring_cancel_lead_terms(vector_heap &h,
			      const ringelement &hcoefficient, 
			      const exponent_vector *hexponents,
			      int hcomponent,
			      const exponent_vector *gexponents,
			      const polynomial &g) const
{
  int *mCancelExp = new int[nvars_];
  if (true) //(!coeffs_QQ)
    {
      // In this case we assume that 'g' is monic.
      int sign = 1;  
      vec f;
      divide_exponents(hexponents, gexponents, mCancelExp, sign);
        // sign is only set in skew commutative case.

      if (sign == 1)
	{
	  ringelement c = negate_coefficient(hcoefficient);
	  f = ring_mult_by_term(h.get_target(), c, mCancelExp, hcomponent, g);
	  remove_coefficient(c);
	}
      else
	{
	  f = ring_mult_by_term(h.get_target(), 
				hcoefficient, mCancelExp, hcomponent, 
				g);
	}
      h.add(f);
    }
  delete [] mCancelExp;
}


void EInterface::add_multiple_to(vector_heap &h, 
		     const ringelement &a, 
		     const exponent_vector *m,
		     const vec &v) const
{
  vec f = mult_by_term(h.get_target(),a,m,v);
  h.add(f);
}

void EInterface::add_ring_multiple_to(vector_heap &h, 
			  const ringelement &a, 
			  const exponent_vector *m,
			  int x,
			  const polynomial &r) const
{
  vec f = ring_mult_by_term(h.get_target(),a,m,x,r);
  h.add(f);
}

void EInterface::display_exponents(buffer &o, const exponent_vector *exp) const
{
  int *m = M->make_one();
  M->from_expvector(exp, m);
  M->elem_text_out(o,m);
  M->remove(m);
}

void EInterface::display_vector(buffer &o, const freemodule &F, const vec &f) const
{
  F->elem_text_out(o,f);
}
