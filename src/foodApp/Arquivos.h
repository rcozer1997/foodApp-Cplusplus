#pragma once

#include "Lanchonetes/Lanche.h"
#include "Lanchonetes/Lanchonete.h"
#include "Lanchonetes/Pedidos.h"
#include "Usuarios/Administrador.h"
#include "Usuarios/Cliente.h"
#include "Usuarios/Proprietario.h"
#include "Usuarios/Usuario.h"
#include "Sistema.h"
#include <string>
#include <vector>
#include <iostream>
//#include "exceptionhelper.h"

namespace foodApp
{

	using ArrayList = java::util::ArrayList;

	using Lanche = foodApp::Lanchonetes::Lanche;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;
	using Pedidos = foodApp::Lanchonetes::Pedidos;
	using Usuario = foodApp::Usuarios::Usuario;

	class Arquivos
	{

	public:
		virtual void salvaUsuariosArq(std::vector<Usuario*> &listaUsuarios, const std::wstring &fileName);

		virtual void lerUsuariosArq(std::vector<Usuario*> &listaUsuarios);

		virtual void lerLanchesArq(std::vector<Lanche*> &todosLanches, std::vector<Lanchonete*> &lanchonetes);

		virtual void lerPedidosArq(std::vector<Pedidos*> &pedidos, std::vector<Lanchonete*> &lanchonetes);

		virtual void salvaLanchoneteArq(std::vector<Lanchonete*> &lanchonetes);

		virtual void lerLanchonetesArq(std::vector<Lanchonete*> &lanchonetes, Sistema *sistema);

		virtual void salvaPedidosArq(std::vector<Pedidos*> &pedidos);


		virtual void salvaLanchesArq(std::vector<Lanche*> &lanches);
	};
}
