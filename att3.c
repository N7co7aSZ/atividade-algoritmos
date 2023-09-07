#include <ncurses.h>

int main()
{ initscr();
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);

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
  mvwprintw(janela, 3, 3, "Bem vindo ao conversor de ASCII decimal e hexadecimal.");
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
        char caracter;
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 5, 6, "Digite um caracter para ser convertido em ASCII.");
        mvwscanw(janela, 7, 28, "%c", &caracter);
        int converter = (int)caracter;
        mvwprintw(janela, 13, 17, "Codigo ASCII em decimal: %d", converter);
        mvwprintw(janela, 18, 13, "Codigo ASCII em hexadecimal: 0x%X", converter);
        mvwprintw(janela, 23, 14, "Obrigado por usar o conversor!");
        break;
    case '2':
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 13, 14, "Obrigado por usar o conversor!");
        break;
}
  wrefresh(janela);

  getch();
  endwin();
  return 0;
}