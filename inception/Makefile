NAME = inception

.PHONY : all
all : $(NAME)
$(NAME) :
	sudo mkdir -p ${HOME}/data/mariadb ${HOME}/data/wordpress 
	sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env up --force-recreate --build -d

.PHONY : clean 
clean :
	sudo docker-compose -f srcs/docker-compose.yml --env-file srcs/.env down --rmi all -v --remove-orphans 

.PHONY : fclean 
fclean : clean
	sudo rm -rf ${HOME}/data
	sudo docker system prune -a -f

.PHONY : re
re : fclean all
