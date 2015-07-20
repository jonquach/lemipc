/*
** process.c for process.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Mar  8 21:53:24 2015 Daniel Han
** Last update Sun Mar  8 23:41:25 2015 Daniel Han
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>
#include "lemipc.h"

int		my_rand()
{
  return (rand() % 100);
}

int	        other_process(t_data *d)
{
  char		*new_board;
  int		pos;

  if ((d->board = shmat(d->shm_id, NULL, SHM_R | SHM_W)) == (void *)-1)
    {
      fprintf(stderr, "Error : shmat failed during init\n");
      return (EXIT_FAILURE);
    }
  new_board = d->board;
  pos = my_rand();
  while (find_right_player(new_board, pos, '2') != 0 ||
	 get_nb_player(new_board, '2') <= 10)
    {
      pos = my_rand();
      if (new_board[pos] != '1')
	new_board[pos] = '2';
    }
  if (sem_op_add(d) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void		display_board(char *board)
{
  static int	turn = 0;
  int		i;

  i = 0;
  printf("\nTurn %d\n", turn++);
  while (board[i] != '\0')
    {
      if (i % 10 == 0)
  	printf("\n");
      printf("%c", board[i]);
      ++i;
    }
  printf("\n");
  if (turn == 100)
    {
      if (get_nb_player(board, '1') > get_nb_player(board, '2'))
	printf("Team 1 win");
      else if (get_nb_player(board, '1') < get_nb_player(board, '2'))
	printf("Team 2 win");
      if (get_nb_player(board, '1') == get_nb_player(board, '2'))
	printf("Draw");
      exit(EXIT_FAILURE);
    }
  sleep(1);
}

char		*init_board(void *ptr, int board_size)
{
  char		*board;
  int		i;
  int		pos;

  board = ptr;
  i = 0;
  while (i < board_size)
    {
      board[i] = '0';
      ++i;
    }
  board[i] = '\0';
  i = 0;
  while (i <= 10)
    {
      pos = my_rand();
      board[pos] = '1';
      ++i;
    }
  return (board);
}

int		main_process(t_data *d)
{
  char		*new_board;

  new_board = init_board(d->board, BOARD_SIZE);
  if (sem_op_sub(d) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf("\nInitiliazing board ...\n");
  display_board(new_board);
  printf("\nGame start !\n");
  game_start(new_board);
  printf("\nGame Over\n");
  return (EXIT_SUCCESS);
}
