#pragma once

#include "../Arquivos.h"
#include "../Sistema.h"
#include "../Exceptions/CodigoReplicadoException.h"
#include "Lanche.h"
#include "Pedidos.h"
#include <string>
#include <vector>
#include <iostream>

namespace foodApp::Lanchonetes
{
	using BufferedReader = java::io::BufferedReader;
	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;
	using CodigoReplicadoException = foodApp::Exceptions::CodigoReplicadoException;

	class Lanchonete
	{
	public:
		int codigo = 0;
		std::wstring nome;
		std::wstring endereco;
		std::wstring categoria;
		float pontos = 0.0F;
		std::wstring nomeProprietario;
	private:
		std::wstring emailProprietario;
	public:
		std::vector<Lanche*> lanches = std::vector<Lanche*>();
		std::vector<Pedidos*> listaPedidos = std::vector<Pedidos*>();
	private:
		double precoMedio = 0.0;

	public:
		Sistema *sistema = new Sistema();
		Arquivos *arq = new Arquivos();
		Scanner *s = new Scanner(System::in);

		virtual ~Lanchonete()
		{
			delete sistema;
			delete arq;
			delete s;
		}

		virtual std::wstring toString();

		Lanchonete(BufferedReader *b, Sistema *sistema);

//JAVA TO C++ CONVERTER TODO TASK: No base class can be determined:
		Lanchonete(int codigo, const std::wstring &nome, const std::wstring &endereco, const std::wstring &categoria, const std::wstring &nomeProprietario, const std::wstring &emailProprietario); //super();
		virtual void gravaLanchonete(BufferedWriter *b);

		virtual void cadastraLanche(Lanchonete *l);

		virtual int getCodigo();

		virtual std::wstring getProprietarioNome();

		virtual std::wstring getProprietarioEmail();
		virtual std::vector<Lanche*> getListaLanches();

		virtual void removeTodosPedidos();

		virtual void removeTodosLanches();

		virtual void listarLanches();

		virtual bool verificaExistenciaLanche(int codigo);

		virtual void visualizarPedidos();

		virtual void visualizarPedidoEspecifico();

		virtual Pedidos *buscarPedido(int codigo);

		virtual std::vector<Lanche*> getLanches();

		virtual std::vector<Pedidos*> getListaPedidos();

		virtual double getPrecoMedio();

		virtual int comparaPontos(Lanchonete *l);

		virtual int comparaVendas(Lanchonete *l);


		virtual void precoMedioLanches();

		virtual int compareTo(Lanchonete *l);

		virtual void fazerPedido(const std::wstring &nomeCliente);

		virtual void removePedido(Pedidos *p);

		virtual std::wstring getNome();

		virtual void atualizaPontos(float nota);

		virtual int geraCodigoPedido();

		virtual double calculaValorTotalPedido(std::vector<Lanche*> &lanchesComprados);
	};




}
