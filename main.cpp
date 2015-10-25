#include "main.h"

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;
using namespace io;

Game::Game(){
  device = createDevice( video::EDT_OPENGL, dimension2d<u32>(1280, 1024), 32, false, false, false, &eventRec);
  driver = device->getVideoDriver();
  smgr = device->getSceneManager();
  guienv = device->getGUIEnvironment();
  eventRec.runn = 1;
}

void Game::mainLoop(){
  while(device->run() && eventRec.runn){
    driver->beginScene(true, true, SColor(255,100,101,140));

    smgr->drawAll();
    guienv->drawAll();

    driver->endScene();
  }
}

void Game::loadTerrain(){
  ITerrainSceneNode* terrain = smgr->addTerrainSceneNode(
    "resources/other/heightmap.png",
    0,                  // parent node
    -1,                 // node id
    core::vector3df(0.f, 0.f, 0.f),     // position
    core::vector3df(0.f, 0.f, 0.f),     // rotation
    core::vector3df(40.f, 4.4f, 40.f),  // scale
    video::SColor ( 255, 255, 255, 255 ),   // vertexColor
    5,                  // maxLOD
    scene::ETPS_17,             // patchSize
    4                   // smoothFactor
    );
    terrain->setMaterialFlag(video::EMF_LIGHTING, false);
    terrain->setMaterialTexture(0, driver->getTexture("resources/other/heightmap_texture.png"));
    terrain->setPosition(vector3df(0, 0, 0));
    ITriangleSelector* selector = smgr->createTerrainTriangleSelector(terrain, 0);
    terrain->setTriangleSelector(selector);
    scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
    selector, camera, core::vector3df(10,10,10),
    core::vector3df(0,-9,0),
    core::vector3df(0,50,0));
    camera->addAnimator(anim);
    scene::ISceneNode* skybox=smgr->addSkyBoxSceneNode(
    driver->getTexture("resources/textures/skybox/coulee_up.jpg"),
    driver->getTexture("resources/textures/skybox/coulee_dn.jpg"),
    driver->getTexture("resources/textures/skybox/coulee_rt.jpg"),
    driver->getTexture("resources/textures/skybox/coulee_lf.jpg"),
    driver->getTexture("resources/textures/skybox/coulee_ft.jpg"),
    driver->getTexture("resources/textures/skybox/coulee_bk.jpg"));
}

void Game::startGame(){
  stringw ver_info = "Sniper version alpha";
  guienv->addStaticText(ver_info.c_str(), rect<s32>(10,10,360,22), false);
  IGUIFont* font_small = guienv->getFont("resources/other/font_small.xml");
  guienv->getSkin()->setFont(font_small);
  device->setWindowCaption(L"Sniper");
  setupCamera();
  loadTerrain();
  mainLoop();
}
void Game::setupCamera(){
  camera = smgr->addCameraSceneNodeFPS();
  device->getCursorControl()->setVisible(false);
  camera->setFarValue(999999);
  camera->setPosition(vector3df(100, 1000, 100));
  setupHud();
}
void Game::setupHud(){
  IAnimatedMesh* gunmesh = smgr->getMesh("resources/models/weapons/test.obj");
  IAnimatedMeshSceneNode* gunnode;
  if(gunmesh)
  {
             gunnode = smgr->addAnimatedMeshSceneNode(gunmesh, gunnode);
             gunnode->setParent(camera);
             gunnode->setPosition(vector3df(50, 0, 1000));
             gunnode->setRotation(vector3df(0, 0, 1000));
             gunnode->updateAbsolutePosition();
             std::cout << gunnode->getAbsolutePosition().X << ", " << gunnode->getAbsolutePosition().Y << ", "
            << gunnode->getAbsolutePosition().Z;
             //gunnode->setScale(vector3df(1, 1, 1));
  }
}
int main()
{
  Game game;
  game.startGame();
  // game.setupCamera();
  // game.loadTerrain();
  // game.renderer();
  return 0;
}
