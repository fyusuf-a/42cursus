export DOCKER_PATH_MACHINE=~/goinfre/docker/machine

docker-machine -s $DOCKER_PATH_MACHINE create default
docker-machine -s $DOCKER_PATH_MACHINE start default
docker-machine -s $DOCKER_PATH_MACHINE env
eval $(docker-machine -s $DOCKER_PATH_MACHINE env)
