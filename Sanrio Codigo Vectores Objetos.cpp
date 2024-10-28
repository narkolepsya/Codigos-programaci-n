#include <iostream>
#include <vector>
using namespace std;
class Sanrio
{
	private:
		string nombre;
	public:
		Sanrio(string nombre)
		{
			this -> nombre = nombre;
		}
		string getNombre()
		{
			return nombre;
		}
		void MostrarPersonaje()
		{
			cout << "Personaje: " << nombre << endl;
		}
};
class ListaDePersonajes
{
	private:
		vector <Sanrio *> personaje;
	public:
		void agregarPersonaje(Sanrio * a)
		{
			personaje.push_back(a);
		}
		void quitarPersonaje()
		{
			personaje.pop_back();
		}
		void quitarPersonajeSeleccionado(Sanrio * a)
		{
			vector<Sanrio*> ::iterator it;
			for (it = personaje.begin(); it != personaje.end(); it++)
			{
				if (*it == a)
				{
            		personaje.erase(it);
            		break;
            	}
			}
		}
		void sizeLista()
		{
			cout << "Tamanho lista " << personaje.size() <<endl;
		}
		void OrdenarLista() // ordena por abecedario
		{
			for (int i = 0; i < personaje.size()-1; i++)
			{
				for (int j = i+1; j < personaje.size(); j++)
				{
					if (personaje.at(i) -> getNombre() > personaje.at(j) -> getNombre())
					{
						Sanrio * aux = personaje.at(i);
						personaje.at(i) = personaje.at(j);
						personaje.at(j) = aux;
					}
				}
			}
		}
		void MostrarInfo()
		{
			for (int i = 0; i < personaje.size(); i++)
			{
				cout << i + 1;
				personaje.at(i) -> MostrarPersonaje();
			}
		}
		void MostrarInfoUnSoloPj(string nombre)
		{
			for (int i = 0; i < personaje.size(); i++)
			{
			    if (personaje.at(i) -> getNombre() == nombre)
			    {
			        personaje.at(i) -> MostrarPersonaje();
			        break;
			    }
			}
		}
};
int main()
{
	Sanrio * kero = new Sanrio("Keroppi");
	Sanrio * melo = new Sanrio("My Melody");
	Sanrio * kuro = new Sanrio("Kuromi");
	Sanrio * cina = new Sanrio("Cinnamoroll");
	Sanrio * pocha = new Sanrio("Pochacco");
	Sanrio * pomp = new Sanrio("Perro flan");
	
	ListaDePersonajes * lista = new ListaDePersonajes();
	
	while (true)
	{
	    int opcion;
	    cout << "1. Agregar Personaje " <<endl;
	    cout << "2. Eliminar último personaje" <<endl;
	    cout << "3. Eliminar personaje seleccionado " <<endl;
	    cout << "4. Ordenar Lista por abecedario" <<endl;
	    cout << "5. Mostrar Lista" <<endl;
	    cout << "6. Mostrar un solo personaje" <<endl;
	    cout << "7. Salir" << endl;
	    cin >> opcion;
	    if (opcion == 1)
	    {
	        int subopcion;
            cout << "Seleccione el personaje a agregar:" << endl;
            cout << "1. Keroppi\n2. My Melody\n3. Kuromi\n4. Cinnamoroll\n5. Pochacco\n6. Perro flan" << endl;
            cin >> subopcion;
            
            Sanrio * nuevoPersonaje = NULL;
            switch (subopcion)
            {
                case 1: nuevoPersonaje = kero;
                break;
                case 2: nuevoPersonaje = melo;
                break;
                case 3: nuevoPersonaje = kuro;
                break;
                case 4: nuevoPersonaje = cina;
                break;
                case 5: nuevoPersonaje = pocha;
                break;
                case 6: nuevoPersonaje = pomp;
                break;
                default: cout << "Opción inválida." << endl;
            }
            lista-> agregarPersonaje(nuevoPersonaje);
	    }
	    else if (opcion == 2)
	    {
	       lista -> quitarPersonaje();
	    }
	    else if (opcion == 3)
	    {
	        int subopcion;
            cout << "Seleccione el personaje a agregar:" << endl;
            cout << "1. Keroppi\n2. My Melody\n3. Kuromi\n4. Cinnamoroll\n5. Pochacco\n6. Perro flan" << endl;
            cin >> subopcion;
            
            Sanrio * nuevoPersonaje = NULL;
            switch (subopcion)
            {
                case 1: nuevoPersonaje = kero;
                break;
                case 2: nuevoPersonaje = melo;
                break;
                case 3: nuevoPersonaje = kuro;
                break;
                case 4: nuevoPersonaje = cina;
                break;
                case 5: nuevoPersonaje = pocha;
                break;
                case 6: nuevoPersonaje = pomp;
                break;
                default: cout << "Opción inválida." << endl;
            }
            lista-> quitarPersonajeSeleccionado(nuevoPersonaje);
	    }
	    else if (opcion == 4)
	    {
	        lista -> OrdenarLista();
	    }
	    else if (opcion == 5)
	    {
	        lista -> MostrarInfo();
	    }
	    else if (opcion == 6)
	    {
	        string n;
	        cout << "Ingrese nombre personaje a mostrar" <<endl;
	        cin >> n;
	        lista -> MostrarInfoUnSoloPj(n);
	    }
	    else if (opcion == 7)
	    {
	        break;
	    }
	    cout << endl;
	}
}
