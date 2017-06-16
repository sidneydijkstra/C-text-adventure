// key.h

#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include "item.h"
#include "player.h"
#include "room.h"

class Key : public Item {
public:
	Key(Player* player, std::string name, int weight);
	~Key();

	// food use function
	void use();
private:

	// player
	Player* _player;
};

#endif /* KEY_H */