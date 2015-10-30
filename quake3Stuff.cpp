#include "main.h"

void Game::loadPK3Archive(const io::path &path){
  device->getFileSystem()->addFileArchive(path.c_str());
}
void Game::loadMap(const io::path &path){
  map = (scene::IQ3LevelMesh*) smgr->getMesh(path.c_str());
  if(map){
  IMesh * const geometry = map->getMesh(quake3::E_Q3_MESH_GEOMETRY);
  mapNode = smgr->addOctreeSceneNode(geometry, 0, -1, 4096);
  }
}
