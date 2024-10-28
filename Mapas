#include <iostream>
#include <map>
using namespace std;
int main()
{
    /* map <llave, contenido> nombremapa;*/
    map <string, string> lista;
    map<string, string> lista2 = {
        {"123456789", "Reaper"},
        {"112345678", "Mercy"},
        {"134567890", "DVA"},
        {"145678901", "Kiriko"}
    };
    while (true)
    {
        int opcion;
        cout << "1. Agregar persona con su rut" <<endl;
        cout << "2. Eliminar persona " <<endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Ver que tan grande es la lista 1" <<endl;
        cout << "5. Ver si existe persona en la lista 1 por su rut y imprimirla" <<endl;
        cout << "6. Ver si existe la persona en la lista 1 por su rut " << endl;
        cout << "7. Intercambiar contenido de dos mapas (dos listas) " << endl; 
        cout << "8. Borrar todos los elementos de la lista 1  " << endl;
        cout << "9. Imprimir solo nombre a partir del rut " << endl;
        cin >> opcion;
        if (opcion == 1)
        {
            string rut, nombre;
            cout << "Ingrese rut de la persona " <<endl;
            cin >> rut;
            cout << "Ingese nombre de la persona " <<endl;
            cin >> nombre;
            lista[rut] = nombre;
            cout << "Se añadio a " << nombre << " a la lista " <<endl;
        }
        else if (opcion == 2)
        {
            string rut;
            cout << "Ingrese rut para eliminar a la persona de la lista " <<endl;
            cin >> rut;
            lista.erase(rut);
            cout << "Se ha borrado a la persona de la lista" <<endl;
        }
        else if (opcion == 3)
        {
            if (lista.empty()) // pregunta si es true, o sea q la lista esta vacia
            {
                cout << "Lista está vacia" <<endl;
            }
            else if (lista.empty() == false) // pregunta si es falso, o sea q la lista esta llena
            {
                map <string, string> :: iterator it;
                for (it = lista.begin(); it != lista.end(); it++)
                {
                   cout << "Rut: " << it -> first << ". Nombre: " << it -> second <<endl;
                }
            }
        }
        else if (opcion == 4)
        {
            cout << "La lista tiene un tamaño de " << lista.size() <<endl;
        }
        else if (opcion == 5)
        {
            string rut;
            cout << "Ingrese rut de la persona a buscar" <<endl;
            cin >> rut;
            /*auto it = lista.find(rut); "auto permite deducir el tipo de una variable."*/
            map <string, string> :: iterator it;
            it = lista.find(rut);
            if (it != lista.end())
            {
                cout << "Rut: " << it -> first << ". Nombre: " << it -> second <<endl; // first = llave, second = contenido
            }
            else
            {
                cout << "la persona no se encuentra en la lista" <<endl;
            }
        }
        else if (opcion == 6)
        {
            string rut;
            cout << "Ingrese rut de la persona a buscar" <<endl;
            cin >> rut;
            if (lista.count(rut)) // if lista.count(rut) da true: otra forma de hacerlo "if (lista.count(rut) != false)"
            {
                cout << "La persona existe en el mapa " <<endl;
            }
            else if (lista.count(rut) == false)
            {
                cout << "La persona NO existe en el mapa " <<endl;
            }
        }
        else if (opcion == 7)
        {
            cout << "Se van a intercambiar la lista 1 con la lista 2 " <<endl;
            lista.swap(lista2); // map.swap(map)
            cout << "Lista de datos: " <<endl;
            if (lista.empty() && lista2.empty()) // pregunta si es true, o sea q la lista esta vacia
            {
                cout << "Lista está vacia" <<endl;
            }
            else if (lista.empty() == false && lista2.empty() == false ) // pregunta si es falso, o sea q la lista esta llena
            {
                map <string, string> :: iterator it;
                cout << "LISTA 1: " <<endl;
                for (it = lista.begin(); it != lista.end(); it++)
                {
                   cout << "Rut: " << it -> first << ". Nombre: " << it -> second <<endl;
                }
                cout << "LISTA 2: " <<endl;
                for (it = lista2.begin(); it != lista2.end(); it++)
                {
                   cout << "Rut: " << it -> first << ". Nombre: " << it -> second <<endl;
                }
            }
        }
        else if (opcion == 8)
        {
            lista.clear();
            cout << "Se han borrado todos los elementos de la lista " <<endl;
        }
        else if (opcion == 9)
        {
            string rut;
            cout << "Ingrese rut de la persona a buscar" <<endl;
            cin >> rut;
            cout << "El nombre de la persona es" << lista.at(rut) << endl;
        }
    }
}
