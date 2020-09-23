#!/bin/bash

PULSAR_RELEASE_TAG='pulsar-2.6.1'
echo "7--- installing pulsar dependacies ---" && \
    mkdir /var/local/git/pulsar && \
    wget https://archive.apache.org/dist/pulsar/${PULSAR_RELEASE_TAG}/DEB/apache-pulsar-client.deb -O /var/local/git/pulsar/apache-pulsar-client.deb && \
    wget https://archive.apache.org/dist/pulsar/${PULSAR_RELEASE_TAG}/DEB/apache-pulsar-client-dev.deb -O /var/local/git/pulsar/apache-pulsar-client-dev.deb && \
    cd /var/local/git/pulsar && \
    apt install ./apache-pulsar-client*.deb && \
    rm -rf /var/local/git/pulsar 
    cd ~

echo "8--- building alcor-control-agent"
cd ~/pulsar-test && cmake . && make


echo "10--- running alcor-control-agent"
./build/bin/PulsarTest -d &
