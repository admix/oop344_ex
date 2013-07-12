#ifndef __SOUND_MAKER__
#define __SOUND_MAKER__

#include <string>
#include <iostream>
#include "iSoundMaker.h"
#include "Base.h"

class SoundMaker : public Base, public iSoundMaker
   {
   private:
   protected:
      std::string sound;
   public:
      SoundMaker() : Base(), sound("Bang") {}
      void playSound() {std::cout << sound << "\n";}
   };


#endif