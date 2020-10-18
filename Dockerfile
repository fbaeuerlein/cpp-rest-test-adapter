FROM ubuntu:20.04

# tzdata confirmation override
ENV DEBIAN_FRONTEND=noninteractive 

RUN apt-get update && apt-get -y upgrade

# we need git to run as dev container
RUN apt-get -y install git 

# install compiler and build stuff
RUN apt-get -y install build-essential cmake clang-tidy clang-format clang 

# install documentation stuff
RUN apt-get -y install doxygen plantuml graphviz 

# other 
RUN apt-get -y install lcov iwyu curl

# install swagger-codegen
RUN apt-get -y install maven
RUN git clone --depth 1 https://github.com/openapitools/openapi-generator
WORKDIR /openapi-generator
RUN mvn clean package 

WORKDIR /
RUN apt-get clean
