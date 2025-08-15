import time

class JogoDamas:
    def __init__(self):
        # 8x8 board: 0 = empty, 1 = white, -1 = black, 2 = white king, -2 = black king
        self.tabuleiro = [[0 for _ in range(8)] for _ in range(8)]
        self.inicializar_tabuleiro()

    def inicializar_tabuleiro(self):
        for i in range(8):
            for j in range(8):
                if (i + j) % 2 == 1:
                    if i < 3:
                        self.tabuleiro[i][j] = -1
                    elif i > 4:
                        self.tabuleiro[i][j] = 1

    def definir_tabuleiro(self, brancas=[], damas_brancas=[], pretas=[], damas_pretas=[]):
        self.tabuleiro = [[0 for _ in range(8)] for _ in range(8)]
        for (i, j) in brancas:
            self.tabuleiro[i][j] = 1
        for (i, j) in damas_brancas:
            self.tabuleiro[i][j] = 2
        for (i, j) in pretas:
            self.tabuleiro[i][j] = -1
        for (i, j) in damas_pretas:
            self.tabuleiro[i][j] = -2
        return self

    def terminou(self):
        return not self.gerar_movimentos(1) and not self.gerar_movimentos(-1)

    def mostrar(self):
        print("  " + " ".join(str(j) for j in range(8)))
        for i, linha in enumerate(self.tabuleiro):
            print(i, end=" ")
            for p in linha:
                if p == 1:
                    print("○", end=" ")
                elif p == -1:
                    print("●", end=" ")
                elif p == 2:
                    print("♔", end=" ")
                elif p == -2:
                    print("♚", end=" ")
                else:
                    print(".", end=" ")
            print()

    def avaliar(self):
        valor = 0
        for linha in self.tabuleiro:
            for p in linha:
                if p == 1:
                    valor += 1
                elif p == 2:
                    valor += 1.5
                elif p == -1:
                    valor -= 1
                elif p == -2:
                    valor -= 1.5
        return valor

    def avaliar_avancada(self):
        valor = 0
        for i, linha in enumerate(self.tabuleiro):
            for j, p in enumerate(linha):
                if p == 1:
                    valor += 1 + (7 - i) * 0.1
                elif p == 2:
                    valor += 1.5
                elif p == -1:
                    valor -= 1 + i * 0.1
                elif p == -2:
                    valor -= 1.5
        return valor

    def avaliar_posicional(self):
        valor = 0
        for i, linha in enumerate(self.tabuleiro):
            for j, p in enumerate(linha):
                if p == 1:
                    valor += 1 + (7 - i) * 0.05 + (j in [0, 7]) * 0.1
                elif p == 2:
                    valor += 1.5
                elif p == -1:
                    valor -= 1 + i * 0.05 + (j in [0, 7]) * 0.1
                elif p == -2:
                    valor -= 1.5
        return valor

    def gerar_movimentos(self, jogador):
        movimentos = []
        capturas = []
        for i in range(8):
            for j in range(8):
                if self.tabuleiro[i][j] == jogador or self.tabuleiro[i][j] == 2 * jogador:
                    capt = self._gerar_capturas(i, j, jogador)
                    if capt:
                        capturas.extend(capt)
                    else:
                        movs = self._gerar_movimentos_simples(i, j, jogador)
                        movimentos.extend(movs)
        return capturas if capturas else movimentos

    def _gerar_movimentos_simples(self, i, j, jogador):
        movimentos = []
        direcoes = [(-1, -1), (-1, 1)] if jogador == 1 else [(1, -1), (1, 1)]
        if abs(self.tabuleiro[i][j]) == 2:
            direcoes += [(-d[0], -d[1]) for d in direcoes]
        for di, dj in direcoes:
            ni, nj = i + di, j + dj
            if 0 <= ni < 8 and 0 <= nj < 8 and self.tabuleiro[ni][nj] == 0:
                movimentos.append(((i, j), (ni, nj), False))
        return movimentos

    def _gerar_capturas(self, i, j, jogador):
        capturas = []
        direcoes = [(-1, -1), (-1, 1)] if jogador == 1 else [(1, -1), (1, 1)]
        if abs(self.tabuleiro[i][j]) == 2:
            direcoes += [(-d[0], -d[1]) for d in direcoes]
        for di, dj in direcoes:
            ni, nj = i + di, j + dj
            ci, cj = i + 2 * di, j + 2 * dj
            if (0 <= ci < 8 and 0 <= cj < 8 and
                self.tabuleiro[ni][nj] * jogador < 0 and
                self.tabuleiro[ci][cj] == 0):
                capturas.append(((i, j), (ci, cj), True))
        return capturas

    def movimentar(self, movimento, jogador):
        novo = JogoDamas()
        novo.tabuleiro = [linha[:] for linha in self.tabuleiro]
        (i1, j1), (i2, j2), captura = movimento
        peca = novo.tabuleiro[i1][j1]
        novo.tabuleiro[i1][j1] = 0
        novo.tabuleiro[i2][j2] = peca
        if captura:
            novo.tabuleiro[(i1 + i2) // 2][(j1 + j2) // 2] = 0
        # Promoção
        if jogador == 1 and i2 == 0 and peca == 1:
            novo.tabuleiro[i2][j2] = 2
        elif jogador == -1 and i2 == 7 and peca == -1:
            novo.tabuleiro[i2][j2] = -2
        return novo

    def ganhador(self):
        brancas = pretas = 0
        for linha in self.tabuleiro:
            for p in linha:
                if p > 0:
                    brancas += 1
                elif p < 0:
                    pretas += 1
        if brancas > 0 and pretas == 0:
            return 1
        elif pretas > 0 and brancas == 0:
            return -1
        elif brancas == 0 and pretas == 0:
            return 0
        else:
            return None

def alternar_jogador(jogador):
    """Alterna entre jogador 1 e -1"""
    return -1 if jogador == 1 else 1

def minimax_alpha_beta(jogo, profundidade, jogador_atual, alpha, beta, computador, nos_visitados=None):
    """Algoritmo minimax com poda alpha-beta e contagem de nós visitados"""
    if nos_visitados is None:
        nos_visitados = [0]
    nos_visitados[0] += 1

    if jogo.terminou() or profundidade == 0:
        return jogo.avaliar(), None, nos_visitados

    melhor_mov = None

    if jogador_atual == computador:  # Maximizar
        melhor_valor = -float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _, nos_visitados = minimax_alpha_beta(novo_jogo, profundidade-1, alternar_jogador(jogador_atual), 
                                      alpha, beta, computador, nos_visitados)
            if valor > melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            alpha = max(alpha, melhor_valor)
            if beta <= alpha:  # Poda
                break
    else:  # Minimizar
        melhor_valor = float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _, nos_visitados = minimax_alpha_beta(novo_jogo, profundidade-1, alternar_jogador(jogador_atual), 
                                      alpha, beta, computador, nos_visitados)
            if valor < melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            beta = min(beta, melhor_valor)
            if beta <= alpha:  # Poda
                break

    return melhor_valor, melhor_mov, nos_visitados

# Tabela de transposição para otimização
transposition_table = {}

def minimax_com_tt(jogo, profundidade, jogador_atual, alpha, beta, computador, nos_visitados=None):
    """Minimax com tabela de transposição"""
    if nos_visitados is None:
        nos_visitados = [0]
    nos_visitados[0] += 1

    # Verifica se o estado já foi calculado
    hash_key = hash(str(jogo.tabuleiro.tostring()) + str(jogador_atual))
    if hash_key in transposition_table:
        return transposition_table[hash_key] + (nos_visitados,)

    if jogo.terminou() or profundidade == 0:
        resultado = (jogo.avaliar(), None, nos_visitados)
        transposition_table[hash_key] = (jogo.avaliar(), None)
        return resultado

    melhor_mov = None

    if jogador_atual == computador:  # Maximizar
        melhor_valor = -float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _, nos_visitados = minimax_com_tt(novo_jogo, profundidade-1, alternar_jogador(jogador_atual), 
                                   alpha, beta, computador, nos_visitados)
            if valor > melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            alpha = max(alpha, melhor_valor)
            if beta <= alpha:  # Poda
                break
    else:  # Minimizar
        melhor_valor = float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _, nos_visitados = minimax_com_tt(novo_jogo, profundidade-1, alternar_jogador(jogador_atual), 
                                   alpha, beta, computador, nos_visitados)
            if valor < melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            beta = min(beta, melhor_valor)
            if beta <= alpha:  # Poda
                break

    transposition_table[hash_key] = (melhor_valor, melhor_mov)
    return melhor_valor, melhor_mov, nos_visitados

def testar_heuristicas():
    """Testa as diferentes heurísticas em cenários específicos"""
    cenarios = [
        ("Tabuleiro Inicial", lambda: JogoDamas()),
        ("Situação Bloqueada", lambda: JogoDamas().definir_tabuleiro(
            [(2,2), (3,3), (2,4)], [(4,2), (5,3), (4,4)])
        ),
        ("Final de Jogo", lambda: JogoDamas().definir_tabuleiro(
            [(1,1)], [], [(7,7)], [(0,0)])
        ),
        ("Vantagem Posicional", lambda: JogoDamas().definir_tabuleiro(
            [(2,1), (3,2)], [(5,4), (6,5)])
        )
    ]
    
    print("\n=== TESTE DE HEURÍSTICAS ===")
    for nome, setup in cenarios:
        jogo = setup()
        print(f"\n{nome}:")
        jogo.mostrar()
        print(f"Material: {jogo.avaliar():.2f}")
        print(f"Avançada: {jogo.avaliar_avancada():.2f}")
        print(f"Posicional: {jogo.avaliar_posicional():.2f}")

def testar_profundidades():
    """Testa o impacto da profundidade no desempenho"""
    jogo = JogoDamas()
    profundidades = [2, 3, 4, 5]
    
    print("\n=== TESTE DE PROFUNDIDADES ===")
    print("Sem tabela de transposição:")
    for p in profundidades:
        start_time = time.time()
        _, _, nos = minimax_alpha_beta(jogo, p, 1, -float('inf'), float('inf'), 1)
        tempo = time.time() - start_time
        print(f"Profundidade {p}: {tempo:.3f}s, Nós visitados: {nos[0]}")
    
    print("\nCom tabela de transposição:")
    for p in profundidades:
        transposition_table.clear()
        start_time = time.time()
        _, _, nos = minimax_com_tt(jogo, p, 1, -float('inf'), float('inf'), 1)
        tempo = time.time() - start_time
        print(f"Profundidade {p}: {tempo:.3f}s, Nós visitados: {nos[0]}")

def jogar_partia(profundidade1, profundidade2, usar_tt=False):
    """Simula uma partida entre duas IAs com diferentes profundidades"""
    jogo = JogoDamas()
    jogador_atual = 1
    historico = []
    
    print(f"\n=== PARTIDA IA (Prof. {profundidade1}) vs IA (Prof. {profundidade2}) ===")
    
    while not jogo.terminou():
        profundidade = profundidade1 if jogador_atual == 1 else profundidade2
        start_time = time.time()
        
        if usar_tt:
            valor, movimento, _ = minimax_com_tt(jogo, profundidade, jogador_atual, 
                                               -float('inf'), float('inf'), jogador_atual)
        else:
            valor, movimento, _ = minimax_alpha_beta(jogo, profundidade, jogador_atual, 
                                                    -float('inf'), float('inf'), jogador_atual)
        
        tempo = time.time() - start_time
        
        if movimento is None:
            break
            
        jogo = jogo.movimentar(movimento, jogador_atual)
        historico.append((jogador_atual, movimento, valor, tempo))
        jogador_atual = alternar_jogador(jogador_atual)
    
    print("\nResultado final:")
    jogo.mostrar()
    print(f"Avaliação final - Material: {jogo.avaliar()}")
    print(f"Avaliação final - Avançada: {jogo.avaliar_avancada():.2f}")
    print(f"Avaliação final - Posicional: {jogo.avaliar_posicional():.2f}")
    
    vencedor = jogo.ganhador()
    if vencedor == 1:
        print("Jogador 1 (Brancas) venceu!")
    elif vencedor == -1:
        print("Jogador 2 (Pretas) venceu!")
    else:
        print("Empate!")
    
    return historico, vencedor

def main():
    # Executa os experimentos
    testar_heuristicas()
    testar_profundidades()
    
    # Partidas IA vs IA para comparação
    print("\n=== PARTIDAS COMPARATIVAS ===")
    print("\nPartida 1: Profundidade 2 vs 3")
    jogar_partia(2, 3)
    
    print("\nPartida 2: Profundidade 3 vs 4 (com TT)")
    jogar_partia(3, 4, usar_tt=True)
    
    # Jogo interativo (opcional)
    print("\n=== MODO INTERATIVO ===")
    resposta = input("Deseja jogar contra a IA? (s/n): ")
    if resposta.lower() == 's':
        jogo_interativo()

def jogo_interativo():
    """Modo interativo para jogar contra a IA"""
    jogo = JogoDamas()
    jogador_humano = 1  # 1 para brancas, -1 para pretas
    profundidade_ia = 3
    
    print("\n=== JOGO INTERATIVO ===")
    print("Você está jogando com as peças brancas (○)")
    print("A IA está jogando com as peças pretas (●)")
    
    while not jogo.terminou():
        jogo.mostrar()
        
        if jogador_humano == 1:
            # Turno do humano
            movimentos = list(jogo.gerar_movimentos(jogador_humano))
            if not movimentos:
                print("Você não tem movimentos válidos!")
                break
                
            print("\nSeus movimentos disponíveis:")
            for i, mov in enumerate(movimentos):
                print(f"{i}: De {mov[0]} para {mov[1]}", 
                      "(captura)" if mov[2] else "")
                
            movimento = None
            movimento_valido = False
            while not movimento_valido:
                try:
                    escolha = int(input("Escolha seu movimento (índice): "))
                    if 0 <= escolha < len(movimentos):
                        movimento = movimentos[escolha]
                        movimento_valido = True
                    else:
                        print("Índice inválido!")
                except ValueError:
                    print("Digite um número válido!")
            
            if movimento is not None:
                jogo = jogo.movimentar(movimento, jogador_humano)
            else:
                print("Nenhum movimento selecionado. Turno perdido.")
        else:
            # Turno da IA
            print("\nIA pensando...")
            start_time = time.time()
            _, movimento, _ = minimax_alpha_beta(jogo, profundidade_ia, -1, 
                                               -float('inf'), float('inf'), -1)
            tempo = time.time() - start_time
            print(f"IA moveu de {movimento[0]} para {movimento[1]} (tempo: {tempo:.2f}s)")
            jogo = jogo.movimentar(movimento, -1)
            
        jogador_humano *= -1
    
    # Fim do jogo
    jogo.mostrar()
    vencedor = jogo.ganhador()
    if vencedor == 1:
        print("Você venceu!")
    elif vencedor == -1:
        print("IA venceu!")
    else:
        print("Empate!")

if __name__ == "__main__":
    main()