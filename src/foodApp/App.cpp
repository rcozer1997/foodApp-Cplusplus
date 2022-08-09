#include "App.h"
#include "Arquivos.h"
#include "Sistema.h"
#include "Menus.h"

namespace foodApp
{
	using Scanner = java::util::Scanner;
	using EmailInvalidoException = foodApp::Exceptions::EmailInvalidoException;
	using Administrador = foodApp::Usuarios::Administrador;
	using Cliente = foodApp::Usuarios::Cliente;
	using Proprietario = foodApp::Usuarios::Proprietario;

	void App::main(std::vector<std::wstring> &args)
	{
		Scanner *s = new Scanner(System::in);
		Arquivos *arq = new Arquivos();
		Sistema *sistema = new Sistema();
		Menus *menus = new Menus();

			arq->lerUsuariosArq(sistema->getListaUsuarios());
			arq->lerLanchonetesArq(sistema->getTodasLanchonetes(), sistema);
			arq->lerLanchesArq(sistema->getTodosLanches(), sistema->getTodasLanchonetes()); //O arquivo dos lanches sera lido e o codigo verificara o nome da lanchonete que ele esta cadastrado, para inseri-lo na lista da lanchonete respectiva
			arq->lerPedidosArq(sistema->getTodosPedidos(), sistema->getTodasLanchonetes()); //O mesmo ocorre com os pedidos, que serão inseridos nas lanchonetes respectivas
			int opcao;
			do
			{
				menus->menuPrincipal();
				opcao = s->nextInt();

				switch (opcao)
				{

				case 1:
				{
					std::wcout << L"Qual perfil deseja cadastrar?" << std::endl;
					menus->printaPerfisUsuarios();
					int opcaoCadastro = s->nextInt();
					switch (opcaoCadastro)
					{
					case 1:
					{
						Administrador *a = new Administrador(sistema);
						try
						{
							if (!sistema->verificaCadastro(a, sistema->getListaUsuarios()))
							{
//JAVA TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
								break;
							}
							sistema->getListaUsuarios().push_back(a);
							arq->salvaUsuariosArq(sistema->getListaUsuarios(), L"Usuarios.csv");
						}
						catch (const EmailInvalidoException &e)
						{
							std::wcout << e->what() << std::endl;
						}

//JAVA TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
						break;

//JAVA TO C++ CONVERTER TODO TASK: A 'delete a' statement was not added since a was passed to a method or constructor. Handle memory management manually.
					}
					case 2:
						try
						{
							Proprietario *p = new Proprietario(sistema);
							if (!sistema->verificaCadastro(p, sistema->getListaUsuarios()))
							{
//JAVA TO C++ CONVERTER TODO TASK: A 'delete p' statement was not added since p was passed to a method or constructor. Handle memory management manually.
								break;
							}
							sistema->getListaUsuarios().push_back(p);
							arq->salvaUsuariosArq(sistema->getListaUsuarios(), L"Usuarios.csv");
							sistema->getListaUsuarios().empty();

//JAVA TO C++ CONVERTER TODO TASK: A 'delete p' statement was not added since p was passed to a method or constructor. Handle memory management manually.
						}
						catch (const EmailInvalidoException &e)
						{
							std::wcout << e->what() << std::endl;
						}
						break;
					case 3:
						try
						{
							Cliente *c = new Cliente(sistema);
							if (!sistema->verificaCadastro(c, sistema->getListaUsuarios()))
							{
//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
								break;
							}
							sistema->getListaUsuarios().push_back(c);
							arq->salvaUsuariosArq(sistema->getListaUsuarios(), L"Usuarios.csv");

//JAVA TO C++ CONVERTER TODO TASK: A 'delete c' statement was not added since c was passed to a method or constructor. Handle memory management manually.
						}
						catch (const EmailInvalidoException &e)
						{
							std::wcout << e->what() << std::endl;
						}
						break;
					case 0:
						break;
					default:
						std::wcout << L"Opcao invalida! Tente novamente." << std::endl;
					}
					break;
				}
				case 2:
					try
					{
					sistema->login(sistema->getListaUsuarios(), sistema);

					}
					catch (const EmailInvalidoException &e)
					{
					std::wcout << e->what() << std::endl;
					}
					break;
				case 0:
					std::wcout << L"Volte sempre!" << std::endl;
					break;
				default:
					std::wcout << L"Opcao invalida! Tente novamente." << std::endl;
					break;
				}
			}while (opcao != 0);

		delete menus;
//JAVA TO C++ CONVERTER TODO TASK: A 'delete sistema' statement was not added since sistema was passed to a method or constructor. Handle memory management manually.
		delete arq;
		delete s;
	}
}
