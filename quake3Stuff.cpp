#include "main.h"

void Game::Quake3Stuff::loadPK3Archive(const io::path &path){
  device->getFileSystem()->addZipFileArchive(path);
}
