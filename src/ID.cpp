#include "ID.h"

string ID::stringType()
{

	if (type == 0)return "admin";
	if (type == 1)return "student";
	if (type == 2)return "teacher";

}
