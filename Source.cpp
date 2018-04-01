#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;


struct symbol
{
	char value;//T for true or F for false or N for null (temporary)
	bool assigned;//a flag to know if it is assigned or not
	bool pure;//Is it a pure symbol or not?
	int name;//which variable?
};

struct clause
{
	bool isempty;
	bool isunit;
	char value;//T for true or F for false or N for null (temporary)
	bool assigned;//a flag to know if it is assigned or not
	vector<symbol> S;//A set of symbols that have created the clause
};

struct formulae
{
	vector <clause> f;
	bool satisfiable;//satisfiability of the formulae
	bool assigned;//a flag to know if it is assigned or not
};

formulae read_initial() {
	formulae T_f;
	symbol T_s;
	clause T_c;
	fstream inputfile("C:\\Users\\Mirzababa\\Downloads\\Telegram Desktop\\sample3.txt");
	if (inputfile.is_open()) {
		string dummyLine;
		getline(inputfile, dummyLine);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 2; j++) {
				inputfile >> T_s.name;
				T_s.assigned = false;
				T_s.value = 'N';
				T_s.pure = false;

				T_c.S.push_back(T_s);
			}
			T_c.assigned = false;
			T_c.isempty = false;
			T_c.isunit = false;
			T_c.value = 'N';

			T_f.f.push_back(T_c);
			T_f.satisfiable = false;
		}
		return T_f;
	}
	else
	{
		cout << "\tCouldn't read file!\n\tPlease enter correct path \n";
		exit(0);
	}


}
void check_satisfiability_formulae(formulae formulae) /**/
{
	formulae.assigned = false;
	int count = 0;
	for (int i = 0; i < formulae.f.size(); i++)
	{
		if (formulae.f[i].assigned)
		{
			count++;
			if (formulae.f[i].value == false)
			{
				formulae.assigned = true;
				formulae.satisfiable = false;
				break;
			}
		}
		else
		{
			formulae.assigned = false;
			break;
		}
		if (count == formulae.f.size())
		{
			formulae.assigned = true;
			formulae.satisfiable = true;
		}
	}
}
bool DPLL(formulae formul)
{
	if (formul.assigned = true)
		return formul.satisfiable;
}
int main() {

	formulae input = read_initial();
}