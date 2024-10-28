#include <iostream>
#include <vector>
using namespace std;
class Estudiante
{
	private:
		string rut;
		string nombre;
		vector <float> notas;
	public:
		Estudiante(string rut, string nombre)
		{
			this -> rut = rut;
			this -> nombre = nombre;
		}
		void ingresarNota(float nota)
		{
			notas.push_back(nota);
			cout << "Se ha añadido la nota " << nota <<endl;
		}
		void ingresarMuchasNotas(vector <float> lista)
		{
			for (int i = 0; i < lista.size() ; i++)
			{
				notas.push_back(lista.at(i));
			}
			cout << "Se han agregado un total de " << lista.size() << "notas" <<endl;
		}
		float promedioNotas()
		{
			float total = 0;
			for (int i = 0; i < notas.size(); i++)
			{
				total = total + notas.at(i);
			}
			return total / notas.size();
		}
		void lista()
		{
			cout << "Nombre: " << nombre << ". Rut: " << rut << endl;
			cout << "NOTAS: " <<endl;
			for (int i = 0; i < notas.size() ; i++)
			{
				cout << notas.at(i) <<endl;
			}
			cout << "Promedio notas: " << promedioNotas() <<endl;
			cout << " ---------------------------------------- " <<endl;
		}
		string getNombre()
		{
			return nombre;
		}
};
int main()
{
	string nombres;
	float notaa;
	Estudiante * e = new Estudiante("22069982", "Gaby");
	Estudiante * b = new Estudiante("2940432", "Jacinta");
	vector <float> listadenotas;
	while(true)
	{
		float n;
		string respuesta;
		cout << "Ingrese nota a añadir a lista" <<endl;
		cin >> n;
		listadenotas.push_back(n);
		cout << "Quiere parar de ingresar notas? SI/NO" <<endl;
		cin >> respuesta;
		if (respuesta == "Si")
		{
			break;
		}
	}
	cout << "Ingrese nombre para añadir nota "<< endl;
	cin >> nombres;
	if (nombres == e-> getNombre())
	{
		cout << "Ingrese Nota a añadir" <<endl;
		cin >> notaa;
		e -> ingresarNota(notaa);
	}
	else if (nombres == b -> getNombre())
	{
		cout << "Ingrese Nota a añadir" <<endl;
		cin >> notaa;
		b -> ingresarNota(notaa);
	}
	cout << endl;
	e -> ingresarMuchasNotas(listadenotas);
	e -> lista();
	cout << endl;
	b -> ingresarMuchasNotas(listadenotas);
	b -> lista();
}
