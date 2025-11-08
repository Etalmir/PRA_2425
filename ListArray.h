#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H
#include "Generic_list.h"
#include <ostream>

template <typename T>
class ListArray : public GenericList<T> {
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
    public:
        // Constructor y Destructor
        ListArray() : max(MINSIZE), n(0) {
            arr = new T[max];
        }
        ~ListArray() {
            delete[] arr;
        }

        // Metodo para redimensionar el array
        void resize(int newSize) {
            // Creamos una nueva lista con el nuevo tamaño
            T* newArr = new T[newSize];
            // Copiamos los elementos de la lista anitgua a la nueva
            for (int i = 0; i < n; ++i){
                newArr[i] = arr[i];
            }
            // Eliminamos la lista anituga
            delete[] arr;
            // Actualizamos el puntero a la nueva lista
            arr = newArr;
            // Actualizamos el tamaño mázimo al nuevo.
            max = newSize;
        }

        // Método para añadir elementos a la lista
        void insert(int pos, const T& e) override {
            if (pos < 0 || pos > n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            if (n >= max){
                resize(max * 2);
            }
            for (int i = n; i > pos; --i){
                arr[i] = arr[i - 1];
            }
            arr[pos] = e;
            ++n;
        }

        // Método para añadir elementos al final de la lista
        void append(const T& e) override {
            insert(n, e);
        }

        // Método para añadir elementos al principio de la lista
        void prepend(const T& e) override {
            insert(0, e);
        }

        // Método para eliminar elementos de la lista
        T remove(int pos) override {
            if (pos < 0 || pos >= n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            // Capturamos el elemento a eliminar
            T eliminado = arr[pos];
            // Desplazamos los elementos una posiión hacia la izquierda
            for (int i = pos; i < n - 1; ++i){
                arr[i] = arr[i + 1];
            }
            // Reducimos el total de elementos activos en la lista.
            --n;
            // Si el total de elementos libres son muy pocos (siempre respetando el mínimo), redimensionamos la lista.
            if (n <= max / 4 && max / 2 >= MINSIZE) resize(max / 2);
            // Devolvemos el elemento eliminado.
            return eliminado;
        }

        // Método para obtener un elemento de la lista
        T get(int pos) const override {
            if (pos < 0 || pos >= n){
                throw std::out_of_range("Posición dada fuera de rango");
            }
            return arr[pos];
        }

        // Método para buscar un elemento en la lista
        int search(const T& e) const override {
            for (int i = 0; i < n; ++i){
                if (arr[i] == e){
                    return i;
                }
            }
            return -1; // No encontrado
        }

        // Método para comprobar si la lista está vacía
        bool empty() const override {
            return n == 0;
        }

        // Método para obtener el tamaño de la lista
        int size() const override {
            return n;
        }

        // Sobrecarga del operador de acceso, devuelve el elemento en la posición dada
        T operator[](int pos) const {
            return get(pos);
        }

        // Sobrecarga del operador de salida para imprimir la lista, devuelve la lista en un flujo de salida, imprime los elementos separados por espacios y comas
        friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
            for (int i = 0; i < list.n; i++){
            if (i < list.n - 1)
                out << list.arr[i] << ", ";
            else
                out << list.arr[i] << "\n";
            }
            return out;
        }
};

#endif