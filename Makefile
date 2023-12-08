NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Separate source files for server and client
SRC_SERVER = server.c
SRC_CLIENT = client.c

# Separate object files for server and client
OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

FT_LIBFT_PATH = ./libft
FT_LIBFT_NAME = ./libft/libft.a
FT_PRINTF_PATH = ./printf
FT_PRINTF_NAME = ./printf/libftprintf.a

# The all target should build both server and client
all: $(NAME_SERVER) $(NAME_CLIENT)

# Separate compilation rules for server and client
$(NAME_SERVER): $(OBJS_SERVER)
	make -s -C $(FT_LIBFT_PATH)
	make -s -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF_NAME) $(FT_LIBFT_NAME) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	make -s -C $(FT_LIBFT_PATH)
	make -s -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF_NAME) $(FT_LIBFT_NAME) -o $(NAME_CLIENT)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make -s -C $(FT_LIBFT_PATH) clean
	make -s -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	make -s -C $(FT_LIBFT_PATH) fclean
	make -s -C $(FT_PRINTF_PATH) fclean

re: fclean all
