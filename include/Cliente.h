#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "../include/Sistema.h"
#include "../include/Excecoes/CodigoNaoEncontradoException.h"
/*
#include "ComparaLanchonetePontos.h"
#include "ComparaLanchonetePrecoMedio.h"
#include "ComparaLanchoneteVendas.h"
*/
#include "../include/Lanche.h"
#include "../include/Lanchonete.h"
#include "../include/Usuario.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Lanchonete;

class Cliente : public Usuario
{
public:
	//Scanner *s = new Scanner(System::in);
	virtual ~Cliente()
	{
		//delete s;
	}
	Cliente(Sistema *sistema);

	Cliente(vector<string> &list);

	void menu() override;

	virtual void exibirLanchonetes();

	virtual Lanchonete *buscarLanchonete(int codigo);

	virtual void verLanchesLanchonete();

	virtual void listarLanchonetesPontuacao();

	virtual void listarPontuacaoCategoria();

	virtual void listarLanchonetesPrecoMedio();

	virtual void listarLanchonetesVendas();

	virtual void buscarLanche();

	virtual void fazerPedidoLanchonete();

	virtual void avaliaLanchonete();
};

#endif
