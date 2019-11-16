#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <math.h>
#include <time.h>

float funcaoFreeInseguro(int BUFFER_SIZE, int LOOP)
{
    int i;
    char *destino;

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        destino = (char *)malloc((BUFFER_SIZE * 2 + 1) * sizeof(char));
        free(destino);
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoFreeSeguro(int BUFFER_SIZE, int LOOP)
{
    int i;
    char *destino;

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        destino = (char *)malloc((BUFFER_SIZE * 2 + 1) * sizeof(char));
        free(destino);
        destino = NULL;     //ATERRAMENTO DO PONTEIRO
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSTRCAT(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        strcat(destino, origem);
        strcat(destino, origem);
        destino[0] = '\0';
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSTRNCAT(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        strncat(destino, origem, sizeof(destino) - strlen(destino) - 1);
        strncat(destino, origem, sizeof(destino) - strlen(destino) - 1);
        destino[0] = '\0';
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoG_STRLCAT(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        g_strlcat(destino, origem, sizeof(destino));
        g_strlcat(destino, origem, sizeof(destino));
        destino[0] = '\0';
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSTRCPY(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino [BUFFER_SIZE + 1];
    char origem1 [BUFFER_SIZE + 1];
    char origem2 [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem1, "\0");
    strcpy(origem2, "\0");

    memset(origem1, 'x', sizeof(origem1));
    origem1[sizeof(origem1) - 1 ] = '\0';

    memset(origem2, 'y', sizeof(origem2));
    origem2[sizeof(origem2) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        strcpy(destino, origem1);
        strcpy(destino, origem2);
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSTRNCPY(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino [BUFFER_SIZE + 1];
    char origem1 [BUFFER_SIZE + 1];
    char origem2 [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem1, "\0");
    strcpy(origem2, "\0");

    memset(origem1, 'x', sizeof(origem1));
    origem1[sizeof(origem1) - 1 ] = '\0';

    memset(origem2, 'y', sizeof(origem2));
    origem2[sizeof(origem2) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        strncpy(destino, origem1, BUFFER_SIZE);
        destino[sizeof(destino) - 1] = '\0';

        strncpy(destino, origem2, BUFFER_SIZE);
        destino[sizeof(destino) - 1] = '\0';
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoG_STRLCPY(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino [BUFFER_SIZE + 1];
    char origem1 [BUFFER_SIZE + 1];
    char origem2 [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem1, "\0");
    strcpy(origem2, "\0");

    memset(origem1, 'x', sizeof(origem1));
    origem1[sizeof(origem1) - 1 ] = '\0';

    memset(origem2, 'y', sizeof(origem2));
    origem2[sizeof(origem2) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        g_strlcpy(destino, origem1, sizeof(destino));
        g_strlcpy(destino, origem2, sizeof(destino));
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSPRINTF(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
    {
        sprintf(destino, "%s%s",origem, origem);
        destino[0] = '\0';
    }

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoSNPRINTF(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
        snprintf(destino, sizeof(destino) - 1, "%s%s", origem, origem);

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

float funcaoG_SNPRINTF(int BUFFER_SIZE, int LOOP)
{
    int i;
    char destino[BUFFER_SIZE * 2 + 1];
    char origem [BUFFER_SIZE + 1];

    strcpy(destino, "\0");
    strcpy(origem, "\0");

    memset(origem, 'x', sizeof(origem));
    origem[sizeof(origem) - 1 ] = '\0';

    clock_t INICIO = clock();

    for(i = 0; i < LOOP; i++)
        g_snprintf(destino, sizeof(destino), "%s%s", origem, origem);

    clock_t FIM = clock();

    return (float)(FIM - INICIO)/CLOCKS_PER_SEC;
}

void teste(int BUFFER_SIZE, int LOOP)
{
	int i = 0;

	float tempoFREE        = 0;
	float tempoFREESAFE    = 0;
	float tempoSTRCAT      = 0;
	float tempoSTRNCAT     = 0;
	float tempoSPRINTF     = 0;
	float tempoSNPRINTF    = 0;
	float tempoSTRCPY      = 0;
	float tempoSTRNCPY     = 0;
	float tempoG_SNPRINTF  = 0;
	float tempoG_STRLCAT   = 0;
	float tempoG_STRLCPY   = 0;

	tempoFREESAFE   = funcaoFreeSeguro      (BUFFER_SIZE, LOOP);
	tempoFREE       = funcaoFreeInseguro    (BUFFER_SIZE, LOOP);
	tempoSTRCAT     = funcaoSTRCAT          (BUFFER_SIZE, LOOP);
	tempoSTRNCAT    = funcaoSTRNCAT         (BUFFER_SIZE, LOOP);
	tempoSPRINTF    = funcaoSPRINTF         (BUFFER_SIZE, LOOP);
	tempoSNPRINTF   = funcaoSNPRINTF        (BUFFER_SIZE, LOOP);
	tempoSTRCPY     = funcaoSTRCPY          (BUFFER_SIZE, LOOP);
	tempoSTRNCPY    = funcaoSTRNCPY         (BUFFER_SIZE, LOOP);
	tempoG_SNPRINTF = funcaoG_SNPRINTF      (BUFFER_SIZE, LOOP);
	tempoG_STRLCAT  = funcaoG_STRLCAT       (BUFFER_SIZE, LOOP);
	tempoG_STRLCPY  = funcaoG_STRLCPY       (BUFFER_SIZE, LOOP);  

	printf("TESTE para BUFFER SIZE: %d\n", BUFFER_SIZE);
	printf("TESTE para LOOP: %d\n", LOOP);
	printf("\n---------------------------");
	printf("\n|Funcao     | Tempo Total");
	printf("\n---------------------------");
	printf("\n|FREE       | %.3f", tempoFREE);
	printf("\n|FREE SAFE  | %.3f", tempoFREESAFE);
	printf("\n|STRCAT     | %.3f", tempoSTRCAT);
	printf("\n|STRNCAT    | %.3f", tempoSTRNCAT);
	printf("\n|G_STRLCAT  | %.3f", tempoG_STRLCAT);
	printf("\n|SPRINTF    | %.3f", tempoSPRINTF);
	printf("\n|SNPRINTF   | %.3f", tempoSNPRINTF);
	printf("\n|G_SNPRINTF | %.3f", tempoG_SNPRINTF);
	printf("\n|STRCPY     | %.3f", tempoSTRCPY);
	printf("\n|STRNCPY    | %.3f", tempoSTRNCPY);
	printf("\n|G_STRLCPY  | %.3f", tempoG_STRLCPY);
	printf("\n---------------------------\n\n");

}

int main(int argc, char *argv[])
{
    int BUFFER_SIZE;
    int LOOP;

    if(argc == 3)
    {
        sscanf(argv[1], "%d", &BUFFER_SIZE);
        sscanf(argv[2], "%d", &LOOP);
    }
    else
    {
        BUFFER_SIZE = 10;
        LOOP        = 100000000;
        printf("Usando variaveis padrao. Se deseja inserir outros valores, segue o modelo de argumentos.\n\nBUFFER_SIZE LOOP\n\n");
    }

    printf("BUFFER SIZE: %d \nLOOP: %d \n\nPressione qualquer tecla para continuar.", BUFFER_SIZE, LOOP);
    getchar();
    system("clear || cls");

    teste(BUFFER_SIZE, LOOP);

    return 0;
}