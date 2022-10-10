//
// Created by erafa on 02/10/2022.
//

#ifndef IMAGENES_VDINAMICO_H
#define IMAGENES_VDINAMICO_H
#include "imagen.h"
#include <climits>
#include <math.h>
#include "algorithm"
#include "iostream"
using namespace std;

template<class T>
class vDinamico {
    int taml,tamf;
    T *vector = new T[0];
public:
    /** Crea un vector dinámico de tamaño fisico 1 y tamaño lógico 0 */
    vDinamico(){
        tamf = 1;
        taml = 0;
        delete[] vector;
        vector = new T[tamf];
    };
    /** Crea un vector dínamico con un tamaño lógico en concreto. */
    vDinamico(unsigned int tamlog){
        taml = 0;
        int t = log2(tamlog) + 1;
        tamf = pow(2,t);
        vector = new T[tamf];
    };
    /** Constructor copia. */
    vDinamico(const vDinamico<T>& origen){
        tamf = origen.tamf;
        taml = origen.taml;
        vector = origen.vector;
    };
    /** Constructor copia parcial.
     * Se realiza una copia parcial de un vector dinámico,
     * dado una posición inicial y el número de elementos que se desean copiar*/
    vDinamico(const vDinamico<T>& origen, unsigned int posicionInicial, unsigned int numElementos){
        int j = 0, i = posicionInicial;
        taml = numElementos;
        delete[] vector;
        int ta = log2(numElementos) + 1;
        vector = new T[tamf = pow(2,ta)];

        while(i<(posicionInicial+numElementos) && j<numElementos*2)
        {
            vector[j] = origen.vector[i];
            j++;
            i++;
        }
    };
    /** Operador = de vectores dinámicos. */
    vDinamico<T>& operator=(vDinamico<T>& vec){
        if (&vec != this)
        {
            delete[] vector;
            tamf = vec.tamf;
            taml = vec.taml;
            vector = new T[tamf];

            for(int i = 0; i < taml; i++)
            {
                vector[i] = vec.vector[i];
            }
        }
        return *this;
    };
    /** Operador [] del vector dinámico. */
    T &operator[](int pos) {
        return vector[pos];
    };
    /** Función para aumentar el tamaño fisico del vector dinámico.
     * Cuando el tamaño lógico sea igual al tamaño físico se se aumentará el tamaño fisico.
     * El metodo usado para aumentar el tamaño es la siguiente potencia de 2 inmediatamente superior al tamaño lógico*/
    void aumenta(){
        if (taml == tamf)
        {
            T *v_aux;
            int log = log2(taml);
            log = log + 1;
            v_aux = new T[tamf = pow(2,log)];
            for (int i = 0; i < taml; i++) {
                v_aux[i] = vector[i];
            }
            delete[] vector;
            vector = v_aux;
        }
    }
    /** Función para disminuir el tamaño físico del vector dinámico.
     * Cuando el tamaño logico multiplicado por 3 es menor que el tamaño físico se realizara la reducción del tamaño físico. */
    void disminuye(){
        if (taml*3 < tamf)
        {
            int log = log2(taml);
            log = log + 1;
            tamf = pow(2,log);
            T *v_aux = new T[tamf];
            for (int i = 0; i < taml; i++) {
                v_aux[i] = vector[i];
            }
            delete[] vector;
            vector = v_aux;
        }
    }
    /** Función para insertar un dato en el vector dinámico.
     * La inserccion se realizará en una posición en concreto si se le pasa la posición,
     * si no se le pasa la posición la insercción se realizará al final del vector.
     * Cada vez que se inserta un dato el tamaño lógico aumenta en 1. */
    void insertar(const T& dato, unsigned int pos = UINT_MAX){

        aumenta();

        if(pos == UINT_MAX)
        {
            vector[taml] = dato;
        } else
        {
            for (int i = taml-1; i >= pos; i++)
            {
                vector[i+1] = vector[i];
            }
            vector[pos] = dato;

        }
        taml++;

    }
    /** Función para borrar un dato del vector dinámico.
     * Se devuelve el dato borrado del vector.
     * Si no se pasa una posición en concreto se eliminará el último dato del vector.
     * Cada vez que se elimina un dato del vector se disminuirá el tamaño lógico en 1. */
    T borrar (unsigned int pos = UINT_MAX){
        T borrado;
        if (pos == UINT_MAX)
        {
            borrado = vector[taml];
            vector[taml] = T();
        }else
        {
            borrado = vector[pos];
            for (int i = pos; i < taml; i++)
            {
                vector[i]=vector[i+1];
            }
        }
        disminuye();
        taml--;
        return borrado;
    }
    /** Ordena el vector dinámico de menor a mayor. */
    void ordenar(){
        sort(vector, vector+taml);
    }
    /** Ordena el vector dinámico de mayor a menor. */
    void ordenarRev(){
        sort(vector, vector+taml, std::greater<T>());
    }
    /** Función de una busqueda de un dato en el vector dinámico.
     * Devuelve la posición si se encuentra.
     * Si no se encuentra devuelve -1. */
    int busquedaBin(T& dato){
        int infimo = 0;
        int supremo = taml - 1;
        int pos;

        while (infimo <= supremo) {
            pos = (infimo + supremo) / 2;
            if (vector[pos] == dato)
            {
                return pos;
            }else if (stoi(vector[pos].getId()) < stoi(dato.getId()))
            {
                infimo = pos + 1;
            } else
            {
                supremo = pos - 1;
            }

        }
        return -1;
    }
    /** Devuelve el tamaño lógico del vector dinámico, es decir, la cantidad de datos que hay en el vector. */
    int tamlog(){
        return taml;
    }
    /** Destructor del vector dinámico. */
    virtual ~vDinamico(){
        delete[] vector;
        tamf = 0;
        taml = 0;
    }

};


#endif //IMAGENES_VDINAMICO_H
