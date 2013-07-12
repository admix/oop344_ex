#ifndef __I_SOUND_MAKER__
#define __I_SOUND_MAKER__

#include "iBase.h"

class iSoundMaker : public iBase
   {
   private:
   protected:
   public:
      virtual void playSound() = 0;
   };


#endif