#include <stdio.h> //biblioteca do C
#include <stdlib.h> //biblioteca para auxilar com funcoes extras
#include <string.h> //biblioteca para manipular strings
#include <time.h> //biblioteca usada para gerar a palavra aleatoria com rand
#include <stdbool.h> //biblioteca usada para usar valores booleanos no acerto e erro
#include <unistd.h> //essa biblioteca sera usada somente para a funcao sleep() que da ao usuario um carregamento do jogo
#include<locale.h> // biblioteca para a interpreta��o dos caracteres brasileiros

int ler_tamanho(FILE *arq_palavras){ //essa funcao sera responsavel por calcular a quantidade de palavras do arquivo para definifir o tamanho do vetor
    int tamanho = 0; //contador de tamanho
    char tamanho_palavra[7]; //somente palavras com 5 caracteres
    while (fgets(tamanho_palavra, 7, arq_palavras) != NULL){ //nesse while ele ira ler o arquivo se não for vazio e dentro há um laço
        if (strlen(tamanho_palavra) == 6 && tamanho_palavra[5] == '\n'){ //esse laço percorre as palavras do arquivo e verifica se tem 5 letras
            tamanho++; //caso haja ele adicionara a tamanho para que seja definido o tamanho do vetor de palavras com 5 letras futuramente
        }
    }
    return tamanho; //retorno inteiro com o tamanho total das palavras, assim o tempo está otimizado para ele achar todas palavras de 5 letras
}

int nmr_aleatorio(int limitacao_tamanho){ //essa funcao gera o numero aleatorio, perceba que ele recebe de parametro...
    int nmr_gerado; //inteiro do numero   //o tamanho exato de palavras do vetor para gerar um % exatamente no limite
    srand(time(NULL)); //funcao para chamar o numero aleatorio
    nmr_gerado = rand()%limitacao_tamanho; //gera o numero até no maximo o tamanho do ultimo vetor
    return nmr_gerado; //retorna o numero inteiro
}

int main(){ //funcao principal do jogo
	setlocale(LC_ALL, "Portuguese");// define a linguagem para portugu�s
	
    FILE *arq_palavras; //declara o arquivo
    arq_palavras = fopen("sem_acentos.txt", "r"); //abre o arquivo e le
    if(arq_palavras == NULL){ //se o arquivo for vazio
        printf("Erro ao tentar abrir o arquivo com as palavras!\n"); //mensagem de erro
        return -1; //retorna -1
    }
    int tamanho = ler_tamanho(arq_palavras); //tamanho recebe como maximo a quantidade maxima de palavras do arquivo
    arq_palavras = fopen("sem_acentos.txt", "r"); //le o arquivo novamente do 0, agora que sabemos o tamanho
    char palavras[tamanho][7]; //define um vetor de palavras para guardar com tamanho maximo de palavras de 5 letras acahados em ler_tamanho()
    int index = 0; //variavel de index para futuramente entrar em um laço que mexe em vetores
    while (fgets(palavras[index], 7, arq_palavras) != NULL && index < tamanho){ //funcao fgets pega as palavras do arquivo
        if (strlen(palavras[index]) == 6 && palavras[index][5] == '\n'){ //nesse if o vetor palavras[index] esta recebendo todas as palavras com 5 letras
            index++; //adiciona +1 ao index para que laco chege ate o final do vetor
        }
    } //fim do laco
    fclose(arq_palavras); //fecha o arquivo, agora temos todas as palavras gravadas no vetor
    int plvr_escolhida = nmr_aleatorio(tamanho); //plvr_escolhida recebe um inteiro de nmr_aleatorio(note que ele está passando o tamanho para ser calculado la na funcao até onde ele pode gerar)
    printf("Bem vindo ao Wordle!, para iniciar aperte Enter"); //essa é a interface que o usario ira visualizar
    char confirmacao; //variavel de controle para salvar o enter dado
    scanf("%c", &confirmacao); //para o enter para variavel
    printf("\nREGRAS: \n"); //regras do jogo
    printf("1. Uma palavra com cinco letras será sorteada.\n");
    printf("2. Serão dadas 6 chances para acertar a palavra.\n");
    printf("3. Se a palavra não estiver no dicionário, não sera debitado do número de tentativas restantes.\n");
    printf("\nEXEMPLO: \n"); //exemplo para usuario
    printf("\t\t+-----------+\n\t\t| T U R M A |\n\t\t| ^ x x x ! |\n\t\t+-----------+\n");
    printf("\nLEGENDA: \n"); //explicacao dos icones
    printf("'^' -  Faz parte da palavra e está na posição correta.\n");
    printf("'x' -  Não fazem parte da palavra.\n");
    printf("'!' -  Faz parte da palavra mas não está na posição correta.\n");
    printf("\nCaso tenha entendido, para começar o jogo aperte Enter");
    scanf("%c", &confirmacao);
    system("clear"); //apos o usuario confimar essa funcao em especifico limpa a tela, pois o usuario entendeu todas regras e o jogo comecara
    printf("A palavra está sendo sorteada, aguarde...\n");
    sleep(3); //esse e o carregamento do jogo so para o segurar o usuario durante 3 segundo, tempo razoavel
    printf("A palavra sorteada foi escolhida com sucesso! Boa sorte!\n\n"); //o jogo comecou!
    char tentativas[6][5]; //vetor que salva os palpites do jogador
    int i, j; //int para criar laço
    for(i=0; i<6; i++){
        for(j=0; j<5; j++){
            tentativas[i][j] = '-'; //esse laço substitui os '-' da interface toda vez que o usuario coloca uma palavra nova
        }
    }
    int tentativas_restantes = 6; //tentativas restantes do usuario
    bool acertou = false; //aqui definiremos acertou como falso pois ele não acertou nada ainda
    while(tentativas_restantes > 0 && !acertou){ //ele pode tentar ate tentativas ser zerada
        printf("Tentativas restantes: %d\n", tentativas_restantes); //printa as chances restantes
        printf("\t  +-------+\n"); // essa é a interface do wordle, definida em 6 linhas com 5 letras cada, ele salva as palavras para o jogador ver
        for(i=0; i<6; i++){
            printf("\t| ");
            for(j=0; j<5; j++){
                printf("%c ", tentativas[i][j]); //esse laco printa a palavra dentro do quadro de palavras com cada caractere
            }
            printf("|\n");
        }
        printf("\t  +-------+\n"); //final da interface wordle
        char palpite[6]; //essa é a variavel que salva o palpite do jogador a cada caractere
        printf("Insira o seu palpite (5 letras minúsculas, sem acentos): ");
        scanf("%s", palpite); //manda o digitado para palpite
        bool entrada_valida = true; //definiremos uma entrada valida como true, se ela n atender aos requisitos não descontara pontos e ele podera colocar denovo
        if (strlen(palpite) != 5){ //se a palavra por exemplo tiver mais de 5 letras
            entrada_valida = false; // esse valido se torna falso e ele futuramente precisara digitar denovo
        } 
        else{ //outro motivo tambem faz a entrada ficar invalida
            for(i=0; i<5; i++){
                if (palpite[i] < 'a' || palpite[i] > 'z'){ //se ele digiar uma palavra invalida que não está no dicionario
                    entrada_valida = false; //ela tornara a entrada invalida
                    break;
                }
            }
        }
        if (!entrada_valida){ //se a entrada for diferente de valida, ou seja invalida
            printf("Entrada inválida! Insira 5 letras minúsculas, sem acentos.\n"); //printa mensagem de invalidez
            continue; //continua mas não desconta das tentavas do jogador entao ele terá que digiar novamente
        }
        int corretos = 0, quase_corretos = 0; //FELIPE ARRUMAR ESSA É UMA VARIAVEL DE CONTROLE DE ACERTOS DAQUI PARA BAIXO ELE PRECISA INDICAR QUAL LETRA TA CERTA E QUAL POSICAO É
        for(i=0; i<5; i++){
            if (palpite[i] == palavras[plvr_escolhida][i]){
                corretos++;
            } else {
                for(j=0; j<5; j++){
                    if (palpite[i] == palavras[plvr_escolhida][j]){
                        quase_corretos++;
                        break;
                    }
                }
            }
        }
        int tentativa_atual = 6 - tentativas_restantes;
        for(i=0; i<5; i++){
            tentativas[tentativa_atual][i] = palpite[i];
        }
    printf("+-------+\n");
    printf("| ");
    for(i=0; i<5; i++){
        printf("%c ", palpite[i]);
    }
    printf("|\n");
    printf("| ^ %d   |\n", corretos);
    printf("| ! %d   |\n", quase_corretos);
    printf("+-------+\n");
    if (corretos == 5){ //se o 5 das letras forem acertadas, o usuario ganhou
        acertou = true; //acertou e verdadeiro
    } 
    else{
        tentativas_restantes--; //caso não desconta das tentativas
    }
    } //fim do game onde o usuario da os palpites
    if(acertou){ // se ele acertou ou seja, se acertou == true
        printf("Parabéns, você acertou a palavra!\n");
    }
    else{ //se ele errou, mostrará qual palavra que foi sorteada
        printf("Que pena, você não conseguiu acertar a palavra. A palavra era: %s\n", palavras[plvr_escolhida]);
    }
    printf("+-----------+\n");
    return 0;
}
