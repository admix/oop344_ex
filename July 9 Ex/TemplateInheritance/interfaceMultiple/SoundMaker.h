#ifndef __SOUND_MAKER__
#define __SOUND_MAKER__

#include <string>
#include <iostream>
#include "iSoundMaker.h"
#include "Base.h"
template <class T = iSoundMaker>
class SoundMaker : public Base<T>
   {
   private:
   protected:
      std::string sound;
   public:
      SoundMaker() : Base<T>(), sound("Bang") {}
      void playSound() 
	  {
		  std::cout << sound << "\n";
	  }
   };


#endif