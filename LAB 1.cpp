#include <iostream>
using namespace std;
class Robot
{
    private:
        string nombre;
        int salud;
        int ataque;
    public:
        void setNombre(string n)
        {
            nombre = n;
        }
        void setAtaque(int a)
        {
            ataque = a;
        }
        void setSalud(int s)
        {
            salud = s;
        }
        string getNombre()
        {
            return nombre;
        }
        int getAtaque()
        {
            return ataque;
        }
        int getSalud()
        {
            return salud;
        }
};
void IngresoDatos (Robot * a)
{
    string n;
    int s, at;
    cout << "Ingresar nombre del Robot" << endl;
    cin >> n;
    a -> setNombre(n);
    cout << "El nombre del robot es: " << a -> getNombre() << endl;
    cout << "Ingresar Salud del Robot" << endl;
    cin >> s;
    a -> setSalud(s);
    cout << "La salud del robot es: " << a -> getSalud() << endl;
    cout << "Ingresar daño de ataque del Robot" << endl;
    cin >> at;
    a -> setAtaque(at);
    cout << "El daño de ataque del robot es: " << a -> getAtaque() << endl;
}
void AtaqueRobotA(Robot * a, Robot *b)
{
    int d;
    d = b -> getSalud() - a -> getAtaque();
    b -> setSalud(d);
}
void AtaqueRobotB(Robot * a, Robot *b)
{
    int d;
    d = a -> getSalud() - b -> getAtaque();
    a -> setSalud(d);
}
void Duelo (Robot * a, Robot * b)
{
    int turno = 1;
    while (a -> getSalud() > 0 || b -> getSalud() > 0 )
    {
        if (turno % 2 == 0)
        {
            AtaqueRobotA(a, b);
            cout << " Turno " << turno << ": " << a -> getNombre() << "Ha atacado a " << b -> getNombre() << "." << b -> getNombre() << "Ha perdido " << a -> getAtaque() << "de salud" << endl;
            if (b-> getSalud() < 1)
            {
                cout << "Felicidades, ha ganado " << a -> getNombre() <<endl;
                break;
            }
            turno++;
        }
        else
        {
            AtaqueRobotB(a, b);
            cout << " Turno " << turno << ": " << b -> getNombre() << "Ha atacado a " << a -> getNombre() << "." << a -> getNombre() << "Ha perdido " << b -> getAtaque() << "de salud" << endl;
            if (a-> getSalud() < 1)
            {
                cout << "Felicidades, ha ganado " << b -> getNombre() <<endl;
                break;
            }
            turno++;
        }
        
    }
}
int main()
{
    Robot * RobotA = new Robot;
    Robot * RobotB = new Robot;
    cout << "-------------------------------------------------" <<endl;
    IngresoDatos (RobotA);
    IngresoDatos (RobotB);
    Duelo (RobotA, RobotB);
}
