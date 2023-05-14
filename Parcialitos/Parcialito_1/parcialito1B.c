#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>


/* 1 */
/* supongo que m es la matriz y no puede darse el caso de m != NULL y m[i] == NULL */
void identidad1(double **m, size_t filas, size_t columnas) {
    if ((NULL != m) && (filas == columnas)) {
        for (size_t i = 0; i < filas; i++) {
            for (size_t j = 0; j < columnas; ++j) {
                m[i][j] = (i == j) ? 1 : 0;
            }
        }
    }
}
#if 0
void identidad1(double **m, size_t filas, size_t columnas) {
    if ((NULL != m) && (filas == columnas)) {
        for (size_t i = 0; i < filas; i++) {
            memset(m[i], 0, columnas * sizeof(double));
            m[i][i] = 1;
        }
    }
}
#endif


typedef enum {ST_OK, ST_ERR_INVALID_ARG, ST_ERR_NULL_PTR, ST_ERR_DIMENSIONES, ST_ERR_ENOMEM} status_t;


/* supongo que m es la matriz y no puede darse el caso de m != NULL y m[i] == NULL */
status_t identidad2(double **m, size_t filas, size_t columnas)
{
    if (NULL == m) {
        return ST_ERR_NULL_PTR;
    }

    if (filas != columnas) {
        return ST_ERR_DIMENSIONES;
    }

    identidad1(m, filas, columnas);

    return ST_OK;
}


/* 2 */
/* función auxiliar: supongo que siempre le pasan los parámetros correctamente */
double sumar(const double *v, size_t l)
{
    double suma = v[0];

    for (size_t i = 1; i < l; i++) {
        suma += v[i];
    }

    return suma;
}


/* supongo que m es la matriz y no puede darse el caso de m != NULL y m[i] == NULL */
ssize_t ej2(const double **m, size_t filas, size_t columnas)
{
    double suma_max;
    ssize_t index;

    if ((NULL == m) || (0 == filas) || (0 == columnas)) {
        return -1;
    }

    suma_max = sumar(m[0], columnas);
    index = 0;

    for (size_t i = 1; i < filas; i++) {
        double suma = sumar(m[i], columnas);
        if (suma > suma_max) {
            index = i;
            suma_max = suma;
        }
    }

    return index;
}


/* 3 */
/* supongo que m es la matriz y no puede darse el caso de m != NULL y m[i] == NULL */
status_t traza(double *t, const float **m, size_t filas, size_t columnas)
{
    double _traza;

    if ((NULL == t) || (NULL == m)) {
        return ST_ERR_NULL_PTR;
    }
    if ((filas != columnas) || (0 == filas)) {
        return ST_ERR_DIMENSIONES;
    }

    _traza = m[0][0];
    for (size_t i = 1; i < filas; i++) {
        _traza += m[i][i];
    }

    *t = _traza;
    return ST_OK;
}


/* 4 */
#define MSJ_ERR_ARGUMENTOS "ERROR: cantidad de argumentos inválida"
int main(int argc, char *argv[])
{
    size_t menor = 1;

    if (argc < 2) {
        fprintf(stderr, "%s\n", MSJ_ERR_ARGUMENTOS);
        return EXIT_FAILURE;
    }

    for (size_t i = 2; i < argc; i++) {
        if (strcmp(argv[menor], argv[i]) > 0) {
            menor = i;
        }
    }

    puts(argv[menor]);

    return EXIT_SUCCESS;
}


/* 5 */
int *crear_vector(size_t n)
{
    return calloc(n, sizeof(int));
}

int *crear_vector2(size_t n)
{
    int *v;

    v = (int *) malloc(n * sizeof(int));
    if (NULL == v) {
        return NULL;
    }

    for (size_t i = 0; i < n; ++i) {
        v[i] = 0;
    }
    /* o bien: memset(v, 0, n * sizeof(int)); */

    return v;
}
status_t crear_vector3(int **v, size_t n)
{
    if (NULL == v) {
        return ST_ERR_NULL_PTR;
    }

    if (0 == n) {
        return ST_ERR_INVALID_ARG;
    }

    *v = calloc(n, sizeof(int));
    if (NULL == *v) {
        return ST_ERR_ENOMEM;
    }

    return ST_OK;
}
