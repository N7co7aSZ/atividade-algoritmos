 #include <ncurses.h>
 #include <math.h>

int main()
{ initscr();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);

  int altura, largura, start_y, start_x;
  altura = 30;
  largura = 60;
  start_x = (COLS - largura) / 2;
  start_y = (LINES - altura) / 2;

  WINDOW * janela = newwin(altura, largura, start_y, start_x);
  wattron(janela, COLOR_PAIR(1));
  refresh();
  box(janela, 0, 0);
  wborder(janela, '|', '|', '-', '-', '*', '*', '*', '*');
  mvwprintw(janela, 5, 12, "Bem vindo a calculadora da hipotenusa.");
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
        float cateto1, cateto2, hipotenusa;
        wclear(janela);
        box(janela, 0, 0);
        wborder(janela, '*', '*', '*', '*', '*', '*', '*', '*');
        mvwprintw(janela, 5, 13, "Digite o valor do primeiro cateto.");
        mvwscanw(janela, 7, 28, "%f", &cateto1);
        mvwprintw(janela, 10, 13, "Digite o valor do segundo cateto.");
        mvwscanw(janela, 12, 28, "%f", &cateto2);
        hipotenusa = sqrt((cateto1 * cateto1) + (cateto2 * cateto2));
        mvwprintw(janela, 17, 16, "O valor da hipotenusa e: %.2f.", hipotenusa);
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