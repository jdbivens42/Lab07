/*  # Lab07
	Due 3/06/15
	https://github.com/jdbivens42/Lab07/
	Katherine (Katie) Brown, Joe Bivens, Curtis Patel
*/
#include "Problem22_1.h"
#include "RombergIntegration.h"
#include "RecursiveIntegration.h"

#include <iostream>
using namespace std;
#include <math.h>

Problem22_1::Problem22_1() 
{}

Problem22_1::~Problem22_1()
{}

//the function evaluation depends on the current values for the parameters
double Problem22_1::evaluate(double* xy)
{
	//random comment
   double x = xy[0];
   double result = 2*x;
   result += 3/x;
   result *= result;
   return result;
}

double Problem22_1::integrate(int level)
{
   return RombergIntegration::accurateRomberg(this, lower, upper, level);
}

//insert a set limits method to set the upper and lower limits
void Problem22_1::setLowerLimit(double a)
{
   lower = a;
}

void Problem22_1::setUpperLimit(double b)
{
   upper = b;
}

int main()
{
   Problem22_1* p = new Problem22_1();  //mean = 10.5, variance = 5.7
	#if DEBUG
	cout << "Created the problem\n";
	#endif
   //lower limits
   p->setLowerLimit(1.0);
   p->setUpperLimit(2.0);
   #if DEBUG
	cout << "Limits set\n";
	#endif
   double result;

   #if DEBUG
   cout << "Begin integration\n";
   #endif
   
   result = p->integrate(0);
   cout << "The area under the curve using accurate Romberg level 0: " << result << endl;

   result = p->integrate(1);
   cout << "The area under the curve using accurate Romberg level 1: " << result << endl;

   result = p->integrate(2);
   cout << "The area under the curve using accurate Romberg level 2: " << result << endl;

   result = p->integrate(3);
   cout << "The area under the curve using accurate Romberg level 3: " << result << endl;

   #if DEBUG
	cout << "End integration\n";
	#endif
   delete p;
   return 0;
}
