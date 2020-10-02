#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


int m[100000], mas[100000];
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;
	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


int cmp(const void* a, const void* b) {    //функция сравнения элементов массива
	{
		return *(int*)a - *(int*)b;		// Если результат вычитания равен 0, то числа равны
	}
}




int main()
{

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	FILE *f; int size;

	printf("Введите размер массивов: ");
	scanf_s("%d", &size);
	fopen_s(&f, "res.txt", "a+");
	while (size!=0)
	{
		fprintf(f, "Размер массива=:");
		fprintf(f, "%d \n", size);

	for (int i = 0; i < size; i++) {   //Заполнение массива рандомными числами
		m[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}
	
	fprintf(f, "Случайные числа:\n\n");
	int start_time = clock();
	shell(mas, size);	//Сортировка Шелла
	int end_time = clock();
	int search_time = end_time - start_time;
	fprintf(f, "Сортировка шелла:");
	fprintf(f, "%d \n", search_time);

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}

	
	start_time = clock();
	qs(mas, 0, size - 1);	//Быстрая сортировка
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(f, "Быстрая сортировка:");
	fprintf(f, "%d \n", search_time);

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}

	start_time = clock();
	qsort(mas, size, sizeof(int), cmp); // Ф-я быстрой сортировки
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(f, "Ф-я быстрой сортировки:");
	fprintf(f, "%d \n\n", search_time);

	for (int i = 1; i < size; i++) {		//Возрастающая последовательность
		m[i] = m[i-1]+1;
	}

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}

	fprintf(f, "Возрастающа последовательность:\n\n");
	start_time = clock();
	shell(mas, size);	//Сортировка Шелла
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(f, "Сортировка шелла:");
	fprintf(f, "%d \n", search_time);

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}


	start_time = clock();
	qs(mas, 0, size - 1);	//Быстрая сортировка
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(f, "Быстрая сортировка:");
	fprintf(f, "%d \n", search_time);

	for (int i = 0; i < size; i++) {   //Копирование во второй массив
		mas[i] = m[i];
	}

	start_time = clock();
	qsort(mas, size, sizeof(int), cmp); // Ф-я быстрой сортировки
	end_time = clock();
	search_time = end_time - start_time;
	fprintf(f, "Ф-я быстрой сортировки:");
	fprintf(f, "%d \n\n", search_time);


		for (int i = 0; i < size; i++) {	//Убывающая последовательность
		m[i] = size -i;
	 }

		fprintf(f, "Убывающая последовательность:\n\n");
		start_time = clock();
		shell(mas, size);	//Сортировка Шелла
		end_time = clock();
		search_time = end_time - start_time;
		fprintf(f, "Сортировка шелла:");
		fprintf(f, "%d \n", search_time);

		for (int i = 0; i < size; i++) {   //Копирование во второй массив
			mas[i] = m[i];
		}


		start_time = clock();
		qs(mas, 0, size - 1);	//Быстрая сортировка
		end_time = clock();
		search_time = end_time - start_time;
		fprintf(f, "Быстрая сортировка:");
		fprintf(f, "%d \n", search_time);

		for (int i = 0; i < size; i++) {   //Копирование во второй массив
			mas[i] = m[i];
		}

		start_time = clock();
		qsort(mas, size, sizeof(int), cmp); // Ф-я быстрой сортировки
		end_time = clock();
		search_time = end_time - start_time;
		fprintf(f, "Ф-я быстрой сортировки:");
		fprintf(f, "%d \n\n", search_time);


			for (int i = 0; i < size/2; i++) {	//Возрастающе-убывающая последовательность
				m[i] = m[i - 1] + 1;
	 }
			for (int i = 5; i < size; i++) {
				m[i] = size - i;
			}

			fprintf(f, "Возрастающа-убывающая последовательность:\n\n");
			start_time = clock();
			shell(mas, size);	//Сортировка Шелла
			end_time = clock();
			search_time = end_time - start_time;
			fprintf(f, "Сортировка шелла:");
			fprintf(f, "%d \n", search_time);

			for (int i = 0; i < size; i++) {   //Копирование во второй массив
				mas[i] = m[i];
			}


			start_time = clock();
			qs(mas, 0, size - 1);	//Быстрая сортировка
			end_time = clock();
			search_time = end_time - start_time;
			fprintf(f, "Быстрая сортировка:");
			fprintf(f, "%d \n", search_time);

			for (int i = 0; i < size; i++) {   //Копирование во второй массив
				mas[i] = m[i];
			}

			start_time = clock();
			qsort(mas, size, sizeof(int), cmp); // Ф-я быстрой сортировки
			end_time = clock();
			search_time = end_time - start_time;
			fprintf(f, "Ф-я быстрой сортировки:");
			fprintf(f, "%d \n\n", search_time);

			printf("Введите размер массивов: ");
			scanf_s("%d", &size);
			}
			
	fclose(f);
	return (0);
}
