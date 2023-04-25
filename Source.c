#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//ѕодключаем библиотеки
#include <math.h>
#include <locale.h>
#include<stdlib.h>

void sozdanie(double* b, int* k)//создаем функцию, где делаем ввод массива
{
	printf("Enter k: ");
	scanf("%d", k);
	int i;
	for (i = 0; i < *k; i++)//вводим массив 
	{
		printf("B[%d] = ", i);
		scanf("%lf", &b[i]);
	}
	for (i = 0; i < *k; i++) // выводим массив на экран 
	{
		printf("%lf ", b[i]);
	}

}

double minim(double* b, int k, double x, double y)//создаем функцию, где ищем минимальный элемент, принадлежащий заданному промежутку
{
	double min;
	int flag;
	flag = 0;
	int i;
	for (i = 0; i < k; i++)//ищем, есть ли хот€ бы один элемент в масссиве, удовлетвор€ющий неравенству
	{
		if ((fabs(b[i]) > x) && (fabs(b[i]) < y))
		{
			flag = 1;
		}
	}

	if (flag == 1)//если такой элемент нашли, то ищем минимум 
	{
		min = y;
		for (i = 0; i < k; i++)
		{
			if ((fabs(b[i]) > x) && (fabs(b[i]) < y))
			{
				if (b[i] < min)
				{
					min = b[i];
				}
			}
		}
	}
	else min = x;//если нет, то min приравниваем к x
	return(min);
}

double mindva(double* b, int k)//создаем функцию, где ищем минимальный элемент из всех положительных
{
	int i, kol, flag;
	double min;
	kol = 0;
	flag = 0;
	for (i = 0; i < k; i++)//ищем, есть ли хот€ бы один положительный элемент 
	{
		if (b[i] > 0)
		{
			flag = 1;//если такой элемент нашелс€, то присваиваем переменной flag значение 1
			min = b[i];//присваиваем начальное значение переменной min
			break;
		}
	}

	if (flag == 1)//если такой элемент нашелс€, то ищем минимальный элемент
	{
		for (i = 0; i < k; i++)
		{
			if (b[i] > 0)
			{
				if (b[i] < min)
				{
					min = b[i];
				}
			}
		}
	}
	else min = -5;//если ни одного положительного элемента не нашлось, то присваем переменной min какое-то отрицательное значение (например -5)
	return(min);
}

double srar(double* b, int k, double min)//создаем функцию, где ищем среднее арифметическое всех положительных элементов до первого минимума 
{
	int kol, i;
	kol = 0;//инициализируем переменную kol
	for (i = 0; i < k; i++)//считаем количество переменных до первого минимума 
	{
		if (b[i] != min)
			kol++;
		else break;
	}
	double sum;
	sum = 0;//инициализируем переменную sum 
	if (kol == 0) return(0);
	else
	{
		for (i = 0; i < kol; i++)
		{
			sum = sum + b[i];
		}
		double sr;
		sr = sum / kol;//считаем среднее арифметическое 
		return(sr);
	}
}

int main()
{
	int k;
	double b[100];//заводим массив 
	double minimal, average, minimaldva;
	double x, y;
	printf("LAB WORK#4\nSpesivtseva Polina\n");
	sozdanie(&b, &k);
	printf("\nenter X: ");
	scanf("%lf", &x);
	printf("enter Y: ");
	scanf("%lf", &y);
	minimal = minim(&b, k, x, y);//находим мимнимум, удовлетвор€ющий неравенству, вызыва€ функцию
	if (minimal == x) //провер€ем, нашелс€ ли хот€ бы один такой элемент, удовлетвор€ющий неравенству
	{
		printf("no minimum\n");//если нет, то выводим на экран "no minimum"
	}
	else { printf("minimum = %lf\n", minimal); } //в другом случае, функци€ вернет минимальное значение

	minimaldva = mindva(&b, k);//находим минимальный из всех положительных элементов массива (первый положительный)
	if (minimaldva == -5)
	{
		printf("no minimum\n");//в другом случае выводим на экран "no minimum"
	}
	else
	{
		average = srar(&b, k, minimaldva);//находим среднее арифметическое, вызыва€ функцию
		printf("average = %lf\n", average);
	}
	return 0;
}

