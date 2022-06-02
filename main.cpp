#include <iostream>

using namespace std;

void swap(int P[], int i, int j)
{
	int s = P[i];
	P[i] = P[j];
	P[j] = s;
}

bool nextPermutation(int P[], int n)
{
	int j = n - 2;
	while (j != -1 && P[j] >= P[j + 1])
		j--;
	if (j == -1)
		return false; // no more permutations
	int k = n - 1;
	while (P[j] >= P[k])
		k--;
	swap(P, j, k);
	int l = j + 1, r = n - 1;
	while (l < r)
		swap(P, l++, r--);
	return true;
}

void printPermutation(int P[], int n) 
{
	static int permutationNumber = 1;
	cout.width(3);
	cout << permutationNumber++ << ": ";
	for (int i = 0; i < n; i++)
		cout << P[i] << " ";
	cout << endl;
}

int main()
{
	int *P = new int[3];
	cout << "Enter 3 numbers you want to permute: ";
	cin >> P[0] >> P[1] >> P[2];
	printPermutation(P, 3);
	while (nextPermutation(P, 3))
		printPermutation(P, 3);
	delete[] P;
	system("pause");
	return 0;
}