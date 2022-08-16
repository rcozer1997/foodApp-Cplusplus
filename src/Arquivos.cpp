#include "../include/Arquivos.h"
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Arquivos::Arquivos()
{
}

Arquivos::~Arquivos()
{
}

void Arquivos::salvaUsuariosArq(vector<Usuario*> &listaUsuarios)
{			
	ofstream file;
	try
	{	
		
		file.open("Usuarios.csv");
		if(!file.is_open()){
			cerr << "Arquivo nao pode ser aberto." << endl;
			//return 0;
			//break;
		}

		file << to_string(listaUsuarios.size()) << endl;
		for(auto u : listaUsuarios){
			file << u->getNome() << endl;
			file << u->getEmail() << endl;
			file << u->getSenha() << endl;
			file << u->getIdent() << endl;
			//u->gravaUsuariosArq(file);
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exceptions occurred" << e.what() << endl;
	}
}

/* 
void Arquivos::lerUsuariosArq(vector<Usuario*> &listaUsuarios)
{
	//ifstream file;
	//file.exceptions(ifstream::badbit);
	try
	{
		ifstream file("Usuarios.csv");
		file.open("Usuarios.csv");
		string line;
		//int t = static_cast<int>(cin >> line);
		int t = static_cast<int>(file >> line);
		vector<string> d;
		for(int i=0; i<t; i++)
		{
			for(int j=0; j<4; j++)
			{
				string data;
				file >> data;
				d.push_back(data);
			}
			int id = stoi(d[3]);
			if(id == 1)
			{
				Administrador tempVar(d);
				listaUsuarios.push_back(&tempVar);
			}
			else if(id == 2)
			{
				Proprietario tempVar2(d);
				listaUsuarios.push_back(&tempVar2);
			}
			else if(id == 3)
			{
				Cliente tempVar3(d);
				listaUsuarios.push_back(&tempVar3);
			}
			d.clear();
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
	/*catch(const ifstream::failure& e)
	{
		cout << "Exception opening/reading file" << endl;
	}*/
	/*catch(...)
	{
		cout << "Exception occurred" << endl;
	}
}*/

/*
void Arquivos::lerLanchesArq(vector<Lanche*> &todosLanches, vector<Lanchonete*> &lanchonetes)
{
	//ifstream file;
	//file.exceptions(ifstream::badbit);
	try
	{
		ifstream file;
		vector<string> temp;
		string line;
		int t = static_cast<int>(file >> line);
		for(int i=0; i<t; i++)
		{
			for(int j=0; j<4; j++)
			{
				string dados;
				file >> dados;
				temp.push_back(dados);
			}
			string nomeLanchonete = temp[3];
			for(auto l : lanchonetes)
			{
				if(nomeLanchonete == l->getNome())
				{
					Lanche tempVar(temp);
					l->getListaLanches().push_back(&tempVar);
				}
			}
			Lanche tempVar2(temp);
			todosLanches.push_back(&tempVar2);
			temp.clear();
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
	/*catch(const ifstream::failure& e)
	{
		cout << "Exception opening/reading file" << endl;
	}*/
	/*catch(...)
	{
		cout << "Exception occurred" << endl;
	}
}
*/
/*
void Arquivos::lerPedidosArq(vector<Pedidos*> &pedidos, vector<Lanchonete*> &lanchonetes)
{
	//ifstream file;
	//file.exceptions(ifstream::badbit);
	try
	{
		ifstream file;
		file.open("Pedidos.csv");
		vector<string> temp;
		string line;
		int t = static_cast<int>(file >> line);
		for(int i=0; i<t; i++)
		{
			for(int j=0; j<6; j++)
			{
				string dados;
				file >> dados;
				temp.push_back(dados);
			}
			string nomeLanchonete = temp[5];
			for(auto l : lanchonetes)
			{
				if(nomeLanchonete == l->getNome())
				{
					Pedidos tempVar(temp);
					l->getListaPedidos().push_back(&tempVar);
				}
			}
			Pedidos tempVar2(temp);
			pedidos.push_back(&tempVar2);
			temp.clear();
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
	/*catch(const ifstream::failure& e)
	{
		cout << "Exception opening/reading file" << endl;
	}*/
	/*catch(...)
	{
		cout << "Exception occurred" << endl;
	}
}
*/
/*
void Arquivos::salvaLanchoneteArq(vector<Lanchonete*> &lanchonetes)
{
	try
	{
		ofstream file;
		file.open("Lanchonetes.csv");
		file << lanchonetes.size() << endl;
		for(auto l : lanchonetes)
		{
			l->gravaLanchonete(file);
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
	/*catch(...)
	{
		cout << "Exception occurred" << endl;
	}
}*/

/*
void Arquivos::lerLanchonetesArq(vector<Lanchonete*> &lanchonetes, Sistema *sistema)
{
	//ifstream file;
	//file.exceptions(ifstream::badbit);
	try
	{
		ifstream file;
		file.open("Lanchonetes.csv");
		string line;
		int t = static_cast<int>(file >> line);
		for(int i=0; i<t; i++)
		{
			Lanchonete tempVar(file, sistema);
			lanchonetes.push_back(&tempVar);
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
	/*catch(const ifstream::failure& e)
	{
		cout << "Exception opening/reading file" << endl;
	}*/
	/*catch(...)
	{
		cout << "Exception occurred" << endl;
	}
}
*/
/*
void Arquivos::salvaPedidosArq(vector<Pedidos*> &pedidos)
{
	try
	{
		ofstream file;
		file.open("Pedidos.csv");
		file << pedidos.size() << endl;
		for(auto p : pedidos)
		{
			p->gravaPedido(file);
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
}*/
/*
void Arquivos::salvaLanchesArq(vector<Lanche*> &lanches)
{
	try
	{
		ofstream file;
		file.open("Lanches.csv");
		file << lanches.size() << endl;
		for(auto l : lanches)
		{
			l->gravaLanche(file);
		}
		file.close();
	}
	catch(exception& e)
	{
		cout << "Exception occurred" << e.what() << endl;
	}
} */
