#include <gtest/gtest.h>

TEST(PunterosTest, 00) {
    int numero = 2;
    int *puntero_a_numero;
    puntero_a_numero=&numero; //el & se usa para acceder al lugar de memoria de la variable numero
    // TODO: Hacer que puntero_a_numero apunte a numero

    EXPECT_EQ(2, *puntero_a_numero);

    // TODO: Pensar... ¿es necesario liberar memoria?
    // No es necesario liberar memoria porque número vive en el stack, no en el
    // heap, por lo que la memoria se libera automáticamente cuando el programa
    // salga del scope en que fue definida la variable.

}

TEST(PunterosTest, 01) {
    int *numero;
    numero=new int;
    *numero=2;
//tambien vale hace numero=new int(2);

    // TODO: Reservar memoria para un entero en el heap, hacer que la variable
    // numero apunte a dicho espacio y guardar un 2.

    EXPECT_EQ(2, *numero);
    delete numero;
    numero = nullptr;
    // TODO: Liberar memoria y asegurarse de que no queden referencias a
    // punteros inválidos apuntando a la posición que ya no podemos acceder.

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 02) {
    int *numero = new int(2);
    *numero=*numero+3;
    // TODO: Sumar 3 al valor existente en `numero`.

    EXPECT_EQ(5, *numero);
    delete numero;
    numero=nullptr;
    // TODO: Liberar memoria y asegurarse de que no queden referencias a
    // punteros inválidos apuntando a la posición que ya no podemos acceder.

    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 03) {
    int numero = 2;
    int *puntero_a_numero;
    puntero_a_numero=&numero;
    // TODO: Hacer que `puntero_a_numero` apunte exactamente a la posición de
    // memoria donde está el valor de `numero`.

    EXPECT_EQ(2, *puntero_a_numero);
}


TEST(PunterosTest, 04) {
    int *numero = new int;
    int *alias_de_numero;
    *numero = 2; 
    alias_de_numero=numero;//como numero es un puntero puedo igualar los punteros
    // TODO: Hacer que `alias_de_numero` apunte a la misma posicion de memoria
    // que `numero`. No está permitiro reservar memoria nueva para `alias_de_numero`.

    EXPECT_EQ(numero, alias_de_numero);
    EXPECT_EQ(2, *alias_de_numero);

    delete alias_de_numero;
    alias_de_numero = nullptr;
    EXPECT_EQ(nullptr, alias_de_numero);

    // TODO: Pensar... ¿a dónde apunta con `numero` ahora? ¿Qué ocurre si
    // queremos acceder al valor en dicha posición de memoria?
    // `numero` quedó invalidado porque apunte a la posición de memoria que
    // acabamos de devolver. Típicamente deberíamos hacer `numero = nullptr`
    // también para evitar acceder por error a esa posición.

}
