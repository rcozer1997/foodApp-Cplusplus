#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "../include/Lanchonete.h"
#include "../include/Lanche.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Pedidos
{
public:
	int codigo = 0;
	string nomeCliente;
	double valorTotal = 0.0;
	int qntItens = 0;
	string nomeLanchonete;
	//LocalDateTime data;//
	//time_t time(time_t *time);
	//time_t data;
	string data;
	//Lanchonete *lanchonete;
	vector<Lanche*> produtos = vector<Lanche*>();

	 ~Pedidos();

	 string toString();

	//Pedidos(int codigo, vector<Lanche*> &produtos, const string &nomeCliente, double valorTotal, int qntItens, const string &nomeLanchonete, LocalDateTime data);
	Pedidos(int codigo, vector<Lanche*> &produtos, const string &nomeCliente, double valorTotal, int qntItens, const string &nomeLanchonete, const string &data);

	Pedidos(vector<string> &list);

	 void gravaPedido(ofstream file);
	// void gravaPedido(BufferedWriter *b);

	 int getCodigo();

	 vector<Lanche*> getProdutos();

	 int getQntItens();

	// LocalDateTime getData();
	 string getData();
};

#endif
