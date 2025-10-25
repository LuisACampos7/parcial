#include <iostream>     // Para entrada y salida estándar
#include <string>       // Para usar strings
#include <vector>       // Para almacenar síntomas
#include <queue>        // Para la estructura de cola (queue)
using namespace std;

// ------------------------------------------------------------
// ESTRUCTURAS DE DATOS
// ------------------------------------------------------------

// Estructura para los síntomas de un paciente
struct Sintoma {
    string descripcion;
    int gravedad; // de 1 a 10
};

// Estructura para un paciente
struct Paciente {
    string nombre;
    int edad;
    string motivoConsulta;
    vector<Sintoma> sintomas; // cada paciente puede tener varios síntomas
};

// ------------------------------------------------------------
// FUNCIONES DEL PROGRAMA
// ------------------------------------------------------------

// 1️⃣ Función para registrar un nuevo paciente
Paciente ingresarPaciente() {
    Paciente p;
    cin.ignore(); // Limpia el búfer antes de getline()

    cout << "\n--- Registrar nuevo paciente ---\n";
    cout << "Nombre: ";
    getline(cin, p.nombre);

    cout << "Edad: ";
    cin >> p.edad;
    cin.ignore();

    cout << "Motivo de la consulta: ";
    getline(cin, p.motivoConsulta);

    int cantidadSintomas;
    cout << "¿Cuantos síntomas desea registrar? ";
    cin >> cantidadSintomas;
    cin.ignore();

    // Bucle para registrar los síntomas
    for (int i = 0; i < cantidadSintomas; i++) {
        Sintoma s;
        cout << "\n--- Síntoma " << i + 1 << " ---\n";
        cout << "Descripción: ";
        getline(cin, s.descripcion);

        cout << "Nivel de gravedad (1-10): ";
        cin >> s.gravedad;
        cin.ignore();

        p.sintomas.push_back(s);
    }

    cout << "\n✅ Paciente registrado correctamente.\n";
    return p;
}

// 2️⃣ Mostrar la lista de pacientes (sin eliminarlos)
void mostrarPacientes(queue<Paciente> cola) {
    if (cola.empty()) {
        cout << "\n⚠️ No hay pacientes en la cola.\n";
        return;
    }

    cout << "\n=== PACIENTES EN ESPERA ===\n";
    int pos = 1;

    // OJO: se pasa por copia para no alterar la cola original
    while (!cola.empty()) {
        Paciente p = cola.front();
        cout << "\nPaciente #" << pos++ << "\n";
        cout << "👤 Nombre: " << p.nombre
             << "\n🎂 Edad: " << p.edad
             << "\n🏥 Motivo: " << p.motivoConsulta
             << "\n";

        if (p.sintomas.empty()) {
            cout << "  (Sin síntomas registrados)\n";
        } else {
            cout << "  Síntomas:\n";
            for (auto &s : p.sintomas) {
                cout << "   - " << s.descripcion << " (gravedad " << s.gravedad << ")\n";
            }
        }

        cola.pop(); // Avanzamos al siguiente (sin afectar la original)
    }
}

// 3️⃣ Atender al siguiente paciente (el primero en la cola)
void atenderPaciente(queue<Paciente> &cola) {
    if (cola.empty()) {
        cout << "\n⚠️ No hay pacientes para atender.\n";
        return;
    }

    Paciente p = cola.front(); // obtenemos al primer paciente
    cola.pop(); // lo eliminamos de la cola

    cout << "\n--- Atendiendo paciente ---\n";
    cout << "👤 Nombre: " << p.nombre << "\n";
    cout << "🎂 Edad: " << p.edad << "\n";
    cout << "🏥 Motivo: " << p.motivoConsulta << "\n";

    if (p.sintomas.empty()) {
        cout << "  (Sin síntomas registrados)\n";
    } else {
        cout << "  Síntomas:\n";
        for (auto &s : p.sintomas) {
            cout << "   - " << s.descripcion << " (gravedad " << s.gravedad << ")\n";
        }
    }

    cout << "\n✅ El paciente ha sido atendido y retirado de la cola.\n";
}

// 4️⃣ Mostrar el siguiente paciente sin retirarlo
void verSiguientePaciente(const queue<Paciente> &cola) {
    if (cola.empty()) {
        cout << "\n⚠️ No hay pacientes en espera.\n";
        return;
    }

    Paciente p = cola.front();
    cout << "\n👀 Siguiente paciente en ser atendido:\n";
    cout << "👤 " << p.nombre << " (" << p.edad << " años)\n";
    cout << "Motivo: " << p.motivoConsulta << "\n";
}

// ------------------------------------------------------------
// 5️⃣ FUNCIÓN PRINCIPAL (MENÚ)
// ------------------------------------------------------------
int main() {
    queue<Paciente> colaPacientes; // Cola dinámica de pacientes
    int opcion;

    do {
        cout << "\n========== MENU CLÍNICA ==========\n";
        cout << "1. Registrar paciente\n";
        cout << "2. Ver pacientes en espera\n";
        cout << "3. Atender paciente\n";
        cout << "4. Ver siguiente paciente\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                colaPacientes.push(ingresarPaciente());
                break;
            case 2:
                mostrarPacientes(colaPacientes);
                break;
            case 3:
                atenderPaciente(colaPacientes);
                break;
            case 4:
                verSiguientePaciente(colaPacientes);
                break;
            case 5:
                cout << "\n👋 Saliendo del sistema...\n";
                break;
            default:
                cout << "\n❌ Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
