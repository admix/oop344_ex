#ifndef __I_BELL__
#define __I_BELL__

#include "iSoundMaker.h"

class iBell : public iSoundMaker
   {
   private:
   protected:
   public:
      virtual void switchHammer() = 0;
   };


#endif