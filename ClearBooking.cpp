#include "ClearBooking.h"

void ClearBooking::loop()
{
	system("cls");
	data->clearBooking();
	cout << "已清空预约记录\n";
	system("pause");
	exit();
}
