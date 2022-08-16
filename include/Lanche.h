#ifndef LANCHE_H_
#define LANCHE_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Lanche
{
public:
	int codigo = 0;
	string descricao;
	float preco = 0.0F;
	string nomeLanchonete;

	 ~Lanche();

	Lanche(int codigo, const string &descricao, float preco, const string &nomeLanchonete);

	Lanche(vector<string> &list);

	void gravaLanche(ofstream file);

	// void gravaLanche(BufferedWriter *b);

	string getNome();

	int getCodigo();

	string getDescricao();

	float getPreco();

	string getNomeLanchonete();

	string toString();

	int compareTo(Lanche *l);
};

#endif
