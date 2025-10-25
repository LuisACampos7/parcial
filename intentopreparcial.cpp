#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace std;

struct libros{
    string titulo;
    string autor;
    int año;
    int paginas;
};

struct bibliotecas{
    string nombre;
    int empleados;
    vector <libros> libro;
};

void solicitar(list<struct bibliotecas>& biblioteca, vector<struct libros>& libro){
    bibliotecas newbiblioteca;
    cout<<"ingrese el nombre de la biblioteca"<<endl;
    getline (cin>> ws, newbiblioteca.nombre);
    cout<<"ingrese la cantidad de empleados"<<endl;
    cin>> newbiblioteca.empleados;

    biblioteca.push_back(newbiblioteca);


    cout<<"continuar N/n o S/s"<<endl;
    char cont;
    cin>>cont;
    while(cont == 's' || cont =='S')
    {
        libros l;
    cout<<"ingrese el nombre del libro"<<endl;
    getline (cin>> ws, l.titulo);
    cout<<"ingrese la cantidad de empleados"<<endl;
    cin>> l.año;

    newbiblioteca.libro.push_back(l);

    cout<<"continuar N/n o S/s"<<endl;
    cin>>cont;
    }
}

void imprimir(list<struct bibliotecas>& biblioteca, vector<struct libros> libro){
for (bibliotecas i : biblioteca){
    cout<<"nombre: "<<i.nombre<<endl;
    cout<<"empleados: "<<i.empleados<<endl;
}
cout<<endl;

for(libros i : libro){
    cout<<"titulo: "<<i.titulo<<endl;
    cout<<"año"

}
}


int main(){
    int opcion;
    list<struct bibliotecas> biblioteca; 
    vector<struct libros> libro;
    do
    {
        cout<<"ingrese la opcion que desea realizar"<<endl;
        cout<<"1.añadir biblioteca"<<endl;
        cout<<"2. mostrar"<<endl;
        cout<<"3. ordenar"<<endl;
        cout<<"4. buscar"<<endl;
        cout<<"5.salir"<<endl;

        cin>>opcion;

        switch (opcion)
        {
        case 1:
            solicitar(biblioteca, libro);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            cout<<"saliendo... "<<endl;
        default:
            cout<<"ingrese una opcion valida"<<endl;
            break;
        }
    } while (opcion != 5);
    
}