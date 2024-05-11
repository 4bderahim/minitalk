CC = cc 
CFLAGS = -Wall -Wextra -Werror
SERVER_C = mini_utils.c talk_utils.c server.c
SERVER_OBJ = $(SERVER_C:.c=.o)
CLIENT_C = client.c
SERVER_PROG = server
CLIENT_PROG = client

BSERVER_C = mini_utils.c talk_utils.c server_bonus.c
BSERVER_OBJ = $(BSERVER_C:.c=.o)
BCLIENT_C = mini_utils.c client_bonus.c
BSERVER_PROG = server_bonus
BCLIENT_PROG = client_bonus

all : $(SERVER_PROG) $(CLIENT_PROG) 
bonus: $(BSERVER_PROG) $(BCLIENT_PROG)


$(SERVER_PROG) : $(SERVER_OBJ) 
	@$(CC)  $(CFLAGS) $^ -o $@
$(CLIENT_PROG) : $(CLIENT_C:.c=.o) 
	@$(CC) $(CFLAGS) $^ -o $@


$(BSERVER_PROG) : $(BSERVER_OBJ) 
	@$(CC) $(CFLAGS) $^ -o $@
$(BCLIENT_PROG) : $(BCLIENT_C:.c=.o) 
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -rf *.o
fclean:
	@rm -rf *.o $(SERVER_PROG) $(CLIENT_PROG) $(BSERVER_PROG) $(BCLIENT_PROG)
re: fclean all