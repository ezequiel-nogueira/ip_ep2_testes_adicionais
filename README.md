para funcionar:

-- colocar o script de testes adicionais no mesmo diretorio do ep;
-- incluir o nome do seu ep na linha 3;
-- comentar a funcao main do seu ep;

compilar os testes:

gcc -Wall -g testes_adicionais.c testes_adicionais

rodar:

./testes_adicionais > testes_adicionais_saida_meu.txt

comparar:

diff testes_adicionais_saida.txt testes_adicionais_saida_meu.txt

se sair limpo tudo certo. 



