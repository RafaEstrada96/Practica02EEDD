//
// Created by erafa on 02/10/2022.
//

#ifndef IMAGENES_VDINAMICO_H
#define IMAGENES_VDINAMICO_H

#define UINT_MAX 4565654335
using namespace std;

template<class T>
class VDinamico {
    T *vector;
    int taml,tamf;
public:
    VDinamico<T>();
    VDinamico<T>(unsigned int tamlog);
    VDinamico<T>(const VDinamico<T>& origen);
    VDinamico<T>(const VDinamico<T>& origen, unsigned int posicionInicial, unsigned int numElementos);
    T& operator=(unsigned int pos);
    T& operator[](unsigned int pos);
    void insertar(const T& dato, unsigned int pos = UINT_MAX);
    T borrar(unsigned int pos = UINT_MAX);
    void ordenar();
    void ordenarRev();
    int busquedaBin(T& dato);
    unsigned int tamlog();

    virtual ~VDinamico<T>();
};


#endif //IMAGENES_VDINAMICO_H
