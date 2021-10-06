# MAPA
* Colocar plano de fundo
* Criar matriz M x N
* Criar função de get de posição em pixels a partir da posição na matriz
* Colocar os blocos indestrutíveis nas posições em que M e N são ambos ímpares
* Colocar X blocos destrutíveis em X posições aleatórias, tal que M ou N são pares e (M, N) != 0, 0
* Criar função de get se posição da matrix é um bloco destrutível, indestrutível, nada, ou personagem

# PERSONAGEM
* Criar personagem na posição (0, 0)
* Criar movimentos do personagem sobre a matriz, de acordo com o botão pressionado
* Renderizar personagem de acordo com sua posição na matriz, em 60fps
* Verificar se povimento é possível de acordo com o bloco na próxima posição

# BOMBAS
* Colocar bomba na mesma posição do personagem com clique do botão
* Não deixar personagem colidir com a bomba
* Criar um timer para a bomba explodir
* Criar explosão que pega E blocos de distância
* Destruir todos os primeiros blocos no caminho
* Matar personagem no caminho (se não tiver bloco antes)
* Deixar jogador colocar P bombas por vez
