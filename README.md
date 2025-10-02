# Tarea 2: Ordenamiento de Orden Lineal

## TODO

- [X] **Cargar `Data Set`.**
- [X] **Implementar Lista Enlazada:**
    - Debe ser una lista enlazada simple.
    - La inserción debe tener un costo de O(1).
    - Debe almacenar la posición de los códigos, no los valores.

- [X] **Implementar Algoritmos de Ordenamiento:**
    - [X] Implementar `RadixSort` usando `CountingSort` como base (seguir Algoritmo 2).
    - [X] Implementar `QuickSort`.
    - [X] Implementar `MergeSort`.

- [ ] **Medición de Rendimiento:**
    - [X] Ejecutar cada algoritmo de ordenamiento con los 3 conjuntos de datos (`500K`, `1M`, `10M`).
    - [X] Correr cada experimento 5 veces.
    - [X] Calcular el tiempo de ejecución promedio y la desviación estándar.
    - [ ] Crear gráficos comparando rendimiento con base al dataset

- [x] **README.md:**
    - [x] Añadir los pasos para compilar y ejecutar el proyecto.

## Compilación y Ejecución

Para compilar el proyecto, simplemente ejecuta el siguiente comando:

```bash
make
```

Esto generará un ejecutable en la carpeta `build/`.

Para compilar y ejecutar el proyecto, puedes usar:

```bash
make run
```

Si deseas limpiar los archivos de compilación, puedes usar:

```bash
make clean
```
