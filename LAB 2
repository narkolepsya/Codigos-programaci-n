#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Payaso
{
    private:
        string nombreart;
        string nombrereal;
        int edad;
    public:
        Payaso(string nombreart, string nombrereal, int edad)
        {
            this -> nombreart = nombreart;
            this -> nombrereal = nombrereal;
            this -> edad = edad;
        }
        string getNombreArt()
        {
            return nombreart;
        }
        string getNombreReal()
        {
            return nombrereal;
        }
        int getEdad()
        {
            return edad;
        }
};
class Estacionamiento
{
    private:
    // llave = id auto, contenido = autos de payasos
        map <string, vector<Payaso*> > AutosSec;
    public:
        void AgregarPayaso(string idAuto, string nombreart, string nombrereal, int edad)
        {
            if (AutosSec.count(idAuto)) // si da true significa q existe
            {
                map <string, vector<Payaso*> > :: iterator it;
                for (it = AutosSec.begin(); it != AutosSec.end(); it++)
                {
                    if (it -> first == idAuto)
                    {
                        Payaso * p = new Payaso(nombreart, nombrereal, edad);
                        AutosSec[idAuto].push_back(p);
                    }
                }
            }
            else if (AutosSec.count(idAuto) == false) // no existe
            {
                AutosSec[idAuto] = vector <Payaso*>();
                map <string, vector<Payaso*> > :: iterator it;
                for (it = AutosSec.begin(); it != AutosSec.end(); it++)
                {
                    if (it -> first == idAuto)
                    {
                        Payaso * p = new Payaso(nombreart, nombrereal, edad);
                        AutosSec[idAuto].push_back(p);
                    }
                }
            }
        }
        void EliminarPayaso(string idAuto, string nombreart)
        {
            if (AutosSec.count(idAuto)) // si da true significa q existe
            {
                map <string, vector<Payaso*> > :: iterator it;
                for (it = AutosSec.begin(); it != AutosSec.end(); it++)
                {
                    if (it -> first == idAuto)
                    {
                        for (int i = 0; i < it -> second.size(); i++)
                        {
                            if (it -> second[i] -> getNombreArt() == nombreart)
                            {
                                it -> second.erase(it -> second.begin() +i);
                            }
                        }
                    }
                }
            }
        }
        Payaso* BuscarPayaso(string idAuto, string nombreart)
        {
            if (AutosSec.count(idAuto)) // si da true significa q existe
            {
                map <string, vector<Payaso*> > :: iterator it;
                for (it = AutosSec.begin(); it != AutosSec.end(); it++)
                {
                    if (it -> first == idAuto)
                    {
                        for (int i = 0; i < it -> second.size(); i++)
                        {
                            if (it -> second[i] -> getNombreArt() == nombreart)
                            {
                                cout << "Nombre artistico: " << it -> second[i] -> getNombreArt() << endl;
                                cout << "Nombre real: " << it -> second[i] -> getNombreReal() <<endl;
                                cout << "Edad: " << it -> second[i] -> getEdad() <<endl;
                                return it -> second[i];
                            }
                        }
                    }
                }
            }
        }
        void imprimirAutos()
        {
            map <string, vector<Payaso*> > :: iterator it;
            for (it = AutosSec.begin(); it != AutosSec.end(); it++)
            {
                if (it -> second.empty())
                {
                    cout << "Están vacios todos los autos " <<endl;
                }
                else
                {
                    cout << "Auto: " << it -> first << endl;
                for (int i = 0; i < it -> second.size(); i++)
                {
                    cout << "Nombre artistico: " << it -> second[i] -> getNombreArt() << endl;
                    cout << "Nombre real: " << it -> second[i] -> getNombreReal() <<endl;
                    cout << "Edad: " << it -> second[i] -> getEdad() <<endl;
                    cout << endl;
                    cout << "---------------------------------------------------" <<endl;
                }
                }
            }
        }
};
int main()
{
    Estacionamiento * e = new Estacionamiento();
    e -> AgregarPayaso("Auto 1", "b", "a", 18);
    e -> imprimirAutos();
    e -> EliminarPayaso("Auto 1", "b");
    cout << "A" << e-> BuscarPayaso("Auto 1", "b") << endl;
    e -> imprimirAutos();
}
