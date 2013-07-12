#ifndef __BELL__
#define __BELL__

#include "iBell.h"
#include "SoundMaker.h"

class Bell : public SoundMaker, public iBell
   {
   private:
   protected:
   public:
      Bell() : SoundMaker() {sound = "Ding"}
      void switchHammer() 
         {
         if(sound == "Ding")
            sound = "Dong";
         else
            sound = "Ding";
         }
   };


#endif