#include <iostream>
#include "Cola.h"

using namespace std;

void eliminarOcurrencias(Cola<int> &cola, int numero) {
    Cola<int> colaAux;
    bool encontrado = false;
    bool numeroEncontrado = false;
    
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        if (dato == numero) {
            if (!encontrado) {
                colaAux.encolar(dato);
                encontrado = true;    
            }
            numeroEncontrado = true;
        } else {
            colaAux.encolar(dato);  
        }
    }

    if (!numeroEncontrado) {
        cout << "Error: El número " << numero << " no está presente en la cola." << endl;
    }
    
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {
    
    Cola<int> cola;
    int numero;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Lectura del número
    cout << "Ingrese el numero a eliminar: ";
    cin >> numero;

    // Eliminar las ocurrencias excepto la primera
    eliminarOcurrencias(cola, numero);

    // Mostrar la cola final
    cout << "Cola final: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }
    cout << endl;
}
