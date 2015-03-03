#include "RombergIntegration.h"
#include "RecursiveIntegration.h"
#include "QueueLinked.h"
#include "Double.h"
using CSC2110::Double;

#include <math.h>

//a is the lower limit and b is the upper limit
double RombergIntegration::accurateRomberg(MultiVarFunction* f, double a, double b, int level)
{
	#if DEBUG
	cout << "Creating objects\n";
	#endif
   Double* db;  //use this variable to place and retrieve values on the queue
   
   #if DEBUG
   cout << "Created double\n";
   #endif
   
   QueueLinked<Double>* q1 = new QueueLinked<Double>();
   QueueLinked<Double>* q2 = new QueueLinked<Double>();

   #if DEBUG
	cout << "Finished Creating objects\n\n\n";
	#endif

   int counter = 0;
   int n = 1;  //current number of intervals
   while ( counter < level + 1)
   {
	   #if DEBUG
	   cout << "Counter: " << counter << endl;
	   cout << "n: " << n << endl;
	   #endif
	   //random comment
      //DO THIS
      //obtain the required number of trapezoid evaluations depending on the number of levels requested
      //put all of the level 0 results on the q1

		#if DEBUG
		cout << "About to calculate res\n";
		#endif
		double res = RecursiveIntegration::romberg(f, a, b, n);
		#if DEBUG
		cout << "Res: " << res << endl;
		#endif
		db = new Double(res);
		q1->enqueue(db); 
        //double the number of intervals
		n = 2*n;

		
		double res = accurateRomberg(f, a, b, n);
		Double* d = new Double(res);
		q1->enqueue(d); 

      n = 2*n;  //double the number of intervals

      counter++;
   }

   //q1 now has all of the level 0 integration results

   double factor;  //use this to compute the current Romberg Factor (4^k stuff)
   int power = 1;  //k, used to compute the Romberg Factor

   //if level 0 has been requested, the loop will not execute
   //the total number of executions of the loop is ??

   //DO THIS
   //did that
   int iterations =  ( level * (level+1))/2;            //can be precomputed
   while (iterations > 0)
   {
      //DO THIS
      //use the algorithm described in the lab to improve the accuracy of your level 0 results
		

		db = q1->dequeue();
		double more = db->getValue();
		db = q1->peek();
		double less = db->getValue();

		Double* more_Double = q1->dequeue();
		double more = more_Double->getValue();
		delete more_Double;
		Double* less_Double = q1->peek();
		double less = less_Double->getValue();
		delete less_Double;

		factor = pow(4, power);

		double res = ((factor * more) - less) / (factor - 1);
		delete db;
		
		db = new Double(res);
		q2->enqueue(db);
		power++;
		if(q1->size() == 1)
		{
			db = q1->dequeue();
			delete db;
			
			QueueLinked<Double>* temp = q1;
			q1 = q2;
			q2 = temp;
			
		}
	
 iterations--;
   }

   //obtain the final answer
   db = q1->dequeue();
   double result = db->getValue();  
   delete db;

   delete q1;
   delete q2;

   return result;
}
