/*
** main.c for main.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Tue Mar  3 16:40:49 2015 Daniel Han
** Last update Sun Mar  8 22:31:37 2015 Daniel Han
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "lemipc.h"

int	        start_lemipc(char *path)
{
  t_data	*d;

  srand(time(NULL));
  if ((d = malloc(sizeof(t_data))) == NULL)
    {
      fprintf(stderr, "Error : malloc failed\n");
      return (EXIT_FAILURE);
    }
  if ((d->key = ftok(path, 0)) == -1)
    {
      fprintf(stderr, "Error : ftok failed\n");
      return (EXIT_FAILURE);
    }
  if (init_shm(d) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		main()
{
  char		*path;

  if ((path = getenv("PWD")) == NULL)
    {
      fprintf(stderr, "Error : PWD not found.\n");
      return (EXIT_FAILURE);
    }
  return (start_lemipc(path));
}
