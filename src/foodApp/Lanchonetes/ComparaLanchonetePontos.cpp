#include "ComparaLanchonetePontos.h"

namespace foodApp::Lanchonetes
{
	using Comparator = java::util::Comparator;

	int ComparaLanchonetePontos::compare(Lanchonete *a, Lanchonete *b)
	{
		return a->comparaPontos(b);
	}
}
