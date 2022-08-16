#ifndef LANCHONETE_H_
#define LANCHONETE_H_

#include "../include/Arquivos.h"
#include "../include/Sistema.h"
#include "../include/Excecoes/CodigoReplicadoException.h"
#include "../include/Lanche.h"
#include "../include/Pedidos.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Sistema;
class Arquivos;

class Lanchonete
{
private:
	string emailProprietario;
	double precoMedio = 0.0;
public:
	int codigo = 0;
	string nome;
	string endereco;
	string categoria;
	float pontos = 0.0F;
	string nomeProprietario;
	vector<Lanche*> lanches = vector<Lanche*>();
	vector<Pedidos*> pedidos = vector<Pedidos*>();
	Sistema *sistema;
	Arquivos *arq;
	//Scanner *s = new Scanner(System::in);
	//Lanchonete();
	 ~Lanchonete();

	 string toString();

	Lanchonete(ifstream file, Sistema *sistema);

	//Lanchonete(BufferedReader *b, Sistema *sistema);

	Lanchonete(int codigo, const string &nome, const string &endereco, const string &categoria, const string &nomeProprietario, const string &emailProprietario);

	 void gravaLanchonete(ofstream file);

	// void gravaLanchonete(BufferedWriter *b);

	 void cadastraLanche(Lanchonete *l);

	 int getCodigo();

	 string getProprietarioNome();

	 string getProprietarioEmail();

	 vector<Lanche*> getListaLanches();

	 void removeTodosPedidos();

	 void removeTodosLanches();

	 void listarLanches();

	 bool verificaExistenciaLanche(int codigo);

	 void visualizarPedidos();

	 void visualizarPedidoEspecifico();

	 Pedidos *buscarPedido(int codigo);

	 vector<Lanche*> getLanches();

	 vector<Pedidos*> getListaPedidos();

	 double getPrecoMedio();

	 int comparaPontos(Lanchonete *l);

	 int comparaVendas(Lanchonete *l);

	 void precoMedioLanches();

	 int compareTo(Lanchonete *l);

	 void fazerPedido(const string &nomeCliente);

	 void removePedido(Pedidos *p);

	 string getNome();

	 void atualizaPontos(float nota);

	 int geraCodigoPedido();

	 double calculaValorTotalPedido(vector<Lanche*> &lanchesComprados);


};

#endif
