#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>
using namespace std;


struct symbol
{
	char value;//T for true or F for false or N for null (temporary)
	bool sign;//T for true or F for false
	bool pure;//Is it a pure symbol or not?
	int name;//which variable?
	bool assigned;// flag to know if it is assigned or not this meanes this symbol was added to model or not

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


	fstream inputfile("E:\\Course\\AI\\AI2\\HW2_AI2\\Sample1.txt");
	if (inputfile.is_open()) {
		string dummyLine;
		getline(inputfile, dummyLine);
		for (int i = 0; i < 10; i++) {
			clause T_c;
			for (int j = 0; j < 3; j++) {
				symbol T_s;
				inputfile >> T_s.name;
				T_s.assigned = false;
				T_s.value = 'N';
				T_s.pure = false;
				if (T_s.name > 0) 
				{
					T_s.sign = true;
				}
				else
				{
					T_s.sign = false;
				}
				

				T_c.S.push_back(T_s);
			}

			T_c.assigned = false;
			T_c.isempty = false;
			T_c.isunit = false;
			T_c.value = 'N';

			T_f.f.push_back(T_c);
			T_f.satisfiable = false;
			T_f.assigned = false;
		}
		return T_f;
	}
	else
	{
		cout << "\tCouldn't read file!\n\tPlease enter correct path \n";
		exit(0);
	}


}

bool check_unit_clause(formulae formulae) {

}

bool check_pure_symbol(formulae formulae) {

}

bool empty(formulae formulae) {
	if (formulae.f.empty()) { return true; }
	else{return false;}
}
bool check_empty_clause(formulae formulae) {

	return std::for_each(formulae.f.begin(), formulae.f.end(), empty(formulae));
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
bool logicOR(bool a, bool b)
{
	if (a == true || b == true)
		return true;
	if (a == false && b == false)
		return true;
}
void update(formulae formul, symbol symbol)
{
	for (int i = 0; i < formul.f.size(); i++)
	{
		int count = 0;
		bool clause_value = false;
		for (int j = 0; j < formul.f[i].S.size(); j++)
		{
			if (formul.f[i].S[j].assigned)
			{
				count++;
				clause_value = logicOR(clause_value, formul.f[i].S[j].sign);
			}
			if (formul.f[i].S[j].name == symbol.name)
			{
				if (formul.f[i].S[j].sign == symbol.sign)
					formul.f[i].S[j].value = symbol.value;
				else
					formul.f[i].S[j].value = !symbol.value;
				formul.f[i].S[j].assigned = true;
				count++;
				clause_value = logicOR(clause_value, formul.f[i].S[j].sign);
			}
			if (count == formul.f[i].S.size())
			{
				formul.f[i].value = clause_value;
				formul.f[i].assigned = true;
			}
		}

	}

}
bool DPLL(formulae formul, vector<symbol> Model)
{
	if (formul.assigned = true)
		return formul.satisfiable;
}
int main() {

	formulae input = read_initial();
}