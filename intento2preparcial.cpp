#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace std;

// ==========================
// ESTRUCTURAS
// ==========================
struct Libro {
    string titulo;
    string autor;
    int año;
    int paginas;
};

struct Biblioteca {
    string nombre;
    int empleados;
    vector<Libro> libros;
};

// ==========================
// FUNCIONES
// ==========================

void solicitar(list<Biblioteca> &bibliotecas) {
    Biblioteca nueva;
    cout << "\nIngrese el nombre de la biblioteca: ";
    getline(cin >> ws, nueva.nombre);

    cout << "Ingrese la cantidad de empleados: ";
    cin >> nueva.empleados;

    char cont;
    do {
        Libro l;
        cout << "\n--- Agregar libro ---" << endl;
        cout << "Título: ";
        getline(cin >> ws, l.titulo);
        cout << "Autor: ";
        getline(cin, l.autor);
        cout << "Año de publicación: ";
        cin >> l.año;
        cout << "Número de páginas: ";
        cin >> l.paginas;

        nueva.libros.push_back(l);

        cout << "\n¿Desea agregar otro libro? (S/N): ";
        cin >> cont;

    } while (cont == 's' || cont == 'S');

    // Finalmente agregamos la biblioteca completa a la lista
    bibliotecas.push_back(nueva);
    cout << "\nBiblioteca agregada correctamente.\n";
}

void imprimir(const list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\nNo hay bibliotecas registradas.\n";
        return;
    }

    cout << "\n=== LISTA DE BIBLIOTECAS ===\n";
    for (const Biblioteca &b : bibliotecas) {
        cout << "\nNombre: " << b.nombre << endl;
        cout << "Empleados: " << b.empleados << endl;

        if (b.libros.empty()) {
            cout << "  (Sin libros registrados)\n";
        } else {
            cout << "  Libros:\n";
            for (const Libro &l : b.libros) {
                cout << "   - " << l.titulo << " (" << l.autor
                     << ", " << l.año << ", " << l.paginas << " págs)\n";
            }
        }
    }
}

// (opcional) función para ordenar por nombre
void ordenarBibliotecas(list<Biblioteca> &bibliotecas) {
    bibliotecas.sort([](const Biblioteca &a, const Biblioteca &b) {
        return a.nombre < b.nombre;
    });
    cout << "\nBibliotecas ordenadas alfabéticamente.\n";
}

// (opcional) función para buscar por nombre
void buscarBiblioteca(const list<Biblioteca> &bibliotecas, const string &nombre) {
    bool encontrada = false;
    for (const Biblioteca &b : bibliotecas) {
        if (b.nombre == nombre) {
            cout << "\nBiblioteca encontrada:\n";
            cout << "Nombre: " << b.nombre << endl;
            cout << "Empleados: " << b.empleados << endl;
            cout << "Libros registrados: " << b.libros.size() << endl;
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "\nNo se encontró una biblioteca con ese nombre.\n";
    }
}

// ==========================
// FUNCIÓN PRINCIPAL
// ==========================
int main() {
    list<Biblioteca> bibliotecas;
    int opcion;

    do {
        cout << "\n===== MENÚ =====\n";
        cout << "1. Añadir biblioteca\n";
        cout << "2. Mostrar bibliotecas\n";
        cout << "3. Ordenar por nombre\n";
        cout << "4. Buscar biblioteca\n";
        cout << "5. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        cin.ignore(); // limpiar salto de línea pendiente

        switch (opcion) {
        case 1:
            solicitar(bibliotecas);
            break;
        case 2:
            imprimir(bibliotecas);
            break;
        case 3:
            ordenarBibliotecas(bibliotecas);
            break;
        case 4: {
            string nombre;
            cout << "\nIngrese el nombre a buscar: ";
            getline(cin, nombre);
            buscarBiblioteca(bibliotecas, nombre);
            break;
        }
        case 5:
            cout << "\nSaliendo...\n";
            break;
        default:
            cout << "\nOpción inválida, intente de nuevo.\n";
            break;
        }

    } while (opcion != 5);

    return 0;
}
