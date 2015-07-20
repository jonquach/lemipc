/*
** player.c for player.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Mar  8 22:33:35 2015 Daniel Han
** Last update Sun Mar  8 23:20:57 2015 Daniel Han
*/

#include "lemipc.h"

int		find_right_player(char *board, int pos, char id)
{
  if (board[pos] == id)
    return (0);
  return (1);
}

int		get_nb_player(char *board, char id)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (board[i] != '\0')
    {
      if (board[i] == id)
	++nb;
      ++i;
    }
  return (nb);
}

int		find_player(char *board, char id)
{
  int		i;

  i = 0;
  while (board[i] != '\0')
    {
      if (board[i] == id)
	return (0);
      ++i;
    }
  return (1);
}

int		check_end(char *board)
{
  if (find_player(board, '1') == 0 && find_player(board, '2') == 0)
    return (1);
  if (find_player(board, '1') == 1 && find_player(board, '2') == 1)
    return (1);
  return (0);
}
