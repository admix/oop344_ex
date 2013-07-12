#include "Speaker.h"
#include "Bell.h"

int main()
   {
   Speaker a;
   Speaker b;

   Bell c;

   a.playSound();
   a.increaseVolume();

   
   b.increaseVolume();
   b.playSound();
   
   c.playSound();
   c.switchHammer();
   c.playSound();

   std::cout << a.getID() << " " << b.getID() << " " c.getID();

   }