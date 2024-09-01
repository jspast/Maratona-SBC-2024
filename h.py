def permutacao(num_per, posicoes, num):

    teste = 1
    bit = 1
    pos = 0

    for x in range(len(posicoes)):

        if teste & num_per:
            num = num | bit << posicoes[pos]

        teste = teste << 1

        pos += 1

    return num

if __name__ == "__main__":

    M = input()
    N = input()

    M_int = int(M.replace("*", "0"), 2)
    N_int = int(N.replace("*", "0"), 2)

    M = M[::-1]
    N = N[::-1]

    M_pos = []
    N_pos = []

    pos = -2
    while pos != -1:

        if pos == -2:
            pos = -1

        pos = M.find("*", pos + 1)

        if pos != -1:
            M_pos.append(pos)

    pos = -2
    while pos != -1:

        if pos == -2:
            pos = -1

        pos = N.find("*", pos + 1)

        if pos != -1:
            N_pos.append(pos)

    M_per = 2 ** len(M_pos)
    N_per = 2 ** len(N_pos)

    n = 0
    N_int_buf = N_int
    achou = False

    while achou == False and n < N_per:

        m = 0

        while achou == False and m < M_per:

            mensagem = permutacao(m, M_pos, M_int)

            if mensagem % N_int_buf == 0:
                achou = True
            else:
                m += 1

        n += 1

        N_int_buf = permutacao(n, N_pos, N_int)

    print(format(mensagem, 'b'))