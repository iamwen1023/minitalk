/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlo <wlo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:48:50 by wlo               #+#    #+#             */
/*   Updated: 2021/08/02 17:54:46 by wlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
int					exponentInt(int n);
int					convertToDecimal(char *s);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s);
void				handle_message(char *message, int id);
void				messageToClient(siginfo_t *siginfo);
void				handler_new(int signum, siginfo_t *siginfo, void *context);
struct sigaction	settingSigation(struct sigaction action);

#endif
