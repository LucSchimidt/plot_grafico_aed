#include <stdio.h>
#include <math.h>
#include <graphics.h>


void funcaoLinear(float a, float b) {
    //funcao linear =  a.x + b

    float escalaX = 10.0;
    float escalaY = 10.0;

    float centerXs = getmaxx() / 2.0;
    float centerYs = getmaxy() / 2.0;

    float x1 = -1000.0;
    float x2 = 1000.0;
    float y1, y2;

    y1 = (a*x1) + b;
    y2 = (a*x2) + b;

    //============================================================================
    //Montando o gráfico:

    line(centerXs + x1 * escalaX, centerYs - y1 * escalaY, centerXs + x2 * escalaX, centerYs - y2 * escalaY); // Desenha a linha diagonal:

    getch();

}


void funcaoQuadratica(float a, float b, float c) {
    //funcao quadratica = a.x**2 + bx + c


    int x;
    float y, prev_x, prev_y;
    float xI, xII;
    float escalaX = 20.0;
    float escalaY = 20.0;
    float incremento_parabola = 0.01;
    float centerXs = getmaxx() / 2.0;
    float centerYs = getmaxy() / 2.0;

    float delta;

    delta = (pow(b, 2)) - (4.0*a*c);

    printf("Delta = %f\n", delta);

    if (delta > 0) {

        xI = (-b + sqrt(delta))/(2.0*a);
        xII = (-b - sqrt(delta))/(2.0*a);

        printf("X1 = %f\n", xI);
        printf("X2 = %f\n", xII);


    } else if(delta == 0) {
        int xo = (-b + sqrt(delta))/2*a;

        printf("%f\n", xo);

    } else if(delta < 0){
        printf("\nA equacao nao possui raizes reais!\n");

    }


    // Calcular o primeiro ponto
    prev_x = -centerXs / escalaX;
    prev_y = a * prev_x * prev_x + b * prev_x + c;

    // Desenhar a parábola como uma série de linhas entre pontos adjacentes
    for (x = -centerXs / escalaX + incremento_parabola; x < centerXs / escalaX; x += incremento_parabola) {
        y = a * x * x + b * x + c;
        line(centerXs + prev_x * escalaX, centerYs - prev_y * escalaY, centerXs + x * escalaX, centerYs - y * escalaY);
        prev_x = x;
        prev_y = y;
    }

}



int main() {
    int opcao;
    int largura = 800;  // Largura desejada da tela
    int altura = 600;   // Altura desejada da tela
    int centerX, centerY, startX, startY;


    printf("==================================================\n");
    printf("Bem vindo ao Plotador de Graficos!\n\n");
    printf("Escolha o tipo de funcao que voce deseja plotar:\n");
    printf("Digite [1] para funcao linear;\n");
    printf("Digite [2] para funcao quadratica;\n\n");

    scanf("%d", &opcao);


    int gd = DETECT, gm; // Inicializador da tela
    initwindow(largura, altura, "Plot de Grafico - Lucas Schimidt");

    startX = 0;
    startY = 0;
    centerX = getmaxx() / 2;
    centerY = getmaxy() / 2;

    //Montando uma linha para o grafico:
    setcolor(WHITE);
    line(centerX, 0, centerX, getmaxy()); // Desenha o eixo Y (vertical)
    line(0, centerY, getmaxx(), centerY); // Desenha o eixo X (horizontal)

    //Montando a escala do grafico:
    while (startX < getmaxx()) {

        line(startX, centerY - 2, startX, centerY + 2);

        startX = startX +  10;
    }

    while(startY < getmaxy()) {
        line(centerX - 2, startY, centerX + 2, startY);

        startY = startY +  10;
    }


    if (opcao == 1) {
        float a = 0.0;
        float b = 0.0;

        setcolor(RED);

        printf("Insira o valor do coeficiente angular:\n");
        scanf("%f", &a);
        printf("\n");

        printf("Insira o valor do coeficiente linear:\n");
        scanf("%f", &b);
        printf("\n");

        funcaoLinear(a, b);
    }
    else if (opcao == 2) {

        float a = 0.0;
        float b = 0.0;
        float c = 0.0;

        setcolor(RED);

        printf("Insira o valor do coeficiente a:\n");
        scanf("%f", &a);
        printf("\n");

        printf("Insira o valor do coeficiente b:\n");
        scanf("%f", &b);
        printf("\n");

        printf("Insira o valor do coeficiente c:\n");
        scanf("%f", &c);
        printf("\n");

        funcaoQuadratica(a, b, c);


        setcolor(RED);

        getch();// Aguarda a entrada de uma tecla

    } else {
        printf("Nenhuma opção selecionada.");
        getch();
    }


    // Fecha o modo gráfico
    closegraph();

    return 0;
}
