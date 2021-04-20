#include <iostream> 
#include <conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
const int keyRight = 77;
const int keyLeft = 75;
const int keyUp = 72;
const int keyDown = 80;
const int enter = 13;
const int escape = 27;
const int backspace = 8;
const int sleepTime = 1000;

struct mData {
	int index;
	char fam[20]; //type = 1
	char im[20]; //type = 2
	char otch[20]; //type = 3
	int group;
	int proga;
	int linal;
	int matan;
	int dm;
	double sredball;
	mData *prev;
	mData *next;
};

void gotoxy(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(handle, position);
}

int vvodCifr(int maxnum) {
	int chislo = 0, stepen = 0, maxStepen = -1, count = 0, T = 1;
	char number;
	int C[9] = { 0 }, i = 0;

	while (T) {
		switch (number = _getch()) {
		case enter: T = 0; break;
		case escape: exit(0); break;
		case backspace: {
			if (count > 0) {
				cout << "\b \b";
				count--;
			}
			if (i > 0) {
				C[i - 1] = 0;
				i--;
			}
			if (maxStepen > -1) {
				maxStepen--;
			}
		}
		default: {
			if (count == maxnum) { break; }
			else if (number > 47 and number < 58) { cout << number - 48; C[i] = number - 48; i++; count++; maxStepen++; } break;
		}
		}
	}

	for (int j = (count - 1); j >= 0; j--)
	{
		chislo += (C[j] * pow(10, stepen));
		if (stepen < maxStepen) {
			stepen++;
		}
	}
	return chislo;
}

void vvodStroki(mData *&tmp, int type){
	int T = 1, count = 0, i = 0;
	char C[20] = { 0 }, letter;

	while (T) {
		switch (letter = _getch()) {
		case enter: T = 0; break;
		case escape: exit(0); break;
		case backspace: {
			if (count > 0) {
				cout << "\b \b";
				count--;
			}
			if (i > 0) {
				C[i - 1] = 0;
				i--;
			}
		}
		default: {
			if (count == 20) { break; }
			else if ((letter > -65 and letter < 0) or (letter > 64 and letter < 123)) { cout << letter; C[i] = letter; i++; count++;  } break;
		}
		}
	}

	if (type == 1) {
		for (int i = 0; i < 20; i++) {
			tmp->fam[i] = C[i];
		}
	}
	else if (type == 2) {
		for (int i = 0; i < 20; i++) {
			tmp->im[i] = C[i];
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 20; i++) {
			tmp->otch[i] = C[i];
		}
	}
	
}

int main();

void deleteList(mData *&head) {
	mData *next1;
	while (head) {
		next1 = head->next;
		delete head;
		head = next1;
	}
}

void addElement(mData *&head, mData *&tail, int index, int &bdSize, int posYStrelki1) {
	mData *tmp = NULL;
	mData *newelem = NULL;

	tmp = head;
	newelem = new mData;
	newelem->group = 0;
	gotoxy(184, posYStrelki1); cout << "   ";
	gotoxy(1, posYStrelki1); cout << index;
	gotoxy(9, posYStrelki1); cout << ">";
	for (;;) {
		vvodStroki(newelem, 1); //ввод фамилия
		if (newelem->fam[0] == 0) continue;
		else break;
	}
	gotoxy(9, posYStrelki1); cout << " "; gotoxy(32, posYStrelki1); cout << ">";
	for (;;) {
		vvodStroki(newelem, 2); //ввод имя
		if (newelem->im[0] == 0) continue;
		else break;
	}
	gotoxy(32, posYStrelki1); cout << " "; gotoxy(55, posYStrelki1); cout << ">";
	for (;;) {
		vvodStroki(newelem, 3); //ввод отчество
		if (newelem->otch[0] == 0) continue;
		else break;
	}
	gotoxy(55, posYStrelki1); cout << " "; gotoxy(78, posYStrelki1); cout << ">";
	for (;;) {
		newelem->group = vvodCifr(4); //ввод номера группы
		if (newelem->group == 0) continue;
		else break;
	}
	gotoxy(78, posYStrelki1); cout << " "; gotoxy(93, posYStrelki1); cout << ">";
	for (int i = 0;;) {
		gotoxy(94, posYStrelki1);
		newelem->proga = vvodCifr(1); //ввод оценки за прогу
		if (newelem->proga < 2 or newelem->proga > 5) {
			gotoxy(94, posYStrelki1); cout << " ";
			continue;
		}
		else break;
	}
	gotoxy(93, posYStrelki1); cout << " "; gotoxy(112, posYStrelki1); cout << ">";
	for (int i = 0;;) {
		gotoxy(113, posYStrelki1);
		newelem->linal = vvodCifr(1); //ввод оценки за линал
		if (newelem->linal < 2 or newelem->linal > 5) {
			gotoxy(113, posYStrelki1); cout << " ";
			continue;
		}
		else break;
	}
	gotoxy(112, posYStrelki1); cout << " "; gotoxy(131, posYStrelki1); cout << ">";
	for (int i = 0;;) {
		gotoxy(132, posYStrelki1);
		newelem->matan = vvodCifr(1); //ввод за матан
		if (newelem->matan < 2 or newelem->matan > 5) {
			gotoxy(132, posYStrelki1); cout << " ";
			continue;
		}
		else break;
	}
	gotoxy(131, posYStrelki1); cout << " "; gotoxy(143, posYStrelki1); cout << ">";
	for (int i = 0;;) {
		gotoxy(144, posYStrelki1);
		newelem->dm = vvodCifr(1); //ввод за дм
		if (newelem->dm < 2 or newelem->dm > 5) {
			gotoxy(144, posYStrelki1); cout << " ";
			continue;
		}
		else break;
	}
	newelem->sredball = ((newelem->linal + newelem->matan + newelem->proga + newelem->dm) / 4.0) * 1.0; //средняя оценка
	gotoxy(143, posYStrelki1); cout << " "; gotoxy(168, posYStrelki1); cout << newelem->sredball;
	   
	if (head == NULL) {
		head = newelem;
		head->next = NULL;
		head->prev = NULL;
		tail = newelem;
		tail->next = NULL;
		tail->prev = NULL;
		head->index = index;
	}
	for (int i = 1; i <= bdSize; i++) {
		if (index == 1) {
			//newelem = new mData;
			newelem->next = head;
			head->prev = newelem;
			head = newelem;
			head->prev = NULL;
			head->index = index;
			break;
		}
		else if (i == index) {
			while (tmp->index != index - 1) { tmp = tmp->next; }
			//newelem = new mData;
			newelem->next = tmp->next;
			tmp->next = newelem;
			newelem->prev = tmp;
			newelem->next->prev = newelem;
			newelem->index = index;
			break;
		}
		else if (index == bdSize + 1) {
			//newelem = new mData;
			while (tmp->index != index - 1) { tmp = tmp->next; }
			tmp->next = newelem;
			newelem->next = NULL;
			tail = newelem;
			newelem->prev = tmp;
			newelem->index = index;
			break;
		}
	}
	
	tmp = head;
	for (int i = 1; i <= bdSize; i++) {
		tmp->index = i;
		tmp = tmp->next;
	}
	bdSize++;
}

void editElem(mData *head, mData *tail, int index, int posYStrelki1) {
	mData *tmp;
	int T = 1, key = 1;
	char ch;

	gotoxy(184, posYStrelki1); cout << "   ";
	tmp = head;
	while (tmp->index != index) { tmp = tmp->next; }
	gotoxy(9, posYStrelki1); cout << ">";
	while (T) {
		
		ch = _getch();
		if (ch == 'а') {
			ch = _getch();
		}
		switch (ch) {
		case keyRight: 
		{
			if (key < 8) 
			{
				switch (key)
				{
				case 1: 
				{
					gotoxy(9, posYStrelki1); cout << " ";
					gotoxy(32, posYStrelki1); cout << ">";
					break;
				}
				case 2:
				{
					gotoxy(32, posYStrelki1); cout << " ";
					gotoxy(55, posYStrelki1); cout << ">";
					break;
				}
				case 3:
				{
					gotoxy(55, posYStrelki1); cout << " ";
					gotoxy(78, posYStrelki1); cout << ">";
					break;
				}
				case 4:
				{
					gotoxy(78, posYStrelki1); cout << " ";
					gotoxy(93, posYStrelki1); cout << ">";
					break;
				}
				case 5:
				{
					gotoxy(93, posYStrelki1); cout << " ";
					gotoxy(112, posYStrelki1); cout << ">";
					break;
				}
				case 6:
				{
					gotoxy(112, posYStrelki1); cout << " ";
					gotoxy(131, posYStrelki1); cout << ">";
					break;
				}
				case 7:
				{
					gotoxy(131, posYStrelki1); cout << " ";
					gotoxy(143, posYStrelki1); cout << ">";
					break;
				}
				}
				key++;
			}

			break;
		}
		case keyLeft: 
		{
			if (key > 1)
			{
				switch (key)
				{
				case 2:
				{
					gotoxy(32, posYStrelki1); cout << " ";
					gotoxy(9, posYStrelki1); cout << ">";
					break;
				}
				case 3:
				{
					gotoxy(55, posYStrelki1); cout << " ";
					gotoxy(32, posYStrelki1); cout << ">";
					break;
				}
				case 4:
				{
					gotoxy(78, posYStrelki1); cout << " ";
					gotoxy(55, posYStrelki1); cout << ">";
					break;
				}
				case 5:
				{
					gotoxy(93, posYStrelki1); cout << " ";
					gotoxy(78, posYStrelki1); cout << ">";
					break;
				}
				case 6:
				{
					gotoxy(112, posYStrelki1); cout << " ";
					gotoxy(93, posYStrelki1); cout << ">";
					break;
				}
				case 7:
				{
					gotoxy(131, posYStrelki1); cout << " ";
					gotoxy(112, posYStrelki1); cout << ">";
					break;
				}
				case 8:
				{
					gotoxy(143, posYStrelki1); cout << " ";
					gotoxy(131, posYStrelki1); cout << ">";
					break;
				}
				}
				key--;
			}

			break;
		}
		case enter:
		{
			switch (key)
			{
			case 1:
			{
				for (int i = 0; i < 20; i++) cout << " ";
				gotoxy(10, posYStrelki1);
				for (;;) {
					vvodStroki(tmp, 1); //ввод фамилия
					if (tmp->fam[0] == 0) continue;
					else break;
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < 20; i++) cout << " ";
				gotoxy(33, posYStrelki1);
				for (;;) {
					vvodStroki(tmp, 2); //ввод имя
					if (tmp->im[0] == 0) continue;
					else break;
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < 20; i++) cout << " ";
				gotoxy(56, posYStrelki1);
				for (;;) {
					vvodStroki(tmp, 3); //ввод отч
					if (tmp->otch[0] == 0) continue;
					else break;
				}
				break;
			}
			case 4:
			{
				for (int i = 0; i < 4; i++) cout << " ";
				gotoxy(79, posYStrelki1);
				for (;;) {
					tmp->group = vvodCifr(4); //ввод номера группы
					if (tmp->group == 0) continue;
					else break;
				}
				break;
			}
			case 5:
			{
				cout << " ";
				for (int i = 0;;) {
					gotoxy(94, posYStrelki1);
					tmp->proga = vvodCifr(1); //ввод оценки за прогу
					if (tmp->proga < 2 or tmp->proga > 5) {
						gotoxy(94, posYStrelki1); cout << " ";
						continue;
					}
					else break;
				}
				break;
			}
			case 6:
			{
				cout << " ";
				for (int i = 0;;) {
					gotoxy(113, posYStrelki1);
					tmp->linal = vvodCifr(1); //ввод оценки за линал
					if (tmp->linal < 2 or tmp->linal > 5) {
						gotoxy(113, posYStrelki1); cout << " ";
						continue;
					}
					else break;
				}
				break;
			}
			case 7:
			{
				cout << " ";
				for (int i = 0;;) {
					gotoxy(132, posYStrelki1);
					tmp->matan = vvodCifr(1); //ввод оценки за матан
					if (tmp->matan < 2 or tmp->matan > 5) {
						gotoxy(132, posYStrelki1); cout << " ";
						continue;
					}
					else break;
				}
				break;
			}
			case 8:
			{
				cout << " ";
				for (int i = 0;;) {
					gotoxy(144, posYStrelki1);
					tmp->dm = vvodCifr(1); //ввод оценки за дм
					if (tmp->dm < 2 or tmp->dm > 5) {
						gotoxy(144, posYStrelki1); cout << " ";
						continue;
					}
					else break;
				}
				break;
			}
			default: break;
			}
			tmp->sredball = (tmp->dm + tmp->linal + tmp->matan + tmp->proga) / 4.0;
			gotoxy(168, posYStrelki1); cout << "    ";
			gotoxy(168, posYStrelki1); cout << tmp->sredball;
		}
		case escape: 
		{
			gotoxy(9, posYStrelki1); cout << " ";
			gotoxy(32, posYStrelki1); cout << " ";
			gotoxy(55, posYStrelki1); cout << " ";
			gotoxy(78, posYStrelki1); cout << " ";
			gotoxy(93, posYStrelki1); cout << " ";
			gotoxy(112, posYStrelki1); cout << " ";
			gotoxy(131, posYStrelki1); cout << " ";
			gotoxy(143, posYStrelki1); cout << " ";
			T = 0; break;
		}
		}
		
	}

}

void deleteElement(mData *&head, mData *&tail, int index, int &bdSize) {
	mData *del;
	mData *tmp = NULL;

	tmp = head;
	if ((index == 1) and (bdSize == 1)) {
		delete head;
		head = NULL;
		tail = NULL;
	}
	else if (index == 1) {
		tmp = head;
		head = head->next;
		head->prev = NULL;
		delete tmp;
	}
	else if (index == bdSize) {
		while (tmp->index != (index - 1 )) { tmp = tmp->next; }
		delete tmp->next;
		tmp->next = NULL;
		tail = tmp;
	}
	else {
		while (tmp->index != (index - 1)) { tmp = tmp->next; }
		del = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
		delete del;
	}

	bdSize--;
}

void saveTOFILE(mData *head) {
	FILE *file;
	mData *tmp;
	char fambuf[20] = { 0 }, imbuf[20] = { 0 }, otchbuf[20] = { 0 };
	int groupbuf, progabuf, linalbuf, matanbuf, dmbuf;
	double sredballbuf;

	file = fopen("database.txt", "wb");
	tmp = head;
	while (tmp != NULL) {
		for (int i = 0; i < 20; i++) {
			fambuf[i] = tmp->fam[i];
		}
		for (int i = 0; i < 20; i++) {
			imbuf[i] = tmp->im[i];
		}
		for (int i = 0; i < 20; i++) {
			otchbuf[i] = tmp->otch[i];
		}
		groupbuf = tmp->group;
		progabuf = tmp->proga;
		linalbuf = tmp->linal;
		matanbuf = tmp->matan;
		dmbuf = tmp->dm;
		sredballbuf = tmp->sredball;

		for (int i = 0; i < 20; i++) {
			fwrite(&fambuf[i], sizeof(char), 1, file);
		}
		for (int i = 0; i < 20; i++) {
			fwrite(&imbuf[i], sizeof(char), 1, file);
		}
		for (int i = 0; i < 20; i++) {
			fwrite(&otchbuf[i], sizeof(char), 1, file);
		}
		fwrite(&groupbuf, sizeof(int), 1, file);
		fwrite(&progabuf, sizeof(int), 1, file);
		fwrite(&linalbuf, sizeof(int), 1, file);
		fwrite(&matanbuf, sizeof(int), 1, file);
		fwrite(&dmbuf, sizeof(int), 1, file);
		fwrite(&sredballbuf, sizeof(double), 1, file);
		
		tmp = tmp->next;
	}
	fclose(file);
}

mData* getFROMFILE() {
	FILE *file;
	mData *tmp, *newElem, *head = NULL, *tail = NULL;
	int s = 0;

	file = fopen("database.txt", "rb");
	fseek(file, 0, SEEK_END);
	s = ftell(file);
	s /= (sizeof(char) * 60 + sizeof(int) * 5 + sizeof(double));
	if (s == 0) {

	}
	else
	{
		for (int i = 0; i < s; i++) {
			newElem = new mData;
			newElem->next = head;
			head = newElem;
		}
		tmp = head;
		for (int i = 0; i < s; i++) {
			tmp->prev = tail;
			tail = tmp;
			tmp = tmp->next;
		}
		fseek(file, 0, SEEK_SET);
		tmp = head;
		for (int i = 0; i < s; i++) {
			for (int i = 0; i < 20; i++) {
				fread(&tmp->fam[i], sizeof(char), 1, file);
			}
			for (int i = 0; i < 20; i++) {
				fread(&tmp->im[i], sizeof(char), 1, file);
			}
			for (int i = 0; i < 20; i++) {
				fread(&tmp->otch[i], sizeof(char), 1, file);
			}
			fread(&tmp->group, sizeof(int), 1, file);
			fread(&tmp->proga, sizeof(int), 1, file);
			fread(&tmp->linal, sizeof(int), 1, file);
			fread(&tmp->matan, sizeof(int), 1, file);
			fread(&tmp->dm, sizeof(int), 1, file);
			fread(&tmp->sredball, sizeof(double), 1, file);

			tmp = tmp->next;
		}
	}
	fclose(file);
	return head;
}

void sortnum(mData **q, int bdSize, int qwer, mData *head) {
	switch (qwer) {
	case '4':
	{
		for (int i = 0; i < bdSize; i++)
			for (int j = 0; j < bdSize - i - 1; j++)
				if (q[j]->group > q[j + 1]->group)
				{
					mData *temp = q[j];
					q[j] = q[j + 1];
					q[j + 1] = temp;
				}
	}
	}

	mData *tmp = head; //tail???

}


void prorisovka(int posYStrelki1) {
	gotoxy(0, posYStrelki1 + 2);
	for (int i = 0; i < 182; i++)
		cout << "—";
	gotoxy(8, posYStrelki1 - 1); cout << "|";
	gotoxy(8, posYStrelki1); cout << "|";
	gotoxy(8, posYStrelki1 + 1); cout << "|";
	gotoxy(31, posYStrelki1 - 1); cout << "|";
	gotoxy(31, posYStrelki1); cout << "|";
	gotoxy(31, posYStrelki1 + 1); cout << "|";
	gotoxy(54, posYStrelki1 - 1); cout << "|";
	gotoxy(54, posYStrelki1); cout << "|";
	gotoxy(54, posYStrelki1 + 1); cout << "|";
	gotoxy(77, posYStrelki1 - 1); cout << "|";
	gotoxy(77, posYStrelki1); cout << "|";
	gotoxy(77, posYStrelki1 + 1); cout << "|";
	gotoxy(92, posYStrelki1 - 1); cout << "|";
	gotoxy(92, posYStrelki1); cout << "|";
	gotoxy(92, posYStrelki1 + 1); cout << "|";
	gotoxy(111, posYStrelki1 - 1); cout << "|";
	gotoxy(111, posYStrelki1); cout << "|";
	gotoxy(111, posYStrelki1 + 1); cout << "|";
	gotoxy(130, posYStrelki1 - 1); cout << "|";
	gotoxy(130, posYStrelki1); cout << "|";
	gotoxy(130, posYStrelki1 + 1); cout << "|";
	gotoxy(142, posYStrelki1 - 1); cout << "|";
	gotoxy(142, posYStrelki1); cout << "|";
	gotoxy(142, posYStrelki1 + 1); cout << "|";
	gotoxy(166, posYStrelki1 - 1); cout << "|";
	gotoxy(166, posYStrelki1); cout << "|";
	gotoxy(166, posYStrelki1 + 1); cout << "|";
	gotoxy(181, posYStrelki1 - 1); cout << "|";
	gotoxy(181, posYStrelki1); cout << "|";
	gotoxy(181, posYStrelki1 + 1); cout << "|";
}

void printEmptyStr() {
	cout << "                                                                                                                                                                                        ";
}

void rasstavitindex(mData *head) {
	mData *tmp = head;
	int i = 1;
	while (tmp != NULL) {
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

void viviodvpole(mData *head, int posYStrelki1, int bdSize, int index, int pseudo) {
	mData *tmp = head;
	int k = 0;

	while (tmp->index != index - pseudo) {
		tmp = tmp->next;
	}

	for (int i = index; i < bdSize + 1; i++) {
		gotoxy(1, posYStrelki1 + k * 4); cout << tmp->index + pseudo;
		gotoxy(10, posYStrelki1 + k * 4); for (int j = 0; j < 20; j++) cout << tmp->fam[j];
		gotoxy(33, posYStrelki1 + k * 4); for (int j = 0; j < 20; j++) cout << tmp->im[j];
		gotoxy(56, posYStrelki1 + k * 4); for (int j = 0; j < 20; j++) cout << tmp->otch[j];
		gotoxy(79, posYStrelki1 + k * 4); cout << tmp->group;
		gotoxy(94, posYStrelki1 + k * 4); cout << tmp->proga;
		gotoxy(113, posYStrelki1 + k * 4); cout << tmp->linal;
		gotoxy(132, posYStrelki1 + k * 4); cout << tmp->matan;
		gotoxy(144, posYStrelki1 + k * 4); cout << tmp->dm;
		gotoxy(168, posYStrelki1 + k * 4); cout << tmp->sredball;

		k++;
		tmp = tmp->next;
	}
}

void startVivod() {
	cout << " Индекс | " << setw(20) << left << "Фамилия" << " | " << setw(20) << left << "Имя" << " | "
		<< setw(20) << left << "Отчество" << " | " << "Номер группы" << " | " << "Программирование" << " | "
		<< "Линейная алгебра" << " | " << "Матанализ" << " | " << "Дискретная математика" << " | " << "Средний балл" << " | ";
	cout << endl;
	for (int i = 0; i < 182; i++)
		cout << "—";

	gotoxy(190, 0);
	cout << "Справка: ";
	gotoxy(190, 1);
	cout << "Поля не могут быть пустыми!";
	gotoxy(190, 2);
	cout << "Оценки вводятся в диапазоне от 2 до 5";
	gotoxy(190, 3);
	cout << "Выбрать запись для редактирования или";
	gotoxy(190, 4);
	cout << "добавить запись - Enter";
	gotoxy(190, 5);
	cout << "Удалить выбранную запись - D";
	gotoxy(190, 6);
	cout << "Сохранить базу данных в файл - S";
	gotoxy(190, 7);
	cout << "Загрузить базу данных из файла - L";
	gotoxy(190, 8);
	cout << "Добавить запись перед выбранной записью - Q";
	gotoxy(190, 9);
	cout << "Удалить все записи - W";
	gotoxy(190, 10);
	cout << "Назад и выход - escape";
}

int bdSizeCheck(mData *head) {
	mData *tmp = head;
	int s = 0;
	while (tmp != NULL) {
		s++;
		tmp = tmp->next;
	}
	return s;
}

int main() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key = 1, ex = 0, T = 1, posYStrelki1 = 3, index = 1, bdSize = 0;
	char ch;
	mData *head = NULL, *tail = NULL;

	startVivod();
	while (T) {
		gotoxy(184, posYStrelki1);
		cout << "<--";
		ch = _getch();
		if (ch == 'а') {
			ch = _getch();
		}
		switch (ch) {
		case keyUp: if (index > 1) { index--; gotoxy(184, posYStrelki1); cout << "   "; posYStrelki1 -= 4; } break;
		case keyDown: {
			if (index < bdSize + 1) {
				index++;
				gotoxy(184, posYStrelki1); 
				cout << "   ";
				posYStrelki1 += 4;
			}
			break; 
		}
		case 'w':
		{
			deleteList(head);
			bdSize = 0;
			index = 1;
			posYStrelki1 = 3;
			system("cls");
			startVivod();
			break;
		}
		case 'd':
		{
			if (index == bdSize + 1) break;
			else
			{
				gotoxy(0, posYStrelki1 - 1);
				for (int i = 0; i < (bdSize * 4); i++) {
					printEmptyStr();
					cout << endl;
				}
				deleteElement(head, tail, index, bdSize);
				rasstavitindex(head);
				if ((head != NULL) and (index != (bdSize + 1))) { 
					int k = bdSize - index + 1, i = 0; 
					while (k != 0) {  
						gotoxy(0, (posYStrelki1 + i * 4) - 1);
						prorisovka(posYStrelki1 + i * 4);
						k--; i++;
					}
					viviodvpole(head, posYStrelki1, bdSize, index, 0);
				}
				break;
			}
		}
		case 'q':
		{
			if (head == NULL or (index == bdSize + 1)) break;

			gotoxy(0, posYStrelki1 - 1);
			for (int i = 0; i < (bdSize * 4); i++) {
				printEmptyStr();
				cout << endl;
			}
			prorisovka(posYStrelki1);
			bdSize++;
			int k = bdSize - index, i = 1;
			while (k != 0) {  
				gotoxy(0, (posYStrelki1 + i * 4) - 1);
				prorisovka(posYStrelki1 + i * 4);
				k--; i++;
			}
			viviodvpole(head, posYStrelki1 + 4, bdSize, index + 1, 1);
			addElement(head, tail, index, bdSize, posYStrelki1);
			rasstavitindex(head);
			index++;
			posYStrelki1 += 4;
			bdSize--; //компенсация addelement
			break;

		}
		case 'e':
		{
			char qwer;
			qwer = _getch();
			if (qwer == 'a')
				qwer = _getch();
			switch (qwer)
			{
			case '4':
			{
				mData **q = new mData*[bdSize];
				mData *tmp = head;
				for (int i = 0; i < bdSize; i++)
				{
					q[i] = tmp;
					tmp = tmp->next;
				}
				delete [] q;
				break;
			}
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			default: break;
			}
		}
		case 's':
		{
			if (head == NULL) break;

			saveTOFILE(head);
			gotoxy(190, 12); cout << "Сохранено!";
			Sleep(sleepTime);
			gotoxy(190, 12); cout << "          ";

			break;
		}
		case 'l':
		{
			deleteList(head);
			bdSize = 0;
			index = 1;
			posYStrelki1 = 3;
			head = getFROMFILE();
			rasstavitindex(head);
			system("cls");
			startVivod();
			bdSize = bdSizeCheck(head);
			for (int i = 0; i < bdSize; i++) {
				prorisovka(posYStrelki1 + i * 4);
			}
			viviodvpole(head, posYStrelki1, bdSize, index, 0);
			break;
		}
		case enter: {
			if (index <= bdSize)
			{
				editElem(head, tail, index, posYStrelki1);
			}
			else {
				prorisovka(posYStrelki1);
				addElement(head, tail, index, bdSize, posYStrelki1);
			}
	
			break;
		}
		
		case escape: exit(0); break;
		default:  break;
		}
	}
	   	
	system("pause");
	return 0;
}