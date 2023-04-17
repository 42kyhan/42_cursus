NAME = inception

all: $(NAME)

$(NAME):
		mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb
		docker compose -f ./srcs/docker-compose.yml up -d

clean:
		docker compose -f ./srcs/docker-compose.yml down --rmi all --remove-orphans -v

fclean: clean
		rm -rf ${HOME}/data
		docker system prune -a --volumes -f
		docker network prune -f
		docker volume prune -f

re: fclean all

.PHONY: all clean fclean re