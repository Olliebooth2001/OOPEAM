#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int ageRating, int ID, int likes, int dislikes)
	: name(name), description(desc), cost(cost), ageRating(ageRating), id(ID), likes(likes), dislikes(dislikes)
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

float Game::GetLikes()
{
	return likes;
}

float Game::GetDislikes()
{
	return dislikes;
}

float Game::GetRating()
{

	if (dislikes == 0 && likes == 0)
	{
		return 0;
	}

	if (dislikes == 0 && likes > 0)
	{
		return 100.0f;
	}
	
	
	return (likes / (dislikes + likes)) * 100;
	
	
}

void Game::addLike()
{
	likes++;
}

void Game::addDislike()
{
	dislikes++;
}
