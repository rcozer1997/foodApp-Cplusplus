#include "ComparaLanchonetePrecoMedio.h"

namespace foodApp::Lanchonetes
{
	using Comparator = java::util::Comparator;

	int ComparaLanchonetePrecoMedio::compare(Lanchonete *a, Lanchonete *b)
	{
		return a->compareTo(b);
	}
}
