/*
 * SwiftResult.h
 *
 *  Created on: 2014-05-28
 *      Author: Behrooz Shafiee Sarjaz
 */

#ifndef SWIFTRESULT_H_
#define SWIFTRESULT_H_

//#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPClientSession.h>
#include <iostream>
#include <ErrorNo.h>

namespace Swift {

template <class T>
class SwiftResult {
  Poco::Net::HTTPResponse *response;
  Poco::Net::HTTPClientSession *session;
  SwiftError error;
  /** Real Data **/
  T payload;

public:
  SwiftResult():response(nullptr), session(nullptr), error(SwiftError::SWIFT_OK,"SWIFT_OK")  {
  }

  virtual ~SwiftResult() {
    if(response!=nullptr) {
      delete response;
      response = nullptr;
    }
    if(payload!=nullptr) {
      delete static_cast<T>(payload);
      payload = nullptr;
    }
    if(session!=nullptr) {
      delete session;
      session = nullptr;
    }

    std::cout <<"DESTRUCTOR SWIFTRESULT"<<std::endl;
  }

  const SwiftError& getError() const {
    return error;
  }

  void setError(const SwiftError& error) {
    this->error = error;
  }

  T getPayload() const {
    return payload;
  }

  void setPayload(T payload) {
    this->payload = payload;
  }

  Poco::Net::HTTPResponse* getResponse() const {
    return response;
  }

  void setResponse(Poco::Net::HTTPResponse* response) {
    this->response = response;
  }

  Poco::Net::HTTPClientSession* getSession() const {
    return session;
  }

  void setSession(Poco::Net::HTTPClientSession* _session) {
    this->session = _session;
  }
};

} /* namespace Swift */

#endif /* SWIFTRESULT_H_ */
