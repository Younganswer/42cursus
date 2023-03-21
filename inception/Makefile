DOCKER_COMPOSE = docker-compose -f ./srcs/docker-compose.yml

up:
	@${DOCKER_COMPOSE} up --build -d
	@echo "Done: All containers are up and running";

down:
	@${DOCKER_COMPOSE} down
	@echo "Done: All containers are down";

start:
	@${DOCKER_COMPOSE} start
	@echo "Done: All containers are started"

stop:
	@${DOCKER_COMPOSE} stop
	@echo "Done: All containers are stopped"

status:
	@${DOCKER_COMPOSE} ps

.PHONY: up down stop start status job

.NOTPARALLEL: up down stop start status job