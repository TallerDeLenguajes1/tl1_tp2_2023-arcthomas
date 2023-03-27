#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu
{
    int velPrcss;
    int anio;
    int cant;
    char *tipo_cpu;
} typedef pc;

void asignarValoresRand(pc *compu, char tipos[][10])
{
    int indice_aleatorio = rand() % 6;
    compu->velPrcss = 1 + (rand() % 3);
    compu->anio = 2015 + rand() % (2023 - 2015 + 1);
    compu->cant = 1 + (rand() % 8);
    compu->tipo_cpu = strcpy(compu->tipo_cpu, tipos[indice_aleatorio]);
}

void cargarCompu(pc *compu, char tipos[][10])
{
    int indice;
    printf("Cargar velocidad de procesamiento:\n");
    fflush(stdin);
    scanf("%d", &(compu->velPrcss));
    printf("Cargar año:\n");
    fflush(stdin);
    scanf("%d", &(compu->anio));
    printf("Cargar cantidad:\n");
    fflush(stdin);
    scanf("%d", &(compu->cant));
    printf("Cargar tipo de CPU según opción:\n1- Intel\n2- AMD\n3- Celeron\n4- Athlon\n5- Core\n6- Pentium\n");
    fflush(stdin);
    scanf("%d", &indice);
    compu->tipo_cpu = (char *)malloc(10 * sizeof(char));
    compu->tipo_cpu = strcpy(compu->tipo_cpu, tipos[(indice - 1)]);
}

void mostrarCompus(pc compus[])
{
   int i;
   printf("Compus disponibles: 2\n\n");
   for(i = 0; i < 5; i++){
      printf("Datos de la PC %d:\n", (1 + i));
      printf("Velocidad del procesador: %dHz", compus[i].velPrcss);
      printf("\nAño: %d", compus[i].anio);
      printf("\nCantidad: %d", compus[i].cant);
      printf("\nTipo de procesador: ");
      puts(compus[i].tipo_cpu);
      printf("\n");
   }
}

void pcVieja(pc compus[]) 
{
   int aux, cont = 0, aux2 = 2050;
   for (int i = 0; i < 5; i++){
      if(compus[i].anio < aux2){
         aux = cont;
         aux2 = compus[i].anio;
      }
      cont++;
   }
   printf("Datos de la PC más vieja:\n");
   printf("Velocidad del procesador: %dHz", compus[aux].velPrcss);
   printf("\nAño: %d", compus[aux].anio);
   printf("\nCantidad: %d", compus[aux].cant);
   printf("\nTipo de procesador: ");
   puts(compus[aux].tipo_cpu);
   printf("\n");
}

void pcVeloz(pc compus[]){
   int aux, cont = 0, aux2 = 0;
   for (int i = 0; i < 5; i++){
      if(compus[i].velPrcss > aux2){
         aux = cont;
         aux2 = compus[i].velPrcss;
      }
      cont++;
   }
   printf("Datos de la PC más veloz:\n");
   printf("Velocidad del procesador: %dHz", compus[aux].velPrcss);
   printf("\nAño: %d", compus[aux].anio);
   printf("\nCantidad: %d", compus[aux].cant);
   printf("\nTipo de procesador: ");
   puts(compus[aux].tipo_cpu);
   printf("\n");
}

int main()
{
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    pc compu1;
    compu1.tipo_cpu = (char *)malloc(10 * sizeof(char));
    asignarValoresRand(&compu1, tipos);
    printf("Velocidad de procesamiento: %d\n", compu1.velPrcss);
    printf("Año: %d\n", compu1.anio);
    printf("Cantidad: %d\n", compu1.cant);
    printf("Tipo de CPU: %s\n", compu1.tipo_cpu);
    free(compu1.tipo_cpu);
    pc compus[5];
    pc *pcompus = compus;
    for (int i = 0; i < 5; i++)
    {
        cargarCompu(pcompus, tipos);
        pcompus++;
    }
    mostrarCompus(compus);
    pcVieja(compus);
    pcVeloz(compus);
    for (int i = 0; i < 5; i++)
    {
        free(compus[i].tipo_cpu);
    }
}