import numpy as np
import copy

class JogoDamas:
    """Classe que implementa a lógica do jogo de damas.

    Atributos:
        tabuleiro: Matriz 8x8 que representa o estado do jogo, onde:
            0 = casa vazia
            1 = peça branca normal
            2 = dama branca
            -1 = peça preta normal
            -2 = dama preta
    """

    def __init__(self):
        """Inicializa o jogo com o tabuleiro na configuração padrão."""
        self.tabuleiro = self._criar_tabuleiro_inicial()

    def definir_tabuleiro(self, pecas_pretas, pecas_brancas, damas_pretas=None, damas_brancas=None):
        """Configura um tabuleiro personalizado com as peças especificadas.

        A função recebe:
            pecas_pretas: Lista de tuplas (linha, coluna) para peças pretas normais
            pecas_brancas: Lista de tuplas (linha, coluna) para peças brancas normais
            damas_pretas: Lista de tuplas (linha, coluna) para damas pretas (opcional)
            damas_brancas: Lista de tuplas (linha, coluna) para damas brancas (opcional)
        """
        self.tabuleiro = np.zeros((8, 8), dtype=int)
        for peca in pecas_pretas:
            i, j = peca
            if self._eh_dentro_tabuleiro(i, j):
                self.tabuleiro[i][j] = -1
        for peca in pecas_brancas:
            i, j = peca
            if self._eh_dentro_tabuleiro(i, j):
                self.tabuleiro[i][j] = 1
        for dama in damas_pretas or []:
            i, j = dama
            if self._eh_dentro_tabuleiro(i, j):
                self.tabuleiro[i][j] = -2
        for dama in damas_brancas or []:
            i, j = dama
            if self._eh_dentro_tabuleiro(i, j):
                self.tabuleiro[i][j] = 2

    def _criar_tabuleiro_inicial(self):
        """Cria a configuração inicial padrão do tabuleiro de damas.

        A função devolve:
            Matriz 8x8 com as peças posicionadas nas casas escuras das 3 primeiras
            e 3 últimas linhas.
        """
        tabuleiro = np.zeros((8, 8), dtype=int)
        for i in range(3):
            for j in range(8):
                if (i + j) % 2 == 1:
                    tabuleiro[i][j] = -1  # peças pretas
        for i in range(5, 8):
            for j in range(8):
                if (i + j) % 2 == 1:
                    tabuleiro[i][j] = 1  # peças brancas
        return tabuleiro

    def _eh_dentro_tabuleiro(self, linha, coluna):
        """Verifica se uma posição está dentro dos limites do tabuleiro.

        A função recebe:
            linha: Índice da linha (0 a 7)
            coluna: Índice da coluna (0 a 7)

        e devolve:
            True se a posição é válida, False caso contrário.
        """
        return 0 <= linha < 8 and 0 <= coluna < 8

    def _movimentos_direcao(self, linha, coluna, jogador):
        """Determina as direções possíveis de movimento para uma peça.

        A função recebe:
            linha: Linha atual da peça
            coluna: Coluna atual da peça
            jogador: 1 para brancas, -1 para pretas

        e devolve:
            Lista de tuplas (delta_linha, delta_coluna) com as direções possíveis.
        """
        direcoes = [(-1, -1), (-1, 1)] if jogador == 1 else [(1, -1), (1, 1)]
        if abs(self.tabuleiro[linha, coluna]) == 2:  # dama
            direcoes += [(-d[0], -d[1]) for d in direcoes]
        return direcoes

    def _pode_capturar(self, linha, coluna, d_linha, d_coluna, jogador):
        """Verifica se uma peça pode capturar outra na direção especificada.

        A função recebe:
            linha: Linha atual da peça
            coluna: Coluna atual da peça
            d_linha: Direção vertical do movimento
            d_coluna: Direção horizontal do movimento
            jogador: 1 para brancas, -1 para pretas

        e devolve:
            True se a captura é possível, False caso contrário.
        """
        mid_linha, mid_coluna = linha + d_linha, coluna + d_coluna
        fim_linha, fim_coluna = linha + 2 * d_linha, coluna + 2 * d_coluna
        if not self._eh_dentro_tabuleiro(fim_linha, fim_coluna):
            return False
        meio = self.tabuleiro[mid_linha, mid_coluna]
        destino = self.tabuleiro[fim_linha, fim_coluna]
        return meio != 0 and np.sign(meio) != jogador and destino == 0

    def gerar_movimentos(self, jogador):
        """Gera todos os movimentos válidos para o jogador especificado.

        Prioriza movimentos de captura (obrigatórios nas regras das damas).

        A função recebe:
            jogador: 1 para brancas, -1 para pretas

        e devolve um generator (Yields):
            Tuplas ((linha_origem, coluna_origem), (linha_destino, coluna_destino),
                   (linha_captura, coluna_captura)) para cada movimento possível.
                   O terceiro elemento é None para movimentos sem captura.
        """
        jogador_sinal = 1 if jogador == 1 else -1
        capturas_encontradas = False

        # Primeiro verifica capturas obrigatórias
        for linha in range(8):
            for coluna in range(8):
                peca = self.tabuleiro[linha, coluna]
                if np.sign(peca) != jogador_sinal:
                    continue
                for d in self._movimentos_direcao(linha, coluna, jogador_sinal):
                    if self._pode_capturar(linha, coluna, *d, jogador_sinal):
                        fim = (linha + 2*d[0], coluna + 2*d[1])
                        captura = (linha + d[0], coluna + d[1])
                        yield ((linha, coluna), fim, captura)
                        capturas_encontradas = True

        # Se houver capturas, não gera movimentos simples
        if capturas_encontradas:
            return

        # Movimentos simples sem captura
        for linha in range(8):
            for coluna in range(8):
                peca = self.tabuleiro[linha, coluna]
                if np.sign(peca) != jogador_sinal:
                    continue
                for d_linha, d_coluna in self._movimentos_direcao(linha, coluna, jogador_sinal):
                    nova_linha = linha + d_linha
                    nova_coluna = coluna + d_coluna
                    if self._eh_dentro_tabuleiro(nova_linha, nova_coluna) and self.tabuleiro[nova_linha, nova_coluna] == 0:
                        yield ((linha, coluna), (nova_linha, nova_coluna), None)

    def movimentar(self, movimento, jogador):
        """Executa um movimento e retorna um novo estado do jogo.

        A função recebe:
            movimento: Tupla ((origem), (destino), (captura))
            jogador: 1 para brancas, -1 para pretas

        e devolve:
            Nova instância de JogoDamas com o estado atualizado.
        """
        novo_jogo = copy.deepcopy(self)
        (origem, destino, captura) = movimento
        o_linha, o_coluna = origem
        d_linha, d_coluna = destino

        # Move a peça
        peca = novo_jogo.tabuleiro[o_linha, o_coluna]
        novo_jogo.tabuleiro[o_linha, o_coluna] = 0
        novo_jogo.tabuleiro[d_linha, d_coluna] = peca

        # Remove peça capturada se houver
        if captura:
            c_linha, c_coluna = captura
            novo_jogo.tabuleiro[c_linha, c_coluna] = 0

        # Promoção a dama
        if jogador == 1 and d_linha == 0 and abs(peca) == 1:
            novo_jogo.tabuleiro[d_linha, d_coluna] = 2
        elif jogador == -1 and d_linha == 7 and abs(peca) == 1:
            novo_jogo.tabuleiro[d_linha, d_coluna] = -2

        return novo_jogo

    def mostrar(self):
        """Exibe o tabuleiro atual no console com representação visual."""
        simbolos = {
            0: ".",
            1: "○", 2: "♔",
            -1: "●", -2: "♚"
        }
        print("\n   " + " ".join(map(str, range(8))))
        for i, linha in enumerate(self.tabuleiro):
            print(f"{i}  " + " ".join(simbolos[v] for v in linha))
        print()

    def terminou(self):
        """Verifica se o jogo terminou.

        A função devolve:
            True se não houver movimentos válidos para algum jogador, False caso contrário.
        """
        return not any(self.gerar_movimentos(1)) or not any(self.gerar_movimentos(-1))

    def ganhador(self):
        """Determina o vencedor do jogo.

        A função devolve:
            1 se as brancas venceram, -1 se as pretas venceram, 0 se empate ou jogo em andamento.
        """
        if not any(self.gerar_movimentos(1)):
            return -1
        if not any(self.gerar_movimentos(-1)):
            return 1
        return 0

    def avaliar(self):
        """Avalia o estado atual do jogo com uma função heurística de análise material.

        A função devolve:
            Valor numérico onde positivo favorece as brancas e negativo as pretas.
            Peças normais valem ±1 e damas valem ±3.
        """
        peso = {1: 1, 2: 3, -1: -1, -2: -3, 0: 0}
        return np.sum([peso[peca] for peca in self.tabuleiro.flatten()])
    
    def avaliar_avancada(self):
        valor = 0
        for i in range(8):
            for j in range(8):
                peca = self.tabuleiro[i, j]
                if peca == 0:
                    continue
            
                # Valor base (como na heurística original)
                if abs(peca) == 1:
                    valor += peca * 1  # Peça normal: ±1
                else:
                    valor += peca * 3  # Dama: ±3
            
                # Bônus por posição (centro é mais valioso)
                if (i + j) % 2 == 1:  # Apenas casas escuras
                    if 2 <= i <= 5 and 2 <= j <= 5:
                        valor += 0.2 * peca  # Bônus para peças no centro
            
                # Bônus por proteção (peças na borda são mais seguras)
                if i == 0 or i == 7 or j == 0 or j == 7:
                    valor += 0.1 * peca
            
                # Bônus por potencial de promoção (peças perto da última linha)
                if peca == 1 and i <= 2:  # Peça branca perto de virar dama
                    valor += 0.3
                elif peca == -1 and i >= 5:  # Peça preta perto de virar dama
                    valor -= 0.3
        return valor
    
    def avaliar_posicional(self):
        """Heurística que considera mobilidade e controle de centro"""
        valor = 0
        mobilidade_brancas = len(list(self.gerar_movimentos(1)))
        mobilidade_pretas = len(list(self.gerar_movimentos(-1)))
        valor += 0.1 * (mobilidade_brancas - mobilidade_pretas)
        
        centro = [(i,j) for i in range(3,5) for j in range(3,5) if (i+j)%2==1]
        for i,j in centro:
            peca = self.tabuleiro[i,j]
            if peca != 0:
                valor += 0.2 * peca/abs(peca)
        return valor + self.avaliar()

def alternar_jogador(jogador):
    """Alterna entre jogador 1 e -1"""
    return -1 if jogador == 1 else 1

def minimax_alpha_beta(jogo, profundidade, jogador_atual, alpha, beta, computador):
    """Algoritmo minimax com poda alpha-beta"""
    if  jogo.terminou() or profundidade == 0:
        return jogo.avaliar(), None

    melhor_mov = None

    if jogador_atual == computador:  # Maximizar
        melhor_valor = -float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)

            valor, _ = minimax_alpha_beta(novo_jogo, profundidade - 1,
                                           alternar_jogador(jogador_atual), alpha, beta, computador)
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

            valor, _ = minimax_alpha_beta(novo_jogo, profundidade - 1,
                                           alternar_jogador(jogador_atual), alpha, beta, computador)
            if valor < melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            beta = min(beta, melhor_valor)
            if beta <= alpha:  # Poda
                break

    return melhor_valor, melhor_mov
    
def main():
    #jogo = JogoDamas()

    #print("=== JOGO DE DAMAS ===")
    #print("Jogador 1: ● (peças pretas)")
    #print("Jogador 2: ○ (peças brancas)")
    #print("Damas: ♛ (jogador 1) e ♕ (jogador 2)")
    #print()

    #jogo.mostrar()

    # Exemplo de movimentos
    #print("Movimentos disponíveis para o Jogador 1:")
    #movimentos = list(jogo.gerar_movimentos(1))
    #for i, mov in enumerate(movimentos):
        #print(mov)
        #print(f"{i+1}: De ({mov[0]}) para ({mov[1]}) com captura ({mov[2]!=None})")

    #print("\nExecutando movimento: (5,0) para (4,1)")
    #jogo = jogo.movimentar(movimentos[0], 1)

    #print("\nTabuleiro após movimento:")
    #jogo.mostrar()

    #print("Movimentos disponíveis para o Jogador 2:")
    #movimentos = jogo.gerar_movimentos(2)
    #for i, mov in enumerate(movimentos):
        #print(f"{i+1}: De ({mov[0]}) para ({mov[1]}) com captura ({mov[2]!=None})")

    jogo = JogoDamas()
   # print("Avaliação:", jogo.avaliar())
   # pecas_pretas = [(2,2), (3,3), (2,4)]
    #pecas_brancas = [(4,2), (5,3), (4,4)]
    #jogo.definir_tabuleiro(pecas_pretas, pecas_brancas)
    #jogo.mostrar()
    #print("Avaliação:", jogo.avaliar())
    #print("Avaliação avançada:", jogo.avaliar_avancada())

    #print("=== TESTE DE HEURÍSTICAS ===")
    #testar_heuristicas()
    
    #print("\n=== TESTE DE PROFUNDIDADES ===")
    #testar_profundidades()

    jogo = JogoDamas()
    
    computador1 = -1
    computador2 = 1
    jogador_atual = computador1
    profundidade = 5

    print("=== JOGO DE DAMAS ===")
    print("Jogador 1: ● (peças pretas)")
    print("Jogador 2: ○ (peças brancas)")
    print("Damas: ♛ (jogador 1) e ♕ (jogador 2)")
    print("Computador 1= ", computador1)
    print("Computador 2= ", computador2)
    jogo.mostrar()

    while not jogo.terminou():

        movimento = None 

        print("Turno do Computador 1 ", jogador_atual == computador1) if jogador_atual == computador1 else print("Turno do Computador 2 ", jogador_atual == computador2)
        if jogador_atual == computador1 or jogador_atual == computador2:
            print("Computador pensando...")

            _, movimento = minimax_alpha_beta(jogo, profundidade=profundidade, jogador_atual=jogador_atual, alpha=-float('inf'), beta=float('inf'), computador=computador1 if jogador_atual == computador1 else computador2)
        else:
            movimentos = list(jogo.gerar_movimentos(jogador_atual))
            if not movimentos:
                break

            movimento_valido = False
            while not movimento_valido:
                try:
                    mov = int(input(f"\nEscolha um movimento: {', '.join(f'{i}: {v}' for i, v in enumerate(movimentos))} (informe o índice): "))
                    if mov in range(len(movimentos)):
                        movimento = movimentos[mov]
                        movimento_valido = True
                    else:
                        print("Escolha um índice válido!")
                except ValueError:
                    print("Entrada inválida! Digite um número.")

        if movimento is None:
            break

        jogo = jogo.movimentar(movimento, jogador_atual)  # Usar jogador_atual em vez da expressão complexa
        jogo.mostrar()
        jogador_atual = alternar_jogador(jogador_atual)

    print("Fim do jogo!")
    print("Avaliação:", jogo.avaliar())
    print("Avaliação avançada:", f"{jogo.avaliar_avancada():.2f}")
    print("Avaliação posicional:", f"{jogo.avaliar_posicional():.2f}")

    # Verifica fim do jogo
    resultado = jogo.ganhador()
    if resultado != 0:
        jogo.mostrar()
        print("\n" + "="*20)
        print("   FIM DO JOGO!")
        print("="*20)

        if resultado == -2:
            print("Empate!")
        elif resultado == computador1:
            print("Computador 1 ganhou!")
        elif resultado == computador2:
            print("Computador 2 ganhou!")
        else:
            print("Você ganhou!")

if __name__ == "__main__":
    main()
