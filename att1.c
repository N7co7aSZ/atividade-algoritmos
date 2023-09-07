#include <ncurses.h>

int main()
{ initscr();
  start_color();
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);

  int altura, largura, start_y, start_x;
  altura = 30;
  largura = 60;
  start_x = (COLS - largura) / 2;
  start_y = (LINES - altura) / 2;

  WINDOW * janela = newwin(altura, largura, start_y, start_x);
  wattron(janela, COLOR_PAIR(1));
  refresh();
  box(janela, 0, 0);
  wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
  mvwprintw(janela, 3, 7, "Bem vindo a calculadora da media de duas notas.");
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
        float nota1, nota2, media;
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 5, 17, "Digite a sua primeira nota.");
        mvwscanw(janela, 7, 28, "%f", &nota1);
        mvwprintw(janela, 10, 17, "Digite a sua segunda nota.");
        mvwscanw(janela, 12, 28, "%f", &nota2);
        media = (nota1 + nota2)/2;
        mvwprintw(janela, 17, 17, "A sua media foi de: %.2f", media);
        mvwprintw(janela, 24, 14, "Obrigado por usar a calculadora!");
        break;
    case '2':
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 13, 14, "Obrigado por usar a calculadora!");
        break;
}
  wrefresh(janela);

  getch();
  endwin();
  return 0;
}