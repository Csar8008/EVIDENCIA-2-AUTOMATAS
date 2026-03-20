# 📘 Teoría de Autómatas - Evidencia de Aprendizaje 2

Este proyecto corresponde a la **Evidencia de Aprendizaje 2** de la materia *Teoría de Autómatas* en la **Universidad Autónoma de Nuevo León (UANL)**.  
El objetivo es implementar una **gramática independiente del contexto** y un **programa computacional** que valide cadenas pertenecientes a un lenguaje específico definido por matrícula, iniciales de apellidos y nombre.

---

## 📖 Descripción del Lenguaje

El lenguaje está definido como:

\[
L = \{ i(w)^n \; i(w^{-1})^{2n} j^2 \mid n \geq 1 \}
\]

Donde:
- **i** = número de matrícula (todos los dígitos).
- **w** = iniciales de los apellidos.
- **w⁻¹** = inversa de *w*.
- **j** = primer nombre (en minúsculas, sin acentos).
- **n ≥ 1**.

### Ejemplo
Si:
- Matrícula: `0123456`
- Nombre: `yozedh`
- Apellidos: `Guerrero Ceja` → iniciales `gc`

Entonces:
- `w = gc`
- `w⁻¹ = cg`
- `i = 0123456`
- `j = yozedh`

Cadenas válidas:
```text
0123456gc0123456cgcgyozedhyozedh
0123456gcgc0123456cgcgcgcgyozedhyozedh


