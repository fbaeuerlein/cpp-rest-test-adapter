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
RUN apt-get -y install openjdk-8-jdk openjdk-8-jre maven
WORKDIR /
RUN git clone --depth 1 https://github.com/swagger-api/swagger-codegen.git
WORKDIR /swagger-codegen

# use the right jdk!
RUN JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/ mvn clean package 

RUN apt-get clean
