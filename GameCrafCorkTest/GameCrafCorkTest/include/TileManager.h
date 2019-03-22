#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <vector>
#include "Tile.h"
#include "Shape.h"

class TileManager
{
public:
	TileManager();
	~TileManager();
private:
	std::vector<std::vector<Tile>> m_tileVector;
};

#endif

