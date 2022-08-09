#include "Usuario.h"

namespace foodApp::Usuarios
{
	using BufferedWriter = java::io::BufferedWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;
	using Scanner = java::util::Scanner;
	using Arquivos = foodApp::Arquivos;
	using Sistema = foodApp::Sistema;

	std::wstring Usuario::toString()
	{
		return L"Usuario [nome=" + nome + L", email=" + email + L", senha=" + senha + L", ident=" + std::to_wstring(ident) + L"]";
	}

	Usuario::Usuario(Sistema *sistema)
	{
		std::wcout << L"Nome:";
		std::wstring nome = s->nextLine();
		std::wcout << L"Email:";
		std::wstring email = s->nextLine();
		std::wcout << L"Senha:";
		std::wstring senha = s->nextLine();
		this->nome = nome;
		this->email = email;
		this->senha = senha;
		this->sistema = sistema;
	}

	Usuario::Usuario(std::vector<std::wstring> &list)
	{
		this->nome = list[0];
		this->email = list[1];
		this->senha = list[2];
		this->ident = std::stoi(list[3]);
	}

	void Usuario::gravaUsuariosArq(BufferedWriter *b)
	{
		b->write(this->nome + L"\n");
		b->write(this->email + L"\n");
		b->write(this->senha + L"\n");
		b->write(std::to_wstring(this->ident) + L"\n");
	}

	std::wstring Usuario::getEmail()
	{
		return this->email;
	}

	std::wstring Usuario::getSenha()
	{
		return this->senha;
	}

	std::wstring Usuario::getNome()
	{
		return this->nome;
	}

	int Usuario::getIdent()
	{
		return this->ident;
	}

	bool Usuario::isProp()
	{
		if (this->ident == 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Usuario::removerCadastro(const std::wstring &email, std::vector<Usuario*> &listaUsuarios)
	{
//JAVA TO C++ CONVERTER TODO TASK: There is no C++ equivalent to 'toString':
		std::wcout << listaUsuarios.toString() << std::endl;
		for (int i = 0; i < listaUsuarios.size();i++)
		{
			Usuario *u = listaUsuarios[i];
//JAVA TO C++ CONVERTER TODO TASK: Cannot test for object identity between 2 string objects in C++:
			if (u->getEmail() == email)
			{
				std::wcout << L"Tem certeza que deseja remover o cadastro?" << std::endl;
				std::wcout << L"1 - Sim\n2 - Nao" << std::endl;
				int opcao = s->nextInt();

				if (opcao == 1)
				{
//JAVA TO C++ CONVERTER TODO TASK: The Java Collection 'remove(Object)' method is not converted:
					listaUsuarios.remove(u);
					std::wcout << L"Cliente removido!" << std::endl;
					arq->salvaUsuariosArq(listaUsuarios, L"Usuarios.csv");
					break;
				}
				else if (opcao == 2)
				{
					break;
				}
			}
		}
	}
}
