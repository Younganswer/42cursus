DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

up:
	@mkdir -p ./srcs/requirements/mariadb/data
	@mkdir -p ./srcs/requirements/nginx/logs
	@${DOCKER_COMPOSE} up --build -d

down:
	@${DOCKER_COMPOSE} down

start:
	@${DOCKER_COMPOSE} start

stop:
	@${DOCKER_COMPOSE} stop

clean:
	@rm -rf ./srcs/requires/mariadb/data/*
	@rm -rf ./srcs/requires/nginx/logs/*

.PHONY: up down stop start

.NOTPARALLEL: up down stop start
