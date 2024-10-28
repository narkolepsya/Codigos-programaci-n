/*"
Se ha creado un programa para contar los días de lluvia de las comunas de santiago y los mm que han caido

Cree un map < string, vector <int> > lluvia;
en el que la llave sea la comuna y el contenido un vector que guarde los milimetros por día en q llovió.

cree una funcion que permita ingresar los mm que cayeron de agua en cierta comuna y día. después imprima los días en los q llovió y la cantidad acumulada de mm

(aqui habia otra funcion q era cmo para sacar el promedio d los dias d lluvia con respecto a todas las comunas q existan, algo asi...pero no m acuerdo)

cree una funcion q retorne la cantidad de comunas en las q hubo sequia. si en una comuna los mm por día superan los 3 no se considera como comuna para la sequia
"
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Precipitaciones
{
    private:
        // map <llave, contenido> nombredelmapa;
        map <string, vector <int> > lluvias;
    public:
        void agregarDiasDeLluvia(string comuna, int mm)
        {
            int totalmm = 0, tam = 0;
            lluvias[comuna].push_back(mm);
            map <string, vector <int> > :: iterator it;
            for (it = lluvias.begin(); it != lluvias.end(); it++)
            {
                if (it -> first == comuna)
                {
                    for (int i = 0; i < it -> second.size(); i++)
                    {
                        totalmm = totalmm + it -> second[i];
                    }
                }
                tam = it -> second.size();
            }
            cout << "Llovio en total " << tam << " dias, con un total de " << totalmm << " mm de lluvia" <<endl;
            
        }
        void revisarcuantolloviopordia(string comuna)
        {
            map <string, vector <int> > :: iterator it;
            for (it = lluvias.begin(); it != lluvias.end(); it++)
            {
                if (it -> first == comuna)
                {
                    for (int i = 0; i < it -> second.size(); i++)
                    {
                        cout << "en el día " << i+1 << " llovió un total de " << it -> second[i] << endl;
                    }
                }
            }
        }
        void sacarpromedio(string comuna)
        {
            float totalmm = 0, tam = 0;
            map <string, vector <int> > :: iterator it;
            for (it = lluvias.begin(); it != lluvias.end(); it++)
            {
                if (it -> first == comuna)
                {
                    for (int i = 0; i < it -> second.size(); i++)
                    {
                        totalmm = totalmm + it -> second[i];
                    }
                }
                tam = lluvias.size();
            }
            cout << "El promedio total de agua q cayó en " << comuna << "fue de " << (totalmm / tam) << endl;
        }
        int cantidadcomunasequia()
        {
            int cantidad = 0;
            map <string, vector <int> > :: iterator it;
            for (it = lluvias.begin(); it != lluvias.end(); it++)
            {
                bool sequia = true;
                for (int i = 0; i < it -> second.size(); i++)
                {
                    if (it -> second[i] > 3)
                    {
                        sequia = false;
                        break;
                    }
                }
                if (sequia == true)
                {
                    cantidad++;
                }
            }
            return cantidad;
        }
};
int main()
{
    Precipitaciones * p = new Precipitaciones();
    p -> agregarDiasDeLluvia("Puente asalto", 2);
    p -> agregarDiasDeLluvia("Puente asalto", 2);
    p -> agregarDiasDeLluvia("Puente asalto", 2);
    p -> agregarDiasDeLluvia("Huechuraba", 2);
    p -> agregarDiasDeLluvia("Huechuraba", 2);
    p -> agregarDiasDeLluvia("Huechuraba", 2);
    p -> agregarDiasDeLluvia("Huechuraba", 2);
    p -> agregarDiasDeLluvia("Huechuraba", 2);
    p -> revisarcuantolloviopordia("Huechuraba");
    p ->sacarpromedio("Huechuraba");
    cout << "la cantidad de comunas con sequia son " << p -> cantidadcomunasequia();
}
