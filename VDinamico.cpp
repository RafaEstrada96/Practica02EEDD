//
// Created by erafa on 02/10/2022.
//

#include "VDinamico.h"

template<class T>
VDinamico<T>::VDinamico() {

}

template<class T>
VDinamico<T>::VDinamico(unsigned int tamlog) {

}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {

}

template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned int posicionInicial, unsigned int numElementos) {

}

template<class T>
T &VDinamico<T>::operator=(unsigned int pos) {
}

template<class T>
T &VDinamico<T>::operator[](unsigned int pos) {
}

template<class T>
void VDinamico<T>::insertar(const T &dato, unsigned int pos) {

}

template<class T>
T VDinamico<T>::borrar(unsigned int pos) {
    return nullptr;
}

template<class T>
void VDinamico<T>::ordenar() {

}

template<class T>
void VDinamico<T>::ordenarRev() {

}

template<class T>
int VDinamico<T>::busquedaBin(T &dato) {
}

template<class T>
unsigned int VDinamico<T>::tamlog() {
    return taml;
}

template<class T>
VDinamico<T>::~VDinamico<T>() {

}
