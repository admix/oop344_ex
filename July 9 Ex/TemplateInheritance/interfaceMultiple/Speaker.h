#ifndef __SPEAKER__
#define __SPEAKER__

#include "iSpeaker.h"
#include "SoundMaker.h"
template <class T = iSpeaker>
class Speaker : public SoundMaker<>
   {
   private:
   protected:
   public:
      Speaker() : SoundMaker<>() {}
      void increaseVolume()
         {
         this->sound += "!";
         }
   };


#endif