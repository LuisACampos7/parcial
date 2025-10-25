#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// ==============================
// ESTRUCTURA DE LIBRO
// ==============================
struct Libro {
    string titulo;
    string autor;
    int anioPublicacion;
    int numPaginas;
};

// ==============================
// ESTRUCTURA DE BIBLIOTECA
// ==============================
struct Biblioteca {
    string nombre;
    string ubicacion;
    string telefono;
    int numEmpleados;
    string horario;
    vector<Libro> coleccion; // Vector dinámico para libros
};

// ==============================
// FUNCIONES AUXILIARES
// ==============================

// Función para ingresar una biblioteca y sus libros
Biblioteca ingresarBiblioteca() {
    Biblioteca biblio;
    int cantidadLibros;

    cout << "\n=== INGRESAR NUEVA BIBLIOTECA ===\n";
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, biblio.nombre);
    cout << "Ubicacion: ";
    getline(cin, biblio.ubicacion);
    cout << "Telefono: ";
    getline(cin, biblio.telefono);
    cout << "Numero de empleados: ";
    cin >> biblio.numEmpleados;
    cin.ignore();
    cout << "Horario de apertura: ";
    getline(cin, biblio.horario);

    cout << "\n¿Cuantos libros desea agregar a esta biblioteca? ";
    cin >> cantidadLibros;
    cin.ignore();

    for (int i = 0; i < cantidadLibros; i++) {
        Libro libro;
        cout << "\n--- Libro " << i + 1 << " ---\n";
        cout << "Titulo: ";
        getline(cin, libro.titulo);
        cout << "Autor: ";
        getline(cin, libro.autor);
        cout << "Año de publicacion: ";
        cin >> libro.anioPublicacion;
        cout << "Numero de paginas: ";
        cin >> libro.numPaginas;
        cin.ignore();
        biblio.coleccion.push_back(libro);
    }

    return biblio;
}

// Mostrar todas las bibliotecas (se hace una copia de la pila)
void mostrarBibliotecas(stack<Biblioteca> biblios) {
    cout << "\n=== LISTA DE BIBLIOTECAS (de la última a la primera) ===\n";
    if (biblios.empty()) {
        cout << "No hay bibliotecas registradas.\n";
        return;
    }

    int indice = 1;
    while (!biblios.empty()) {
        Biblioteca b = biblios.top();
        biblios.pop();

        cout << "\nBiblioteca #" << indice++ << endl;
        cout << "Nombre: " << b.nombre << endl;
        cout << "Ubicacion: " << b.ubicacion << endl;
        cout << "Telefono: " << b.telefono << endl;
        cout << "Empleados: " << b.numEmpleados << endl;
        cout << "Horario: " << b.horario << endl;

        cout << "\nColeccion de libros:\n";
        for (const Libro &lib : b.coleccion) {
            cout << " - " << lib.titulo << " (" << lib.autor << ", "
                 << lib.anioPublicacion << ", " << lib.numPaginas << " pag.)\n";
        }
    }
}

// Buscar una biblioteca por nombre
void buscarBiblioteca(stack<Biblioteca> biblios, string nombreBuscado) {
    bool encontrado = false;

    while (!biblios.empty()) {
        Biblioteca b = biblios.top();
        biblios.pop();

        if (b.nombre == nombreBuscado) {
            encontrado = true;
            cout << "\n=== BIBLIOTECA ENCONTRADA ===\n";
            cout << "Nombre: " << b.nombre << endl;
            cout << "Ubicacion: " << b.ubicacion << endl;
            cout << "Telefono: " << b.telefono << endl;
            cout << "Empleados: " << b.numEmpleados << endl;
            cout << "Horario: " << b.horario << endl;

            cout << "\nLibros:\n";
            for (const Libro &lib : b.coleccion) {
                cout << " - " << lib.titulo << " (" << lib.autor << ")\n";
            }
            break;
        }
    }

    if (!encontrado)
        cout << "\nNo se encontró una biblioteca con ese nombre.\n";
}

// Ordenar las bibliotecas (pila → vector → orden → pila)
stack<Biblioteca> ordenarBibliotecas(stack<Biblioteca> biblios) {
    vector<Biblioteca> temp;

    // Pasar la pila al vector
    while (!biblios.empty()) {
        temp.push_back(biblios.top());
        biblios.pop();
    }

    // Ordenar alfabéticamente
    sort(temp.begin(), temp.end(), [](Biblioteca a, Biblioteca b) {
        return a.nombre < b.nombre;
    });

    // Volver a llenar la pila en el orden correcto
    stack<Biblioteca> ordenada;
    for (auto &b : temp) {
        ordenada.push(b);
    }

    cout << "\nBibliotecas ordenadas por nombre correctamente.\n";
    return ordenada;
}

// ==============================
// NUEVAS FUNCIONES
// ==============================

// Vaciar toda la pila
void vaciarPila(stack<Biblioteca> &biblios) {
    if (biblios.empty()) {
        cout << "\nLa pila ya está vacía.\n";
        return;
    }

    while (!biblios.empty()) {
        biblios.pop();
    }

    cout << "\nTodas las bibliotecas han sido eliminadas de la pila.\n";
}

// Mostrar cantidad de elementos en la pila
void mostrarCantidad(stack<Biblioteca> biblios) {
    cout << "\nActualmente hay " << biblios.size() << " biblioteca(s) en la pila.\n";
}

// Eliminar la biblioteca superior (la última agregada)
void eliminarUltima(stack<Biblioteca> &biblios) {
    if (biblios.empty()) {
        cout << "\nNo hay bibliotecas para eliminar.\n";
        return;
    }

    cout << "\nEliminando la biblioteca: " << biblios.top().nombre << endl;
    biblios.pop();
    cout << "La última biblioteca fue eliminada correctamente.\n";
}

// ==============================
// FUNCIÓN PRINCIPAL
// ==============================
int main() {
    stack<Biblioteca> bibliotecas;
    int opcion;

    do {
        cout << "\n===== MENU DE BIBLIOTECAS (STACK) =====\n";
        cout << "1. Agregar biblioteca\n";
        cout << "2. Mostrar bibliotecas\n";
        cout << "3. Buscar biblioteca por nombre\n";
        cout << "4. Ordenar bibliotecas por nombre\n";
        cout << "5. Mostrar cantidad de bibliotecas\n";
        cout << "6. Eliminar la última biblioteca\n";
        cout << "7. Vaciar toda la pila\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            Biblioteca nueva = ingresarBiblioteca();
            bibliotecas.push(nueva);
            cout << "\nBiblioteca agregada correctamente.\n";
            break;
        }
        case 2:
            mostrarBibliotecas(bibliotecas);
            break;
        case 3: {
            string nombre;
            cout << "Ingrese el nombre de la biblioteca a buscar: ";
            cin.ignore();
            getline(cin, nombre);
            buscarBiblioteca(bibliotecas, nombre);
            break;
        }
        case 4:
            bibliotecas = ordenarBibliotecas(bibliotecas);
            break;
        case 5:
            mostrarCantidad(bibliotecas);
            break;
        case 6:
            eliminarUltima(bibliotecas);
            break;
        case 7:
            vaciarPila(bibliotecas);
            break;
        case 8:
            cout << "\nSaliendo del programa...\n";
            break;
        default:
            cout << "\nOpcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 8);

    return 0;
}
