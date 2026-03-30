import tkinter as tk

def validar_i(cadena, i, index):
    for j in range(len(i)):
        if index >= len(cadena) or cadena[index] != i[j]:
            return None
        index += 1
    return index

def validar_w(cadena, w, index):
    n = 0
    while cadena[index:index+len(w)] == w:
        n += 1
        index += len(w)
    if n == 0:
        return None, None
    return index, n

def validar_wi(cadena, wi, index, n):
    ni = 0
    while cadena[index:index+len(wi)] == wi:
        ni += 1
        index += len(wi)
    if ni != 2 * n:
        return None
    return index

def validar_j(cadena, j, index):
    len_j = len(j)
    for i in range(len_j):
        if index + i >= len(cadena) or cadena[index + i] != j[i]:
            return None
    for i in range(len_j):
        if index + len_j + i >= len(cadena) or cadena[index + len_j + i] != j[i]:
            return None
    return index + 2 * len_j

def validar_cadena(cadena):
    w = "gh"
    wi = "hg"
    j = "elva"
    i = "2101295"
    index = 0
    index = validar_i(cadena, i, index)
    if index is None:
        return False, "I no está al inicio"
    res = validar_w(cadena, w, index)
    if res[0] is None:
        return False, "w debe aparecer al menos una vez"
    index, n = res
    index = validar_i(cadena, i, index)
    if index is None:
        return False, "Falta la segunda I"
    index = validar_wi(cadena, wi, index, n)
    if index is None:
        return False, "w inversa no cumple 2n"
    index = validar_j(cadena, j, index)
    if index is None:
        return False, "j debe aparecer 2 veces"
    if index != len(cadena):
        return False, "Hay caracteres extra"
    return True, "Cadena válida"

def verificar():
    cadena = entrada.get()
    if cadena == "":
        resultado.config(text="Ingresa una cadena", fg="#ff5f5f")
        return
    valido, mensaje = validar_cadena(cadena)
    if valido:
        resultado.config(text="CADENA VALIDA", fg="#22c55e")
    else:
        resultado.config(text="CADENA INVALIDA\n" + mensaje, fg="#ff5f5f")

def limpiar():
    entrada.delete(0, tk.END)
    resultado.config(text="")

ventana = tk.Tk()
ventana.title("Validar Cadena a partir de una Gramatica")

ancho = ventana.winfo_screenwidth() // 2
alto = ventana.winfo_screenheight() // 2
x = (ventana.winfo_screenwidth() // 2) - (ancho // 2)
y = (ventana.winfo_screenheight() // 2) - (alto // 2)
ventana.geometry(f"{ancho}x{alto}+{x}+{y}")

ventana.configure(bg="#0f172a")

titulo = tk.Label(
    ventana,
    text="VALIDAR CADENA A PARTIR DE UNA GRAMATICA",
    font=("Segoe UI", 20, "bold"),
    bg="#0f172a",
    fg="#e2e8f0"
)
titulo.pack(pady=20)

info = tk.Label(
    ventana,
    text="G    = {I, Wⁿ, I, WI²ⁿ, J²}\nI      = 2101295\nW    = gh\nWI   = hg\nJ      = elva",
    font=("Segoe UI", 14),
    bg="#0f172a",
    fg="#94a3b8",
    justify="left",
    anchor="e"
)
info.pack(pady=5)

entrada = tk.Entry(
    ventana,
    width=35,
    font=("Segoe UI", 14),
    bg="white",
    fg="black",
    insertbackground="black",
    bd=0,
    justify="center"
)
entrada.pack(pady=25, ipady=8)

frame_botones = tk.Frame(ventana, bg="#0f172a")
frame_botones.pack()

btn_validar = tk.Button(
    frame_botones,
    text="VALIDAR",
    font=("Segoe UI", 11, "bold"),
    bg="#22c55e",
    fg="white",
    activebackground="#16a34a",
    padx=25,
    pady=10,
    bd=0,
    command=verificar
)
btn_validar.grid(row=0, column=0, padx=10)

btn_limpiar = tk.Button(
    frame_botones,
    text="LIMPIAR",
    font=("Segoe UI", 11, "bold"),
    bg="#ef4444",
    fg="white",
    activebackground="#dc2626",
    padx=25,
    pady=10,
    bd=0,
    command=limpiar
)
btn_limpiar.grid(row=0, column=1, padx=10)

resultado = tk.Label(
    ventana,
    text="",
    font=("Segoe UI", 14, "bold"),
    bg="#0f172a"
)
resultado.pack(pady=30)

ventana.mainloop()