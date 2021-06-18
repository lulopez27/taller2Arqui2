# ReadMe para códigos seriales y paralelos
Conjunto a este documento deben haber 4 códigos en C. saxpy.c, saxpy_loop.c, const_e.c & const_e_loop.c
Los primeros dos se refieren al algoritmo SAXPY, que es usualemente utilizado con tarjetas gráficas.
Los otros dos son formas de calcular la constante "e".
Estos se crearon con el proposite de hacer benhmark para comparar un código serail y uno paralelo utilizando OpenMP.

### Pre-requisitos 📋
Estos códigos no utilizan bibliotecas externas a C. Se compilaron y ejecutaron estos códigos en un ambiente de Linux (LinuxMint). Para compular se utilizó GCC.
### Bibliotecas utilizadas 🔩
stdio.h
stdlib.h
omp.h
Todas vienen por defecto en GCC.
## Despliegue 📦
Para compilar se debe utilizar la bandera de OpenMP, para GCC es -fopemp. Por ejemplo para saxpy.c:
gcc -fopenmp saxpy.c -o saxpy.
Para ejecutar el código se debe de correr de formar:
./saxpy

Este código define ciertas variables como globales, para permitir que se edite facilmente. En saxpy.c y su homólogo con hilos existe la variable array_size. Entre más grande su tamaño más tardará en ejecutarse. 


RECORDAR: después de editar un archivo, se debe guardar y compilar, de otra manera no se va a reflejar el cambio.
## Construido con 🛠️
Las herramientas utilizadas para el desarrollo de este proyecto son:

* VisualStudioCode

## Autor ✒️
* **Luis Daniel López Salas** - *Estudiante* - [lulopez27](https://github.com/lulopez27)





