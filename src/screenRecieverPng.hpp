#ifndef SCREEN_RECIEVER_PNG_HPP_INCLUDED
#define SCREEN_RECIEVER_PNG_HPP_INCLUDED

#include "screenReciever.hpp"
#include <aio.h>

struct Frame
{
   aiocb* file;
   double time;
};

class ScreenRecieverPng : public ScreenReciever
{
   public:
   virtual void setImageManager(boost::shared_ptr<ImageManager> manager);
   virtual void processScreen( boost::shared_ptr<ImageType> );
   virtual void setSize(int width, int height);
   virtual void stopProcess();

   private:

   int evFd;
      int width;
      int height;
      boost::shared_ptr<ImageManager> manager;

      std::vector<Frame> frames;

};

#endif