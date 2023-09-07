#include <ncurses.h>

int main()
{ initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);

  int altura, largura, start_y, start_x;
  altura = 30;
  largura = 60;
  start_x = (COLS - largura) / 2;
  start_y = (LINES - altura) / 2;

  WINDOW * janela = newwin(altura, largura, start_y, start_x);
  wattron(janela, COLOR_PAIR(1));
  refresh();
  box(janela, 0, 0);
  wborder(janela, '#', '#', '#', '#', '#', '#', '#', '#');
  mvwprintw(janela, 3, 5, "Bem vindo ao conversor de Fahrenheit para Celsius.");
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
        float temperaturaF, temperaturaC;
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '"', '"', '"', '"', '"', '"', '"', '"');
        mvwprintw(janela, 5, 7, "Digite a temperatura em Fahrenheit e a converta");
        mvwprintw(janela, 6, 25, "em Celsius.");
        mvwscanw(janela, 7, 28, "%f", &temperaturaF);
        temperaturaC = (temperaturaF - 32) * 5/9;
        mvwprintw(janela, 15, 13, "A temperatura em Celsius e:  %.2fC", temperaturaC);
        mvwprintw(janela, 23, 8, "Obrigado por usar o conversor de temperatura!");
        break;
    case '2':
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 13, 7, "Obrigado por usar o conversor de temperatura!");
        break;
}
  wrefresh(janela);

  getch();
  endwin();
  return 0;
}