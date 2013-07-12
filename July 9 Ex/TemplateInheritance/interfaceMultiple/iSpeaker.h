#ifndef __I_SPEAKER__
#define __I_SPEAKER__

#include "iSoundMaker.h"

class iSpeaker : public iSoundMaker
   {
   private:
   protected:
   public:
      virtual void increaseVolume() = 0;
   };


#endif