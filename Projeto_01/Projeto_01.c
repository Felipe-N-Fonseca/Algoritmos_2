#include <ctype.h>
#include <locale.h> // biblioteca para a interpretação dos caracteres brasileiros
#include <stdbool.h> //biblioteca usada para usar valores booleanos no acerto e erro
#include <stdio.h>  //biblioteca do C
#include <stdlib.h> //biblioteca para auxilar com funcoes extras
#include <string.h> //biblioteca para manipular strings
#include <time.h>   //biblioteca usada para gerar a palavra aleatoria com rand
#include <unistd.h> //essa biblioteca sera usada somente para a funcao sleep() que da ao usuario um carregamento do jogo

int ler_tamanho(
    FILE *arq_palavras) {  // essa funcao sera responsavel por calcular a
                           // quantidade de palavras do arquivo para definifir o
                           // tamanho do vetor
  int tamanho = 0;         // contador de tamanho
  char tamanho_palavra[7]; // somente palavras com 5 caracteres
  while (fgets(tamanho_palavra, 7, arq_palavras) !=
         NULL) { // nesse while ele ira ler o arquivo se não for vazio e dentro
                 // há um laÃço
    if (strlen(tamanho_palavra) == 6 &&
        tamanho_palavra[5] == '\n') { // esse laço percorre as palavras do
                                      // arquivo e verifica se tem 5 letras
      tamanho++; // caso haja ele adicionara a tamanho para que seja definido o
                 // tamanho do vetor de palavras com 5 letras futuramente
    }
  }
  return tamanho; // retorno inteiro com o tamanho total das palavras, assim o
                  // tempo está otimizado para ele achar todas palavras de 5
                  // letras
}

int nmr_aleatorio(
    int limitacao_tamanho) { // essa funcao gera o numero aleatorio, perceba que
                             // ele recebe de parametro...
  int nmr_gerado; // inteiro do numero   //o tamanho exato de palavras do vetor
                  // para gerar um % exatamente no limite
  srand(time(NULL)); // funcao para chamar o numero aleatorio
  nmr_gerado = rand() % limitacao_tamanho; // gera o numero até no maximo o
                                           // tamanho do ultimo vetor
  return nmr_gerado;                       // retorna o numero inteiro
}

char finder(char palavra_pc[], char palavra_user[],
            char conca[]) { // essa é a funcao que acha a posicao da palavra
  int i, j, conca_atual = 2;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) { // esse laco percorre o vetor de 5 letras
      if (toupper(palavra_pc[i]) ==
          toupper(palavra_user[i])) { // caso a palavra sorteada estiver na
                                      // posicao correta
        conca[conca_atual] = '^'; // retorna o simbolo de posicao correta
        break;
      } else if (toupper(palavra_pc[j]) ==
                 toupper(
                     palavra_user[i])) { // se estiver na palavra, porem em
                                         // outra posicao retorna o simbolo de !
        conca[conca_atual] = '!';
        break;
      } else { // caso não estiver retorna o simbolo de incorreto
        conca[conca_atual] = 'x';
      }
    }
    conca_atual += 2;
  }
  return conca; // retorna os simbolos
}

int main() {                       // funcao principal do jogo
  setlocale(LC_ALL, "Portuguese"); // define a linguagem para português

  FILE *arq_palavras;                           // declara o arquivo
  arq_palavras = fopen("sem_acentos.txt", "r"); // abre o arquivo e lê
  if (arq_palavras == NULL) {                   // se o arquivo for vazio
    printf("Erro ao tentar abrir o arquivo com as palavras!\n"); // mensagem de
                                                                 // erro
    return -1;                                                   // retorna -1
  }
  int tamanho =
      ler_tamanho(arq_palavras); // tamanho recebe como maximo a quantidade
                                 // maxima de palavras do arquivo
  arq_palavras =
      fopen("sem_acentos.txt",
            "r"); // le o arquivo novamente do 0, agora que sabemos o tamanho
  char palavras[tamanho]
               [7]; // define um vetor de palavras para guardar com tamanho
                    // maximo de palavras de 5 letras acahados em ler_tamanho()
  int index = 0; // variavel de index para futuramente entrar em um laÃ§o que
                 // mexe em vetores
  while (fgets(palavras[index], 7, arq_palavras) != NULL &&
         index < tamanho) { // funcao fgets pega as palavras do arquivo
    if (strlen(palavras[index]) == 6 &&
        palavras[index][5] ==
            '\n') { // nesse if o vetor palavras[index] esta recebendo todas as
                    // palavras com 5 letras
      index++; // adiciona +1 ao index para que laco chege ate o final do vetor
    }
  }                     // fim do laco
  fclose(arq_palavras); // fecha o arquivo, agora temos todas as palavras
                        // gravadas no vetor
  int plvr_escolhida = nmr_aleatorio(
      tamanho); // plvr_escolhida recebe um inteiro de nmr_aleatorio(note que
                // ele estÃ¡ passando o tamanho para ser calculado la na funcao
                // até onde ele pode gerar)
  printf(
      "Bem vindo ao Wordle!, para iniciar aperte Enter"); // essa é a interface
                                                          // que o usario ira
                                                          // visualizar
  char confirmacao;          // variavel de controle para salvar o enter dado
  scanf("%c", &confirmacao); // para o enter para variavel
  printf("\nREGRAS: \n");    // regras do jogo
  printf("1. Uma palavra com cinco letras será sorteada.\n");
  printf("2. Serão dadas 6 chances para acertar a palavra.\n");
  printf("3. Se a palavra não estiver no dicionário, não sera debitado do "
         "número de tentativas restantes.\n");
  printf("\nEXEMPLO: \n"); // exemplo para usuario
  printf(
      "\t+-----------+\n\t| T U R M A |\n\t| ^ x x x ! |\n\t+-----------+\n");
  printf("\nLEGENDA: \n"); // explicacao dos icones
  printf("'^' -  Faz parte da palavra e está na posição correta.\n");
  printf("'x' -  Não faz parte da palavra.\n");
  printf("'!' -  Faz parte da palavra mas não está na posição correta.\n");
  printf("\nCaso tenha entendido, para começar o jogo aperte Enter");
  scanf("%c", &confirmacao);
  system("clear"); // apos o usuario confimar essa funcao em especifico limpa a
  system("cls"); // tela, pois o usuario entendeu todas regras e o jogo comecara
  printf("A palavra está sendo sorteada, aguarde...\n");
  sleep(3); //esse e o carregamento do jogo so para o segurar o usuario
  // durante 3 segundo, tempo razoavel
  printf(
      "A palavra sorteada foi escolhida com sucesso! Boa sorte!\n\n"); // o jogo
                                                                       // comecou!
  time_t tempo_inicial, tempo_final; // essa são as variaveis de tempo, assim
                                     // que inicar começara a contar
  time(&tempo_inicial);     // tempo inicial comecou a contar
  char tentativas[6][100];  // vetor que salva os palpites do jogador
  int i, j;                 // int para criar laço
  for (i = 0; i < 6; i++) { // esse é um laço da interface com '-'
    tentativas[i][0] = '\t';
    tentativas[i][1] = '|';
    for (j = 2; j < 13; j += 2) {
      tentativas[i][j] = ' ';
      tentativas[i][j + 1] =
          '-'; // esse laço substitui os '-' da interface toda vez que o usuario
               // coloca uma palavra nova
    }
    tentativas[i][13] = '|';
    for (j = 14; j < 99; j++) {
      tentativas[i][j] = ' ';
    }
    tentativas[i][99] = '\n';
  }
  int tentativas_restantes; // tentativas restantes do usuario
  bool acertou = false; // aqui definiremos acertou como falso pois ele nÃ£o
                        // acertou nada ainda
  char nome[] =
      "                                                  "; // string que
                                                            // receberá o nome
                                                            // posteriormente
  int tentativa_atual; // variavel que receberá a tentativa atual do jogador
  for (tentativas_restantes = 6;
       tentativas_restantes > 0;) { // ele pode tentar ate tentativas ser zerada
    printf("Tentativas restantes: %d\n",
           tentativas_restantes); // printa as chances restantes

         
    printf("\t+-----------+\n"); // essa é a interface do wordle, definida em 6
                                 // linhas com 5 letras cada, ele salva as
                                 // palavras para o jogador ver
    for (i = 0; i < 6; i++) {
      for (j = 0; j < 100; j++) {
        printf("%c", tentativas[i][j]); // esse laco printa a palavra dentro do
                                        // quadro de palavras com cada caractere
      }
    }
    printf("\t+-----------+\n"); // final da interface wordle
    char palpite[6]; // essa é a variavel que salva o palpite do jogador a cada
                     // caractere
    printf("Insira o seu palpite (5 letras minúsculas, sem acentos): ");
    scanf("%s", palpite); // manda o digitado para palpite
    bool entrada_valida =
        true; // definiremos uma entrada valida como true, se ela n atender aos
              // requisitos não descontara pontos e ele podera colocar denovo
    char palavra_temporaria[5], palpite_temporario[5];
    if (strlen(palpite) !=
        5) {                  // se a palavra por exemplo tiver mais de 5 letras
      entrada_valida = false; // esse valido se torna falso e ele futuramente
                              // precisara digitar denovo
    } else { // outro motivo tambem faz a entrada ficar invalida
      for (i = 0; i < tamanho;
           i++) { // essa funcao verifica se a palavra esta no dicionario
        for (j = 0; j < 5; j++) {
          palpite_temporario[j] = toupper(palpite[j]);
          palavra_temporaria[j] = toupper(palavras[i][j]);
        }
        entrada_valida = false; // a entrada se inicia como falsa
        if (palpite_temporario[0] == palavra_temporaria[0]) {
          if (palpite_temporario[1] == palavra_temporaria[1]) {
            if (palpite_temporario[2] == palavra_temporaria[2]) {
              if (palpite_temporario[3] == palavra_temporaria[3]) {
                if (palpite_temporario[4] == palavra_temporaria[4]) {
                  entrada_valida = true; // somente se a palavra for encontrada no dicionario, ela sera considerada verdadeira
                  break;
                }
              }
            }
          }
        }
      }
    }
    if (!entrada_valida) { // se a entrada for diferente de valida, ou seja invalida
      printf("\nEntrada inválida! Insira 5 letras minúsculas, sem acentos e que esteja no banco de dados.\n\n"); // printa mensagem de invalidez
      continue; // continua mas não desconta das tentavas do jogador entao ele terá¡ que digiar novamente
    }

    tentativa_atual =
        6 - tentativas_restantes; // essa é a funcao que subtrai as tentativas
    int t = 0;
    for (i = 3; i < 13; i += 2) {
      tentativas[tentativa_atual][i] = palpite[t];
      t++;
    }

    char conca0[] =
        "Histórico de tentativas:"; // essa é a interface dos palpites
    char conca1[] = "+-----------+";
    char conca2[] = "| 0 0 0 0 0 |";
    char conca4[] = "| 0 0 0 0 0 |";
    char conca3 = finder(palavras[plvr_escolhida], palpite, conca4); // essa é a funcao que coloca os simbolos da funcao finder

    // concatena o palpite ao lado da interface
    conca2[2] = palpite[0];
    conca2[4] = palpite[1];
    conca2[6] = palpite[2];
    conca2[8] = palpite[3];
    conca2[10] = palpite[4];

    int adicao = (tentativa_atual + 1) * 17;

    if (tentativa_atual == 0) {
      for (j = 0; j < 24; j++) {
        tentativas[0][j + adicao] = conca0[j];
      }
    }
    for (j = 0; j < 14; j++) {
      tentativas[1][j + adicao] = conca1[j];
    }
    for (j = 0; j < 14; j++) {
      tentativas[2][j + adicao] = conca2[j];
    }
    for (j = 0; j < 14; j++) {
      tentativas[3][j + adicao] = conca4[j];
    }
    for (j = 0; j < 14; j++) {
      tentativas[4][j + adicao] = conca1[j];
    }

    int c = 0;
    for (i = 0; i < 5; i++) {
      if (toupper(palavras[plvr_escolhida][i]) == toupper(palpite[i])) {
        c++;
      }
    }
    if (c == 5) {
      acertou = true; // variavel para acertou
      break;
    }
    tentativas_restantes--; // senao tira 1 da tentativa
  }                         // fim do game onde o usuario da os palpites
  time(&tempo_final); // aqui o jogo finalizou e sera marcado o tempo final
  double tempo_levado =
      difftime(tempo_final, tempo_inicial); // recebe o tempo levado na partida
  printf("+-----------------------------------------------+\n"); // placar de fim de jogo
  printf("|                 FIM DE JOGO!!!                |\n");
  printf("+-----------------------------------------------+\n");
  printf("|                                               |\n");
  if (acertou) { // se ele acertou ou seja, se acertou == true
    printf("|       Parabéns, você acertou a palavra!       |\n");
    printf("|                                               |\n"); // aqui temos formatacoes para diferentes tempos
    if (tempo_levado < 10) { // formatacao para unidade de segundos
      printf("|       Seu tempo de resposta foi de %.2fs      |\n",
             tempo_levado);
    }
    if (tempo_levado > 10 && tempo_levado < 100) { // para dezena de segundos
      printf("|       Seu tempo de resposta foi de %.2fs     |\n",
             tempo_levado);
    }
    if (tempo_levado >= 100) { // para centena de segundos
      printf("|       Seu tempo de resposta foi de %.2fs    |\n", tempo_levado);
    }
    if (tempo_levado >= 1000) { // para milhar de segundos
      printf("|       Seu tempo de resposta foi de %.2fs   |\n", tempo_levado);
    }
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");
    printf("digite seu nome: "); // solicitara o nome do usuario
    scanf("%s", nome);
    printf("+-----------------------------------------------+\n");
    printf("|                                               |\n");
    printf("| Nome: ");
    for (i = 0; i < 41; i++) { // salva o nome do usuario
      printf("%c", nome[i]);   // guarda no vetor nome
    }
    printf("|\n");
    printf("|                                               |\n");
    printf("| Número de tentativas %d                        |\n",
           tentativa_atual +
               1); // numero final de tentativas que o usuario tentou
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");
  } else { // se ele errou, mostrarÃ¡ qual palavra que foi sorteada
    printf("|Que pena, você não conseguiu acertar a palavra.|\n");
    printf("|                                               |\n");
    printf(
        "|          A palavra era: %c%c%c%c%c                 |\n", // mostra a palavra para o usuario que errou
        palavras[plvr_escolhida][0], palavras[plvr_escolhida][1],
        palavras[plvr_escolhida][2], palavras[plvr_escolhida][3],
        palavras[plvr_escolhida][4]);
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");
  }

  // area do score

  if (acertou){
    FILE *score;
    score = fopen("score.txt", "a+"); // abre o arquivo ou o cria caso não exista, e da a possibilidade de leitura
    char linha_existe[80]; // variavel para ler a linha 
    if(fgets(linha_existe, 80, score) == NULL){ // verifica se ja tem algo escrito no arquivo
     fprintf(score, "nome:                                              \t| plvra | T | Time\n");
    }
    for (i = 0; i < 50; i++) {
      fprintf(score, "%c", nome[i]); // escreve o nome
    }
    fprintf(score, "\t| "); // divisória
    for (i = 0; i < 5; i++) {
      fprintf(score, "%c", palavras[plvr_escolhida][i]); // escreve a palavra
    }
    fprintf(score, " | %d | %.2f\n", tentativa_atual + 1, tempo_levado); // escreve quantas tentativas tiveram e o tempo levado
    fclose(score); // fecha o arquivo
  }

  return 0;
}
