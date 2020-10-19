// Copyright 2019 The Alcor Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <stdexcept>
#include "producer.h"

using namespace std;
using namespace pulsar;

namespace aca_message_pulsar
{
ACA_Message_Pulsar_Producer::ACA_Message_Pulsar_Producer(string brokers, string topic)
{
  setBrokers(brokers);
  setTopicName(topic);

  this->ptr_producer = new Producer();
  this->ptr_client= new Client(brokers,this->client_config);
}

ACA_Message_Pulsar_Producer::~ACA_Message_Pulsar_Producer()
{
  delete ptr_client;
}

string ACA_Message_Pulsar_Producer::getBrokers() const
{
  return this->brokers_list;
}

string ACA_Message_Pulsar_Producer::getTopicName() const
{
  return this->topic_name;
}

void ACA_Message_Pulsar_Producer::setTopicName(string topic)
{
  this->topic_name = topic;
}


void ACA_Message_Pulsar_Producer::publish(string message)
{
  Result result = this->ptr_client->createProducer(this->topic_name, *(this->ptr_producer));
  if (result != ResultOk) {
    cout << "Error creating producer" << endl;
    return;
  }

  // Publish 10 messages to the topic
  for (int i = 0; i < 10; i++){
    Message msg = MessageBuilder().setContent(message).build();
    Result res = ptr_producer->send(msg);
    cout << "Message sent" << endl;
  }
}



void ACA_Message_Pulsar_Producer::setBrokers(string brokers)
{
  //TODO: validate string as IP address
  this->brokers_list = brokers;
}

} // namespace messagemanager
