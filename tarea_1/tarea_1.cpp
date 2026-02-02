// tarea_1.cpp : 
// 
// Alumno: Josue Martin Garcia Venegas
// 
// Tarea 1 Programación de una solución paralela
// 
// 01/02/2026
//

#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 20

void imprimeArreglo(float* d);

int main()
{
	std::cout << "Sumando Arreglos en Paralelo! \n\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;
	}

	int pedazos = chunk;

	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
	schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
	for (int x = 0; x < mostrar; x++)
	{
		std::cout << d[x]; // Primero imprime el número

		if (x == mostrar - 1)
		{
			// Si es el último, imprime el salto de línea
			std::cout << "\n\n";
		}
		else
		{
			// Si NO es el último, imprime el guion
			std::cout << " - ";
		}
	}
}