/*
** sem.c for sem.c in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Mar  8 21:55:02 2015 Daniel Han
** Last update Sun Mar  8 22:01:03 2015 Daniel Han
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "lemipc.h"

int	        sem_op_add(t_data *d)
{
  d->sembuf.sem_num = 0;
  d->sembuf.sem_flg = 0;
  d->sembuf.sem_op = 1;
  if (semop(d->sem_id, &d->sembuf, 1) == -1)
    {
      fprintf(stderr, "Error : semop failed during add\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	        sem_op_sub(t_data *d)
{
  d->sembuf.sem_num = 0;
  d->sembuf.sem_flg = 0;
  d->sembuf.sem_op = -1;
  if (semop(d->sem_id, &d->sembuf, 1) == -1)
    {
      fprintf(stderr, "Error : semop failed during sub\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		init_sem(t_data *d)
{
  if ((d->sem_id = semget(d->key, 1, SHM_R | SHM_W)) == -1)
    {
      if ((d->sem_id = semget(d->key, 1, IPC_CREAT | SHM_R | SHM_W)) == -1)
	{
	  fprintf(stderr, "Error : semget failed during init\n");
	  return (EXIT_FAILURE);
	}
      if (semctl(d->sem_id, 0, SETVAL, 0) == -1)
	{
	  fprintf(stderr, "Error : semctl failed during init\n");
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
