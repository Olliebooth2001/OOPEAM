#pragma once

#include <string>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int, int, int, int);
		~Game();

		int GetID() const;
		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		int GetRating() const;
		float GetLikes();
		float GetDislikes();
		float GetRating();
		void addLike();
		void addDislike();
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int id;
		float likes;
		float dislikes;
		float rating;
};