/* #ifndef COMPARALANCHEPRECO_H_
#define COMPARALANCHEPRECO_H_

#include <iostream>
#include "Lanche.h"

using namespace std;

class ComparaLanchePreco : public Comparator<Lanche*>
{
public:
	ComparaLanchePreco();
	virtual ~ComparaLanchePreco();
	virtual int compare(Lanche *a, Lanche *b);
};

#endif
 */