/*
 
This is not official program by W Jung,
but it usess his code ( I hope in a good way)
   These functions are part of Mandel 5.9 by Wolf Jung (C) 2007-2013,
   which is free software; you can
   redistribute and / or modify them under the terms of the GNU General
   Public License as published by the Free Software Foundation; either
   version 3, or (at your option) any later version. In short: there is
   no warranty of any kind; you must redistribute the source code as well.
   
   http://www.mndynamics.com/indexp.html
   
   to compile :
   g++ w.cpp -Wall -lm
   ./a.out
   
   
*/

#include <iostream> // std::cout
#include <complex> // std::complex, std::norm

#define  PI      3.1415926535897932385L //from mndynamo.h

// type qulonglong  = unsigned long long int 
// n is a numerator of external angle that land on root point of the wake k/r
// d is a denominator 
// funcion mndAngle::wake from mndcombi.cpp  by Wolf Jung (C) 2007-2013
unsigned long long int wake(int k, int r, unsigned long long int  &n)
{  
   if (k <= 0 || k >= r || r > 64) return 0LL; // 
   unsigned long long int  d = 1LL; int j, s = 0; n = 1LL;
   
   for (j = 1; j < r; j++)
   {  s -= k; 
      if (s < 0) s += r; 
      if (!s) return 0LL;
      if (s > r - k) n += d << j;
   }
   d <<= (r - 1); 
   d--; 
   d <<= 1; 
   d++; //2^r - 1 for r <= 64
   
   return d;
}

// from mndynamo.cpp  by Wolf Jung (C) 2007-2013
void root(double x, double y, double &u, double &v)
{  v = sqrt(x*x + y*y);
   if (x > 0.0) { u = sqrt(0.5*(v + x)); v = 0.5*y/u; return; }
   if (x < 0.0)
   { v = sqrt(0.5*(v - x)); if (y < 0.0) v = -v; u = 0.5*y/v; return; }
   if (y >= 0.0) { u = sqrt(0.5*y); v = u; return; }
   u = sqrt(-0.5*y); v = -u;
}

// int mndlbrot::bifurcate from mndlbrot.cpp  by Wolf Jung (C) 2007-2013
// type mndplex = complex 
int bifurcate(double t, double &a, double &b)
{  int per = 1; if (a < -0.75) per = 2;
   if (a < -1.5 || b > sqrt(27/64.0L) || b < -sqrt(27/64.0L) ) per = 3;
   if (t <= -1.0) return per;
   t *= (2*PI);
   if (per == 1)
   { a = 0.5*cos(t) - 0.25*cos(2*t); b = 0.5*sin(t) - 0.25*sin(2*t); }
   if (per == 2) { a = 0.25*cos(t) - 1.0; b = 0.25*sin(t); }
   if (per <= 2) return per;
   std::complex<double> u, c, c1, l = std::complex<double>(cos(t), sin(t));
   if (a < -1.54) c1 = -1.754877666;
   else
   { c1 = std::complex<double>(-.122561167, .744861767); if (b < 0) c1 = conj(c1); }
   c = 81.0*l*l-528.0*l+4416.0; root(real(c), imag(c), a, b);
   u = pow(-13.5*l*l+144.0*l-800.0 + (-1.5*l+12.0)*std::complex<double>(a, b), 1/3.0);
   c = (1/3.0)*(.25*u + (1.5*l+4.0)/u - 2.0);
   if (norm(c - c1) > .25)
   { u *= std::complex<double>(-0.5, sqrt(0.75)); c = (1/3.0)*(.25*u + (1.5*l+4.0)/u - 2.0); }
   if (norm(c - c1) > .25)
   { u *= std::complex<double>(-0.5, sqrt(0.75)); c = (1/3.0)*(.25*u + (1.5*l+4.0)/u - 2.0); }
   a = real(c); b = imag(c); return 3;
} //bifurcate

// mndlbrot::find from mndlbrot.cpp  by Wolf Jung (C) 2007-2013
// sign 		int. Defined in mndynamo.h  positive is parameter plane, negative is dynamic plane."
int find(int sg, unsigned int preper, unsigned int per, double cx, double cy, double &x, double &y) 
{  double a = cx, b = cy, fx, fy, px, py, w; 
   unsigned int i, j;
   for (i = 0; i < 30; i++)
   {  if (sg > 0) { a = x; b = y; }
      if (!preper)
      {  if (sg > 0) { fx = 0; fy = 0; px = 0; py = 0; }
         else { fx = -x; fy = -y; px = -1; py = 0; }
      }
      else
      {  fx = x; fy = y; px = 1.0; py = 0;
         for (j = 1; j < preper; j++)
         {  if (px*px + py*py > 1e100) return 1;
            w = 2*(fx*px - fy*py); py = 2*(fx*py + fy*px);
            px = w; if (sg > 0) px++;
            w = fx*fx - fy*fy + a; fy = 2*fx*fy + b; fx = w;
         }
      }
      double Fx = fx, Fy = fy, Px = px, Py = py;
      for (j = 0; j < per; j++)
      {  if (px*px + py*py > 1e100) return 2;
         w = 2*(fx*px - fy*py); py = 2*(fx*py + fy*px);
         px = w; if (sg > 0) px++;
         w = fx*fx - fy*fy + a; fy = 2*fx*fy + b; fx = w;
      }
      fx += Fx; fy += Fy; px += Px; py += Py;
      w = px*px + py*py; if (w < 1e-100) return -1;
      x -= (fx*px + fy*py)/w; y += (fx*py - fy*px)/w;
   }
   return 0;
}

// =====================================================================================================================
// ====================================================================================================================
// ========================================================================================================================

int main()
{
  unsigned long long int p, q;
  unsigned long long int num, denom;
  double cx,cy;
  double zx,zy;
  double t;
  
  // --------------------------------------------------------------------------------------------------------------------
  // --------------------  initial value ------------------------------------------------------------------------------
  // ------------------------------------------------------------------------------------------------------------------
   std::cout << "Determine the wake of a limb at the main cardioid of Mandelbrot set. " << "\n";
   std::cout << "Enter a fraction  k/r  for the rotation number, in lowest terms, with  1 <= k < r < 64 " << "\n";    
  while (1)
    {
        std::cout << " Enter numerator of the rotation number, it is integer  1 <= k < 64 :  " << "\n";
        std::cin >> p ;

        if (std::cin.fail()) // no extraction took place
        {
            std::cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            std::cin.ignore(1000, '\n'); // clear out the bad input from the stream
            continue; // try again
        }

        std::cin.ignore(1000, '\n'); // clear out any additional input from the stream

        if (p >= 0) break; // if input value is in good range then exit

	
    }

  
  while (1)
    {
        std::cout << "Enter the denominator of the rotation number, it is integer 1 <= r < 64 :  " << "\n";
        std::cin >> q ;

        if (std::cin.fail()) // no extraction took place
        {
            std::cin.clear(); // reset the state bits back to goodbit so we can use ignore()
            std::cin.ignore(1000, '\n'); // clear out the bad input from the stream
            continue; // try again
        }

        std::cin.ignore(1000, '\n'); // clear out any additional input from the stream

        if (q > 0) break; // if input value is in good range then exit

	
    }
    
  std::cout.precision( 15 );  
  std::cout << "The rotation number is " << p << "/" << q << "\n";
  denom = wake(p,q,num);  
    
  if (denom!=0LL)
  {
    
    std::cout << "The "<< p << "/" <<q <<" wake of the main cardioid is bounded by the parameter rays with the angles :\n";
    std::cout << num << "/" << denom << " and "<< num+1 << "/" << denom << "\n";
  }
  else std::cout << "(k <= 0 || k >= r || r > 64) \n";
  
  t=(double)p/((double)q);
  bifurcate(t, cx,cy);
  std::cout << "The root point of wake is c = "<< cx << " ; " << cy << ":\n";
  
  find(-1,0,1,cx,cy,zx,zy);
  std::cout << "The fixed point alfa is z = "<< zx << " ; " << zy << ":\n";

   return 0;
}
