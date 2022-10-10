#include "head.h"

int main()
{
	setlocale(0, "");


	cout << "Введите количество улиток: ";
	cin >> snailsCount;
	if (snailsCount == 1)
	{
		cout << "Улитка в замешательстве" << endl;
		system("pause");
		return 0;
	}
	Snail* snails = new Snail[snailsCount];
	cout << "Введите координаты для каждой улитки." << endl;
	for (int i = 0; i < snailsCount; i++)
	{
		cout << "улитка " << i+1 << ":\nX: ";
		cin >> snails[i].x;
		cout << "Y: ";
		cin >> snails[i].y;
		cout << endl;
	}
	float shortest_path = 141422;//самое большое расстояние,которое может быть
	float temp = 0;
	int l = 0;
	for (int i = 0; i < snailsCount; i++)
	{
		for (int j = 0; j < snailsCount; j++)
		{
			if (i != j)
			{
				temp = pathlength(snails[i].x, snails[i].y, snails[j].x, snails[j].y);
				snails[i].paths[l] = temp;
				if (temp < shortest_path)
					shortest_path = temp;
				l++;
			}
		}
		snails[i].sortTime();
		l = 0;
	}
	int k = 0;
	for (int i = 0; i < snailsCount; i++)
	{
		if (snails[i].confusion)
		{
			cout << "Улитка " << i+1 << " в замешательстве\n";
			k++;
		}
	}
	cout << "среднее время сортировки = " << avg_time / snailsCount << " millisec." << endl;
	if (k != snailsCount)
		cout << "кратчайшее время = " << shortest_path / 2 << " секунд " << endl << endl;
	system("pause");
	return 0;
}