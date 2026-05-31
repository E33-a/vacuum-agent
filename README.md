# Vacuum Agent

Este proyecto es una simulación en C++ por consola de un "Agente Aspiradora" (Vacuum Agent) que opera dentro de un array bidimensinal. Su objetivo principal es navegar por un entorno y limpiar las casillas que se encuentran sucias.

## ¿Qué hace el programa?

1. **Generación del Entorno:**
   Al iniciar, el programa te pedirá definir el tamaño de la cuadrícula (con un mínimo de 5x5). Luego, generará aleatoriamente un espacio donde algunas baldosas estarán sucias (representadas con el número `1`) y otras limpias (representadas con el número `0`).
2. **Posición del Agente:**
   El usuario puede elegir introducir las coordenadas iniciales de la aspiradora manualmente o dejar que el sistema asigne una posición aleatoria. La aspiradora se representa visualmente con la letra `A` en la cuadrícula principal.
3. **Proceso de Limpieza:**
   En cada paso, la aspiradora limpiará automáticamente todas las casillas adyacentes (sus "vecinos") que estén sucias. El programa te mostrará cómo queda la cuadrícula después de esta acción.
4. **Interacción:**
   Si aún quedan casillas sucias en el mapa, el programa preguntará si debe seguir limpiando. Al aceptar, se podra ingresar nuevas coordenadas para mover la aspiradora a otra parte del espacio seleccionada y limpiar esa zona. El proceso se puede repetir hasta que todo el espacio quede completamente limpio (todos los valores sean `0`).
5. **Historial de Cambios:**
   A lo largo del proceso, el sistema guarda en segundo plano cada cambio individual que sufre la cuadrícula (cada vez que un `1` se convierte en un `0`). Al finalizar el programa, se imprimirá un historial completo ("Space changes") agrupado en bloques. Esto te permite visualizar paso a paso cómo la cuadrícula pasó de su estado inicial sucio a un estado final completamente limpio.

## Compilación y Ejecución

Para compilar el proyecto usando `g++`, abre una terminal en el directorio del proyecto y ejecuta:

```bash
g++ main.cpp -o agent_vacuum
```

Para ejecutar el programa recién compilado:

```bash
./agent_vacuum
```
