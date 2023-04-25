#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//���������� ����������
#include <math.h>
#include <locale.h>
#include<stdlib.h>

void sozdanie(double* b, int* k)//������� �������, ��� ������ ���� �������
{
	printf("Enter k: ");
	scanf("%d", k);
	int i;
	for (i = 0; i < *k; i++)//������ ������ 
	{
		printf("B[%d] = ", i);
		scanf("%lf", &b[i]);
	}
	for (i = 0; i < *k; i++) // ������� ������ �� ����� 
	{
		printf("%lf ", b[i]);
	}

}

double minim(double* b, int k, double x, double y)//������� �������, ��� ���� ����������� �������, ������������� ��������� ����������
{
	double min;
	int flag;
	flag = 0;
	int i;
	for (i = 0; i < k; i++)//����, ���� �� ���� �� ���� ������� � ��������, ��������������� �����������
	{
		if ((fabs(b[i]) > x) && (fabs(b[i]) < y))
		{
			flag = 1;
		}
	}

	if (flag == 1)//���� ����� ������� �����, �� ���� ������� 
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
	else min = x;//���� ���, �� min ������������ � x
	return(min);
}

double mindva(double* b, int k)//������� �������, ��� ���� ����������� ������� �� ���� �������������
{
	int i, kol, flag;
	double min;
	kol = 0;
	flag = 0;
	for (i = 0; i < k; i++)//����, ���� �� ���� �� ���� ������������� ������� 
	{
		if (b[i] > 0)
		{
			flag = 1;//���� ����� ������� �������, �� ����������� ���������� flag �������� 1
			min = b[i];//����������� ��������� �������� ���������� min
			break;
		}
	}

	if (flag == 1)//���� ����� ������� �������, �� ���� ����������� �������
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
	else min = -5;//���� �� ������ �������������� �������� �� �������, �� �������� ���������� min �����-�� ������������� �������� (�������� -5)
	return(min);
}

double srar(double* b, int k, double min)//������� �������, ��� ���� ������� �������������� ���� ������������� ��������� �� ������� �������� 
{
	int kol, i;
	kol = 0;//�������������� ���������� kol
	for (i = 0; i < k; i++)//������� ���������� ���������� �� ������� �������� 
	{
		if (b[i] != min)
			kol++;
		else break;
	}
	double sum;
	sum = 0;//�������������� ���������� sum 
	if (kol == 0) return(0);
	else
	{
		for (i = 0; i < kol; i++)
		{
			sum = sum + b[i];
		}
		double sr;
		sr = sum / kol;//������� ������� �������������� 
		return(sr);
	}
}

int main()
{
	int k;
	double b[100];//������� ������ 
	double minimal, average, minimaldva;
	double x, y;
	printf("LAB WORK#4\nSpesivtseva Polina\n");
	sozdanie(&b, &k);
	printf("\nenter X: ");
	scanf("%lf", &x);
	printf("enter Y: ");
	scanf("%lf", &y);
	minimal = minim(&b, k, x, y);//������� ��������, ��������������� �����������, ������� �������
	if (minimal == x) //���������, ������� �� ���� �� ���� ����� �������, ��������������� �����������
	{
		printf("no minimum\n");//���� ���, �� ������� �� ����� "no minimum"
	}
	else { printf("minimum = %lf\n", minimal); } //� ������ ������, ������� ������ ����������� ��������

	minimaldva = mindva(&b, k);//������� ����������� �� ���� ������������� ��������� ������� (������ �������������)
	if (minimaldva == -5)
	{
		printf("no minimum\n");//� ������ ������ ������� �� ����� "no minimum"
	}
	else
	{
		average = srar(&b, k, minimaldva);//������� ������� ��������������, ������� �������
		printf("average = %lf\n", average);
	}
	return 0;
}

