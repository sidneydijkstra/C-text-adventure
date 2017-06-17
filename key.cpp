#include "key.h"

// food constructor
Key::Key(Player* player, std::string name, std::string _description, int weight) : Item(name, _description, weight) {
	_player = player;
}

// key use function
void Key::use() {
	std::vector<Room*> _rooms = _player->getCurrentRoom()->getClosedRooms();

	if (!_rooms.empty()) {
		for (int i = 0; i < _rooms.size(); i++){
			_rooms[i]->canOpen(this);
		}
	}else {
		// MESSAGE: there is no closed room
		std::cout << "There is no closed room so why use a key?" << std::endl;
	}
}

// key deconstructor
Key::~Key() {
}