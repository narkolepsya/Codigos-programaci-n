#include <iostream>
using namespace std;
class Jugador
{
    private:
        string n_jugador;
        string posicion;
    public:
        Jugador (string n_jugador, string posicion)
        {
            this -> n_jugador = n_jugador;
            this -> posicion = posicion;
        }
        string getN()
        {
            return n_jugador;
        }
        string getP()
        {
            return posicion;
        }
};

class Equipo
{
    private:
        Jugador * j;
        string n_equipo;
        
    public:
        Equipo (Jugador * j, string n_equipo)
        {
            this -> j = j;
            this -> n_equipo = n_equipo;
        }
        void imprimir()
        {
            cout << n_equipo << endl;
            cout << "Nombre:" << j -> getN() <<endl;
        }
};
int main()
{
    Jugador * k = new Jugador("Keria", "ADC");
    Equipo * e = new Equipo(k, "T1");
    e -> imprimir();
}

/*

#include <iostream>
using namespace std;
class Jugador
{
    private:
        string n_jugador;
        string posicion;
    public:
        Jugador (string n_jugador, string posicion)
        {
            this -> n_jugador = n_jugador;
            this -> posicion = posicion;
        }
        string getN()
        {
            return n_jugador;
        }
        string getP()
        {
            return posicion;
        }
};

class Equipo
{
    private:
        Jugador * j;
        string n_equipo;
        
    public:
        Equipo (string n_equipo)
        {
            this -> n_equipo = n_equipo;
        }
        void setJugador(Jugador * k)
        {
            j = k;
        }
        void imprimir()
        {
            cout << n_equipo << endl;
            cout << "Nombre:" << j -> getN() <<endl;
            cout << "Posicion:" << j -> getP() <<endl;
        }
};
int main()
{
    Jugador * a = new Jugador("Keria", "ADC");
    Jugador * b = new Jugador("FAKER", "MID");
    Equipo * e = new Equipo("T1");
    e -> setJugador(a);
    e -> imprimir();
    cout << "///////////////" <<endl;
    e -> setJugador(b);
    e -> imprimir();
}

*/