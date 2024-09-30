/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:38:46 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/30 17:36:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	terminal(t_shell *shell)
{
	char	*input;

	while (1)
	{
		input = readline(B_RED PROMPT DEFAULT);
		input_validation(input);
		shell->input = ft_split(input, ' ');
		lexer(shell);
		print_lst(shell->token_lst);
		if (input == NULL || !ft_strcmp(input, "exit"))
		{
			printf("\nExiting shell...\n");
			free(input);
			free_shell(shell);
			break;
		}
		if (input)
			add_history(input);
		printf("You entered: %s\n", input);
		free(input);
		free_shell(shell);
	}
}

void	free_shell(t_shell *shell)
{
	int	i;
	
	i = 0;
	while(shell->input[i])
		free(shell->input[i++]);
	free(shell->input);

	t_list	*tmp;

	tmp = shell->token_lst;
	while (shell->token_lst)
	{
		tmp = shell->token_lst -> next;
		free(shell->token_lst);
		shell->token_lst = tmp;
	}
}
