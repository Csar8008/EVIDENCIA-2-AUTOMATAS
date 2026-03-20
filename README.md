# 📘 Evidencia de Aprendizaje 2 – Teoría de Autómatas

## 📌 Descripción
Este proyecto consiste en desarrollar una **gramática independiente del contexto** y un **programa en C** capaz de validar cadenas pertenecientes a un lenguaje formal.

El programa permite:
- Ingresar una cadena
- Verificar si es válida según la gramática
- Repetir el proceso hasta que el usuario lo desee

---

## 📖 Definición del lenguaje

```
L = { i(w)^n i(wI)^(2n) j^2 | n ≥ 1 }
```

### Donde:
- `w` = iniciales de los apellidos
- `i` = todos los dígitos de la matrícula
- `wI` = `w` invertida
- `j` = primer nombre
- `n` = número entero (no se escribe en la cadena)

⚠️ Restricción: usar solo letras minúsculas sin acentos

---

## 🧠 Ejemplo

Si:
- Matrícula: `0123456`
- Nombre: `yozedh`
- Apellidos: `guerrero ceja`

Entonces:

```
w = gc
wI = cg
i = 0123456
j = yozedh
```

### ✅ Cadenas válidas:

```
0123456gc0123456cgcgyozedhyozedh
0123456gcgc0123456cgcgcgcgyozedhyozedh
```

---

## 💻 Funcionamiento del programa

El programa realiza:

1. Solicita una cadena
2. Verifica:
   - Inicio con `i`
   - Presencia de `(w)^n`
   - Segunda aparición de `i`
   - Presencia de `(wI)^(2n)`
   - Terminación en `j j`
3. Muestra si es válida o no
4. Permite repetir el proceso

---

## ▶️ Compilación y ejecución

### Compilar:
```bash

```

### Ejecutar:
```
```

---

## 🔁 Ejemplo de uso

```
Ingresa una cadena:
0123456gc0123456cgcgyozedhyozedh

Resultado: Cadena válida

¿Deseas ingresar otra cadena? (s/n):
```

---

## 🛠️ Requisitos



---

