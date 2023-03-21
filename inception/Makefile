up:
	@${MAKE} JOB="up --build -d" job
	@echo "Done: All containers are up and running"; \

down:
	@${MAKE} JOB="down" job
	@echo "Done: All containers are down";

start:
	@${MAKE} JOB="start" job
	@echo "Done: All containers are started"

stop:
	@${MAKE} JOB="stop" job
	@echo "Done: All containers are stopped"

status:
	@${MAKE} JOB="ps" job

job:
ifndef JOB
	@printf "\033[31m" >&2
	@echo "Error: Variable 'JOB' to execute is not set" >&2
	@printf "\033[0m" >&2
	@exit 1
else
	@if [ "$(JOB)" != "up --build -d" -a "$(JOB)" != "down" -a "$(JOB)" != "start" -a "$(JOB)" != "stop" -a "$(JOB)" != "ps" ]; then \
		printf "\033[31m" >&2; \
        printf "Error: Invalid 'JOB' specified: " >&2; \
		echo ${JOB} >&2; \
		printf "\033[0m" >&2; \
        exit 1; \
    fi
	@docker-compose -f ./srcs/docker-compose.yml ${JOB}
endif

.PHONY: up down stop start status job

.NOTPARALLEL: up down stop start status job