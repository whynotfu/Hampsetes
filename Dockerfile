FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Устанавливаем необходимые инструменты
RUN apt-get update && apt-get install -y \
    build-essential \
    qt5-default \
    qttools5-dev-tools \
    libqt5sql5-sqlite \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Копируем только необходимые исходники сервера
COPY ser_ver/*.cpp ser_ver/*.h ser_ver/*.pro ./
COPY hampsters/Cazik/db/DataBase.db ./

# Генерируем Makefile с помощью qmake и компилируем
RUN qmake Server.pro
RUN make

# Создаем директорию для данных
RUN mkdir -p /app/data

# Открываем порт для TCP сервера
EXPOSE 33333

# Запускаем сервер
ENTRYPOINT ["./Server"]