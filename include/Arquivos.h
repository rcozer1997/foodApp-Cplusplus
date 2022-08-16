#ifndef ARQUIVOS_H_
#define ARQUIVOS_H_

#include "../include/Lanche.h"
#include "../include/Lanchonete.h"
#include "../include/Pedidos.h"
#include "../include/Administrador.h"
#include "../include/Cliente.h"
#include "../include/Proprietario.h"
#include "../include/Usuario.h"
#include "../include/Sistema.h"
#include <string>
#include <vector>
#include <iostream>
#include <exception>

using namespace std;
//using Lanche = foodApp::Lanchonetes::Lanche;
//using Lanchonete = foodApp::Lanchonetes::Lanchonete;
//using Pedidos = foodApp::Lanchonetes::Pedidos;
//using Usuario = foodApp::Usuarios::Usuario;

class Arquivos
{
public:
	Arquivos();

	 ~Arquivos();

	 void salvaUsuariosArq(vector<Usuario*> &listaUsuarios);

	 void lerUsuariosArq(vector<Usuario*> &listaUsuarios);

	 void lerLanchesArq(vector<Lanche*> &todosLanches, vector<Lanchonete*> &lanchonetes);

	 void lerPedidosArq(vector<Pedidos*> &pedidos, vector<Lanchonete*> &lanchonetes);

	 void salvaLanchoneteArq(vector<Lanchonete*> &lanchonetes);

	 void lerLanchonetesArq(vector<Lanchonete*> &lanchonetes, Sistema *sistema);

	 void salvaPedidosArq(vector<Pedidos*> &pedidos);

	 void salvaLanchesArq(vector<Lanche*> &lanches);
};

#endif
