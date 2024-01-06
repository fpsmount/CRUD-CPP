#include <stdio.h>
#include <stdlib.h>

#define max 20

int fim = 0;

typedef struct Data TipoData;
typedef struct Disciplina TipoDisc;
typedef struct Aluno TipoAluno;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Disciplina {
    char disciplina[50];
    char professor[50];
    float notas[3];  // Correção aqui
    float media;
};

struct Aluno {
    int matricula;
    char aluno[50];
    char endereco[50];
    TipoData Data;
    TipoDisc Disc;
};

TipoAluno Cadastro[max];

int menu(void), verificaLista(void);
void inicia(void), cadastrar(void);
void exibir(void), exibirAprovados(void);

int main(void) {
    cadastrar();
    exibir();
    system("pause");
    return 0;
}

int menu(void) {
    char opc[2];
    int opcao;

    fflush(stdin);

    printf("\n(1) - Cadastrar aluno\n");
    printf("(2) - Listar todos os alunos\n");
    printf("(3) - Listar alunos aprovados\n");
    printf("(4) - Buscar aluno por nome\n");
    printf("(5) - Buscar aluno por disciplina\n");
    printf("(6) - Alterar aluno \n");
    printf("(7) - Excluir aluno \n");
    printf("(8) - Sair \n");

    do {
        printf("\n>");
        fflush(stdout);
        fgets(opc, sizeof(opc), stdin);
        opcao = atoi(opc);
    } while (opcao < 0 || opcao > 8);

    return opcao;
}

void inicia(void) {
    register int i;
    for (i = 0; i < max; i++)
        Cadastro[i].aluno[0] = '\0';
}

void cadastrar(void) {
    int Cad;
    float soma = 0, media = 0;  // Correção aqui
    Cad = verificaLista();

	fflush(stdin);
	
    printf("\nDigite a matricula do aluno: ");
    fflush(stdout);
    scanf("%d", &Cadastro[Cad].matricula);

	fflush(stdin);

    printf("\nDigite o nome do aluno: ");
    fflush(stdout);
    getchar();  // Consumir o caractere de nova linha pendente
    fgets(Cadastro[Cad].aluno, sizeof(Cadastro[Cad].aluno), stdin);

	fflush(stdin);

    printf("Digite o endereço do aluno: ");
    fflush(stdout);
    fgets(Cadastro[Cad].endereco, sizeof(Cadastro[Cad].endereco), stdin);

	fflush(stdin);

    printf("\nDigite a data de nascimento do aluno (dd/mm/aaaa): ");
    fflush(stdout);
    scanf("%d %d %d", &Cadastro[Cad].Data.dia, &Cadastro[Cad].Data.mes, &Cadastro[Cad].Data.ano);

	fflush(stdin);

    printf("\nProfessor: ");
    fflush(stdout);
    getchar();  // Consumir o caractere de nova linha pendente
    fgets(Cadastro[Cad].Disc.professor, sizeof(Cadastro[Cad].Disc.professor), stdin);

	fflush(stdin);

    printf("\nDigite as 3 notas do aluno: ");
    fflush(stdout);
    scanf("%f %f %f", &Cadastro[Cad].Disc.notas[0], &Cadastro[Cad].Disc.notas[1], &Cadastro[Cad].Disc.notas[2]);

    soma = Cadastro[Cad].Disc.notas[0] + Cadastro[Cad].Disc.notas[1] + Cadastro[Cad].Disc.notas[2];

    Cadastro[Cad].Disc.media = soma / 3;

    fim++;
}

int verificaLista(void) {
    register int t;
    for (t = 0; t < fim && t < max; ++t);
    if (t == 0)
        return -1;
    return t;
}

void exibir(void) {
    int i;

    if (fim == 0) {
        printf("\nNão existe nenhum cadastro no momento!\n");
        return;
    } else {
        for (i = 0; i < fim; ++i) {
            printf("\nMatricula: %d", Cadastro[i].matricula);
            printf("\nNome: %s", Cadastro[i].aluno);
            printf("\nEndereço: %s", Cadastro[i].endereco);
            printf("\nData de nascimento (dd/mm/aaaa): %d %d %d", Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano);
            printf("\nDisciplina: %s", Cadastro[i].Disc.disciplina);
            printf("\nProfessor: %s", Cadastro[i].Disc.professor);
            printf("\nNotas: %.1f, %.1f, %.1f", Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2]);
            printf("\nEndereco de exclusao e alteracao: %d\n", i);
        }
        printf("\nTotal de alunos cadastrados: %d\n", fim);
    }
}

void exibirAprovados(void) {
    register int i;
    int cont = 0;

    if (fim == 0) {
        printf("\nNão existe nenhum aluno cadastrado no momento!\n");
        return;
    } else {
        printf("\nAlunos Aprovados!\n");
        for (i = 0; i < fim; i++) {
            if (Cadastro[i].aluno[0] && Cadastro[i].Disc.media >= 7) {
                printf("\nMatricula: %d", Cadastro[i].matricula);
                printf("\nNome: %s", Cadastro[i].aluno);
                printf("\nEndereco: %s", Cadastro[i].endereco);
                printf("\nData de Nascimento %d/%d/%d", Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano);
                printf("\nDisciplina: %s", Cadastro[i].Disc.disciplina);
                printf("\nProfessor: %s", Cadastro[i].Disc.professor);
                printf("\nNotas: %.1f, %.1f, %.1f", Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2]);
                printf("\nMédia: %.1f", Cadastro[i].Disc.media);
                printf("\nEndereco de exclusao e alteracao: %d\n", i);
                cont++;
            }
        }
    }
    if (cont == 0) {
        printf("\nNão existe aluno aprovado no momento!\n");
        return;
    }
}

