#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
};

Nodo *arbol=NULL;
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int);
void menu();
void mostrarArbol(Nodo *arbol, int contador);

int main()
{
    system("color 0b");
    menu();

    cout << "\n\n";
    return 0;
}

Nodo *crearNodo(int n)
{
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;
    return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n)
{
    if (arbol == NULL)
    {
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else
    {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz)
        {
            insertarNodo(arbol->izquierda, n);
        }
        else
        {
            insertarNodo(arbol->derecha, n);
        }
    }
}

void menu()
{
    int dato, opcion, contador = 0;

    do
    {
        cout << "\t.:M E N U:.\n";
        cout << "1. Insertar Nodo\n";
        cout << "2. Mostrar Arbol\n";
        cout << "3. Salir\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "\nDigite Valor del Nuevo Nodo: ";
            cin >> dato;
            insertarNodo(arbol, dato);
            cout << endl;
            break;

        case 2:
            system("cls");
            cout << "Mostrando el Arbol...\n";
            mostrarArbol(arbol, contador);
            break;
        case 3:
            system("cls");
            break;
        }
    } while (opcion != 3);
}

void mostrarArbol(Nodo *arbol, int contador)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->derecha, contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierda, contador + 1);
    }
}
