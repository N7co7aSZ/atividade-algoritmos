#include <ncurses.h>

int main()
{ initscr();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);

  int altura, largura, start_y, start_x;
  altura = 30;
  largura = 60;
  start_x = (COLS - largura) / 2;
  start_y = (LINES - altura) / 2;

  WINDOW * janela = newwin(altura, largura, start_y, start_x);
  wattron(janela, COLOR_PAIR(1));
  refresh();
  box(janela, 0, 0);
  wborder(janela, '.', '.', '.', '.', '.', '.', '.', '.');
  mvwprintw(janela, 4, 8, "Bem vindo a calculadora do consumo medio de");
  mvwprintw(janela, 5, 17, "combustivel do seu carro.");
  mvwprintw(janela, 15, 16, "Pressione '1' para continuar.");
  mvwprintw(janela, 20, 18,"Pressione '2' para sair.");
  wrefresh(janela);

  int tecla;

  noecho();

  while ((tecla = wgetch(janela)) != '1' && tecla !='2') {

  }

  echo();

  switch (tecla)
{
    case '1':
        float distancia, consumoT, consumoM;
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 5, 8, "Digite a distancia percorrida pelo seu carro.");
        mvwscanw(janela, 7, 28, "%f", &distancia);
        mvwprintw(janela, 10, 2, "Digite o total de litros de combustivel gasto no trajeto.");
        mvwscanw(janela, 12, 28, "%f", &consumoT);
        consumoM = distancia/consumoT;
        mvwprintw(janela, 17, 6, "O consumo de combustivel medio foi de: %.2f l/km", consumoM);
        mvwprintw(janela, 24, 6, "Obrigado por usar a calculadora de combustivel!");
        break;
    case '2':
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 13, 6, "Obrigado por usar a calculadora de combustivel!");
        break;
}
  wrefresh(janela);

  getch();
  endwin();
  return 0;
}