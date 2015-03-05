/*  # Lab07
	Due 3/06/15
	https://github.com/jdbivens42/Lab07/
	Katherine (Katie) Brown, Joe Bivens, Curtis Patel
*/

#if !defined (ROMBERGINTEGRATION_H)
#define ROMBERGINTEGRATION_H

#include "MultiVarFunction.h"

class RombergIntegration
{

   private:

   public:
      static double accurateRomberg(MultiVarFunction* f, double a, double b, int level);
      
};

#endif
