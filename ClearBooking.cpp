#include "ClearBooking.h"

void ClearBooking::loop()
{
	system("cls");
	data->clearBooking();
	cout << "�����ԤԼ��¼\n";
	system("pause");
	exit();
}
