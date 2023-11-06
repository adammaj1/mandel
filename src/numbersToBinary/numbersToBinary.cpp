/*
c++ console program based on the code by Wolf Jung https://www.mndynamics.com/

   These classes are part of Mandel 5.19, which is free software; you can
   redistribute and / or modify them under the terms of the GNU General
   Public License as published by the Free Software Foundation; either
   version 3, or (at your option) any later version. In short: there is
   no warranty of any kind; you must redistribute the source code as well.

=================================================================================

To compile in terminal window: 

cd ~/your_project_folder/
qmake -project
qmake
make

program name is directory name: "your_project_folder" so  to run it: 


./your_project_folder

-----------------------------------------------------------

binary expansion of external angle has preperiod = 0 and period = 3
external angle as a decimal fraction = 1/7
as binary floating point number in program mandel own notation = p001
 program mandel own notation: apb where a is a preperiodic part and b is a periodic part
 so apb in general math notation is 0.a(b)

----------------------------------------------------------

*/




#include <QTextStream>
#include <QString>
#include <cassert>

 typedef  unsigned long long int  qulonglong;
 typedef  long double  mdouble;
 
 // mndAngle::twice
void mndAngle_twice(qulonglong &n, qulonglong &d)
{  if (n >= d) return;
   if (!(d & 1)) 
   	{ d >>= 1; if (n >= d) n -= d; return; }
   qulonglong large = 1LL; 
   large <<= 63; //avoid overflow: large = large + 2^{63}
   if (n < large) 
   	{ n <<= 1; if (n >= d) n -= d; return; }
   n -= large; 
   n <<= 1; 
   large -= (d - large); 
   n += large;
}




// "The function is computing the preperiod and period (of n/d under doubling map)
// and setting the denominator to  2^preperiod*(2^period - 1) if possible.
// So 1/5 becomes 3/15 and 2/10 becomes 3/15 as well.
// The period is returned as the value of the function, 
// n and d are changed ( Arguments passed to function by reference)
// and the preperiod is returned in k." (Wolf Jung)
// 
/*
input 
n = numerator
d = denominator

output
p = period
k = preperiod
n = normalized numerator
d = normalized denominator

*/
int mndAngle_normalize(qulonglong &n, qulonglong &d, int &k)
{  if (!d) return 0;
   n %= d; 
   while (!(n & 1) && !(d & 1)) 
   	{ n >>= 1; d >>= 1; }
   int p; //
   qulonglong n0;
   qulonglong n1 = n; 
   qulonglong d1 = d;
   qulonglong np;
   
   k = 0; 
   while (!(d1 & 1)) 
   	{ k++; d1 >>= 1; if (n1 >= d1) n1 -= d1; }
   n0 = n1;
   for (p = 1; p <= 65 - k; p++) 
   	{ 	mndAngle_twice(n1, d1); 
   		if (n1 == n0) break; }
   if (k + p > 64) return 0; // "The angle  N1/N2 has  preperiod + period > 64."
   
   np = 1LL << (p - 1); np--; 
   np <<= 1; 
   np++; //2^p - 1 for p <= 64
   n0 = np; 
   d >>= k; 
   n1 = d; 
   if (n1 > n0) { n1 = n0; n0 = d; }
   while (1) 
   	{ d1 = n0 % n1; 
   	if (!d1) break; 
   	n0 = n1; 
   	n1 = d1; } //gcd n1
   	
   n /= d/n1; 
   n *= np/n1; 
   d = np << k;
   return p;
}


/*
convert decimal fraction n/d to binary fraction in mandel notation

input : 
 n = numerator of n/d
 d = denominator of n/d
 
output: b = binary floating point fraction in mandel notation ( QString)


*/
bool QmnCombiDialog_numbersToBinary(qulonglong n, qulonglong d, QString &text)
{  
	int k, p = mndAngle_normalize(n, d, k); 
	if (!p) return false; // if period == 0
	
	//if period is not zero 
	QTextStream(stdout) << "binary expansion of external angle has preperiod = "<< k << " and period = "<< p << Qt::endl;
	d >>= k; 
	QString t; 
	text.setNum(n / d, 2); 
	t.setNum(n % d, 2);
	if (k) 
		{ while (text.length() < k) text.prepend(QChar('0')); }
   		else text = QString("");
   		
   	while (t.length() < p) t.prepend(QChar('0'));
	t.prepend(QChar('p')); 
	if (p > 1 || !k) text.append(t);
	
	return true;
}







int main() {


 int n = 1;
 int d = 7;

 QString b;

 
 
 
 assert(n>0); // positive fraction
 assert(n<d); // proper fraction
 
 
 bool e = QmnCombiDialog_numbersToBinary(n, d, b);
 if (e == false) {QTextStream(stdout) << "error in QmnCombiDialog_numbersToBinary: period is 0 "<< d << Qt::endl; return 1;}
 
 
 QTextStream(stdout) << "external angle as a decimal fraction = "<< n << "/"<< d << Qt::endl;
 QTextStream(stdout) << "as binary floating point number in program mandel own notation = "<< b << Qt::endl;
 QTextStream(stdout) <<" program mandel own notation: apb where a is a preperiodic part and b is a periodic part" << Qt::endl;
 QTextStream(stdout) <<" so apb in general math notation is 0.a(b)" << Qt::endl;
 
 return 0;
}
