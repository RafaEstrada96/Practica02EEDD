#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "imagen.h"
#include "fecha.h"

using namespace std;

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
    int cont = 0;   //Contador para movernos por el contenedor.
    /// Lectura del fichero y añadir al contenedor de imagenes.
    is.open("../imagenes_v1.csv");
    if( is.good() ) {

        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {
            if (fila!="") {

                columnas.str(fila);

                imagen img = imagen();

                //formato de fila: id;email;nombre;tam;fecha;etiquetas

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                //img.setId(id);
                getline(columnas,email,';');
                //img.setEmail(email);
                getline(columnas,nombre,';');
                //img.setNombre(nombre);

                columnas >> tam;   //las secuencia numéricas se leen y trasforman directamente
                columnas.ignore(); //omitimos carácter ';' siguiente
                //img.setTam(tam);

                columnas >> dia; columnas.ignore();
                columnas >> mes; columnas.ignore();
                columnas >> anno; columnas.ignore();

                //img.setFecha(Fecha(dia, mes, anno));

                getline(columnas,etiquetas,';');
                //img.setEtiquetas(etiquetas);

                img = imagen(id,email,nombre,tam, Fecha(dia,mes,anno),etiquetas);

                cont++; //Se aumenta el contenedor de imágenes.

                fila="";
                columnas.clear();
            }
        }
        is.close();
        ///Recorremos el contenedor de imágenes para poder mostrar las 50 primeras.
        for(int i = 0; i < 50; i++){

            imagen image; //Recuperamos la imagen de la posición i.
            std::cout << ++contador
                      << " Imagen: ("
                      << " Nombre=" << image.getNombre()
                      << " Fecha=" << image.getFecha().verDia() << "/" << image.getFecha().verMes() << "/" << image.getFecha().verAnio()
                      << " Etiquetas=" << image.getEtiquetas()
                      << ")" << std::endl;

        }


        std::cout << "Tiempo de ejecucion del primer ejercicio es: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }

    ///Realizacion ejercicio 2.

    ///--------------------------------
    ///Realizacion ejercicio 3.

    ///--------------------------------
    ///Realizacion ejercicio 4.

    ///--------------------------------
    ///Realizacion ejercicio 5.

    ///--------------------------------

    std::cout << "El tiempo total para la realizacion de la practica es: " << ((clock() - t_ini_total) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
}