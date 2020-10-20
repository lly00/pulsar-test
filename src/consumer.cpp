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

#include "consumer.h"
#include <iostream>

using namespace std;
using namespace pulsar;

namespace aca_message_pulsar
{
ACA_Message_Pulsar_Consumer::ACA_Message_Pulsar_Consumer(string brokers, string subscription_name)
{
  setBrokers(brokers);
  setSubscriptionName(subscription_name);

  // TO DO: Construct the configuration
  // Create the consumer and client
  this->ptr_consumer = new Consumer();
  this->ptr_client= new Client(brokers,this->client_config);
}

ACA_Message_Pulsar_Consumer::~ACA_Message_Pulsar_Consumer()
{
  //delete ptr_consumer;
  delete ptr_client;
}

string ACA_Message_Pulsar_Consumer::getBrokers() const
{
  return this->brokers_list;
}

string ACA_Message_Pulsar_Consumer::getLastTopicName() const
{
  return this->topic_name;
}

string ACA_Message_Pulsar_Consumer::getSubscriptionName() const
{
  return this->subscription_name;
}

void ACA_Message_Pulsar_Consumer::setSubscriptionName(string subscription_name)
{
  this->subscription_name = subscription_name;
}


void messageListener(Consumer consumer,const Message& message){
    consumer.acknowledge(message);
    cout << "<=====incoming message: " << message.getDataAsString() << endl;
}

bool ACA_Message_Pulsar_Consumer::consumeDispatched(string topic)
{
  int rc;
  int overall_rc = EXIT_SUCCESS;
  Result result;
  Message message;

  this->consumer_config.setMessageListener(messageListener);
  result = this->ptr_client->subscribe(topic,this->subscription_name,this->consumer_config,*(this->ptr_consumer));

  if (result != Result::ResultOk){
    cout << "Failed to subscribe topic" << topic << endl;
    return -1;
  }

  cout << "Consumer consuming messages from topic: " << topic << endl;

  
  //Receive message
  // result = this->ptr_consumer->receive(message);

  // if (result != Result::ResultOk) {
  //   cout << "Failed to receive message from topic:" << topic << endl;
  //   return EXIT_FAILURE;
  // }

  // else{
  //   cout << "<=====incoming message: " << message.getDataAsString() << endl;

  //   // Now acknowledge message
  //   this->ptr_consumer->acknowledge(message);
  // }
  return overall_rc;
}

void ACA_Message_Pulsar_Consumer::setBrokers(string brokers)
{
  //TODO: validate string as IP address
  this->brokers_list = brokers;
}

void ACA_Message_Pulsar_Consumer::setLastTopicName(string topic)
{
  this->topic_name = topic;
}

} // namespace aca_message_pulsar
