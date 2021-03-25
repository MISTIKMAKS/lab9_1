#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec {KOMPUTERNINAUKY, INFORMATIKA, MATEMATIKAIEKONOMIKA, FIZUKAIINFORMATIKA, TRUDOVENAVCHANNA};

string spec_str[] = { "Computer Science", "Informatics", "Mathematics and Economics", "Physics and Informatics", "Handicraft" };

struct Student
{
	string last_name;
	int cource;
	Spec speciality;
	int fizuka;
	int matematika;
	union{
		int programuvanna;
		int chuselni_metody;
		int pedagogika;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
int SearchC(Student* s, const int N);
int SearchB(Student* s, const int N);
int SearchA(Student* s, const int N);
int SearchDuble(Student* s, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Insert N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	SearchC(s, N);
	SearchB(s, N);
	SearchA(s, N);
	SearchDuble(s, N);
}
void Create(Student* s, const int N) {
	int speciality;
	for (int i = 0; i < N; i++)
	{
		cout << "Student № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Last Name: "; getline(cin, s[i].last_name);
		cout << " Cource : "; cin >> s[i].cource;
		cout << " Speciality (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Handicraft): ";
		cin >> speciality;
		s[i].speciality = (Spec)speciality;
		switch (s[i].speciality) {
		case KOMPUTERNINAUKY:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Programming : "; cin >> s[i].programuvanna;
			break;
		case INFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Numerical Methods : "; cin >> s[i].chuselni_metody;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		case FIZUKAIINFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		case TRUDOVENAVCHANNA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "============================================================================="
		<< endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |"
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[i].last_name
			<< "| " << setw(6) << right << s[i].cource << " "
			<< "| " << setw(10) << left << spec_str[s[i].speciality];
		switch (s[i].speciality) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << "|" << " " << setw(3) << right << s[i].programuvanna << " |"
				<< " " << setw(3) << right << " |" << " " << setw(3) << right << " |" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< s[i].chuselni_metody << " |" << setw(3) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right 
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		}
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}
int SearchC(Student* s, const int N) {
	cout << "Students with C grade on Physics:";
	int c = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].fizuka == 3) {
			c++;
		}
	}
	cout << c << endl;
	return c;
}
int SearchB(Student* s, const int N) {
	cout << "Students with B grade on Physics:";
	int b = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].fizuka == 4) {
			b++;
		}
	}
	cout << b << endl;
	return b;
}
int SearchA(Student* s, const int N) {
	cout << "Students with A grade on Physics:";
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].fizuka == 5) {
			a++;
		}
	}
	cout << a << endl;
	return a;
}
int SearchDuble(Student* s, const int N) {
	cout << "Students with Physics|Math (5|5 ; 4|4):";
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (s[i].fizuka == 5 && s[i].matematika == 5 || s[i].fizuka == 4 && s[i].matematika == 4) {
			num++;
		}
	}
	cout << num << endl;
	return num;
}