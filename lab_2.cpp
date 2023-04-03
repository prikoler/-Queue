#include <iostream>


using namespace std;


struct A
{
	 int inphone;
	int outphone;
	int min;
	A* u;
};

int main()
{
	setlocale(0, "RUS");
	int isxod;
	cout << "ВВедите исходный номер =";
	cin >> isxod;
	cout << endl;
	A* top, * bot, * h;
	int maxm = 0;
	int t = 0;
	cout << "min=";
	cin >> t;
	if (t == 0)
	{
		return 0;
	}
	bot = top = new A;
	bot->min = t;
	cout << "inphone=";
	cin >> bot->inphone;
	cout << "\n";
	cout << "outphone=";
	cin >> bot->outphone;
	cout << "\n";
	maxm = t;
	while (1)
	{
		cout << "min=";
		cin >> t;
		cout << "\n";
		if (t == 0)
		{
			break;
		}
		bot->u = new A;
		bot->u->min = t;
		cout << "inphone=";
		cin >> bot->u->inphone;
		cout << "\n";
		cout << "outphone=";
		cin >> bot->u->outphone;
		cout << "\n";
		if (maxm < t)
		{
			maxm = t;
		}
		bot = bot->u;
	}
	bot->u = 0;
	h = top;
	//3 удаление исходного
	
	if (h->inphone == isxod)
	{
		A* gg;
		gg = h->u;
		delete top;
		top = gg;
	}
	
	h = top;
	while (h->u)
	{

		if (h->u->inphone == isxod)
		{
			A* aa;
			aa = h->u->u;
			delete h->u;
			h->u = aa;
		}
		if (h->u)
		{
			h = h->u;
		}
	}
	h = top;
	//3
	if (h->min > 5)
	{
		A* gg;
		gg = h->u;
		int min1, in1, out1;
		min1 = h->min-5;
		in1 = h->inphone;
		out1 = h->outphone;
		h->min = 5;
		while (1)
		{
			h->u = new A;
			if (min1 - 5 > 0)
			{
				h->u->min = 5;
				h->u->outphone = out1;
				h->u->inphone = in1;
				min1 -= 5;
				h = h->u;
			}
			else
			{
				if (min1 == 0)
				{
					break;
				}

				h->u->outphone = out1;
				h->u->inphone = in1;
				h->u->min = min1;
				h->u->u = gg;
				break;
			}
		}
	}
	h = top;
	while (h->u)
	{
		if (h->u->min > 5)
		{
			A* gg;
			gg = h->u->u;
			int min1, in1, out1;
			min1 = h->u->min;
			in1 = h->u->inphone;
			out1 = h->u->outphone;
			delete h->u;
			while (1)
			{
				h->u = new A;
				if (min1 - 5 > 0)
				{
					h->u->min = 5;
					h->u->outphone = out1;
					h->u->inphone = in1;
					min1 -= 5;
					h = h->u;
				}
				else
				{
					if (min1 == 0)
					{
						break;
					}

					h->u->outphone = out1;
					h->u->inphone = in1;
					h->u->min = min1;
					h->u->u = gg;
					break;
				}
			}
		}
		if (h->u)
		{
			h = h->u;
		}
	}
	h = top;
	while (h)
	{

		cout << h->min << endl;
		cout << h->inphone << endl;
		cout << h->outphone << endl;
		h = top->u;
		delete top;
		top = h;
	}
}
/*Для списка из "Работы №2" необходимо выполнить следующие преобразования:
1) Удалить из списка все узлы, содержащие заданный исходящий номер;
2) Заменить узлы, соответствующие звонкам с продолжительностью больше 5-ти на соответствующее количество узлов,
имеющих длительность разговора <=5 по максимуму так, чтобы суммарная длительность в замещающих узлах была равна исходной.
Например, если в узле было 14, то будет 5, 5 и 4.*/
