import numpy as np
import copy
import time

class JogoDamas:
    def __init__(self):
        self.tabuleiro = self._criar_tabuleiro_inicial()

    def definir_tabuleiro(self, pecas_pretas, pecas_brancas, damas_pretas=None, damas_brancas=None):
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
        tabuleiro = np.zeros((8, 8), dtype=int)
        for i in range(3):
            for j in range(8):
                if (i + j) % 2 == 1:
                    tabuleiro[i][j] = -1
        for i in range(5, 8):
            for j in range(8):
                if (i + j) % 2 == 1:
                    tabuleiro[i][j] = 1
        return tabuleiro

    def _eh_dentro_tabuleiro(self, linha, coluna):
        return 0 <= linha < 8 and 0 <= coluna < 8

    def _movimentos_direcao(self, linha, coluna, jogador):
        direcoes = [(-1, -1), (-1, 1)] if jogador == 1 else [(1, -1), (1, 1)]
        if abs(self.tabuleiro[linha, coluna]) == 2:
            direcoes += [(-d[0], -d[1]) for d in direcoes]
        return direcoes

    def _pode_capturar(self, linha, coluna, d_linha, d_coluna, jogador):
        mid_linha, mid_coluna = linha + d_linha, coluna + d_coluna
        fim_linha, fim_coluna = linha + 2 * d_linha, coluna + 2 * d_coluna
        if not self._eh_dentro_tabuleiro(fim_linha, fim_coluna):
            return False
        meio = self.tabuleiro[mid_linha, mid_coluna]
        destino = self.tabuleiro[fim_linha, fim_coluna]
        return meio != 0 and np.sign(meio) != jogador and destino == 0

    def gerar_movimentos(self, jogador):
        jogador_sinal = 1 if jogador == 1 else -1
        capturas_encontradas = False
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
        if capturas_encontradas:
            return
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
        novo_jogo = copy.deepcopy(self)
        (origem, destino, captura) = movimento
        o_linha, o_coluna = origem
        d_linha, d_coluna = destino
        peca = novo_jogo.tabuleiro[o_linha, o_coluna]
        novo_jogo.tabuleiro[o_linha, o_coluna] = 0
        novo_jogo.tabuleiro[d_linha, d_coluna] = peca
        if captura:
            c_linha, c_coluna = captura
            novo_jogo.tabuleiro[c_linha, c_coluna] = 0
        if jogador == 1 and d_linha == 0 and abs(peca) == 1:
            novo_jogo.tabuleiro[d_linha, d_coluna] = 2
        elif jogador == -1 and d_linha == 7 and abs(peca) == 1:
            novo_jogo.tabuleiro[d_linha, d_coluna] = -2
        return novo_jogo

    def mostrar(self):
        simbolos = {0: ".", 1: "○", 2: "♔", -1: "●", -2: "♚"}
        print("\n   " + " ".join(map(str, range(8))))
        for i, linha in enumerate(self.tabuleiro):
            print(f"{i}  " + " ".join(simbolos[v] for v in linha))
        print()

    def terminou(self):
        return not any(self.gerar_movimentos(1)) or not any(self.gerar_movimentos(-1))

    def ganhador(self):

        if not any(self.gerar_movimentos(1)):
            return -1
        if not any(self.gerar_movimentos(-1)):
            return 1
        return 0

    def avaliar(self):
        peso = {1: 1, 2: 3, -1: -1, -2: -3, 0: 0}
        return np.sum([peso[peca] for peca in self.tabuleiro.flatten()])

    # Nova heurística: valoriza centro e penaliza bordas
    def avaliar_avancada(self):
        peso = {1: 1, 2: 3, -1: -1, -2: -3, 0: 0}
        valor = 0
        for i in range(8):
            for j in range(8):
                peca = self.tabuleiro[i, j]
                v = peso[peca]
                if peca != 0 and (i == 0 or i == 7 or j == 0 or j == 7):
                    v *= 0.8
                if peca != 0 and (2 <= i <= 5 and 2 <= j <= 5):
                    v *= 1.2
                valor += v
        return valor

def alternar_jogador(jogador):
    return -1 if jogador == 1 else 1

def minimax_alpha_beta(jogo, profundidade, jogador_atual, alpha, beta, computador, heuristica):
    if jogo.terminou() or profundidade == 0:
        if heuristica == 1:
            return jogo.avaliar(), None
        else:
            return jogo.avaliar_avancada(), None
    melhor_mov = None
    if jogador_atual == computador:
        melhor_valor = -float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _ = minimax_alpha_beta(novo_jogo, profundidade - 1,
                                           alternar_jogador(jogador_atual), alpha, beta, computador, heuristica)
            if valor > melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            alpha = max(alpha, melhor_valor)
            if beta <= alpha:
                break
    else:
        melhor_valor = float('inf')
        for mov in jogo.gerar_movimentos(jogador_atual):
            novo_jogo = jogo.movimentar(mov, jogador_atual)
            valor, _ = minimax_alpha_beta(novo_jogo, profundidade - 1,
                                           alternar_jogador(jogador_atual), alpha, beta, computador, heuristica)
            if valor < melhor_valor:
                melhor_valor = valor
                melhor_mov = mov
            beta = min(beta, melhor_valor)
            if beta <= alpha:
                break
    return melhor_valor, melhor_mov

if __name__ == "__main__":
    jogo = JogoDamas()
    jogador_atual = 1
    computador1 = -1   # -1 pretas
    computador2 = 1    # 1 brancas
    profundidade1 = 2  # profundidade da IA 1
    profundidade2 = 2  # profundidade da IA 2
    heuristica1 = 1   # 1 para heurística normal, 2 para avançada
    heuristica2 = 1    

    print("=== JOGO DE DAMAS IA vs IA ===")
    print("IA 1: ● (peças pretas) - Profundidade:", profundidade1)
    print("IA 2: ○ (peças brancas) - Profundidade:", profundidade2)
    print("Damas: ♚ (IA 1) e ♔ (IA 2)")
    jogo.mostrar()

    tempo_total_ia1 = 0
    tempo_total_ia2 = 0
    jogadas_ia1 = 0
    jogadas_ia2 = 0

    while not jogo.terminou():
        movimento = None
        print("Turno do Jogador ", jogador_atual)
        if jogador_atual == computador1:
            print("IA 1 pensando...")
            t0 = time.time()
            _, movimento = minimax_alpha_beta(
                jogo, profundidade=profundidade1, jogador_atual=jogador_atual,
                alpha=-float('inf'), beta=float('inf'), computador=computador1, heuristica=heuristica1)
            t1 = time.time()
            tempo_total_ia1 += (t1 - t0)
            jogadas_ia1 += 1
            
        else:
            print("IA 2 pensando...")
            t0 = time.time()
            _, movimento = minimax_alpha_beta(
                jogo, profundidade=profundidade2, jogador_atual=jogador_atual,
                alpha=-float('inf'), beta=float('inf'), computador=computador2, heuristica=heuristica2)
            t1 = time.time()
            tempo_total_ia2 += (t1 - t0)
            jogadas_ia2 += 1
            
        if movimento is None:
            break
        jogo = jogo.movimentar(movimento, jogador_atual)
        jogo.mostrar()
        jogador_atual = alternar_jogador(jogador_atual)
        

    print("Fim do jogo!")
    print("Avaliação final:", jogo.avaliar())
    print(f"Tempo total IA 1: {tempo_total_ia1:.4f}s em {jogadas_ia1} jogadas (média: {tempo_total_ia1/jogadas_ia1 if jogadas_ia1 else 0:.4f}s por jogada)")
    print(f"Tempo total IA 2: {tempo_total_ia2:.4f}s em {jogadas_ia2} jogadas (média: {tempo_total_ia2/jogadas_ia2 if jogadas_ia2 else 0:.4f}s por jogada)")

    resultado = jogo.ganhador()
    if resultado != 0:
        jogo.mostrar()
        print("\n" + "="*20)
        print("   FIM DO JOGO!")
        print("="*20)
        if resultado == -2:
            print("Empate!")
        elif resultado == computador1:
            print("IA 1 (pretas) ganhou!")
        elif resultado == computador2:
            print("IA 2 (brancas) ganhou!")
        else:
            print("Empate!")