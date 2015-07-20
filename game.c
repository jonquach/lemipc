/*
** game.c for game.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sat Mar  7 18:10:57 2015 Daniel Han
** Last update Sun Mar  8 23:39:35 2015 Daniel Han
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "lemipc.h"

int	        game_over(t_data *d)
{
  if (shmctl(d->shm_id, IPC_RMID, NULL) == -1)
    {
      fprintf(stderr, "Error : shmctl failed when removing\n");
      return (1);
    }
  if (semctl(d->sem_id, 0, IPC_RMID, 0) == -1)
    {
      fprintf(stderr, "Error : semctl failed when removing\n");
      return (1);
    }
  return (0);
}

void		move_player(char *board)
{
  int		i;
  int		pos;

  i = 0;
  while (board[i] != '\0')
    {
      if (board[i] == '1' || board[i] == '2')
	{
	  pos = my_rand();
	  if (board[pos] != '1' && board[pos] != '2')
	    {
	      board[pos] = board[i];
	      board[i] = '0';
	    }
	}
      ++i;
    }
}

void		is_dead(char *board, int i, char killer)
{
  int		nb;

  nb = 0;
  if (board[i - 1] == killer)
    ++nb;
  if (board[i + 1] == killer)
    ++nb;
  if (board[i - 10] == killer)
    ++nb;
  if (board[i + 10] == killer)
    ++nb;
  if (nb >= 2)
    board[i] = '0';
}

void		game_start(char *board)
{
  int		i;
  char		killer;

  while (check_end(board) == 1)
    {
      i = 0;
      while (board[i] != '\0')
	{
	  if (board[i] == '1' || board[i] == '2')
	    {
	      if (board[i] == '1')
		killer = '2';
	      else
		killer = '1';
	      is_dead(board, i, killer);
	    }
	  ++i;
	}
      display_board(board);
      move_player(board);
    }
}
