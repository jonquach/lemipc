/*
** lemipc.h for lemipc.h in /home/han_d/rendu/PSU_2014_lemipc
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Tue Mar  3 16:41:58 2015 Daniel Han
** Last update Sun Mar  8 23:26:52 2015 Daniel Han
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_

#include <sys/types.h>
#include <sys/sem.h>

/*
** Game Information Macro
*/
#define BOARD_SIZE 100

/*
** Game Data Structure
*/

typedef struct		s_data
{
  key_t			key;
  int			shm_id;
  void			*board;
  int			sem_id;
  struct sembuf		sembuf;
}			t_data;

/*
** game.c
*/
int			game_over(t_data *);
void			is_dead(char *, int, char);
void			game_start(char *);
int			check_end(char *);

/*
** player.c
*/
int			find_right_player(char *, int, char);
int			get_nb_player(char *, char);
int			find_player(char *, char);

/*
** process.c
*/
int			my_rand();
int			other_process(t_data *);
char			*init_board(void *, int);
void			display_board(char *);
int		        main_process(t_data *);

/*
** sem.c
*/
int			sem_op_add(t_data *);
int			sem_op_sub(t_data *);
int			init_sem(t_data *);

/*
** shm.c
*/
int			init_shm(t_data *);

/*
** main.c
*/
int			start_lemipc(char *);

#endif /* !LEMIPC_H_ */
