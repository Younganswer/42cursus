DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

up:
	@${DOCKER_COMPOSE} up --build -d

down:
	@${DOCKER_COMPOSE} down

start:
	@${DOCKER_COMPOSE} start

stop:
	@${DOCKER_COMPOSE} stop

status:
	@docker ps

clean:
	@rm -rf volumes/mariadb/*
	@rm -rf volumes/wordpress/*

.PHONY: up down stop start status

.NOTPARALLEL: up down stop start status
