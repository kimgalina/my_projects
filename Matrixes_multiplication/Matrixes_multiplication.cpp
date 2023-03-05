#include<iostream>
using namespace std;

int** creat(int r, int c)
{
	int** mas = new int* [r];
	for (int i = 0; i < r; i++)
	{
		mas[i] = new int[c];

	}
	return mas;

}

void crawed(int** mas, int r, int c)
{
	cout << "Enter the entries of the  matrix";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cin >> mas[i][j];
	}
}
void print(int** mas, int r, int c)
{

	for (int i = 0; i < r; i++,cout << endl)
	{
		for (int j = 0; j < c; j++)
			cout << mas[i][j] <<"\t";
	}
}

int** multipl(int** arr1, int** arr2, int r1, int c1, int r2, int c2)
{
	int** arr3 = creat(r1, c2);
	for (int i = 0; i < r1; i++)
	{
		for (int c = 0; c < c2; c++)
		{
			int sum = 0;
			for (int j = 0; j < c1; j++)
			{
				sum += arr1[i][j] * arr2[j][c];
			}
			arr3[i][c] = sum;
		}
	}

	return arr3;


}


int main()
{
	int r1, c1, r2, c2,r3,c3;

	cout << "Enter the size of the first matrix ";
	cout << "r1 = ";
	cin >> r1;
	cout << "c1 = ";
	cin >> c1;
	int** arr1 = creat(r1, c1);
	metka:cout << "Enter the size of the second  matrix ";
		cout << "r2 = ";
		cin >> r2;
		cout << "c2 = ";
		cin >> c2;
		if (c1 == r2)
		{
			crawed(arr1, r1, c1);
			cout << "The first matrix " << endl;
			print(arr1, r1, c1);
			int** arr2 = creat(r2, c2);
			crawed(arr2, r2, c2);
			cout << "The second matrix " << endl;
			print(arr2, r2, c2);
			int** arr3 = multipl(arr1, arr2, r1, c1, r2, c2);
			cout << "The result matrix is " << endl;
			print(arr3, r1, c2);

			for (int i = 0; i < r2; i++)
				delete[] arr2[i];
			delete[] arr2;
			for (int i = 0; i < r1; i++)
				delete[] arr3[i];
			delete[] arr3;

		}
		else
		{
			cout << "This matrixes can not be multiplied !" << endl;
			goto metka;
		}
	for (int i = 0; i < r1; i++)
		delete[] arr1[i];
	delete[] arr1;


	return 0;

}