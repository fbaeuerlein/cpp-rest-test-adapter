# cpp-rest-test-adapter <!-- omit in toc -->

A simple to use REST adapter to control C++ for integration testing purposes

- [Overview](#overview)
- [Building](#building)
- [Execution of api-server](#execution-of-api-server)
- [Some curl commands for testing](#some-curl-commands-for-testing)

## Overview

This is some small project to evaluate the capabilities of openapi-generator for C++ to create REST testing interfaces for embedded devices.
Simply i want to be able to set sensor values, switches, etc. remotely with some nice browser based testing frontend.

The frontend has still to be evaluated.

## Building

    mkdir build
    cd build && cmake .. && make

## Execution of api-server

Simply run api-server. It will open a port at 9080 and serves the definition from openapi.yaml.

## Some curl commands for testing

Set switch state:

    curl -X POST localhost:9080/switches/switch1 -d "{ \"desiredState\" : false }"

Server should print:

    switch1: OFF
