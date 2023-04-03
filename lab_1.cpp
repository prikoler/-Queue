#include <iostream>
#include <cstring>

using namespace std;

struct phone
{
	char phone_sourсe[11];
	char phone_receiver[11];
	float time;
	phone* link;
	phone* link1;
	
};

int x;
char phone_tmp[11];
float time5, max_time;

phone* p, * back, * top, * del, * top_, * back_, *top1, *back1, *tmp, *tmp_;

void out_info(phone* h)
{
	cout << "Информация о разговорах:\n";
	
	while (h)
	{
		cout << "Источник : " << h->phone_sourсe << endl;
		cout << "Приёмник : " << h->phone_receiver << endl;
		cout << "Время : " << h->time << endl;

		h = h->link;
	}
}
void out_upnumber_info(phone * h)
{
	cout << "Информация о разговорах:\n";

	while (h)
	{
		cout << "Источник : " << h->phone_sourсe << endl;
		cout << "Приёмник : " << h->phone_receiver << endl;
		cout << "Время : " << h->time << endl;

		h = h->link1;
	}
}
void in_info()
{
	float time;
	while (1)
	{
		cout << "   1-Вести информацию о телефоном звонке\n   0-Окончание Ввода\n :- ";
		cin >> x;
		if (x == 0)
			break;

		back->link = new phone;
		back = back->link;

		cout << "\nВведите номер источника звонка - ";
		cin >> back->phone_sourсe;

		cout << "\nВведите номер приёмника звонка - ";
		cin >> back->phone_receiver;

		cout << "\nВведите продолжительнсть раговора в минутах -  ";
		cin >> time;
		back->time = time;

		if (time > max_time)
		{
			max_time = time;
		}
		tmp = top1;
		tmp_ = top1;
		while (tmp)
		{
			if (strcmp(back->phone_sourсe, back1->phone_sourсe) > 0)
			{
				back1->link1 = back;
				back1 = back1->link1;
				back1->link1 = 0;
			}
			
			
			
				if (strcmp(back->phone_sourсe, tmp->phone_sourсe) < 0 )
				{
					if (tmp == top1)
					{
						back->link1 = top1;
						top1 = back;
						break;
					}
					else
					{
						tmp_->link1 = back;
						tmp_ = tmp_->link1;
						tmp_->link1 = tmp;
					}
				}
			
			tmp_ = tmp;
			tmp = tmp->link1;
		}


	}
	back->link = 0;
}
void delyzel()
{
	while (1)
	{

		cout << " 1 - указать номер, информацию о разговоре с которым надо удалить\n 0 - выход\n :- ";
		cin >> x;
		if (x == 0)
			break;
		cout << "укажите номер, информацию о разговоре с которым надо удалить -  ";
		cin >> phone_tmp;
		del = top;
		p = top;
		while (p)
		{
			if (strcmp(p->phone_sourсe, phone_tmp) == 0)
			{
				if (del == p)//если предыдущий указатель равен идущему 
				{
					top = del->link;
					del = top;
					delete p;
					p = del;
				}
				else
				{
					del->link = p->link;// указатель связи предыдущего указываем на последующую структуру
					delete p;
					p = del->link;
				}
			}
			else
			{
				del = p;
				p = p->link;
			}
		}

	}
}
void maxtime5()
{
	del = top;
	p = top;
	while (p)
	{

		if (p->time > 5)
		{
			time5 = p->time;
			top_ = new phone; // создаю дополнительную очередь
			back_ = top_;
			while (time5 > 5)
			{

				strcpy(top_->phone_sourсe, p->phone_sourсe);
				strcpy(top_->phone_receiver, p->phone_receiver);
				top_->time = 5;
				time5 = time5 - 5;
				top_->link = new phone;
				top_ = top_->link;
			}
			strcpy(top_->phone_sourсe, p->phone_sourсe);
			strcpy(top_->phone_receiver, p->phone_receiver);
			top_->time = time5;
			top_->link = p->link; //конец дополнительной очерди связываю с оснойной очереди после узла с временем больше 5
			if (del == p)//если предыдущий указатель равен идущему 
			{
				top = back_;
			}
			else //предыдущий узел связываю с началом дополнительной очереди
			{
				del->link = back_;
			}
			delete p;

			p = top_;
		}
		del = p;
		p = p->link;

	}
}


int main()
{
		setlocale(0, "rus");
	{
		// Создаю первый узел очереди
		top = new phone;
		top1 = top;
		cout << "Введите информацию о телефоном звонке\n";
		cout << "Введите номер источника звонка - ";

		cin >> top->phone_sourсe;

		cout << "Введите номер приёмника звонка - ";
		cin >> top->phone_receiver;

		cout << "Введите продолжительнсть раговора в минутах -  ";
		cin >> max_time;
		top->time = max_time;
		back = top;
		back1 = back;
		back->link = 0;
		back1->link1 = 0;
		in_info();
	}
	
	while (x!=6)
	{
		system("pause");
		system("cls");
		cout << "Выберите действие из списка меню :\n";
		cout << "1. Вывести информацию в порядке исходного ввода данных\n";
		cout << "2. Вывести информацию в порядке роста исходящих номеров\n";
		cout << "3. Добавить новый узел в список\n";
		cout << "4. Удалить узел\n";
		cout << "5. Заменить узлы, соответствующие звонкам с продолжительностью больше 5-ти на соответствующее количество узлов, имеющих длительность разговора <=5 \n";
		cout << "6. Выйти из меню.\n :-";
		cin >> x;
		switch (x)
		{
		case 1:
			p = top;
			out_info(p);
			break;
		
		case 2:
			p = top1;
			out_upnumber_info(p);
			break;
		case 3:
		
			in_info();
			break;
		
		case 4:
		
			delyzel();
			break;
		
		case 5:
		
			maxtime5();
			break;
		
		default:
			break;
		}
	}
	while (top) // Очистка памяти
	{
		back = top;
		top = top->link;
		delete back;
	}

} 
