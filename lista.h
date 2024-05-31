#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
using namespace std;

template <typename T>
class Lista {
    public:
    Lista();
    ~Lista();

    int longitud();

    void agregarAtras(const T& elemento);

    // Pre: 0 <= posicion < longitud()
    T iesimo(const int posicion);

    // Pre: longitud() > 0
    void borrarUltimo();

    // Pre: 0 <= posicion < longitud()
    void borrarIesimo(const int posicion);

    // Pre: longitud() > 0
    T cursor();

    // Pre: longitud() > 0
    void avanzar();

    // Pre: longitud() > 0
    void retroceder();

    private:
        struct nodo {
            nodo(T un_elemento) : elemento(un_elemento), siguiente(nullptr) {}
            T elemento;
            nodo* siguiente;
            nodo* anterior;
        };

        nodo* _primero;
        nodo* _cursor;
        int _longitud;
};

template <typename T>
Lista<T>::Lista() : _primero(nullptr), _cursor(nullptr), _longitud(0) {}

template <typename T>
int Lista<T>::longitud() {
    return _longitud;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elemento) {
    nodo * nuevo = new nodo(elemento);

    if (_primero == nullptr) {
          _primero = nuevo;
          _cursor = nuevo;
    } else {
        // avanzo hasta que `actual` sea el último nodo
        nodo* actual = _primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
    _longitud++;
}

template <typename T>
T Lista<T>::iesimo(const int posicion) {
    // avanzo hasta que `actual` sea el iésimo nodo
    nodo* actual = _primero;
    int i = 0;
    while (i < posicion){
        actual = actual->siguiente;
        i++;
    }

    return actual->elemento;
}

template <typename T>
Lista<T>::~Lista() {
    nodo * actual = _primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    _primero = nullptr;
}

template <typename T>
void Lista<T>::borrarUltimo() {
    borrarIesimo(_longitud - 1);
}

template <typename T>
void Lista<T>::borrarIesimo(const int posicion) {
    nodo * previo = nullptr;
    nodo * actual = _primero;

    // avanzo hasta que:
    //   - `actual` sea el i-ésimo nodo
    //   - `previo` sea el (i-1)-ésimo nodo (o nullptr, si no hay previo)
    int i = 0;
    while (i < posicion) {
        previo = actual;
        actual = actual->siguiente;
        i++;
    }

    // actualizo el puntero hacia adelante que haga falta (ya sea _primero o el
    // enlace del nodo anterior, dependiendo del caso).
    if (posicion == 0) {
        _primero = actual->siguiente;
    } else {
        previo->siguiente = actual->siguiente;
    }

    // actualizo el puntero hacia atrás del nodo siguiente, de ser necesario.
    if (posicion < _longitud -1) {
        actual->siguiente->anterior = previo;
    }

    // si estoy borrando el nodo apuntado por el cursor, actualizo el cursor
    // como sea necesario según el caso.
    if (actual == _cursor) {
      if (actual->siguiente != nullptr) {
        _cursor = actual->siguiente;
      } else {
        _cursor = previo;
      }
    }

    // ahora sí! ya no quedan referencias a `actual` y todos los enlaces fueron
    // corregidos. libero la memoria del nodo borrado y decremento la longitud
    // precomputada.
    delete actual;
    _longitud--;
}

template <typename T>
T Lista<T>::cursor() {
  return _cursor->elemento;
}

template <typename T>
void Lista<T>::avanzar() {
  if (_cursor->siguiente) {
    _cursor = _cursor->siguiente;
  }
}

template <typename T>
void Lista<T>::retroceder() {
  if (_cursor->anterior) {
    _cursor = _cursor->anterior;
  }
}
#endif
