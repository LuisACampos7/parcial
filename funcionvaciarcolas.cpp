#include <iostream>
#include <queue>
#include <string>
using namespace std;

void vaciarCola(queue<Biblioteca> &biblios) {
    if (biblios.empty()) {
        cout << "\nLa cola ya está vacía.\n";
        return;
    }

    while (!biblios.empty()) {
        biblios.pop(); // Elimina el primer elemento repetidamente
    }

    cout << "\nTodas las bibliotecas han sido eliminadas de la cola.\n";
}

void mostrarCantidad(queue<Biblioteca> biblios) {
    cout << "\nActualmente hay " << biblios.size() << " biblioteca(s) en la cola.\n";
}