def is_str(v) -> bool:
    try:
        str(v)
        return True
    except:
        return False


def is_float(v) -> bool:
    try:
        float(v)
        return True
    except:
        return False


def is_int(v) -> bool:
    try:
        int(v)
        return True
    except:
        return False


def vinput(prompt, validator=lambda: True) -> str:
    """
    Exibe um input com comportamento parecido com a função `input()`,
    porém também valida o resultado com a ajuda de um callback function.

    :param prompt: prompt a ser exibido ao solicitar uma entrada do usuário.
    :type prompt: str
    :param validator: função que valida a entrada. Deve retornar `True` ou `False` 
    :type validator: function
    :return: valor de entrada
    :rtype: str 
    """

    value = input(prompt)
    
    if validator(value):
        return value
    else:
        print("Valor inválido")
        return vinput(prompt, validator)

