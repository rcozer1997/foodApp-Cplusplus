#include "ComparaLanchePreco.h"

namespace foodApp::Lanchonetes
{
	using Comparator = java::util::Comparator;

	int ComparaLanchePreco::compare(Lanche *a, Lanche *b)
	{
		return a->compareTo(b);
	}
}
