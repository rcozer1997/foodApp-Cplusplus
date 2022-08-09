#pragma once

#include "../App.h"
#include "../Arquivos.h"
#include "../Sistema.h"
#include "../Exceptions/CodigoNaoEncontradoException.h"
#include "../Exceptions/CodigoReplicadoException.h"
#include "../Lanchonetes/Lanchonete.h"
#include "../Lanchonetes/Pedidos.h"
#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>

namespace foodApp::Usuarios
{

	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;

	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;
	using CodigoNaoEncontradoException = foodApp::Exceptions::CodigoNaoEncontradoException;
	using CodigoReplicadoException = foodApp::Exceptions::CodigoReplicadoException;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;

	class Proprietario : public Usuario
	{
	public:
		std::vector<Lanchonete*> lanchonetes = std::vector <Lanchonete*>();
		Arquivos *arq = new Arquivos();
		Scanner *s = new Scanner(System::in);

		virtual ~Proprietario()
		{
			delete arq;
			delete s;
		}

		Proprietario(Sistema *sistema);

		Proprietario(std::vector<std::wstring> &list);

		void menu() override;

		virtual void cadastraLanchonete();

		virtual void removeLanchonete();

		virtual void lerLanchonetesProp();

		virtual void removerLanchonetesProprietario();

		virtual void exibirLanchonetes(std::vector<Lanchonete*> &lanchonetes);

		virtual void cadastraLancheLanchonete();

		virtual Lanchonete *buscarLanchonete(int codigo);

		virtual void visualizarPedidosLanchonete();

		virtual void removePedido();

		virtual void listaLanchonetesProprietario();

		virtual bool verificaProprietario(Lanchonete *l);

		virtual std::vector<Lanchonete*> getLanchonetes();

		virtual void removerCadastro(const std::wstring &email, std::vector<Usuario*> &listaUsuarios);
	};







}
