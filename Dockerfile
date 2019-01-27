FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y

RUN apt-get install -y build-essential

RUN apt-get -y install libboost-all-dev

RUN apt-get -y install libssl-dev

RUN apt-get -y install cmake

COPY . /app

RUN mkdir /app/build

WORKDIR /app/build

RUN cmake ..
RUN make

ENTRYPOINT ["sh", "-c", "../bin/kadopon"]
#CMD ["sh", "-c", "../bin/kadopon"]





