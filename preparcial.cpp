#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// -----------------------------
// ESTRUCTURAS DE DATOS
// -----------------------------
struct Libro {
    string titulo;
    string autor;
    int anioPublicacion;
    int numPaginas;
};

struct Biblioteca {
    string nombre;
    string ubicacion;
    string telefono;
    int numEmpleados;
    string horario;
    vector<Libro> libros; // colección dinámica de libros
};

// -----------------------------
// FUNCIONES
// -----------------------------

// 1. Función para ingresar información de una biblioteca y sus libros
Biblioteca ingresarBiblioteca() {
    Biblioteca b;
    cout << "\n--- Ingresar nueva biblioteca ---\n";
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, b.nombre);
    cout << "Ubicacion: ";
    getline(cin, b.ubicacion);
    cout << "Telefono: ";
    getline(cin, b.telefono);
    cout << "Numero de empleados: ";
    cin >> b.numEmpleados;
    cin.ignore();
    cout << "Horario de apertura: ";
    getline(cin, b.horario);

    int cantidadLibros;
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
        b.libros.push_back(libro);
    }

    cout << "\nBiblioteca agregada exitosamente.\n";
    return b;
}

// 2. Función para imprimir la información de todas las bibliotecas
void imprimirBibliotecas(const list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\nNo hay bibliotecas registradas.\n";
        return;
    }

    cout << "\n=== LISTA DE BIBLIOTECAS ===\n";
    for (const auto &b : bibliotecas) {
        cout << "\nNombre: " << b.nombre
             << "\nUbicacion: " << b.ubicacion
             << "\nTelefono: " << b.telefono
             << "\nNumero de empleados: " << b.numEmpleados
             << "\nHorario: " << b.horario
             << "\nLibros:\n";

        if (b.libros.empty()) {
            cout << "  (Sin libros registrados)\n";
        } else {
            for (const auto &l : b.libros) {
                cout << "  - Titulo: " << l.titulo
                     << " | Autor: " << l.autor
                     << " | Año: " << l.anioPublicacion
                     << " | Paginas: " << l.numPaginas << "\n";
            }
        }
    }
}

// 3. Ordenar bibliotecas según criterio (nombre o empleados)
void ordenarBibliotecas(list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\nNo hay bibliotecas para ordenar.\n";
        return;
    }

    int opcion;
    cout << "\nOrdenar bibliotecas por:\n";
    cout << "1. Nombre\n";
    cout << "2. Numero de empleados\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    vector<Biblioteca> temp(bibliotecas.begin(), bibliotecas.end());

    if (opcion == 1) {
        sort(temp.begin(), temp.end(), [](const Biblioteca &a, const Biblioteca &b) {
            return a.nombre < b.nombre;
        });
    } else if (opcion == 2) {
        sort(temp.begin(), temp.end(), [](const Biblioteca &a, const Biblioteca &b) {
            return a.numEmpleados < b.numEmpleados;
        });
    } else {
        cout << "Opcion no valida.\n";
        return;
    }

    bibliotecas.assign(temp.begin(), temp.end());
    cout << "\nBibliotecas ordenadas correctamente.\n";
}

// 4. Buscar biblioteca por nombre
void buscarBiblioteca(const list<Biblioteca> &bibliotecas) {
    if (bibliotecas.empty()) {
        cout << "\nNo hay bibliotecas registradas.\n";
        return;
    }

    cin.ignore();
    string nombreBuscado;
    cout << "\nIngrese el nombre de la biblioteca a buscar: ";
    getline(cin, nombreBuscado);

    bool encontrada = false;
    for (const auto &b : bibliotecas) {
        if (b.nombre == nombreBuscado) {
            cout << "\n--- Biblioteca encontrada ---\n";
            cout << "Nombre: " << b.nombre
                 << "\nUbicacion: " << b.ubicacion
                 << "\nTelefono: " << b.telefono
                 << "\nNumero de empleados: " << b.numEmpleados
                 << "\nHorario: " << b.horario
                 << "\nLibros:\n";

            if (b.libros.empty()) {
                cout << "  (Sin libros registrados)\n";
            } else {
                for (const auto &l : b.libros) {
                    cout << "  - " << l.titulo << " (" << l.autor << ", "
                         << l.anioPublicacion << ", " << l.numPaginas << " págs)\n";
                }
            }

            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "\nNo se encontró una biblioteca con ese nombre.\n";
    }
}

// -----------------------------
// FUNCION PRINCIPAL
// -----------------------------
int main() {
    list<Biblioteca> bibliotecas;
    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Agregar biblioteca\n";
        cout << "2. Mostrar bibliotecas\n";
        cout << "3. Buscar biblioteca\n";
        cout << "4. Ordenar bibliotecas\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                bibliotecas.push_back(ingresarBiblioteca());
                break;
            case 2:
                imprimirBibliotecas(bibliotecas);
                break;
            case 3:
                buscarBiblioteca(bibliotecas);
                break;
            case 4:
                ordenarBibliotecas(bibliotecas);
                break;
            case 5:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpcion no valida.\n";
        }
    } while (opcion != 5);

    return 0;
}
