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
	@${DOCKER_COMPOSE} ps

.PHONY: up down stop start status job

.NOTPARALLEL: up down stop start status job
