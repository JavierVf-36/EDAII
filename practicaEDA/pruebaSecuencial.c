#include "secuencial.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main()
{
      int i,numReg;
      FILE *f;
      tipoAlumno reg;
      char dni[10];

      numReg=leeSecuencial("alumnos.dat");
      printf("Numero de Registros: %d \n\n\n",numReg);

      // Busqueda de registros
      f=fopen("alumnos.dat","rb");
      //MODO: ESCRITURA, LECTURA O AMBAS
      /*
      ************************************************************************
      * -LEER EL CONTENIDO: r (read), b(binario)                              *
      * -SI ADEMAS DE LEER QUIEREMOS ESCRIBIR, EL MODO MAS HABITUAL SERA r+b  *
      * -EL MODO 'W' SIEMPRE REESCRIBE TODO LO QUE HAYA DENTRO                *
      * -CON W, SI EXISTE LO CREA DE 0, PERO SI NO, LO VA A BORRAR            *
      ************************************************************************
      SEEK SET:ORIGEN=INICIO DE FICHERO
      SEEK CUR:ORIGEN=NUMERO DE BYTES A PARTIR DE DONDE ESTA EN ESE INSTANTE EL CURSOR. SI EL VALOR QUE PONGO ES NEGATIVO, DESPLAZO EN EL FICHERO AL REVES
      SEEK END:ORIGEN=SIEMPRE SE UTILIZAN VALORES NEGATIVOS PARA DESPLAZARNOS EN EL FICHERO HACIA EL INICIO
      */

      strcpy(dni,"7389298"); // Registro con NRR 37
      i=buscaReg(f,&reg,dni);
      if (i<0)
      {
         printf("No existe alumno con dni %s\n",dni);   
      } 
      else 
      {
            printf("Registro con NRR %d",i);
            printf("\t %s %s %s %s %s\n\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
      }

      strcpy(dni,"123456789"); // No existe
      i=buscaReg(f,&reg,dni);
      if (i<0)
      {
            printf("\nNo existe alumno con dni %s\n",dni);
      }
      else
      { 
            printf("Registro con NRR %d",i);
            printf("\t %s %s %s %s %s\n\n",reg.dni,reg.nombre,reg.ape1,reg.ape2,reg.provincia);
      }
      fclose(f);

      //Fin de Busqueda


}

int leeSecuencial(char *fichero)
{

}

int buscaReg(FILE *fSecuencial, tipoAlumno *reg,char *dni)
{
      //FCLOSE AL CERRAR EL FICHERO
}

int insertaReg(char *fSecuencial, tipoAlumno *reg)
{
      //POSICIONARSE AL FINAL DEL FICHERO. ABRIR EL FICHERO CON APPEND Y HACER UN FWRITE DEL FICHERO
      

}




