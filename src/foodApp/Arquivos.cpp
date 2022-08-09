#include "Arquivos.h"

namespace foodApp
{
	using BufferedReader = java::io::BufferedReader;
	using BufferedWriter = java::io::BufferedWriter;
	using FileReader = java::io::FileReader;
	using FileWriter = java::io::FileWriter;
	using IOException = java::io::IOException;
	using ArrayList = java::util::ArrayList;
	using Lanche = foodApp::Lanchonetes::Lanche;
	using Lanchonete = foodApp::Lanchonetes::Lanchonete;
	using Pedidos = foodApp::Lanchonetes::Pedidos;
	using Administrador = foodApp::Usuarios::Administrador;
	using Cliente = foodApp::Usuarios::Cliente;
	using Proprietario = foodApp::Usuarios::Proprietario;
	using Usuario = foodApp::Usuarios::Usuario;

	void Arquivos::salvaUsuariosArq(std::vector<Usuario*> &listaUsuarios, const std::wstring &fileName)
	{
		try
		{
			FileWriter *f = new FileWriter(fileName);
			BufferedWriter *b = new BufferedWriter(f);

			b->write(std::to_wstring(listaUsuarios.size()) + L"\n");
			for (auto u : listaUsuarios)
			{
				u->gravaUsuariosArq(b);
			}
			b->close();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
		}
		catch (const IOException &e)
		{
			std::wcout << L"Erro ao salvar o arquivo!" << std::endl;
		}
	}

	void Arquivos::lerUsuariosArq(std::vector<Usuario*> &listaUsuarios)
	{
		try
		{
			FileReader *f = new FileReader(L"Usuarios.csv");
			BufferedReader *b = new BufferedReader(f);
			int t = static_cast<int>(b->readLine());
			std::vector<std::wstring> d;

			for (int i = 0; i < t; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					std::wstring data = b->readLine();
					d.push_back(data);
				}
				int id = std::stoi(d[3]);
				if (id == 1)
				{
					Administrador tempVar(d);
					listaUsuarios.push_back(&tempVar);
				}
				else if (id == 2)
				{
					Proprietario tempVar2(d);
					listaUsuarios.push_back(&tempVar2);
				}
				else if (id == 3)
				{
					Cliente tempVar3(d);
					listaUsuarios.push_back(&tempVar3);
				}
				d.clear();
			}
			b->close();
			f->close();

			delete b;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
		}
		catch (const IOException &e)
		{
			std::wcout << L"Nenhum usuario carregado." << std::endl;
		}
	}

	void Arquivos::lerLanchesArq(std::vector<Lanche*> &todosLanches, std::vector<Lanchonete*> &lanchonetes)
	{
		try
		{
			FileReader *f = new FileReader(L"Lanches.csv");
			BufferedReader *b = new BufferedReader(f);
			std::vector<std::wstring> temp;
			int t = static_cast<int>(b->readLine());
			for (int i = 0; i < t; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					std::wstring dados = b->readLine();
					temp.push_back(dados);
				}
					std::wstring nomeLanchonete = temp[3];
					for (auto l : lanchonetes)
					{
						if (nomeLanchonete == l->getNome())
						{
							Lanche tempVar(temp);
							l->getListaLanches().push_back(&tempVar);
						}
					}
					Lanche tempVar2(temp);
					todosLanches.push_back(&tempVar2);
					temp.clear();
			}
			f->close();
			b->close();

			delete b;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
		}
		catch (const IOException &e)
		{
			std::wcout << L"Nenhum lanche carregado." << std::endl;
		}
	}

	void Arquivos::lerPedidosArq(std::vector<Pedidos*> &pedidos, std::vector<Lanchonete*> &lanchonetes)
	{
		try
		{
			FileReader *f = new FileReader(L"Pedidos.csv");
			BufferedReader *b = new BufferedReader(f);
			std::vector<std::wstring> temp;
			int t = static_cast<int>(b->readLine());
			for (int i = 0; i < t; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					std::wstring dados = b->readLine();
					temp.push_back(dados);
				}
				std::wstring nomeLanchonete = temp[5];
				for (auto l : lanchonetes)
				{
					if (nomeLanchonete == l->getNome())
					{
						Pedidos tempVar(temp);
						l->getListaPedidos().push_back(&tempVar);
					}
				}
				Pedidos tempVar2(temp);
				pedidos.push_back(&tempVar2);
				temp.clear();
			}
			f->close();
			b->close();

			delete b;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
		}
		catch (const IOException &e)
		{
			std::wcout << L"Nenhum pedido carregado." << std::endl;
		}
	}

	void Arquivos::salvaLanchoneteArq(std::vector<Lanchonete*> *lanchonetes)
{
	try
	{
		FileWriter *f = new FileWriter(L"Lanchonetes.csv");
		BufferedWriter *b = new BufferedWriter(f);
		b->write(std::to_wstring(lanchonetes->size()) + L"\n");
		for (auto l : *lanchonetes)
		{
			l->gravaLanchonete(b);
		}
		b->close();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
	}
	catch (const IOException &e)
	{
		std::wcout << L"Erro ao salvar o arquivo." << std::endl;
	}
}

void Arquivos::lerLanchonetesArq(std::vector<Lanchonete*> *lanchonetes, Sistema *sistema)
{
	try
	{
		FileReader *f = new FileReader(L"Lanchonetes.csv");
		BufferedReader *b = new BufferedReader(f);
		int t = static_cast<int>(b->readLine());
		for (int i = 0; i < t; i++)
		{
			Lanchonete tempVar(b, sistema);
			lanchonetes->add(&tempVar);
		}
		f->close();
		b->close();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
	}
	catch (const IOException &e)
	{
		std::wcout << L"Nenhuma lanchonete carregada." << std::endl;
	}
}

void Arquivos::salvaPedidosArq(std::vector<Pedidos*> *pedidos)
{
	try
	{
		FileWriter *f = new FileWriter(L"Pedidos.csv");
		BufferedWriter *b = new BufferedWriter(f);

		b->write(std::to_wstring(pedidos->size()) + L"\n");
		for (auto p : *pedidos)
		{
			p->gravaPedido(b);
		}
		b->close();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
	}
	catch (const IOException &e)
	{
		std::wcout << L"Erro ao salvar o arquivo." << std::endl;
	}
}

void Arquivos::salvaLanchesArq(std::vector<Lanche*> *lanches)
{
	try
	{
		FileWriter *f = new FileWriter(L"Lanches.csv");
		BufferedWriter *b = new BufferedWriter(f);

		b->write(std::to_wstring(lanches->size()) + L"\n");
		for (auto l : *lanches)
		{

			l->gravaLanche(b);
		}
		b->close();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete b' statement was not added since b was passed to a method or constructor. Handle memory management manually.
//JAVA TO C++ CONVERTER TODO TASK: A 'delete f' statement was not added since f was passed to a method or constructor. Handle memory management manually.
	}
	catch (const IOException &e)
	{
		std::wcout << L"Erro ao salvar o arquivo." << std::endl;
	}
}
}
