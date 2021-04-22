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
		int GetLikes();
		int GetDislikes();
		int GetRating();
		void addLike();
		void addDislike();
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int id;
		int likes;
		int dislikes;
		int rating;
};