# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    READ.md                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hohu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 20:50:19 by hohu              #+#    #+#              #
#    Updated: 2026/02/11 20:57:41 by hohu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

*Este proyecto ha sido creado como parte del currículo de 42 por hohu.*

# get_next_line

## Descripción
**Objetivo:** Implementar una función `get_next_line(int fd)` que devuelva, en cada llamada, la siguiente línea leída desde un descriptor de archivo, incluyendo el carácter `\n` si existe. Cuando no queden más líneas (EOF) debe devolver `NULL`.

**Visión general:**
- Lee desde `fd` usando `read()` en bloques de tamaño `BUFFER_SIZE`.
- Mantiene un **stash** (buffer persistente) con datos sobrantes entre llamadas.
- Ensambla una línea completa cuando encuentra `\n` o llega a EOF.

## Instrucciones

### Requisitos
- Compilador: `cc` o `clang`
- Flags (42): `-Wall -Wextra -Werror`
- Definir `BUFFER_SIZE` al compilar (o en el tester)

### Compilación (ejemplo con main de pruebas)
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
### Ejecucion
./gnl file.txt
### limpieza
make
make clean
make fclean
make re

### Recursos

Referencias

man 2 read

man 3 malloc, man 3 free

Documentación sobre EOF y retorno de read()

### Uso de IA (obligatorio indicar)

Herramienta(s): ChatGPT

Para qué se utilizó:

Entender el comportamiento de read() (0 / -1 / >0) y casos límite (EOF, última línea sin \n).

Diseñar el flujo stash -> line + rest y revisar errores típicos (leaks, invalid reads).

Proponer estructura de README y checklist de pruebas.

Qué NO se hizo con IA (recomendado):

No se copió código final sin comprenderlo; se validó con tests y herramientas (valgrind).
