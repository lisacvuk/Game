#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <irrlicht.h>

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;

class Game{
private:
  IrrlichtDevice *device;
  IVideoDriver* driver;
  IGUIEnvironment* guienv;
  ISceneManager* smgr;
  ICameraSceneNode* camera;
  class EventReceiverClass : public IEventReceiver{
  public:
  bool runn;
  virtual bool OnEvent(const SEvent &TEvent);
  };
  class Quake3Stuff{
  public:
    void loadPK3Archive(const io::path);
  };
  EventReceiverClass eventRec;

public:
  Game();
  void startGame();
  void mainLoop();
  void loadTerrain();
  void setupCamera();
  void setupHud();
  //Utility functions
};

#endif
