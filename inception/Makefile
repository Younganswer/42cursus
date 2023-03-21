up:
	@${MAKE} JOB="up --build -d" job

down:
	@${MAKE} JOB="down" job

start:
	@${MAKE} JOB="start" job

stop:
	@${MAKE} JOB="stop" job

status:
	@${MAKE} JOB="ps" job

job:
	@docker-compose -f ./srcs/docker-compose.yml ${JOB}

.PHONY: all up down stop start status job