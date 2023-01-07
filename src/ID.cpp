#include "ID.h"

string ID::stringType()
{

	if (type == 0)return "管理员";
	if (type == 1)return "学生";
	if (type == 2)return "教师";

}
