/*
** init.c for init.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sat Mar  7 18:14:38 2015 Daniel Han
** Last update Sun Mar  8 22:39:10 2015 Daniel Han
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "lemipc.h"

int		init_shm(t_data *d)
{
  d->shm_id = shmget(d->key, BOARD_SIZE, SHM_R | SHM_W);
  if (init_sem(d) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (d->shm_id == -1)
    {
      if ((d->shm_id = shmget(d->key, BOARD_SIZE, IPC_CREAT | SHM_R | SHM_W))
	  == -1)
	{
	  fprintf(stderr, "Error : shmget failed during init\n");
	  return (EXIT_FAILURE);
	}
      if ((d->board = shmat(d->shm_id, NULL, SHM_R | SHM_W)) == (void *)-1)
	{
	  fprintf(stderr, "Error : shmat failed during init\n");
	  return (EXIT_FAILURE);
	}
      main_process(d);
      return (game_over(d));
    }
  else
    {
      if (other_process(d) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
