#include "Store.h"

Store::Store()
{



}

Store::~Store()
{

}

List<Game*>& Store::getGames() {

	return games;

}

void Store::addGame(Game* game) {

	games.addAtEnd(game);


}
