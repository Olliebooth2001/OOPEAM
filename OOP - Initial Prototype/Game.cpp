#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating, int ID)
	: name(name), description(desc), cost(cost), ageRating(rating), id(ID)
{
}

Game::~Game()
{
}

int Game::GetID() const
{
	return id;
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}

int Game::GetRating() const
{
	return ageRating;
}