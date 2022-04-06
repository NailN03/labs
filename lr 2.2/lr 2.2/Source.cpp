#include <iostream>
#include <fstream>

using namespace std;

// ������� ��� ������� ������ �� �����
void Errors(int x) {
    switch (x) {
    case 1:
        cout << "������! ���� �� ������! " << endl;
        exit(0);
    case 3:
        cout << "������! ���������� ����� ������ ���� ������ ����! " << endl;
        exit(0);
    case 4:
        cout << "������!���������� �������� ������ ���� ������ ����!" << endl;
        exit(0);
    case 0:
        cout << "������! ������������� ��������� � ������� \"1\" ��� \"0\"!";
        exit(0);
    }
}

// ������� ��� ���������� ���������
long long maxim(long long ber, long long ike) {
    if (ber > ike)
        return ber;
    else
        return ike;
}

// ������� ��� ��������� ������ ��� �������
int **memory_for_matrix(int row, int col) {
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    return arr;
}

// ������� ����� ������� � ����
void input_matrix(int** arr, int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> arr[i][j];
}

// ������� ������ �������
void print_matrix(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << endl;

    }
}

// ������� ��� ����������� ������������ ����� ������� �� �������
void product(int** arr, int row, int col) {
    long long prod = 1;
    long long max_prod = 1;
    int sign = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 0) {
                prod = 1;
                sign++;
                break;
            }
            prod = prod * arr[i][j];
        }
        if (sign == 0) {
            cout << "������������ ��������� " << i + 1 << " ������: " << prod << endl;
            max_prod = maxim(max_prod, prod);
        }
        prod = 1;
        sign = 0;
    }
    cout << "������������ ������������ ��������� ������, �� ���������� ����:    " << max_prod << endl << endl;
}

//const string filename = "file.txt";
//const string filename = "test1.txt";
//const string filename = "test2.txt";
//const string filename = "err_test1.txt";
//const string filename = "err_test2.txt";
//const string filename = "stealth_file.txt";

int main()
{
    setlocale(LC_ALL, "rus");
    system("color F0");
    int N, M;
    int fl;
    cout << "������� \"0\", ���� ������ ������ ������ � ����,  \"1\", ���� ������ ������� �� �� �����" << endl;
    cin >> fl;
    ifstream fn;
    if (fl == 0) {
        cout << "������� ���������� �����:  ";
        cin >> N;
        if (N == 0)
            Errors(3);
        cout << endl << "������� ���������� ��������:   ";
        cin >> M;
        if (M == 0)
            Errors(4);
        cout << endl;
    }
    else if (fl == 1) {
        fn.open(filename);
        if (!fn.is_open())
            Errors(1);
        fn >> N;
        if (N == 0)
            Errors(3);
        if (M == 0)
            Errors(4);
        cout << "���������� �����:  " << N << endl;
        cout << "���������� ��������:  " << M << endl;
    }
    else {
        Errors(0);
        //goto 
    }
    // ��������� ������ ��� �������
    int** matrix = memory_for_matrix(N, M);

    // ������ ������� � ���� ��� �� �����
    if (fl == 0) {
        cout << "������� ������ " << N * M << " ����� �����, ����������� �������� " << endl;
        input_matrix(matrix, N, M);
        cout << "��������� �������:" << endl;
        print_matrix(matrix, N, M);
    }
    else {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) 
                fn >> matrix[i][j];
        cout << "���������� �������:" << endl;
        print_matrix(matrix, N, M);
    }

    // ������� ������������ ����� ������� �� �������
    product(matrix, N, M);
    system("pause");
}