#ifndef __BELL__
#define __BELL__

#include "iBell.h"
#include "SoundMaker.h"

template <class T = iBell>
class Bell : public SoundMaker<T>
   {
   private:
   protected:
   public:
      Bell() : SoundMaker<T>() {this->sound = "Ding";}
      void switchHammer() 
         {
         if(this->sound == "Ding")
            this->sound = "Dong";
         else
            this->sound = "Ding";
         }
   };


#endif