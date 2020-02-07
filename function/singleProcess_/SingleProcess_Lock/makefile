obj = client_demo.o single_instance.o 
target = client.out
CC = g++


$(target): $(obj)  
	$(CC) $(obj) -o $(target)  
%.o: %.c  
	$(CC) -c $< -o $@  


