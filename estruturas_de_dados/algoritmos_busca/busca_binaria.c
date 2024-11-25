int busca_binaria(int *vetor, int esquerda,int direita, int alvo){
    if(esquerda > direita) return -1;

    int meio = (direita + esquerda) / 2;

    if(vetor[meio] == alvo)
        return meio;

    if(esquerda == direita) return -1;

    if(vetor[meio] < alvo)
        return busca_binaria(vetor, esquerda, meio - 1, alvo);
    
    
    return busca_binaria(vetor, meio + 1, direita, alvo);
}