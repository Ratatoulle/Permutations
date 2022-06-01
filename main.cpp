#include <iostream>

using namespace std;

void swap(int* a, int i, int j)
{
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool NextSet(int* a, int n)
{
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) 
        j--;
    if (j == -1)
        return false; // ������ ������������ ���
    int k = n - 1;
    while (a[j] >= a[k])
        k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; // ��������� ���������� ����� ������������������
    while (l < r)
        swap(a, l++, r--);
    return true;
}

void Print(int* a, int n)  // ����� ������������
{
    static int num = 1; // ����� ������������
    cout.width(3); // ������ ���� ������ ������ ������������
    cout << num++ << ": ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n, * A;
    cout << "Enter the number of permutations: ";
    cin >> n;
    A = new int[n];
    for (int i = 0; i < n; i++)
        A[i] = i + 1;
    Print(A, n);
    while (NextSet(A, n))
        Print(A, n);
    return 0;
}