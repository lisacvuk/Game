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
  ISceneNode* mapNode = 0;
  IQ3LevelMesh* map;
  class EventReceiverClass : public IEventReceiver{
  public:
    bool runn;
    virtual bool OnEvent(const SEvent &TEvent);
  };
  EventReceiverClass eventRec;

public:
  Game();
  void startGame();
  void mainLoop();
  void loadTerrain();
  void setupCamera();
  void setupHud();
  void loadLevel(const signed int);
  //Quake 3 functions
  void loadPK3Archive(const io::path&);
  void loadMap(const io::path&);
  //Utility functions
};

#endif
