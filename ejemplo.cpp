#include <iostream>      // Para entrada y salida estándar
#include <string>        // Para usar cadenas de texto (string)
#include <vector>        // Para usar arreglos dinámicos (vector)
#include <list>          // Para usar listas dinámicas (list)
#include <algorithm>     // Para ordenar elementos con sort()

using namespace std;

// ------------------------------------------------------------
// ESTRUCTURAS DE DATOS
// ------------------------------------------------------------

// Estructura para representar una carrera universitaria
struct Carrera {
    string nombre;
    string departamento;
    int duracion;      // en años
    int numEstudiantes;
};

// Estructura para representar una universidad
struct Universidad {
    string nombre;
    string ciudad;
    string rector;
    int numProfesores;
    string horario;

    // Cada universidad tiene un vector dinámico de carreras
    vector<Carrera> carreras;
};

// ------------------------------------------------------------
// FUNCIONES DEL PROGRAMA
// ------------------------------------------------------------

// 1️⃣ Función para ingresar una nueva universidad y sus carreras
Universidad ingresarUniversidad() {
    Universidad u;

    cout << "\n--- Registrar nueva universidad ---\n";
    cin.ignore(); // Limpia el salto de línea pendiente antes de getline()

    cout << "Nombre de la universidad: ";
    getline(cin, u.nombre);

    cout << "Ciudad: ";
    getline(cin, u.ciudad);

    cout << "Nombre del rector: ";
    getline(cin, u.rector);

    cout << "Numero de profesores: ";
    cin >> u.numProfesores;
    cin.ignore(); // Limpia el salto de línea antes de leer el horario

    cout << "Horario de atencion: ";
    getline(cin, u.horario);

    int cantidadCarreras;
    cout << "\n¿Cuantas carreras desea registrar en esta universidad? ";
    cin >> cantidadCarreras;
    cin.ignore(); // Importante antes de getline() dentro del bucle

    // Bucle para agregar cada carrera
    for (int i = 0; i < cantidadCarreras; i++) {
        Carrera c;
        cout << "\n--- Carrera " << i + 1 << " ---\n";

        cout << "Nombre de la carrera: ";
        getline(cin, c.nombre);

        cout << "Departamento al que pertenece: ";
        getline(cin, c.departamento);

        cout << "Duracion (en años): ";
        cin >> c.duracion;

        cout << "Numero de estudiantes: ";
        cin >> c.numEstudiantes;
        cin.ignore(); // Limpia el salto antes de volver a getline()

        // Agregamos la carrera al vector
        u.carreras.push_back(c);
    }

    cout << "\n✅ Universidad registrada correctamente.\n";
    return u;
}

// 2️⃣ Función para mostrar todas las universidades y sus carreras
void mostrarUniversidades(const list<Universidad> &universidades) {
    if (universidades.empty()) {
        cout << "\n⚠️ No hay universidades registradas.\n";
        return;
    }

    cout << "\n=== LISTA DE UNIVERSIDADES ===\n";
    for (const auto &u : universidades) {
        cout << "\n🏛️ Universidad: " << u.nombre
             << "\n📍 Ciudad: " << u.ciudad
             << "\n👨‍🏫 Rector: " << u.rector
             << "\n👩‍🎓 Profesores: " << u.numProfesores
             << "\n🕒 Horario: " << u.horario << "\n";

        // Mostramos las carreras
        if (u.carreras.empty()) {
            cout << "  (Sin carreras registradas)\n";
        } else {
            cout << "  Carreras:\n";
            for (const auto &c : u.carreras) {
                cout << "   - " << c.nombre
                     << " | Depto: " << c.departamento
                     << " | Duracion: " << c.duracion << " años"
                     << " | Estudiantes: " << c.numEstudiantes << "\n";
            }
        }
    }
}

// 3️⃣ Función para ordenar universidades según un criterio
void ordenarUniversidades(list<Universidad> &universidades) {
    if (universidades.empty()) {
        cout << "\n⚠️ No hay universidades para ordenar.\n";
        return;
    }

    int opcion;
    cout << "\nOrdenar universidades por:\n";
    cout << "1. Nombre\n";
    cout << "2. Numero de profesores\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    // Convertimos la lista en vector para usar sort()
    vector<Universidad> temp(universidades.begin(), universidades.end());

    if (opcion == 1) {
        sort(temp.begin(), temp.end(), [](const Universidad &a, const Universidad &b) {
            return a.nombre < b.nombre;
        });
    } else if (opcion == 2) {
        sort(temp.begin(), temp.end(), [](const Universidad &a, const Universidad &b) {
            return a.numProfesores < b.numProfesores;
        });
    } else {
        cout << "\nOpcion no valida.\n";
        return;
    }

    // Reasignamos el vector ordenado a la lista
    universidades.assign(temp.begin(), temp.end());
    cout << "\n✅ Universidades ordenadas correctamente.\n";
}

// 4️⃣ Función para buscar universidad por nombre
void buscarUniversidad(const list<Universidad> &universidades) {
    if (universidades.empty()) {
        cout << "\n⚠️ No hay universidades registradas.\n";
        return;
    }

    cin.ignore(); // Limpia antes de getline()
    string nombreBuscado;
    cout << "\nIngrese el nombre de la universidad a buscar: ";
    getline(cin, nombreBuscado);

    bool encontrada = false;
    for (const auto &u : universidades) {
        if (u.nombre == nombreBuscado) {
            cout << "\n--- Universidad encontrada ---\n";
            cout << "Nombre: " << u.nombre
                 << "\nCiudad: " << u.ciudad
                 << "\nRector: " << u.rector
                 << "\nNumero de profesores: " << u.numProfesores
                 << "\nHorario: " << u.horario << "\n";

            if (u.carreras.empty()) {
                cout << "  (Sin carreras registradas)\n";
            } else {
                cout << "Carreras:\n";
                for (const auto &c : u.carreras) {
                    cout << "  - " << c.nombre
                         << " (" << c.departamento
                         << ", " << c.duracion << " años, "
                         << c.numEstudiantes << " estudiantes)\n";
                }
            }
            encontrada = true;
            break;
        }
    }

    if (!encontrada)
        cout << "\n❌ No se encontró una universidad con ese nombre.\n";
}

// ------------------------------------------------------------
// 5️⃣ FUNCIÓN PRINCIPAL (MENÚ)
// ------------------------------------------------------------
int main() {
    list<Universidad> universidades; // Lista dinámica de universidades
    int opcion;

    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Registrar universidad\n";
        cout << "2. Mostrar universidades\n";
        cout << "3. Buscar universidad\n";
        cout << "4. Ordenar universidades\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                universidades.push_back(ingresarUniversidad());
                break;
            case 2:
                mostrarUniversidades(universidades);
                break;
            case 3:
                buscarUniversidad(universidades);
                break;
            case 4:
                ordenarUniversidades(universidades);
                break;
            case 5:
                cout << "\n👋 Saliendo del programa...\n";
                break;
            default:
                cout << "\n❌ Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}
