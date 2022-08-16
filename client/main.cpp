#include "../include/Arquivos.h"
#include "../include/Sistema.h"
#include "../include/Menus.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	using namespace std;

	Arquivos *arq = new Arquivos();
	Sistema *sistema = new Sistema();
	Menus *menus = new Menus();

	arq->lerUsuariosArq(sistema->listaUsuarios);
	arq->lerLanchonetesArq(sistema->todasLanchonetes, sistema);
	arq->lerLanchesArq(sistema->todosLanches, sistema->todasLanchonetes); //O arquivo dos lanches sera lido e o codigo verificara o nome da lanchonete que ele esta cadastrado, para inseri-lo na lista da lanchonete respectiva
	arq->lerPedidosArq(sistema->todosPedidos, sistema->todasLanchonetes); //O mesmo ocorre com os pedidos, que serão inseridos nas lanchonetes respectivas

	int opcao;

	do
	{
		menus->MenuPrincipal();
		cin >> opcao;

		switch(opcao)
		{
		case 1:
		{
			wcout << "Qual perfil deseja cadastrar?" << endl;
			menus->printaPerfisUsuarios();
			int opcaoCadastro;
			cin >> opcaoCadastro;

			switch(opcaoCadastro)
			{
			case 1:
			{
				Administrador *a = new Administrador(sistema);
				try
				{
					if(!sistema->verificaCadastro(a, sistema->listaUsuarios))
					{
						break;
					}
					sistema->getListaUsuarios().push_back(a);
					arq->salvaUsuariosArq(sistema->listaUsuarios);
				}
				catch(EmailInvalidoException& e)
				{
					cout << "Exception occurred" << endl;
				}
				break;
			}
			case 2:
			{
				try
				{
					Proprietario *p = new Proprietario(sistema);
					if(!sistema->verificaCadastro(p, sistema->listaUsuarios))
					{
						break;
					}
					sistema->getListaUsuarios().push_back(p);
					arq->salvaUsuariosArq(sistema->listaUsuarios);
					sistema->getListaUsuarios().empty();
				}
				catch(const EmailInvalidoException& e)
				{
					cout << "Exceptions occurred" << endl;
				}
				break;
			}
			case 3:
			{
				try
				{
					Cliente *c = new Cliente(sistema);
					if(sistema->verificaCadastro(c, sistema->listaUsuarios))
					{
						break;
					}
					sistema->getListaUsuarios().push_back(c);
					arq->salvaUsuariosArq(sistema->listaUsuarios);
				}
				catch(const EmailInvalidoException& e)
				{
					cout << "Exceptions occurred" << endl;
				}
				break;
			}
			case 0:
				break;
			default:
				cout << "Opcao invalida! Tente novamente" << endl;
				break;
			}
			
		}
		case 2:
			try
			{
				sistema->login(sistema->listaUsuarios, sistema);
			}
			catch (const EmailInvalidoException& e)
			{
				cout << "Exceptions occurred" << endl;
			}
			break;
		case 0:
			cout << "Volte sempre!" << endl;
			break;
		default:
			cout << "Opcao invalida! Tente novamente" << endl;
		}

	}while(opcao != 0);

	delete menus;
	delete arq;
}
