#ifndef __BASE__
#define __BASE__

#include "iBase.h"
template <class T = iBase>
class Base : public T
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