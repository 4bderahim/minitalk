CC = cc 
CFLAGS = -Wall -Wextra -Werror
SEREVR_C = mini_utils.c talk_utils.c server.c
CLIENT_C = client.c
SERVER_PROG = server
CLIENT_PROG = client

BSERVER_C = mini_utils.c talk_utils.c server_bonus.c
BCLIENT_C = mini_utils.c client_bonus.c
BSERVER_PROG = server_bonus
BCLIENT_PROG = client_bonus

all : $(SERVER_PROG) $(CLIENT_PROG)
bonus: $(BSERVER_PROG) $(BCLIENT_PROG)
$(SERVER_PROG) : $(SEREVR_C)
	@$(CC)  $(CFLAGS) $^ -o $@
$(CLIENT) : $(CLIENT_C) 
	@$(CC) $(CFLAGS) $^ -o $@

$(BSERVER_PROG) : $(BSERVER_C) 
	@$(CC) $(CFLAGS) $^ -o $@

$(BCLIENT_PROG) : $(BCLIENT_C) 
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -rf *.o
fclean:
	@rm -rf *.o $(SERVER_PROG) $(CLIENT_PROG) $(BSERVER_PROG) $(BCLIENT_PROG)

 
re: fclean all