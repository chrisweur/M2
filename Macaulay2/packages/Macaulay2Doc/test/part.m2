QQ[x]
f = (1+x)^5
      assert( (part(,2,f)) === 10*x^2+5*x+1 )
      assert( (part(2,,f)) === x^5+5*x^4+10*x^3+10*x^2 )
      assert( (part(2,3,f)) === 10*x^3+10*x^2 )
      assert( (part(2,f)) === 10*x^2 )
      assert( (part(2,infinity,f)) === x^5+5*x^4+10*x^3+10*x^2 )
      assert( (part(-infinity,2,f)) === 10*x^2+5*x+1 )
      assert( (part(-infinity,infinity,f)) === x^5+5*x^4+10*x^3+10*x^2+5*x+1 )
QQ[x,y,Degrees=>{{1,0},{0,1}}]
f = (1+x+y)^4
      assert( (part(2,{1,0},f)) === 6*x^2*y^2+12*x^2*y+6*x^2 )
      assert( (part(2,{0,1},f)) === 6*x^2*y^2+12*x*y^2+6*y^2 )
      assert( (part(2,{1,1},f)) === 6*x^2+12*x*y+6*y^2 )
      assert( (part(2,3,{1,0},f)) === 4*x^3*y+6*x^2*y^2+4*x^3+12*x^2*y+6*x^2 )
      assert( (part(2,3,{0,1},f)) === 6*x^2*y^2+4*x*y^3+12*x*y^2+4*y^3+6*y^2 )
      assert( (part(2,3,{1,1},f)) === 4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2 )
      assert( (part(2,infinity,{1,0},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x^3+12*x^2*y+6*x^2 )
      assert( (part(2,infinity,{0,1},f)) === 6*x^2*y^2+4*x*y^3+y^4+12*x*y^2+4*y^3+6*y^2 )
      assert( (part(2,infinity,{1,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x*y^3+y^4+4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2 )
      assert( (part(2,,{1,0},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x^3+12*x^2*y+6*x^2 )
      assert( (part(2,,{0,1},f)) === 6*x^2*y^2+4*x*y^3+y^4+12*x*y^2+4*y^3+6*y^2 )
      assert( (part(2,,{1,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x*y^3+y^4+4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2 )
      assert( (part(,2,{1,0},f)) === 6*x^2*y^2+4*x*y^3+y^4+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(,2,{0,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x^3+12*x^2*y+12*x*y^2+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(,2,{1,1},f)) === 6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,2,{1,0},f)) === 6*x^2*y^2+4*x*y^3+y^4+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,2,{0,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x^3+12*x^2*y+12*x*y^2+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,2,{1,1},f)) === 6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,infinity,{1,0},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x*y^3+y^4+4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,infinity,{0,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x*y^3+y^4+4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )
      assert( (part(-infinity,infinity,{1,1},f)) === x^4+4*x^3*y+6*x^2*y^2+4*x*y^3+y^4+4*x^3+12*x^2*y+12*x*y^2+4*y^3+6*x^2+12*x*y+6*y^2+4*x+4*y+1 )