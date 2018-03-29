#include <iostream>
#include <fstream>
#include <list>
#include <map>
using namespace std;

int main (int argc, char *argv[]) {
    ifstream archivo;

	if (argc < 2) {
		cout << "Error, Falta ingresar el archivo de test!" << endl;
		return 1;
	}

  	archivo.open(argv[1]);

  	int cantLinks = 0;
  	int cantPaginas = 0;

  	archivo >> cantPaginas;
  	archivo >> cantLinks;

  	int i,j;
    map<int , list<int> > matriz;

  	for (int k = 0; k < cantLinks; k++)
  	{
  		archivo >> i >> j;

  		map<int , list<int> >::iterator it = matriz.find(i);

	 	if (it != matriz.end()){	// esta la posicion i
	 		matriz[i].push_back(j);
	 	}else{ 	// NO esta la posicion i
	 		list<int> lista;
	 		list<int>::iterator itLista;
  			itLista = lista.begin();
	 		lista.insert(itLista, j);
	 		matriz.insert(pair<int , list<int> >(i,lista));
	 	}
  	}

  	archivo.close();
 	return 0;
}