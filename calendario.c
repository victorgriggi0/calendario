#include <stdio.h>

int anoBissexto(int ano); // Aqui, se tornará verdadeiro quando o ano for bissexto.
int seAnoBissexto(int ano); // Se o ano não for divisível por 4, ou por 100 e nem 400, ele será considerado um ano bissexto.
int atualmente(int a, int m, int d); // Número de dias corridos desde o início do ano.
// Caso fique alguma duvida a respeito das abreviações usadas, segue abaixo o que cada uma simboliza:
// a = ano (s)
// m = mês (es)
// d = dia (s)

long dias(int a, int m, int d); // Número total de dias.
void calendario(int a, int m); // Formato do calendário no modelo mês / ano.

int main(void){

    int ano,mes;

    printf("Oi :) Eu sou um programa de calendario, onde darei o calendario do respectivo mes de determinado ano que voce desejar consultar!\n\n");
    printf("Antes de digitar o mes e o ano, vou ressaltar que ambos precisam ser em formato numerico, combinado? Por exemplo, 08 2002\n");
    printf("Sabendo disso, digite agora o mes e o ano no qual deseja consultar: ");
        scanf("%d %d", &mes, &ano);
            if(ano >= 1900 && mes >= 1 && mes <= 12 && ano <= 2999){ // Condição dada para que o calendário apresente datas entre Janeiro de 1900 até Dezembro de 2999 e utilize meses que existem atualmente.
                calendario(ano, mes);
            }
                else{
                    printf("Hmmm, vamos fazer o seguinte. Iremos usar datas entre Janeiro de 1900 até Dezembro de 2999, e usar somente meses já existam, combinado? :)\n");
                        return 0;
                }

}

int anoBissexto(int a){ // Aqui, se tornará verdadeiro quando o ano for bissexto.
    return(a % 400 == 0) || ((a % 4 == 0) && (a % 100 != 0));
}

int seAnoBissexto(int a){ // Se o ano não for divisível por 4, ou por 100 e nem 400, ele será considerado um ano bissexto.
    return a/4 - a/100 + a/400;
}

int atualmente(int a, int m, int d){ // Número de dias corridos desde o início do ano.
    static int diasDoMeses[] = 
        {-1,0,31,59,90,120,151,181,212,243,273,304,334};
    return diasDoMeses[m] + d + ((m>2 && anoBissexto(a))? 1 : 0);
}

    long dias(int a, int m, int d){ // Número total de dias.

        int anoAnterior;
        anoAnterior = a - 1;
        return 365L * anoAnterior + seAnoBissexto(anoAnterior) + atualmente(a,m,d);

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Os códigos abaixo equivalem as informações que serão dadas no calendário, tais como os nomes dos meses, quantidade de dias e afins.
// Ah, e dependendo do que for mexer, poderá afetar a estética do calendário, então tome cuidado.

void calendario(int a, int m){ // Formato do calendário no modelo mês / ano.

    const char *mes[] = {NULL,
        " Janeiro", "Fevereiro", " Marco", " Abril", " Maio", " Junho",
        " Julho", " Agosto", " Setembro", " Outubro", " Novembro", " Dezembro" 
    };
    char diaDaSemana[] = "do se te qu qu se sa";
    int diasDoMeses[] =
        {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    int testeVar;
    int i,dia;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Os códigos abaixo equivalem ESTRITAMENTE ao comportamento do código em relação a sua estética.

    testeVar = dias(a, m, 1) % 7;
        if(anoBissexto(a))
            diasDoMeses[2] = 29;
                printf("\n    %s %d\n%s\n", mes[m], a, diaDaSemana);

        for(i=0;i<testeVar;i++)
            printf("   ");

        for(i=testeVar,dia=1;dia <= diasDoMeses[m];i++,dia++){
            printf("%2d ",dia);
            
            if(i % 7 == 6)
                printf("\n");
        }
    
}