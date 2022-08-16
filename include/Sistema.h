#ifndef SISTEMA_H_
#define SISTEMA_H_

#include "../include/Excecoes/EmailInvalidoException.h"
#include "../include/Excecoes/SenhaInvalidaException.h"
#include "../include/Lanche.h"
#include "../include/Lanchonete.h"
#include "../include/Pedidos.h"
#include "../include/Administrador.h"
#include "../include/Cliente.h"
#include "../include/Proprietario.h"
#include "../include/Usuario.h"
#include "../include/Arquivos.h"
#include <string>
#include <vector>
#include <iostream>

class Arquivos;

class Sistema
{
public:
	Arquivos *arq;
	vector<Usuario*> listaUsuarios = vector<Usuario*>();
	vector<Lanchonete*> todasLanchonetes = vector<Lanchonete*>();
	vector<Pedidos*> todosPedidos = vector<Pedidos*>();
	vector<Lanche*> todosLanches = vector<Lanche*>();

	bool verificaCadastro(Usuario *u, vector<Usuario*> &listaUsuarios);

	void login(vector<Usuario*> &listaUsuarios, Sistema *sistema);

	void validaSenha(Usuario *u, const string &senha, Sistema *sistema);

	vector<Lanchonete*> getTodasLanchonetes();

	vector<Usuario*> getListaUsuarios();

	vector<Pedidos*> getTodosPedidos();

	vector<Lanche*> getTodosLanches();

	bool verificaExistenciaLanchonete(int codigo);
};

#endif
