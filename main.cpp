#include <iostream>
#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <memory>

using namespace Pistache;

struct HelloHandler // : public Http::Handler 
{
  // HTTP_PROTOTYPE(HelloHandler)

  HelloHandler() 
  : _httpEndpoint(std::make_shared<Http::Endpoint>(Address(Ipv4::any(),9080)))
  {
    Rest::Routes::Get(_router, "/device/:id", Rest::Routes::bind(&HelloHandler::my_cb1, this) );
    Rest::Routes::Post(_router, "/device/:id", Rest::Routes::bind(&HelloHandler::my_cb2, this));
    _httpEndpoint->setHandler(_router.handler());
    _httpEndpoint->serve();
  }

  // void onRequest(const Http::Request& r, Http::ResponseWriter writer) const final 
  // {
  //   writer.send(Http::Code::Ok, "Unknown call!");
  // }

  void my_cb1(const Rest::Request& r, Http::ResponseWriter writer)
  {
    if ( r.method() == Http::Method::Get )
    {
      auto id = r.param(":id").as<std::string>();
      writer.send(Http::Code::Ok, "Hello, World " + id + "!");
    }
    
  }

  void my_cb2(const Rest::Request& r, Http::ResponseWriter writer)
  {
    if ( r.method() == Http::Method::Post )
    {
      auto id = r.param(":id").as<std::string>();
      writer.send(Http::Code::Ok, "Posting " + r.body() + " to " + id + "!");
    }
    
  }  
  std::shared_ptr<Http::Endpoint> _httpEndpoint;

  Rest::Router _router;
};

int main() 
{
  // Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
  HelloHandler hh;
}

// int main(int argc, char const ** argv)
// {
//     std::cout << "Hello World" << std::endl;
// }