#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>


using namespace std;

void input_check(unsigned long& numerator, unsigned long& denominator) {
	bool flg = 1;
	char* num_arr = (char*)malloc(10 * sizeof(char));
	while (flg) {
		printf("Enter a numerator (up to 999'999'999): ");
		if (!scanf_s("%s", num_arr, 10)) {
			printf("Wrong input, re-enter\n---------------------\n");
			rewind(stdin);
			continue;
		}
		int i = 0;
		for (flg = 0; num_arr[i]; i++) {
			if (!isdigit(num_arr[i])) {
				printf("Wrong input, re-enter\n---------------------\n");
				flg = 1;
				break;
			}
		}
		if (!flg) {
			if (!num_arr[i]) {
				i--;
			}
			int dec_place = 1;
			for (; i >= 0; i--)
			{
				numerator += (num_arr[i] - 48) * dec_place;
				dec_place *= 10;
			}
		}
	}
	flg = 1;
	while (flg) {
		printf("Enter a denominator (up to 999'999'999): ");
		if (!scanf_s("%s", num_arr, 10)) {
			printf("Wrong input, re-enter\n---------------------\n");
			rewind(stdin);
			continue;
		}
		int i = 0;
		for (flg = 0; num_arr[i]; i++) {
			if (!isdigit(num_arr[i])) {
				printf("Wrong input, re-enter\n---------------------\n");
				flg = 1;
				break;
			}
		}
		if (!flg) {
			if (!num_arr[i]) {
				i--;
			}
			int dec_place = 1;
			for (; i >= 0; i--)
			{
				denominator += (num_arr[i] - 48) * dec_place;
				dec_place *= 10;
			}
		}
		if (!denominator && !flg)
		{
			printf("Denominator cannot be 0, re-enter\n---------------------\n");
			flg = 1;
		}
	}
	free(num_arr);
	num_arr = NULL;
}

void harmonic(double& rat_1, double& rat_2) {
	double harmonic = 1 / ((1 / rat_1 + 1 / rat_2) / 2);
	printf("Harmonic = %f\n", harmonic);
	system("pause");
	return;
}

void info(void) {
	printf("Simple_rational_counter V. 1.0.3\n");
	printf("Created by ANDREW VOROBIOV I&TP gr.953502\n-------------------------\n");
	system("pause");
	return;
}

int main(void)
{
	unsigned long numerator_1 = 0, denominator_1 = 0, numerator_2 = 0, denominator_2 = 0;
	printf("\t\t\t\t\tRational number 1:\n");
	input_check(numerator_1, denominator_1);
	system("cls");
	printf("\t\t\t\t\tRational number 2:\n");
	input_check(numerator_2, denominator_2);
	double rat_1 = numerator_1 / (double)denominator_1;
	double rat_2 = numerator_2 / (double)denominator_2;
	{
		while (true)
		{
			system("cls");
			printf("\t\t\t\t\tMENU:\n");
			printf("1. Print numerators and denominators\n2. Print rational numbers\n3. Sum of numbers\n");
			printf("4. Subtraction of numbers\n5. Multiplication of numbers\n6. Division of numbers\n");
			printf("7. Get the harmonic value\n8. Program info.\n9. Exit\n-------------------------\n");
			char choice = _getch();
			switch (choice)
			{
			case '1':
				printf("Numerator_1 = %lu. Denominator_1 = %lu.\nNumerator_2 = %lu. Denominator_2 = %lu.\n", numerator_1, denominator_1, numerator_2, denominator_2);
				system("pause");
				break;
			case '2':
				printf("Num_1 = %f\nNum_2 = %f\n", rat_1, rat_2);
				system("pause");
				break;
			case '3':
				printf("Sum = %f\n", rat_1 + rat_2);
				system("pause");
				break;
			case '4':
				printf("Substraction = %f\n", rat_1 - rat_2);
				system("pause");
				break;
			case '5':
				printf("Multiplication = %f\n", rat_1 * rat_2);
				system("pause");
				break;
			case '6':
				printf("Division = %f\n", rat_1 / rat_2);
				system("pause");
				break;
			case '7':
				harmonic(rat_1, rat_2);
				break;
			case '8':
				info();
			}

			if (choice == '9') {
				break;
			}
		}
	}
	return 0;
}
