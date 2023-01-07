#include "ClearBooking.h"

void ClearBooking::loop()
{
	system("cls");
	data->clearBooking();
	cout << "booking items cleared!\n";
	system("pause");
	exit();
}
