#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, int credit)
	: Player(username, password, created, credit)
{
}

Admin::~Admin()
{
}

bool Admin::HasPermissions()
{
	return true;
}
