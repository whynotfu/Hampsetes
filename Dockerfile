FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Обновляем списки пакетов и устанавливаем необходимые библиотеки Qt и инструменты сборки
RUN apt-get update && apt-get install -y \
  build-essential \
  qt5-default \
  qttools5-dev-tools \
  && rm -rf /var/lib/apt/lists/*

# Копируем исходный код в контейнер и задаём рабочую директорию
WORKDIR /app
COPY . /app

