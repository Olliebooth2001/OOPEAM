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
List<Game*>  Store::searchByPriceRange(int priceRange) {

	if (priceRange == 1) {
		for (int i = 0; i < getGames().length(); i++) {
			if (getGames()[i]->GetCost() < 1000) {
				getResults().addAtEnd(getGames()[i]);
			}
		}
	}
	if (priceRange == 2) {
		for (int i = 0; i < getGames().length(); i++) {
			if (getGames()[i]->GetCost() > 1000 && getGames()[i]->GetCost() < 2000) {
				getResults().addAtEnd(getGames()[i]);
			}
		}
	}
	if (priceRange == 3) {
		for (int i = 0; i < getGames().length(); i++) {
			if (getGames()[i]->GetCost() > 2000) {
				getResults().addAtEnd(getGames()[i]);
			}
		}
	}
	return getResults();

}
List<Game*>& Store::getResults() {

	return results;

}

List<Game*> Store::searchByName(std::string inputString) {

	for (int i = 0; i < getGames().length(); i++) {


		if (Utils::StartsWith(getGames()[i]->GetName(), inputString) == true) {
			getResults().addAtEnd(getGames()[i]);
		}

	}
	return getResults();
}