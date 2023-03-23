DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

up:
	@${DOCKER_COMPOSE} up --build -d

down:
	@${DOCKER_COMPOSE} down

start:
	@${DOCKER_COMPOSE} start

stop:
	@${DOCKER_COMPOSE} stop

clean:
	@rm -rf ./srcs/requirements/mariadb/data/*
	@rm -rf ./srcs/requirements/nginx/logs/*
	@rm -rf ./srcs/requirements/wordpress/html/*

fclean: down clean
	@docker rmi -f $$(docker images -a -q)
	@docker volume rm $$(docker volume ls -q)

.IGNORE: fclean

.PHONY: up down stop start clean fclean

.NOTPARALLEL: up down stop start clean fclean
