#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "imagen.h"
#include "fecha.h"
#include "vDinamico.h"

using namespace std;
/** Funcion para la realización del segundo ejercicio de la práctica.
 *  Se ordena el vector de mayor a menor y se muestran las Ids de los 50 primero elementos del vector dinámico. */
void ejercicio2(vDinamico<imagen> &contenedor)
{
    contenedor.ordenarRev();
    int contador=0;
    ///Recorremos el contenedor de imágenes para poder mostrar las 50 primeras.
    for(int i = 0; i < 50; i++){

        std::cout << ++contador
                  << " Imagen: ("
                  << " Id=" << contenedor[i].getId()
                  << ")" << std::endl;

    }
}
/** Funcion para la realización del Tercer ejercicio de la práctica.
 *  Se ordena el vector de menor a mayor y se muestran las Ids de los 50 primero elementos del vector dinámico. */
void ejercicio3(vDinamico<imagen> &contenedor)
{
    contenedor.ordenar();
    int contador = 0;
    ///Recorremos el contenedor de imágenes para poder mostrar las 50 primeras.
    for(int i = 0; i < 50; i++){

        std::cout << ++contador
                  << " Imagen: ("
                  << " Id=" << contenedor[i].getId()
                  << ")" << std::endl;

    }
}
/** Función auxiliar para el ejercicio 4 de la práctica.
 *  Se le pasa la posición del id que se busca en el vector y se muestra por pantalla si se encuentra y la posición que se encuentra.
 *  Y si no se encuentra muestra por pantalla que el id que se busca no está. */
void encontrada_Imagen (int pos, string id_Buscado)
{
    if (pos != -1)
    {
        cout << "La imagen con el Id: " << id_Buscado << " se encuentra en la posicion: " << pos << "." << endl;
    } else
    {
        cout << "La imagen con el Id: " << id_Buscado << " no se encuentra en el contenedor." << endl;
    }
}
/** Funcion para la realización del cuarto ejercicio de la práctica.
 *  Se buscan diferentes Ids en el vector dinámico y se muestra por pantalla si se encuentra o no en el vector. */
void ejercicio4(vDinamico<imagen> &contenedor)
{
    string id_buscar = "346335905";
    imagen img_buscar = imagen();
    img_buscar.setId(id_buscar);
    encontrada_Imagen(contenedor.busquedaBin(img_buscar), id_buscar);
    id_buscar = "999930245";
    img_buscar.setId(id_buscar);
    encontrada_Imagen(contenedor.busquedaBin(img_buscar), id_buscar);
    id_buscar = "165837";
    img_buscar.setId(id_buscar);
    encontrada_Imagen(contenedor.busquedaBin(img_buscar), id_buscar);
    id_buscar = "486415569";
    img_buscar.setId(id_buscar);
    encontrada_Imagen(contenedor.busquedaBin(img_buscar), id_buscar);
    id_buscar = "61385551";
    img_buscar.setId(id_buscar);
    encontrada_Imagen(contenedor.busquedaBin(img_buscar), id_buscar);
}
/** Funcion para la realización del quinto ejercicio de la práctica.
 *  En este ejercicio se crea un nuevo vector dinámico en el que se guardarán las imágenes con email: magdalen_upton99@gmail.com
 *  Y se borraran esas imágenes del primer vector dinámico. */
void ejercicio5(vDinamico<imagen> &contenedor)
{
    vDinamico<imagen> cont_Email = vDinamico<imagen>();
    int i = 0;
    while (i < contenedor.tamlog())
    {
        if (contenedor[i].getEmail() == "magdalen_upton99@gmail.com")
        {
            imagen img;
            img = contenedor.borrar(i);
            cont_Email.insertar(img);
        }
        i++;
    }

    cout << "El tamaño logico del primer vector dinamico es: " << contenedor.tamlog() << endl
         << "Y el tamaño logico del segundo vector dinamico es: " << cont_Email.tamlog() << endl;
    int contador = 0;
    for (int j = 0; j < 10; j++) {
        std::cout << ++contador
                  << " Imagen: ( ID=" << cont_Email[j].getId()
                  << " Email=" << cont_Email[j].getEmail() << " Fichero=" << cont_Email[j].getNombre()
                  << " Tam=" << cont_Email[j].getTam()
                  << " Fecha=" << cont_Email[j].getFecha().verDia() << "/" << cont_Email[j].getFecha().verMes() << "/" << cont_Email[j].getFecha().verAnio()
                  << " Etiquetas=" << cont_Email[j].getEtiquetas()
                  << ")" << std::endl;
    }
}

/** @author Rafael Aznar Estrada rae00010@red.ujaen.es
 *  @author Manuel Sánchez Salazar mss00048@red.ujaen.es
 **/
int main() {
    /// Variables que se usarán para la lectura del fichero.
    std::ifstream is;
    std::stringstream  columnas;
    std::string fila;
    int contador=0;
    std::string id = "", email="", nombre="", etiquetas="";
    int tam = 0, dia = 0, mes = 0, anno = 0;
    clock_t t_ini_total = clock();
    ///Realización del primer ejercicio.
    cout << "Primer ejercicio:" << endl;
    vDinamico<imagen> contenedor;
    int cont = 0;
    /// Lectura del fichero y añadir al contenedor de imagenes.
    is.open("../imagenes_v1.csv");
    if( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {
            if (fila!="") {

                columnas.str(fila);

                ///formato de fila: id;email;nombre;tam;fecha;etiquetas

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas,email,';');
                getline(columnas,nombre,';');

                columnas >> tam;   //las secuencia numéricas se leen y trasforman directamente
                columnas.ignore(); //omitimos carácter ';' siguiente

                columnas >> dia; columnas.ignore();
                columnas >> mes; columnas.ignore();
                columnas >> anno; columnas.ignore();

                getline(columnas,etiquetas,';');

                imagen img = imagen(id,email,nombre,tam, Fecha(dia,mes,anno),etiquetas);
                contenedor.insertar(img);
                cont++;
                fila="";
                columnas.clear();
            }
        }
        is.close();

        std::cout << "Tiempo de ejecucion del primer ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    ///Realizacion ejercicio 2.
    cout << "Segundo ejercicio: " << endl;
    clock_t t_ini = clock();
    ejercicio2(contenedor);
    std::cout << "Tiempo de ejecucion del segundo ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    ///--------------------------------
    ///Realizacion ejercicio 3.
    cout << "Tercer ejercicio: " << endl;

    t_ini = clock();

    ejercicio3(contenedor);

    std::cout << "Tiempo de ejecucion del tercer ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    ///--------------------------------
    ///Realizacion ejercicio 4.
    cout << "Cuarto ejercicio: " << endl;

    t_ini = clock();

    ejercicio4(contenedor);

    std::cout << "Tiempo de ejecucion del cuarto ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    ///--------------------------------
    ///Realizacion ejercicio 5.
    cout << "Quinto ejercicio: " << endl;

    t_ini = clock();

    ejercicio5(contenedor);

    std::cout << "Tiempo de ejecucion del quinto ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    ///--------------------------------

    std::cout << "El tiempo total para la realizacion de la practica es: " << ((clock() - t_ini_total) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
}