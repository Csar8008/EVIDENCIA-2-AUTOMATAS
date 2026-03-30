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
        print("Error: I no está al inicio")
        return False

    res = validar_w(cadena, w, index)
    if res[0] is None:
        print("Error: w debe aparecer al menos una vez")
        return False
    index, n = res

    index = validar_i(cadena, i, index)
    if index is None:
        print("Error: falta la segunda I")
        return False

    index = validar_wi(cadena, wi, index, n)
    if index is None:
        print("Error: w inversa no cumple 2n")
        return False

    index = validar_j(cadena, j, index)
    if index is None:
        print("Error: j debe aparecer 2 veces")
        return False
    if index != len(cadena):
        print("Error: hay caracteres extra")
        return False

    return True

def mostrar_datos():
    print("\nVALIDAR UNA CADENA A PARTIR DE UNA GRAMATICA (GIC)")
    print("\ngramatica: G = {I, W^n, I, WI^2n, J^2 | n >= 1}")
    print("I = 2101295")
    print("W = gh")
    print("WI = hg")
    print("J = elva")

def leer_opcion():
    while True:
        try:
            valor = int(input("-> "))
            if valor in (1, 2):
                return valor
            else:
                print("Ingrese una opción válida")
        except:
            print("Ingrese un número válido")

opc = 1
while opc == 1:
    print("\n" * 3)
    mostrar_datos()

    cadena = input("\nINGRESE UNA CADENA:\n")

    if cadena == "":
        print("\nCadena inválida (vacía)")
    else:
        if validar_cadena(cadena):
            print("\nLA CADENA ES VALIDA PARA ESTA GRAMATICA")
        else:
            print("\nLA CADENA NO ES VALIDA PARA ESTA GRAMATICA")

    print("\nDesea ingresar otra cadena?")
    print("1 - SI")
    print("2 - NO")

    opc = leer_opcion()