#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <glib.h>
#include <glib/gprintf.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

double temporizador_free(const int BUFFER_SIZE, const int LOOP) {
    char *destine = NULL;

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        destine = malloc(BUFFER_SIZE * sizeof(char));
        free(destine);
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_free_s(const int BUFFER_SIZE, const int LOOP) {
    char *destine = NULL;

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        destine = malloc(BUFFER_SIZE * sizeof(char));
        free(destine);
        destine = NULL; /* Aterramento do ponteiro */
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_strcat(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE * 2 + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));    /* Gerado string somente com X */
    source[sizeof(source) - 1 ] = '\0';     /* Terminador NULL */

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        strcat(destine, source);
        strcat(destine, source);
        destine[0] = '\0';  /* Terminador NULL no comeco "limpa" a string */
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_strncat(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE * 2 + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));    /* Gerado string somente com X */
    source[sizeof(source) - 1 ] = '\0';     /* Terminador NULL */

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        strncat(destine, source, sizeof(destine) - strlen(destine) - 1);
        strncat(destine, source, sizeof(destine) - strlen(destine) - 1);
        destine[0] = '\0';  /* Terminador NULL no comeco "limpa" a string */
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_g_strlcat(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE * 2 + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        g_strlcat(destine, source, sizeof(destine));
        g_strlcat(destine, source, sizeof(destine));
        destine[0] = '\0';  /* Terminador NULL no comeco "limpa" a string */
    }

    clock_t END = clock();

    return (double)(END - START)/CLOCKS_PER_SEC;
}

double temporizador_strcpy(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        strcpy(destine, source);
        destine[0] = '\0';  /* Terminador NULL no comeco "limpa" a string */
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_strncpy(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i) {
        strncpy(destine, source, sizeof(destine));
        /* strcpy() nao adiciona autmoaticamente o terminador '\0' no fim */
        destine[sizeof(destine) - 1] = '\0';
        destine[0] = '\0';  /* Terminador NULL no comeco "limpa" a string */
    }

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_g_strlcpy(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i)
        g_strlcpy(destine, source, sizeof(destine));

    clock_t END = clock();

    return (double)(END - START)/CLOCKS_PER_SEC;
}

double temporizador_sprintf(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i)
        sprintf(destine, "%s", source);

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_snprintf(const int BUFFER_SIZE, const int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0]  = '\0'; /* Apaga lixo de memoria */
    source[0]   = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i)
        snprintf(destine, sizeof(destine), "%s", source);

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

double temporizador_g_snprintf(int BUFFER_SIZE, int LOOP) {
    char destine[BUFFER_SIZE + 1];
    char source [BUFFER_SIZE + 1];

    destine[0] = '\0'; /* Apaga lixo de memoria */
    source [0] = '\0';

    memset(source, 'x', sizeof(source));
    source[sizeof(source) - 1 ] = '\0';

    clock_t START = clock();

    for(int i = 0; i < LOOP; ++i)
        g_snprintf(destine, sizeof(destine), "%s", source);

    clock_t END = clock();

    return (double)(END - START) / CLOCKS_PER_SEC;
}

void teste(const int BUFFER_SIZE, const int LOOP) {
	double tempoFREE        = 0;
	double tempoFREESAFE    = 0;
	double tempoSTRCAT      = 0;
	double tempoSTRNCAT     = 0;
	double tempoSPRINTF     = 0;
	double tempoSNPRINTF    = 0;
	double tempoSTRCPY      = 0;
	double tempoSTRNCPY     = 0;
	double tempoG_SNPRINTF  = 0;
	double tempoG_STRLCAT   = 0;
	double tempoG_STRLCPY   = 0;

	tempoFREESAFE   = temporizador_free_s       (BUFFER_SIZE, LOOP);
	tempoFREE       = temporizador_free         (BUFFER_SIZE, LOOP);
	tempoSTRCAT     = temporizador_strcat       (BUFFER_SIZE, LOOP);
	tempoSTRNCAT    = temporizador_strncat      (BUFFER_SIZE, LOOP);
	tempoSPRINTF    = temporizador_sprintf      (BUFFER_SIZE, LOOP);
	tempoSNPRINTF   = temporizador_snprintf     (BUFFER_SIZE, LOOP);
	tempoSTRCPY     = temporizador_strcpy       (BUFFER_SIZE, LOOP);
	tempoSTRNCPY    = temporizador_strncpy      (BUFFER_SIZE, LOOP);
	tempoG_SNPRINTF = temporizador_g_snprintf   (BUFFER_SIZE, LOOP);
	tempoG_STRLCAT  = temporizador_g_strlcat    (BUFFER_SIZE, LOOP);
	tempoG_STRLCPY  = temporizador_g_strlcpy    (BUFFER_SIZE, LOOP);

	printf("TESTE para BUFFER SIZE: %d\n", BUFFER_SIZE);
	printf("TESTE para LOOP: %d\n", LOOP);
	printf("\n---------------------------");
	printf("\n|Funcao     | Tempo Total");
	printf("\n---------------------------");
	printf("\n|FREE       | %f", tempoFREE);
	printf("\n|FREE SAFE  | %f", tempoFREESAFE);
	printf("\n|STRCAT     | %f", tempoSTRCAT);
	printf("\n|STRNCAT    | %f", tempoSTRNCAT);
	printf("\n|G_STRLCAT  | %f", tempoG_STRLCAT);
	printf("\n|SPRINTF    | %f", tempoSPRINTF);
	printf("\n|SNPRINTF   | %f", tempoSNPRINTF);
	printf("\n|G_SNPRINTF | %f", tempoG_SNPRINTF);
	printf("\n|STRCPY     | %f", tempoSTRCPY);
	printf("\n|STRNCPY    | %f", tempoSTRNCPY);
	printf("\n|G_STRLCPY  | %f", tempoG_STRLCPY);
	printf("\n---------------------------\n\n");

}

int main(const int argc, const char *argv[]) {
    int BUFFER_SIZE;
    int LOOP;

    if(argc == 3) {
        sscanf(argv[1], "%d", &BUFFER_SIZE);
        sscanf(argv[2], "%d", &LOOP);
    }
    else {
        BUFFER_SIZE = 100000000;
        LOOP        = 10;
        printf("Usando variaveis padrao. Se deseja inserir outros valores, "
               "siga o modelo de argumentos.\n\nBUFFER_SIZE LOOP\n\n");
    }

    printf("BUFFER SIZE: %d \n"
           "LOOP: %d\n\n"
           "Pressione qualquer tecla para continuar.", BUFFER_SIZE, LOOP);
    getchar();
    system(CLEAR);

    teste(BUFFER_SIZE, LOOP);

    return EXIT_SUCCESS;
}
