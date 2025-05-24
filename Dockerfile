FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
  build-essential \
  qt5-default \
  qttools5-dev-tools \
  && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . /app

