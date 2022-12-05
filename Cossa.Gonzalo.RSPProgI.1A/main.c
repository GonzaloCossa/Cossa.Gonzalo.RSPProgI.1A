#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char marca[20];
    int tipo;
    float peso;
}eVehiculo;

eVehiculo* constructorVehiculo();
eVehiculo* constructorVehiculoParam(int id, char marca[], int tipo, float peso);

int main()
{
    //PUNTO 1
    eVehiculo *vec1 = constructorVehiculo();
    eVehiculo *vec2 = constructorVehiculoParam(1, "Fiat", 1, 950.5);

    //PUNTO 2
    FILE* f = fopen("vehiculo.txt", "w" );
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    else
    {
        fprintf(f, "%d,%s,%d,%f", vec2->id, vec2->marca, vec2->tipo, vec2->peso);
    }

    fclose(f);

    //PUNTO 3
    FILE* f2 = fopen("vehiculo.bin", "wb" );
    if(f2 == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    else
    {
        fwrite(vec2, sizeof(eVehiculo), 1, f2);
    }

    fclose(f2);
    return 0;
}

eVehiculo* constructorVehiculo()
{
    eVehiculo* nuevoVec = malloc(sizeof(eVehiculo));

    if(nuevoVec != NULL)
    {
        nuevoVec->id = 0;
        strcpy(nuevoVec->marca, " ");
        nuevoVec->tipo = 0;
        nuevoVec->peso = 0;
    }

    return nuevoVec;
}

eVehiculo* constructorVehiculoParam(int id, char marca[], int tipo, float peso)
{
    eVehiculo* nuevoVec = malloc(sizeof(eVehiculo));
    if(nuevoVec != NULL && id > 0 && marca != NULL && tipo > 0 && peso > 0)
    {
            nuevoVec->id = id;
            strcpy(nuevoVec->marca, marca);
            nuevoVec->tipo = tipo;
            nuevoVec->peso = peso;
    }
    return nuevoVec;
}
