/*
 ============================================================================
 Name        : calculator.c
 Author      : Коростелева Александра
 License     : GNU GPL
 Description : Программа калькулятор поддерживает работу с вещественными числами,
 обработку ошибок в арифметических выражениях.
 Поддерживаемые операции - сложение, вычитание, умножение, деление, факториал и возведение в степень
 (+ - * / ! ^).
 После выполнения одной операции программа выводит запрос на повторение работы и при положительном
 ответе запускается сначала.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Присвоим переменной t временное значение для работы цикла while
int main(int argc, char *argv[])
{
	char t;
	do
	{
		double a, b, d, f, *A, *B;
		//*A, *B - 1й и 2й векторы
		char c;
		int size;
		float *result;
		//Выведем подсказку
		printf ("Введите операцию (+ - * / ! ^ v):");
		//Введем операцию
		scanf ("\n%c", &c);
		//Создадим блок функций, осуществляющиеся в зависимости от введенной операции
		switch (c)
		{
			//Сложение
			case '+':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a+b);
				break;
			//Вычитание
			case '-':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a-b);
 		    	break;
 		    //Умножение
			case '*':
				printf ("Введите первое число:");
				scanf (" %lg", &a);
				printf ("Введите второе число:");
				scanf (" %lg", &b);
				printf ("%lg", a*b);
				break;
			//Деление
			case '/':
				printf ("Введите первое число:");
				scanf ("%lg", &a);
				printf ("Введите второе число:");
				scanf ("%lg", &b);
				printf ("%lg", a/b);
				break;
			//Факториал
			case '!':
				f=1;
				scanf ("%lf", &a);
				if (a>0)
				{
			    	for (int i=1; i<=a; i++)
			    	{
			        	f=f*i;
			    	}
			    	printf("%.0lf\n", f);
				}
				else if (a<0)
				{
			    	printf ("Ошибка");
				}
				else printf ("1");
				break;
			//Возведение в степень с помощью библиотеки <math.h>
			case '^':
				printf ("Введите число:");
				scanf ("%lf", &a);
				printf ("Введите степень:");
				scanf ("%lf",&b);
				d = pow (a, b);
				printf( " %.1f", d);
			//Работа с векторами
			case 'v':
				printf ("Введите размер векторов: ");
				scanf ("%i", &size);
			    A = malloc(size*sizeof(int));
			    B = malloc(size*sizeof(int));
				result = malloc(size*sizeof(int));
				printf ("Введите координаты первого вектора: ");
				for(int i=0;i<size;i++) scanf("%lf",&A[i]);
				printf ("Введите координаты второго вектора: ");
				for(int i=0;i<size;i++) scanf("%lf",&B[i]);
				printf ("Введите операцию (+ - *): ");
				scanf(" %c",&c);
				if (c == '+')
				{
					printf("Результат сложения векторов: ");
					for(int i=0;i<size;i++) printf("%lf ",A[i]+B[i]);
					printf("\n");
				}
				else if (c == '-')
				{
					printf("Результат вычитания векторов: ");
					for(int i=0;i<size;i++) printf("%lf ",A[i]-B[i]);
					printf("\n");
				}
				else if (c == '*')
				{
					printf("Результат скалярного произведения векторов: ");
					for(int i=0;i<size;i++) printf("%lf ",A[i]*B[i]);
					printf("\n");
				}
				else printf("Такой операции нет, попробуйте снова");
				free(A);
				free(B);
				free(result);
				break;
			default:
				printf ("Ошибка");
		}
		printf ("\nЧтобы продолжить программу нажмите 1\nДля выхода нажмите любой другой символ\n");
		scanf (" %c", &t);
	}
	while (t == '1');
	return 0;
}
