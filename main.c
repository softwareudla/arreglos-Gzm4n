#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    // Inicialización de variables
    float cal[5][3][3];
    char nom[5][20], asi[3][20] = {"Matematicas", "Fisica", "Historia"};

    // Nombres de los estudiantes
    for (int i=0; i<5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i+1);
        fgets(nom[i], 20, stdin);
        nom[i][strcspn(nom[i], "\n")] = '\0';
    }

    // Obtención de calificaciones
    for (int i=0; i<5; i++) {
        printf("Ingrese las calificaciones del estudiante %s\n", nom[i]);
        for (int j=0; j<3; j++) {
            printf("Asignatura: %s\n", asi[j]);
            for (int k=0; k<3; k++) { // Se trabaja con 3 calificaciones por asignatura
                do {
                    printf("Ingrese la calificacion %d (0-10): ", k+1);
                    scanf("%f", &cal[i][j][k]);
                    if (cal[i][j][k] < 0 || cal[i][j][k] > 10) {
                        printf("Calificacion invalida, ingrese de nuevo.\n");
                    }
                } while (cal[i][j][k]<0 || cal[i][j][k]>10);
            }
        }
    }

    // Formato de tabla con encabezados
    printf("\n%-10s %-15s %-15s %-15s %-20s\n", "Nombre", "Matematicas", "Fisica", "Historia", "Promedio General");
    printf("---------------------------------------------------------------------------\n");

    // Cálculos del bloque de estudiantes y formateo para tabla
    for (int i=0; i<5; i++) {
        float sum_e=0; // Suma de calificaciones POR ESTUDIANTE 
        int cal_t=0;   // Número de calificaciones

        // Variables para las asignaturas
        float proms[3] = {0, 0, 0};   
        float maxs[3] = {0, 0, 0};    
        float mins[3] = {10, 10, 10};

        for (int j=0; j<3; j++) {
            float sum_a=0; // Suma de calificaciones POR ASIGNATURA

            for (int k=0; k<3; k++) {
                float aux=cal[i][j][k];
                sum_a+=aux;
                if (aux> maxs[j]) maxs[j] = aux;
                if (aux < mins[j]) mins[j] = aux;
            }
            // Guardar el promedio de la asignatura
            proms[j]=sum_a / 3;
            sum_e += proms[j];
            cal_t++;
        }

        // formato
        printf("%-10s %-5.2f (%2.0f-%2.0f)  %-5.2f (%2.0f-%2.0f)  %-5.2f (%2.0f-%2.0f)  %-5.2f\n",
               nom[i],
               proms[0], mins[0], maxs[0],
               proms[1], mins[1], maxs[1],
               proms[2], mins[2], maxs[2],
               sum_e / cal_t);
    }

     // Cálculos del bloque de asignaturas: promedio, aprobados y reprobados
    printf("\n%-15s %-15s %-15s %-15s\n", "Asignatura", "Promedio", "Aprobados", "Reprobados");
    printf("----------------------------------------------\n");

    for (int j=0; j<3; j++) {
        float sum_total=0;
        int ap=0, rp=0;
        for (int i=0; i<5; i++) {
            float sum_a=0;
            for (int k=0; k<3; k++) {
                sum_a+=cal[i][j][k];
            }
            float prom_a=sum_a/3;
            sum_total+=prom_a;
            if (prom_a >= 6.0) {
                ap++;
            } else {
                rp++;
            }
        }
        // Mostrar el promedio y el número de aprobados y reprobados por asignatura
        printf("%-15s %-15.2f %-15d %-15d\n", asi[j], sum_total / 5, ap, rp);
    }

    return 0;
}



