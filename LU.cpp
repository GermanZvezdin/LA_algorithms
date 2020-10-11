// LU.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;
void LU(vector <vector <double>> A, vector <vector <double>>& L,
	vector <vector <double>>& U, int n) {
	L.resize(n); U.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			L[i].push_back(0);
			U[i].push_back(0);
		}
	}
	
	U = A;

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			L[j][i] = U[j][i] / U[i][i];

	for (int k = 1; k < n; k++)
	{
		for (int i = k - 1; i < n; i++)
			for (int j = i; j < n; j++)
				L[j][i] = U[j][i] / U[i][i];

		for (int i = k; i < n; i++)
			for (int j = k - 1; j < n; j++)
				U[i][j] = U[i][j] - L[i][k - 1] * U[k - 1][j];
	}

}


void mul(vector <vector <double>> A, vector <vector <double>> B,
	vector <vector <double>>& R, int n){
	R.resize(n);
	for (int i = 0; i < n; i++) {
		R[i].resize(n);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				R[i][j] += A[i][k] * B[k][j];
}

void show(vector <vector <double>> A, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\t" << A[i][j] << "\t";
		}
		cout << endl;
	}
}

double sum(vector<double> a, vector<double> b, int n, int m = 0) {
	double ans = 0;
	for (int i = m; i < n; i++) {
		ans += a[i] * b[i];
	}
	return ans;
}
void SLAU(vector <vector <double>> A, vector<double> b, vector<double>& ans, int n) {
	ans.resize(n);
	vector<double> y; 
	y.resize(n);
	vector< vector<double>> L, U;
	LU(A, L, U, n);
	for (int i = 0; i < n; i++) {
		y[i] = b[i] - sum(L[i], y, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = (y[i] - sum(U[i], ans, n, i)) / U[i][i];
	}

}
int main()
{
	int n = 3;
	std::vector<std::vector<double>> A = { {1, 5, 2}, {5, -1, -2}, {9, -13, 7} };
	std::vector<double> b = {7, 0, 9}, ans;
	SLAU(A, b, ans, n);
	for (auto i : ans) {
		std::cout << i << " " ; 
	}
	

	
	return 0;
	
	
	

	
}




















// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
