#include <stdio.h>
#include <stdlib.h>
#include "17829725.c" // Altere para o nome do arquivo .c do EP

int main(){
    printf("=== SUITE COMPLETA DE TESTES ADICIONAIS - EP2 ===\n\n");

    // ==========================================
    // 1. TESTES DE CONSTRUTORES E PONTEIROS NULOS
    // ==========================================
    printf("1. Testes de Construtores e NULL Pointers em Funcoes Principais\n");
    CURSO meuCurso = novoCurso();
    if(meuCurso.numAlunos == 0 && meuCurso.numTurmas == 0) 
        printf("OK  - novoCurso() inicializado com sucesso.\n");
    else 
        printf("NOK - novoCurso() falhou na inicializacao.\n");

    ALUNO aNull = novoAluno("Nulo\0", 0);
    if(adicionarAlunoAoCurso(NULL, &meuCurso) == false && adicionarAlunoAoCurso(&aNull, NULL) == false)
        printf("OK  - adicionarAlunoAoCurso protege contra NULL pointers.\n");
    else
        printf("NOK - adicionarAlunoAoCurso falhou na protecao NULL.\n");

    TURMA tNull = novaTurma(0, "Nula\0", 0, 1, 1);
    if(adicionarTurmaAoCurso(NULL, &meuCurso) == false && adicionarTurmaAoCurso(&tNull, NULL) == false)
        printf("OK  - adicionarTurmaAoCurso protege contra NULL pointers.\n");
    else
        printf("NOK - adicionarTurmaAoCurso falhou na protecao NULL.\n");

    if(matricularAlunoEmTurma(NULL, &tNull) == false && matricularAlunoEmTurma(&aNull, NULL) == false)
        printf("OK  - matricularAlunoEmTurma protege contra NULL pointers.\n");
    else
        printf("NOK - matricularAlunoEmTurma falhou na protecao NULL.\n");

    if(cadastrarNota(NULL, 1001, 80, 80) == false)
        printf("OK  - cadastrarNota protege contra aluno NULL.\n");
    else
        printf("NOK - cadastrarNota falhou na protecao NULL.\n");

    if(retornarModaDasNotasDeAluno(NULL) == -1)
        printf("OK  - retornarModaDasNotasDeAluno protege contra aluno NULL.\n");
    else
        printf("NOK - retornarModaDasNotasDeAluno falhou na protecao NULL.\n");


    // ==========================================
    // 2. TESTES DE ADICAO AO CURSO E DUPLICIDADE
    // ==========================================
    printf("\n2. Testes de Adicao ao Curso e Duplicidade\n");
    ALUNO a1 = novoAluno("Ana Silva\0", 11111);
    ALUNO a2 = novoAluno("Bruno Souza\0", 22222);
    
    if(adicionarAlunoAoCurso(&a1, &meuCurso) == true)
        printf("OK  - Aluno 1 adicionado ao curso com sucesso.\n");
    else
        printf("NOK - Falha ao adicionar aluno 1 ao curso.\n");

    if(adicionarAlunoAoCurso(&a1, &meuCurso) == false)
        printf("OK  - Aluno duplicado no curso rejeitado corretamente.\n");
    else
        printf("NOK - Aluno duplicado aceito indevidamente no curso.\n");

    if(adicionarAlunoAoCurso(&a2, &meuCurso) == true)
        printf("OK  - Aluno 2 adicionado ao curso com sucesso.\n");
    else
        printf("NOK - Falha ao adicionar aluno 2 ao curso.\n");

    TURMA t1 = novaTurma(101, "Calculo 1\0", 2, SEGUNDA, MANHA);
    TURMA t2 = novaTurma(102, "Algebra Linear\0", 2, TERCA, MANHA);

    if(adicionarTurmaAoCurso(&t1, &meuCurso) == true && adicionarTurmaAoCurso(&t2, &meuCurso) == true)
        printf("OK  - Turmas t1 e t2 adicionadas ao curso com sucesso.\n");
    else
        printf("NOK - Falha ao adicionar turmas ao curso.\n");

    if(adicionarTurmaAoCurso(&t1, &meuCurso) == false)
        printf("OK  - Turma duplicada no curso rejeitada corretamente.\n");
    else
        printf("NOK - Turma duplicada aceita indevidamente no curso.\n");


    // ==========================================
    // 3. TESTES DE LOTACAO E DUPLICIDADE EM TURMA
    // ==========================================
    printf("\n3. Testes de Lotacao e Aluno Duplicado em Turma\n");
    TURMA tPequena = novaTurma(103, "Turma Vaga Unica\0", 1, QUARTA, MANHA);
    adicionarTurmaAoCurso(&tPequena, &meuCurso);

    if(matricularAlunoEmTurma(&a1, &tPequena) == true)
        printf("OK  - Aluno 1 matriculado na turma pequena com sucesso.\n");
    else
        printf("NOK - Falha ao matricular aluno 1 na turma pequena.\n");

    if(matricularAlunoEmTurma(&a2, &tPequena) == false)
        printf("OK  - Matricula em turma cheia rejeitada corretamente.\n");
    else
        printf("NOK - Matricula permitida em turma sem vagas.\n");

    if(matricularAlunoEmTurma(&a1, &tPequena) == false)
        printf("OK  - Aluno duplicado na mesma turma rejeitado corretamente.\n");
    else
        printf("NOK - Aluno duplicado permitido na mesma turma.\n");


    // ==========================================
    // 4. TESTES DE NOTAS E FREQUENCIAS INVALIDAS
    // ==========================================
    printf("\n4. Testes de Notas e Frequencias Invalidas\n");
    if(cadastrarNota(&a1, 103, -5, 80) == false) printf("OK  - Nota negativa rejeitada.\n");
    else printf("NOK - Nota negativa aceita indevidamente.\n");

    if(cadastrarNota(&a1, 103, 105, 80) == false) printf("OK  - Nota > 100 rejeitada.\n");
    else printf("NOK - Nota > 100 aceita indevidamente.\n");

    if(cadastrarNota(&a1, 103, 80, -10) == false) printf("OK  - Frequencia negativa rejeitada.\n");
    else printf("NOK - Frequencia negativa aceita indevidamente.\n");

    if(cadastrarNota(&a1, 103, 80, 110) == false) printf("OK  - Frequencia > 100 rejeitada.\n");
    else printf("NOK - Frequencia > 100 aceita indevidamente.\n");

    if(cadastrarNota(&a1, 999, 80, 80) == false) printf("OK  - Nota em disciplina nao matriculada rejeitada.\n");
    else printf("NOK - Nota aceita em disciplina nao matriculada.\n");

    if(cadastrarNota(&a1, 103, 75, 85) == true) printf("OK  - Nota valida cadastrada com sucesso.\n");
    else printf("NOK - Falha ao cadastrar nota valida.\n");


    // ==========================================
    // 5. TESTES DE CONFLITO DE HORARIO
    // ==========================================
    printf("\n5. Testes de Conflito de Horario\n");
    ALUNO aHorario = novoAluno("Carlos Horario\0", 33333);
    adicionarAlunoAoCurso(&aHorario, &meuCurso);

    TURMA h1 = novaTurma(201, "Mat 1\0", 5, SEXTA, TARDE);
    TURMA h2 = novaTurma(202, "Mat 2\0", 5, SEXTA, TARDE);
    adicionarTurmaAoCurso(&h1, &meuCurso);
    adicionarTurmaAoCurso(&h2, &meuCurso);

    if(matricularAlunoEmTurma(&aHorario, &h1) == true)
        printf("OK  - Primeira matricula de horario aceita.\n");
    else
        printf("NOK - Falha na primeira matricula de horario.\n");

    if(matricularAlunoEmTurma(&aHorario, &h2) == false)
        printf("OK  - Conflito de horario (mesmo dia e periodo) rejeitado corretamente.\n");
    else
        printf("NOK - Conflito de horario aceito indevidamente.\n");


    // ==========================================
    // 6. TESTES DE JUBILAMENTO E FORMATURA
    // ==========================================
    printf("\n6. Testes de Jubilamento e Formatura\n");
    ALUNO aJub = novoAluno("Daniel Jubilado\0", 44444);
    adicionarAlunoAoCurso(&aJub, &meuCurso);

    for(int i = 0; i < 14; i++){
        TURMA temp = novaTurma(3000+i, "Mat Reprova\0", 5, QUINTA, TARDE);
        adicionarTurmaAoCurso(&temp, &meuCurso);
        matricularAlunoEmTurma(&aJub, &temp);
        cadastrarNota(&aJub, 3000+i, 20, 50); // Reprova por nota e frequencia
    }
    atualizarStatusAluno(&aJub);

    if(aJub.status == 'J')
        printf("OK  - Aluno jubilado corretamente apos 14 reprovacoes (Status 'J').\n");
    else
        printf("NOK - Status incorreto para aluno jubilado: '%c'.\n", aJub.status);

    TURMA tJubTry = novaTurma(4000, "Tentativa Pos-Jubilamento\0", 5, SEGUNDA, NOITE);
    if(matricularAlunoEmTurma(&aJub, &tJubTry) == false)
        printf("OK  - Matricula de aluno jubilado bloqueada com sucesso.\n");
    else
        printf("NOK - Matricula de aluno jubilado permitida indevidamente.\n");


    // ==========================================
    // 7. TESTES DE LIMITE MAXIMO DE TURMAS (MAX_TURMAS = 18)
    // ==========================================
    printf("\n7. Testes de Limite Maximo de Turmas (MAX_TURMAS = 18)\n");
    ALUNO aMax = novoAluno("Elisa Maxima\0", 55555);
    adicionarAlunoAoCurso(&aMax, &meuCurso);

    int matriculas_ok = 0;
    TURMA turmas_max[19];
    for(int i = 0; i < 19; i++){
        int dia = (i % 5) + 1;
        int periodo = (i % 3) + 1;
        turmas_max[i] = novaTurma(5000+i, "Matricula Maxima\0", 10, dia, periodo);
        adicionarTurmaAoCurso(&turmas_max[i], &meuCurso);
    }

    for(int i = 0; i < 18; i++){
        if(matricularAlunoEmTurma(&aMax, &turmas_max[i])) {
            matriculas_ok++;
            if (i < 4) cadastrarNota(&aMax, 5000+i, 100, 100);
            else if (i < 17) cadastrarNota(&aMax, 5000+i, 0, 100);
        }
    }

    if(matriculas_ok == 18)
        printf("OK  - Exatamente 18 matriculas permitidas (teto MAX_TURMAS).\n");
    else
        printf("NOK - Apenas %d de 18 matriculas permitidas.\n", matriculas_ok);

    if(matricularAlunoEmTurma(&aMax, &turmas_max[18]) == false)
        printf("OK  - Tentativa de 19a matricula rejeitada corretamente.\n");
    else
        printf("NOK - 19a matricula permitida violando MAX_TURMAS.\n");


    // ==========================================
    // 8. TESTES DE MODA COM EMPATE (MAIOR NOTA VENCE)
    // ==========================================
    printf("\n8. Testes de Moda com Empate de Frequencia (Maior Nota Vence)\n");
    ALUNO aModa = novoAluno("Fernanda Moda\0", 66666);
    adicionarAlunoAoCurso(&aModa, &meuCurso);

    TURMA tModa1 = novaTurma(601, "M1\0", 5, SEGUNDA, MANHA);
    TURMA tModa2 = novaTurma(602, "M2\0", 5, TERCA, MANHA);
    TURMA tModa3 = novaTurma(603, "M3\0", 5, QUARTA, MANHA);
    TURMA tModa4 = novaTurma(604, "M4\0", 5, QUINTA, MANHA);

    adicionarTurmaAoCurso(&tModa1, &meuCurso);
    adicionarTurmaAoCurso(&tModa2, &meuCurso);
    adicionarTurmaAoCurso(&tModa3, &meuCurso);
    adicionarTurmaAoCurso(&tModa4, &meuCurso);

    matricularAlunoEmTurma(&aModa, &tModa1);
    matricularAlunoEmTurma(&aModa, &tModa2);
    matricularAlunoEmTurma(&aModa, &tModa3);
    matricularAlunoEmTurma(&aModa, &tModa4);

    cadastrarNota(&aModa, 601, 80, 100); // Faixa 8
    cadastrarNota(&aModa, 602, 85, 100); // Faixa 8
    cadastrarNota(&aModa, 603, 90, 100); // Faixa 9
    cadastrarNota(&aModa, 604, 95, 100); // Faixa 9

    int modaCalculada = retornarModaDasNotasDeAluno(&aModa);
    if(modaCalculada == 9)
        printf("OK  - Desempate da moda funcionou corretamente (Maior nota 9 venceu).\n");
    else
        printf("NOK - Moda retornou %d (Esperado: 9).\n", modaCalculada);

    ALUNO aSemNotas = novoAluno("Sem Notas\0", 77777);
    adicionarAlunoAoCurso(&aSemNotas, &meuCurso);
    if(retornarModaDasNotasDeAluno(&aSemNotas) == -1)
        printf("OK  - Aluno sem disciplinas concluidas retorna -1 na moda.\n");
    else
        printf("NOK - Aluno sem disciplinas concluidas retornou valor invalido na moda.\n");

    printf("\n=== FIM DOS TESTES EXAUSTIVOS ===\n");
    return 0;
}
