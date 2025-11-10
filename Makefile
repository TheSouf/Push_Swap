# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofkhali <sofkhali@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 18:04:33 by sofkhali          #+#    #+#              #
#    Updated: 2025/11/10 17:37:36 by sofkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = push_swap

CC        = cc

CFLAGS    = -Wall -Wextra -Werror

SRCS      = operations.c parsing.c main.c ft_split.c error.c free.c \
            operations2.c operations3.c radix_sort.c sort_small_nbr.c \
            utils_for_stack.c utils.c validation.c index.c sort_small_nbr2.c

OBJS      = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ Push_swap compiled successfully!"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "🧹 Cleaned object files!"

fclean: clean
	@rm -f $(NAME)
	@echo "🔥 Fully cleaned!"

re: fclean all

.PHONY: all clean fclean re
