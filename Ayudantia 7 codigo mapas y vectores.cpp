#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Netflix
{
	private:
		map <string, vector<string> > catalogo;
	public:
		void agregarGenero(string genero)
		{
			if (catalogo.count(genero))
			{
				cout << "El genero ya existe " <<endl;
			}
			else
			{
				catalogo[genero] = vector<string>();
				cout << "Genero " << genero << " agregado." << endl;
			}
		}
		void borrarTitulo(string genero, string titulo)
		{
		    if (catalogo.count(genero)) // Si existe el género
            {
                cout << "El genero es: " << genero << endl;
			    vector<string>& titulos = catalogo[genero];
			    for (int i = 0; i < titulos.size(); i++) // Recorrer los títulos
                {
                    if (titulos[i] == titulo) // Si se encuentra el título
                    {
                        titulos.erase(titulos.begin() + i); // Eliminar el título
                        cout << "Titulo '" << titulo << "' HA SIDO ELIMINADO del genero '" << genero << "'." << endl;
                    }
                }
            }
			else // catalogo.count me da false? si me da false significa q NO existe el genero
			{
				cout << "El genero '" << genero << "' no esta registrado." << endl;
			}
		}
		void agregarTitulo(string genero, string titulo)
		{
			if (catalogo.count(genero)) // catalogo.count me da true? si me da true significa q existe el genero
			{
				catalogo[genero].push_back(titulo);
				cout << "Titulo '" << titulo << "' agregado al genero '" << genero << "'." << endl;
			}
			else // catalogo.count me da false? si me da false significa q NO existe el genero
			{
				cout << "El genero '" << genero << "' no esta registrado." << endl;
			}
		}
		void mostrarTitulosPorGenero(string genero)
		{
		    if (catalogo.find(genero) == catalogo.end())
		    {
    	        cout<<"-----------------------------------------------------------------"<<endl;
                cout << "El genero '" << genero << "' no esta registrado." << endl;
            }
            else
            {
                cout << "El genero es: " << genero << endl;
			    map <string, vector<string> > :: iterator it;
			    for (it = catalogo.begin(); it != catalogo.end(); it++)
		    	{
			    	if (it -> first == genero)
				    {
			    		for (int i = 0; i < it -> second.size(); i++)
				    	{
				    		cout << "Pelicula " << i+1 << ": " << it -> second[i] << endl;
				    	}
			    	}
		    	} 
            }
		}
		int contarpeliculasporgenero(string genero)
		{
		    if (catalogo.find(genero) == catalogo.end())
		    {
    	        cout<<"-----------------------------------------------------------------"<<endl;
                cout << "El genero '" << genero << "' no esta registrado." << endl;
                return 0;
            }
            else
            {
                map <string, vector<string> > :: iterator it;
                it = catalogo.find(genero);
                return it -> second.size();
            }
		}
};
int main()
{
	Netflix * n = new Netflix();
	while (true)
	{
		int opcion;
	    cout << "1. Agregar genero " <<endl;
	    cout << "2. Agregar titulo a genero " <<endl;
	    cout << "3. mostrar Titulos Por Genero " <<endl;
	    cout << "4. contar peliculas por genero" <<endl;
	    cout << "5. eliminar titulo" << endl;
	    cout << "Ingrese cualquier numero para salir" <<endl;
	    cin >> opcion;
	    if (opcion == 1)
	    {
	    	string g;
	    	cout << "Ingrese nombre de genero a añadir " <<endl;
			cin >> g;
			n -> agregarGenero(g);
		}
		else if (opcion == 2)
		{
			string g, t;
			cout << "Ingrese nombre de genero a añadir " <<endl;
			cin >> g;
			cout << "Ingrese nombre de titulo a añadir " <<endl;
			cin >> t;
			n -> agregarTitulo(g, t);
		}
		else if (opcion == 3)
		{
		    string g;
			cout << "Ingrese nombre de genero a buscar " <<endl;
			cin >> g;
			n -> mostrarTitulosPorGenero(g);
		}
		else if (opcion == 4)
		{
		    string g;
			cout << "Ingrese nombre de genero para contar cantidad de peliculas " <<endl;
			cin >> g;
			cout << "El numero de peliculas es " << n -> contarpeliculasporgenero(g) << endl;
		}
		else if (opcion == 5)
		{
		    string g, t;
		    cout << "Ingrese nombre de genero a buscar " <<endl;
		    cin >> g;
			cout << "Ingrese nombre de titulo a borrar " <<endl;
			cin >> t;
			n -> borrarTitulo(g, t);
		}
		else
		{
		    break;
		}
	}
}
