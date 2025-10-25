#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
using namespace std;

struct Libro
{
    string Titulo;
    int Ano_Publicacion;
};

struct Biblioteca
{
    string Nombre;
    string Horario_Apertura;
    vector<Libro> coleccion;
};

void Solicitar_Informacion(list<Biblioteca> &biblioteca)
{
    Biblioteca nueva;
    char cont;
    cout << "Ingrese los datos de la Biblioteca:" << endl;
    cout << "Nombre: ";
    getline(cin >> ws, nueva.Nombre);
    cout << "Horario de apertura: ";
    getline(cin >> ws, nueva.Horario_Apertura);
    cout << "Continuar? (S/s o N/n)";
    while (cont == 's' || cont == 'S')
    {
        Libro nuevo;
        cout << "Ingrese los datos de la Biblioteca:" << endl;
        cout << "Titulo: ";
        getline(cin >> ws, nuevo.Titulo);
        cout << "Horario de apertura: ";
        cin >> nuevo.Ano_Publicacion;

        nueva.coleccion.push_back(nuevo);

        cout << "Continuar? (S/s o N/n)";
        cin >> cont;
    }
    biblioteca.push_back(nueva);
    cout << "Biblioteca registrada" << endl;
}

void Mostrar(list<Biblioteca> &biblioteca, vector<Libro> &coleccion)
{
    for (Biblioteca i : biblioteca)
    {
        cout << "-------------------" << endl;
        cout << "Nombre: " << i.Nombre << endl;
        cout << "Horario: " << i.Horario_Apertura << endl;
        for (Libro t : coleccion)
        {
            cout << "-------------------" << endl;
            cout << "Titulo: " << t.Titulo << endl;
            cout << "Ano de publicacion: " << t.Ano_Publicacion << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void Buscar(const list<Biblioteca> &biblioteca)
{
    string busqueda;
    cout << "Ingrese el nombre de la biblioteca: " << endl;
    getline(cin >> ws, busqueda);

    // Busquedad binario por texto
    auto bibliotecaEncontrada = find_if(
        biblioteca.begin(),
        biblioteca.end(),
        [&](const Biblioteca &nueva)
        { return nueva.Nombre == busqueda;}
        );
}

int main()
{
    list<Biblioteca> biblioteca;
    vector<Libro> coleccion;
    int op;
    do
    {
        cout << "Menu" << endl;
        cout << "1.Solicitar informacion" << endl;
        cout << "2.Mostrar informacion" << endl;
        cout << "3.Ordenar informacion" << endl;
        cout << "4.Salir" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            Solicitar_Informacion(biblioteca);
            break;
        case 2:
            Mostrar(biblioteca, coleccion);
            break;
        case 3:

            break;
        default:
            break;
        }
    } while (op != 4);

    return 0;
}