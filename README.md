# cpp-carlos

Repositorio de ejercicios de C++ para estudiantes de Ingeniería Informática en la UCAB

## Descripción

Este repositorio contiene una colección de ejercicios prácticos en C++ diseñados específicamente para estudiantes de Ingeniería Informática. El objetivo es fomentar el aprendizaje práctico de la programación en C++ a través de ejemplos concretos y aplicaciones reales, promoviendo una educación sólida en conceptos fundamentales de la programación orientada a objetos, manejo de datos y desarrollo de software.

## Estructura del Repositorio

### Archivos Principales

- **`calculadora.cpp`**: Una calculadora básica que implementa operaciones aritméticas simples (suma, resta, multiplicación y división). Este ejercicio introduce conceptos básicos como:
  - Entrada y salida de datos (`cin` y `cout`)
  - Estructuras de control (`if-else`, `while`)
  - Manejo de errores básicos (división por cero)
  - Funciones del sistema para limpiar la pantalla

- **`inventario.cpp`**: Un sistema de gestión de inventario que demuestra el uso de estructuras de datos avanzadas. Incluye funcionalidades para:
  - Agregar productos al inventario
  - Eliminar productos
  - Mostrar el inventario completo
  - Actualizar información de productos
  - Uso de mapas anidados (`std::map`) y tipos genéricos (`std::any`)
  - Validación de entrada de usuario
  - Manejo de memoria y estructuras de datos complejas

## Objetivos Educativos

Estos ejercicios están diseñados para enseñar:

1. **Sintaxis Básica de C++**: Variables, tipos de datos, operadores y expresiones
2. **Estructuras de Control**: Bucles, condicionales y manejo de flujo de programa
3. **Funciones**: Definición, parámetros y retorno de valores
4. **Entrada/Salida**: Interacción con el usuario a través de la consola
5. **Manejo de Errores**: Validación de entrada y manejo de casos excepcionales
6. **Estructuras de Datos**: Uso de contenedores de la STL (Standard Template Library)
7. **Programación Modular**: Separación de lógica en funciones y archivos
8. **Buenas Prácticas**: Comentarios, indentación y legibilidad del código

## Requisitos del Sistema

- Compilador de C++ (g++, clang++, o MSVC)
- Sistema operativo: Windows, Linux o macOS
- Conocimientos básicos de programación (variables, bucles, funciones)

## Cómo Compilar y Ejecutar

### Opción 1: Usando g++ (recomendado para Linux/macOS)

```bash
# Para la calculadora
g++ calculadora.cpp -o calculadora
./calculadora

# Para el sistema de inventario
g++ inventario.cpp -o inventario
./inventario
```

### Opción 2: Usando MSVC (Windows)

```cmd
# Para la calculadora
cl calculadora.cpp /Fe:calculadora.exe
calculadora.exe

# Para el sistema de inventario
cl inventario.cpp /Fe:inventario.exe
inventario.exe
```

### Opción 3: Usando un IDE

Puedes abrir los archivos `.cpp` en cualquier IDE que soporte C++ como:
- Visual Studio Code con extensión C/C++
- Visual Studio
- Code::Blocks
- CLion

## Ejercicios Sugeridos

### Para Principiantes
1. Ejecuta la calculadora y observa cómo funciona
2. Modifica el código para agregar más operaciones (potencia, raíz cuadrada)
3. Agrega validación para números negativos en la división

### Para Intermedios
1. Ejecuta el sistema de inventario
2. Agrega una función para buscar productos por nombre
3. Implementa persistencia de datos (guardar/cargar desde archivo)
4. Agrega cálculo de totales (valor total del inventario)

### Para Avanzados
1. Refactoriza el código usando clases y objetos
2. Implementa un sistema de logging para las operaciones
3. Agrega pruebas unitarias usando frameworks como Google Test
4. Crea una interfaz gráfica usando Qt o similar

## Contribuciones

¡Las contribuciones son bienvenidas! Si deseas agregar más ejercicios o mejorar los existentes:

1. Fork el repositorio
2. Crea una rama para tu feature (`git checkout -b feature/nuevo-ejercicio`)
3. Commit tus cambios (`git commit -am 'Agrega nuevo ejercicio'`)
4. Push a la rama (`git push origin feature/nuevo-ejercicio`)
5. Abre un Pull Request

## Licencia

Este proyecto está bajo la Licencia MIT. Ver el archivo `LICENSE` para más detalles.

## Contacto

Para preguntas o sugerencias, puedes contactar a través de issues en este repositorio.

---

**¡Feliz aprendizaje!** Esperamos que estos ejercicios te ayuden a dominar C++ y te preparen para proyectos más complejos en Ingeniería Informática.
