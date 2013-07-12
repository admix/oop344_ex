#ifndef __BASE__
#define __BASE__

#include "iBase.h"

class Base : public iBase
   {
   private:
      static unsigned int count;

      unsigned int id;
   protected:
   public:
      Base() : id(count++) {}
      unsigned int getID() {return id;}
   };


#endif