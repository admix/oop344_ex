#ifndef __SPEAKER__
#define __SPEAKER__

#include "iSpeaker.h"
#include "SoundMaker.h"

class Speaker : public SoundMaker, public iSpeaker
   {
   private:
   protected:
   public:
      Speaker() : SoundMaker() {}
      void increaseVolume()
         {
         sound += "!";
         }
   };


#endif