#pragma once

#include "../Arquivos.h"
#include "../Sistema.h"
#include <string>
#include <vector>
#include <iostream>

namespace foodApp::Usuarios
{

	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;

	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;

	class Usuario
	{
	public:
		std::wstring nome;
	private:
		std::wstring email;
		std::wstring senha;
	public:
		int ident = 0; // 1 - Administrador , 2 - Proprietario , 3 - Cliente
		Sistema *sistema;
		Arquivos *arq = new Arquivos();
		Scanner *s = new Scanner(System::in);


		virtual ~Usuario()
		{
			delete sistema;
			delete arq;
			delete s;
		}

		virtual std::wstring toString();

		Usuario(Sistema *sistema);

		Usuario(std::vector<std::wstring> &list);

		virtual void gravaUsuariosArq(BufferedWriter *b);

		virtual std::wstring getEmail();

		virtual std::wstring getSenha();

		virtual std::wstring getNome();

		virtual int getIdent();

		virtual bool isProp();

		virtual void menu() = 0;

		virtual void removerCadastro(const std::wstring &email, std::vector<Usuario*> &listaUsuarios);

	};

}
